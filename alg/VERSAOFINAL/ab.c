//#include "ab.h"




//-------------------------------------------------
// funcoes auxiliares
//-------------------------------------------------

//funcao padrao pra ler strings.
//Como usamos muito o run.codes(que nao aceita fgets()), 
//no primeiro semestre, acabamos pegando o costume de usar
//essa funcao.
//p.s.: acabei de ler a ultima linha da especificacao e sei
//que serei xingado haha (mas nao vou mudar pq tenho medo de dar pau);
char *lerstr(){
    int a=0;
    char aux, *vetor=NULL;
    scanf(" %c", &aux);
    while(aux!='\n'){
        vetor = (char*)realloc(vetor, (a+1)*sizeof(char));
        vetor[a]=aux;
        a++;
        aux=getchar();
    }
    vetor[a]='\0';
    return vetor;
}
//impressão da arvore em largura
void imprimir(no *p){
     if (p!=NULL) {
        printf("%c(",p->info);
        imprimir(p->esq);
        printf(",");
        imprimir(p->dir);
        printf(")");
     }
     else printf("NULL");	
}
//impressão de arvore AVL
void imprimir_avl(no_avl **p){
     if (*p!=NULL) {
        printf("%c (fb)=%d(",(*p)->info,(*p)->fb);
        imprimir_avl(&(*p)->esq);
        printf(",");
        imprimir_avl(&(*p)->dir);
        printf(")");
     }
     else printf("NULL");
}

//-------------------------------------------------
// TADs ARVORE BINARIA
//-------------------------------------------------

