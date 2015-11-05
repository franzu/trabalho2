#include<stdlib.h>
#include<stdio.h>

struct tree{	//criamos a estrutura da arvore
	int key;	//chave de localização
	struct tree *left;//ponteiro para um galho com chave menor
	struct tree *right; //ponteiro para um galho com chave maior
};

struct tree *root=NULL;
struct tree *temp=NULL;

struct tree *mallocnode(){//aloca memoria para cada nó
   struct tree *tmp;
   tmp = (struct tree *) malloc(sizeof(struct tree));
   tmp->left = NULL;
   tmp->right = NULL;
   return tmp;
}

void search(int n,struct tree *node){//verifica se o elemento esta na arvore ou nao
    if(node==NULL) printf("\nVish!Elemento nao esta na arvore.");//verifica se esta no nó atual
    else if(node->key==n) printf("\nAe!Elemento esta na arvore.");
    else if(n>node->key) search(n,node->right);//se a chave for maior procura nos filho da direita
    else search(n,node->left);//se for menor,nos filhos da direita
    }

void insert(struct tree *root,struct tree *newnode){//insere nó na arvore
	if(newnode->key<root->key){//compara a chave do nó com a raiz
      if(root->left==NULL)root->left=newnode;//determina se o elemento fica a esquerda ou direita ...
      else insert(root->left,newnode);//em relaçao a cada elemento da arvore
	}
	if(newnode->key>root->key){
      if (root->right==NULL)root->right=newnode;
      else insert(root->right,newnode);
	}
}

struct tree *minimum(struct tree *node){//funcao para achar o menor elemento da subavore...
    struct tree *tmp = node;//que tem o sucessor inorder do elemento a ser deletado...
							//sera usada para alocar no lugar do deletado...
    while (tmp->left != NULL)//o elemento achado por esta funçao no lugar
        tmp = tmp->left;
 	return tmp;
}

struct tree *del(struct tree* node, int key){//funcao de remocao de elemento, retorna struct para...
    if (node == NULL) return;//podermos usar a recursao, mas nao usaremos o resultado
    if (key<node->key) node->left=del(node->left, key);//procura o elemento na arvore
    else if (key > root->key) node->right=del(node->right, key);//...
	else{
        if (root->left==NULL){//deleta elemento com um filho ou nenhum colocando no lugar o filho
            struct tree *tmp =node->right;
            free(node);
            return tmp;
        }
        else if(node->right==NULL){//...
            struct tree *tmp =node->left;
            free(node);
            return tmp;
        }
 		struct tree *tmp= minimum(node->right);//deleta os elemento com dois filho realocando no lugar
        node->key = tmp->key;//o menor sucessor do proximo elemento na sequencia inorder
        node->right = del(node->right,tmp->key);
    }
    return node;
}

void inorder(struct tree *node){//imprime a arvore em sua ordem crescente a partir da raiz
	if(node!=NULL){
		inorder(node->left);
		printf("%d ",node->key);
		inorder(node->right);
	}
}

void preorder(struct tree *node){//imprime a arvore de maneira q os pais aparecam antes dos filhos
	if(node!=NULL){//indo primeiro pra esquerda depois pra direita
		printf("%d ",node->key);
		preorder(node->left);
		preorder(node->right);
	}
}

void postorder(struct tree *node){//imprime a arvore imprimindo primeiro os filhos depois os pais
	if(node!=NULL){//inverso da anterior, mas tambem começando da esquerda para a direita
		postorder(node->left);
		postorder(node->right);
		printf("%d ",node->key);
	}
}

void brcktng(struct tree *node){//imprime a arvore mostrando os galhos e seus filhos
	printf("[");//dentro de colchetes
	if(node!=NULL){
	printf("%d",node->key);
	brcktng(node->left);
	brcktng(node->right);
	}
	printf("]");
}

void main(){//funcao main, contem o menu com as oito opcoes de operacao com a arvore
	int menu=0,s,key,n,i;
	char a;
	struct tree *newnode, *tmp=NULL;
	printf("        --Programa de ARVORE BINARIA DE BUSCA Inicializado--");
	printf("\nMENU:");
	printf("\n1.Inserir elemento.");
	printf("\n2.Deletar elemento.");
	printf("\n3.Buscar elemento.");
	printf("\n4.Impressao em posordem.");
	printf("\n5.Impressao em ordem.");
	printf("\n6.Impressao em preordem.");
	printf("\n7.Impressao em colchetes rotulados.");
	printf("\n8.Sair.");	
	printf("\nEscolha alguma das opcoes com seu respectivo numero:");
	while(menu<8||menu>0){
		scanf("%d",&menu);
			switch(menu){
				case 1:
					printf("Quantos elementos deseja adicionar?  ");
					scanf("%d",&n);
					for(i=1;i<=n;i++){
					newnode=mallocnode();
					printf("Entre a chave do no %d:",i);
					scanf("%d",&newnode->key);
					if(root==NULL)root=newnode;
					else insert(root,newnode);
					}
					break;
				
				case 2:
					if(root==NULL){
						printf("Arvore vazia, insira elementos!");
						break;
					}
					else{
						printf("Entre a chave a ser deletada:\n");
						scanf("%d",&key);
						del(root,key);
						break;
					}
					
				case 3:	
					printf("Escolha o valor a ser buscado:");
					scanf("%d",&s);
					search(s,root);
					break;
				
				case 4:
					if(root!=NULL){
					postorder(root);
					break;
					}
					else break;
				
				case 5:					
					if(root!=NULL){inorder(root);
					break;
					}
					else break;
					
				case 6:					
					if(root!=NULL){preorder(root);
					break;
					}
					else break;
				
				case 7:
					brcktng(root);
					break;
				
				case 8:
					printf("Tchau.");
					return;
				
				default:
					printf("Entrada errada, escolha dentre os numeros!!");
					break;
			}
		printf("\nEscolha novamente:");
	}
	return;
}
	
	
    
    
    
    
    