void criArvore(Arvore *A){
     A->raiz=NULL;
}
int IsEmpty(Arvore *A){
    if (A->raiz==NULL)
       return 1;
    else return 0;
}
no* busca(no *p, elem *x){
    no *aux;
    
    if (p==NULL)
       return(NULL);
    else if (p->info==*x)
         return(p);
    else {
         aux=busca(p->esq,x);
         if (aux==NULL)
            aux=busca(p->dir,x);
         return(aux);
    }    
}
no* busca_pai(no *p, elem *x){
    no *aux;
    
    if (p==NULL)
       return(NULL);
    else if ((p->esq!=NULL) && (p->esq->info==*x))
         return(p);
    else if ((p->dir!=NULL) && (p->dir->info==*x))
         return(p);
    else {
         aux=busca_pai(p->esq,x);
         if (aux==NULL)
            aux=busca_pai(p->dir,x);
         return(aux);
    }
}
void insL(Arvore *A, elem *x, elem *pai, int *erro){
     no *aux, *p;

     if (*pai!=-1) {
        aux=busca(A->raiz,pai);
        if ((aux!=NULL) && (aux->esq==NULL)) {
           p=(no*) malloc(sizeof(no));
           p->info=*x;
           p->esq=NULL;
           p->dir=NULL;
           aux->esq=p;
           *erro=0;
        }
        else *erro=1;
     }
     else if (A->raiz==NULL) {
          p=(no*) malloc(sizeof(no));
          p->info=*x;
          p->esq=NULL;
          p->dir=NULL;
          A->raiz=p;
          *erro=0;
     }
     else *erro=1;
}
void insR(Arvore *A, elem *x, elem *pai, int *erro){
     no *aux, *p;
          
     if (*pai!=-1) {
        aux=busca(A->raiz,pai);
        if ((aux!=NULL) && (aux->dir==NULL)) {
           p=(no*) malloc(sizeof(no));
           p->info=*x;
           p->esq=NULL;
           p->dir=NULL;
           aux->dir=p;
           *erro=0;
        }
        else *erro=1;
     }
     else if (A->raiz==NULL) {
          p=(no*) malloc(sizeof(no));
          p->info=*x;
          p->esq=NULL;
          p->dir=NULL;
          A->raiz=p;
          *erro=0;
     }
     else *erro=1;
}
void finaliza(no *p){
     if (p!=NULL) {
        finaliza(p->esq);
        finaliza(p->dir);
        free(p);
     }
}
void remover(Arvore *A, elem *x, int *erro){
     no *filho, *pai;
     int eh_filho_esq;
     
     //localizando o n� e o pai dele
     if ((A->raiz!=NULL) && (A->raiz->info==*x)) {
        pai=NULL;
        filho=A->raiz;
     }
     else {
          pai=busca_pai(A->raiz,x);
          if (pai!=NULL) {
             if ((pai->esq!=NULL) && (pai->esq->info==*x)) {
                filho=pai->esq;
                eh_filho_esq=1;
             }
             else {
                  filho=pai->dir;
                  eh_filho_esq=0;
             }
          }
          else filho=NULL;
     }
     
     if (filho==NULL)
        *erro=1;
     else {
          //primeiro caso: o n� n�o tem filhos
          if ((filho->esq==NULL) && (filho->dir==NULL)) {
             if (pai!=NULL) {
                if (eh_filho_esq)
                   pai->esq=NULL;
                else pai->dir=NULL;
             }
             else A->raiz=NULL;
             free(filho);
             *erro=0;
          }
          //segundo caso: o n� tem um ou dois filhos
          else {
               if (filho->esq!=NULL) {
                  filho->info=filho->esq->info;
                  filho->esq->info=*x;
               }
               else {
                    filho->info=filho->dir->info;
                    filho->dir->info=*x;
               }
               remover(A,x,erro);
          }
     }
}
void percurso_pre_ordem(no *p){
     if (p!=NULL) {
        printf("%c\n",p->info);
        percurso_pre_ordem(p->esq);
        percurso_pre_ordem(p->dir);
     }
}
void percurso_em_ordem(no *p){
     if (p!=NULL) {
        percurso_em_ordem(p->esq);
        printf("%c\n",p->info);        
        percurso_em_ordem(p->dir);
     }
}
void percurso_pos_ordem(no *p){
     if (p!=NULL) {
        percurso_pos_ordem(p->esq);
        percurso_pos_ordem(p->dir);
        printf("%c\n",p->info);        
     }
}
int espelho_similares(no *p1, no *p2){
    if ((p1==NULL) && (p2==NULL))
         return(1);
    else if ((p1==NULL) || (p2==NULL))
         return(0);
    else if ((espelho_similares(p1->esq,p2->dir)) && (espelho_similares(p1->dir,p2->esq)))
         return(1);
    else return(0);
}
int nosfolhas(no *p){
   if(p == NULL)
        return 0;
   if((p->esq == NULL) && (p->dir == NULL))
        return 1;
   return nosfolhas(p->esq) + nosfolhas(p->dir);
}
void abb(no *p, int *erro){
    if(p->esq==NULL && p->dir==NULL)
        return;
    else if(p->esq==NULL && p->dir!=NULL)
    {
        if(p->dir->info >= p->info)
            *erro = 0;
        else *erro = 1;
        abb(p->dir, erro);
    }
    else if(p->esq!=NULL && p->dir==NULL)
    {
        if(p->esq->info <= p->info)
            *erro = 0;
        else *erro = 1;
        abb(p->esq, erro);
    }
    else
    {
        if((p->esq->info)<=(p->info) && (p->dir->info)>(p->info))
        {
            *erro = 0;
            abb(p->esq, erro);
            abb(p->dir, erro);
        }
        else
        {
            *erro = 1;
            return;
        }
    }
}
int altura(no *p) {
    int alt_esq, alt_dir;

    if (p==NULL)
       return(0);
    else {
         alt_esq=1+altura(p->esq);
         alt_dir=1+altura(p->dir);
         if (alt_esq>alt_dir)
            return(alt_esq);
         else return(alt_dir);
    }
}
int avl(no *p, int *erro){
    int erro2;
    if(p!=NULL)
    {
      if(p->dir!=NULL || p->esq!=NULL)
      {
          if(altura(p->esq)-altura(p->dir)>1 || altura(p->esq)-altura(p->dir)<-1)
            *erro = 0;
      }
      if(p->dir!=NULL)
          avl(p->dir, erro);
      if(p->esq!=NULL)
          avl(p->esq, erro);
    }
    
    abb(p, &erro2);
    if(erro2 == 1 || *erro == 1)
        return 1;
    else return 0;
}
void preOrdemVet(no *p, char *frase, int *i) {
     if (p!=NULL) {
        frase[*i] = p->info;
        (*i)++;
        preOrdemVet(p->esq, frase, i);
        preOrdemVet(p->dir, frase, i);
     }
}
void OrdemVet(no *p, char *frase, int *i) {
     if (p!=NULL) {
        OrdemVet(p->esq, frase, i);
        frase[*i] = p->info;
        (*i)++;
        OrdemVet(p->dir, frase, i);
     }
}
void posOrdemVet(no *p, char *frase, int *i) {
     if (p!=NULL) {
        posOrdemVet(p->esq, frase, i);
        posOrdemVet(p->dir, frase, i);
        frase[*i] = p->info;
        (*i)++;       
     }
}
int verificaOrdem(char *frase){
    int i=0;
    char post, ant;
    post = frase[i+1];
    ant = frase[i];
    while(post != '\0'){
        if(post < ant)
            return 1;
        i++;
        post = frase[i+1];
        ant = frase[i];
    }
    return 0;
}

//-------------------------------------------------
// TADs ARVORE AVL
//-------------------------------------------------


int avlAVL(no_avl *p, int *erro){
    if(p!=NULL)
    {
      if(p->dir!=NULL || p->esq!=NULL)
      {
          if(altura_avl(p->esq)-altura_avl(p->dir) > 1 || altura_avl(p->esq)-altura_avl(p->dir) < -1)
            *erro = 0;
      }
      if(p->dir!=NULL)
          avlAVL(p->dir, erro);
      if(p->esq!=NULL)
          avlAVL(p->esq, erro);
    }
    return *erro;
}
void createAvl(AVL *A){
     A->raiz=NULL;
}
void finalizar_avl(no_avl **p){
     if (*p!=NULL) {
        finalizar_avl(&(*p)->esq);
        finalizar_avl(&(*p)->dir);
        free(*p);
     }     
}
int buscar_avl(no_avl **p, int *x){
    if (*p==NULL)
       return 0;
    else if (*x<(*p)->info)
         return(buscar_avl(&(*p)->esq,x));
    else if (*x>(*p)->info)
         return(buscar_avl(&(*p)->dir,x));
    else return 1;
}
void EE(no_avl **r){
     no_avl *pai=*r;
     no_avl *filho=pai->esq;
     pai->esq=filho->dir;
     filho->dir=pai;
     pai->fb=0;
     filho->fb=0;
     *r=filho;
}
void DD(no_avl **r){
     no_avl *pai=*r;
     no_avl *filho=pai->dir;
     pai->dir=filho->esq;
     filho->esq=pai;
     pai->fb=0;
     filho->fb=0;
     *r=filho;
}
void ED(no_avl **r){
     no_avl *pai=*r;
     no_avl *filho=pai->esq;
     no_avl *neto=filho->dir;
     pai->esq=neto->dir;
     filho->dir=neto->esq;
     neto->esq=filho;
     neto->dir=pai;
     switch (neto->fb) {
            case -1:
                 pai->fb=1;
                 filho->fb=0;
                 break;
            case 0:
                 pai->fb=0;
                 filho->fb=0;
                 break;
            case 1:
                 pai->fb=0;
                 filho->fb=-1;
                 break;
     }
     neto->fb=0;
     *r=neto;
}
void DE(no_avl **r){
     no_avl *pai=*r;
     no_avl *filho=pai->dir;
     no_avl *neto=filho->esq;
     filho->esq=neto->dir;
     pai->dir=neto->esq;
     neto->esq=pai;
     neto->dir=filho;
     switch (neto->fb) {
            case -1:
                 pai->fb=0;
                 filho->fb=1;
                 break;
            case 0:
                 pai->fb=0;
                 filho->fb=0;
                 break;
            case 1:
                 pai->fb=-1;
                 filho->fb=0;
                 break;
     }
     neto->fb=0;
     *r=neto;
}
int aux_insere(no_avl **p, char *x, int *cresceu){
    if (*p==NULL) {
       *p=(no_avl*) malloc(sizeof(no_avl));
       (*p)->info=*x;
       (*p)->fb=0;
       (*p)->esq=NULL;
       (*p)->dir=NULL;
       *cresceu=1;
       return 1;
    }
    else if (*x==(*p)->info)
         return 0;
    else if (*x<(*p)->info) {
         if (aux_insere(&(*p)->esq,x,cresceu)) {
            if (*cresceu) {
	           switch ((*p)->fb) {
	                  case -1:
	                       if ((*p)->esq->fb==-1)
	                          EE(p);
                           else ED(p);
	                       *cresceu=0;
	                       break;
	                  case 0:
	                       (*p)->fb=-1;
	                       *cresceu=1;
	                       break;
                      case 1:
	                       (*p)->fb=0;
	                       *cresceu=0;
	                       break;
               }
            }
            return 1;
         }
         else return 0;
    }
    else {
         if (aux_insere(&(*p)->dir,x,cresceu)) {
            if (*cresceu) {
	           switch ((*p)->fb) {
	                  case -1:
	                       (*p)->fb=0;
                           *cresceu=0;
	                       break;
                      case 0:
	                       (*p)->fb=1;
	                       *cresceu=1;
	                       break;
                      case 1:
	                       if ((*p)->dir->fb==1)
	                          DD(p);
                           else DE(p);
	                       *cresceu=0;
	                       break;
               }
            }
            return 1;
         }
         else return 0;
    }
}
int inserir_avl(no_avl **p, char *x){
  int cresceu;
  return aux_insere(p, x, &cresceu);
}
int altura_avl(no_avl *p) {
   if (p == NULL) 
      return 0;
   else 
   {
      int he = altura_avl(p->esq);
      int hd = altura_avl(p->dir);
      
      if (he < hd) 
        return hd + 1;
      
      else 
        return he + 1;
   }
}
int nosfolhas_avl(no_avl *p){
   if(p == NULL)
        return 0;
   if((p->esq == NULL) && (p->dir == NULL))
        return 1;
   return nosfolhas_avl(p->esq) + nosfolhas_avl(p->dir);
}
void abb_avl(no_avl *p, int *erro){
    if(p->esq==NULL && p->dir==NULL)
        return;
    else if(p->esq == NULL && p->dir != NULL)
    {
        if(p->dir->info > p->info)
            *erro = 0;
        else 
            *erro = 1;
        abb_avl(p->dir, erro);
    }
    else if(p->esq!=NULL && p->dir==NULL)
    {
        if(p->esq->info <= p->info)
            *erro = 0;
        else 
            *erro = 1;
        abb_avl(p->esq, erro);
    }
    else
    {
        if((p->esq->info) <= (p->info) && (p->dir->info) >= (p->info)){
            *erro = 0;
            abb_avl(p->esq, erro);
            abb_avl(p->dir, erro);
        }
        else
        {
            *erro = 1;
            return;
        }
    }
}
void preOrdemVetAVL(no_avl *p, char *frase, int *i) {
     if (p!=NULL) {
        frase[*i] = p->info;
        (*i)++;
        preOrdemVetAVL(p->esq, frase, i);
        preOrdemVetAVL(p->dir, frase, i);
     }
}
void OrdemVetAVL(no_avl *p, char *frase, int *i) {
     if (p!=NULL) {
        OrdemVetAVL(p->esq, frase, i);
        frase[*i] = p->info;
        (*i)++;
        OrdemVetAVL(p->dir, frase, i);
     }
}
void posOrdemVetAVL(no_avl *p, char *frase, int *i) {
     if (p!=NULL) {
        posOrdemVetAVL(p->esq, frase, i);
        posOrdemVetAVL(p->dir, frase, i);
        frase[*i] = p->info;
        (*i)++;       
     }
}