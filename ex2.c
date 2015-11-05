#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct parente{//definimos a estrutura dos parentes com ponteiros para os pais
	int gen;//o indice de geraçao 
	char nome[20];//seu nome
	struct parente *esq;
	struct parente *dir;
};
struct parente *raiz;//definimos a raiz fixa da nossa arvore

struct parente *novo(){//funcao de criaçao e alocaçao de memoria pra um membro
	struct parente *tmp;
	tmp=(struct parente*)malloc(sizeof(struct parente));
	tmp->esq=(struct parente*)malloc(sizeof(struct parente));
	tmp->dir=(struct parente*)malloc(sizeof(struct parente));
	return tmp;
}

struct parente *busca(struct parente* root,char nome[20]){//funcao que procura um individuo na arvore..
	struct parente *tmp=novo();
	if(root!=NULL){
		if(strcmp(root->nome,nome)==0)tmp==root;//a partir de seu nome
	if(tmp==NULL)tmp=busca(root->esq,nome);
	if(tmp==NULL)tmp=busca(root->dir,nome);
	}
	return tmp;//e retorna a struct desse individuo
}

void insert(struct parente *root,char pai[], char mae[],char nome[]){//funcao para inserir os individuos
	struct parente *tmp=NULL;//struct auxiliar
	tmp=novo();
	tmp=busca(root,nome);//buscamos o endereço do individuo
	int n=tmp->gen;
	if(tmp!=NULL){
		strcpy(tmp->esq->nome,pai);//atribuimos os nomes aos pais
		tmp->dir->gen=n+1;
		tmp->dir->dir=NULL;
		tmp->dir->esq=NULL;
		strcpy(tmp->dir->nome,mae);//...
		tmp->esq->gen=n+1;
		tmp->esq->dir=NULL;
		tmp->esq->esq=NULL;
	}
	free(tmp);
}

void antp(struct parente *node,char nome[20]){//funcao de imprimir o antepassados dum individuo
	if(node!=NULL){
		if(strcpy(node->nome,nome)!=0)printf("%s",node->nome);//usamos o principio de preordem para
		antp(node->esq,nome);//imprimir os nomes
		antp(node->dir,nome);
	}
}

void grau(struct parente *p1,struct parente *p2){//funcao de determinaçao do grau de parentesco
	int grau;
	struct parente *tmp;
	tmp=(struct parente*)malloc(sizeof(struct parente));
	if(p1!=NULL&&p2!=NULL){
		if(p1->gen==p2->gen)printf("Grau de parentesco = 0.");//se a geraçao e a mesma o grau deve ser 0
		if(p1->gen>p2->gen){//se um forem de geraçoes diferentes, procuramos um individuo
			tmp=busca(p1,p2->nome);//nos antepassados do outro
			if(tmp==NULL)printf("Grau de parentesco =0.");//se nao estiver la, o grau deve ser 0
			else{
				grau=p1->gen-p2->gen;
				printf("Grau de parentesco =%d.",grau);//se tiverem esta relacao vertical o grau é
			}//a diferença entre suas gerações
		}
		if(p1->gen<p2->gen){//mesmo principio, mas para quando o outro tem geração de numero maior
			tmp=busca(p2,p1->nome);
			if(tmp==NULL)printf("Grau de parentesco =0.");
			else{
				grau=p2->gen-p1->gen;
				printf("Grau de parentesco =%d.",grau);
			}
		}
	}
	free(tmp);
}

void brcktng(struct parente *root){//imprime a arvore mostrando os galhos e seus filhos
	printf("[");//dentro de colchetes
	if(root!=NULL){
	printf("%s",root->nome);//mesmo principio de preordem
	brcktng(root->esq);
	brcktng(root->dir);
	}
	printf("]");//fecha o colchete
}

int um=1;

void gene(struct parente *root,int gen,int um){//funcao para imprimir as geracoes em suas linhas
	int n=root->gen;//variavel de compraçao para pular linha
	if(root!=NULL){
		if(root->gen<=gen)printf("%s",root->nome);//imprime ate certa geraçao escolhida pelo usuario
		if(n=um+1)printf("\n");
		gene(root->esq,gen,root->gen);
		gene(root->dir,gen,root->gen);
	}
}

void main(){
	int n=0,i,menu=0,g;
	char nfilho[20],npai[20],nmae[20];//definimos 3 strings para armazenar os nomes que serao ultilizados
	raiz=novo();//alocamos a raiz
	raiz->gen=1;//definimos a geraçao do mais novo como 1
	printf("Quantos trios(filho-pai-mae) voce deseja incluir em sua arvore?");
	scanf("%d",&n);
	while(n<1){
		scanf("%d",&n);
		printf("Digite outro numero(>=1)!");
		}
	printf("Nome do filho(descendente mais novo):");//configura os dados da raiz, pai e mae
	scanf("%s",raiz->nome);
	strcpy(nfilho,raiz->nome);
	printf("Nome dos pais:\n-");
	scanf("%s",&npai);
	printf("-");
	scanf("%s",&nmae);
	insert(raiz,npai,nmae,nfilho);
	for(i=1;i<n;i++){//configura os ramos
		printf("Nome do filho:");
		scanf("%s",&nfilho);
		printf("Nome dos pais:\n-");
		scanf("%s",&npai);
		printf("-");
		scanf("%s",&nmae);
		insert(raiz,npai,nmae,nfilho);
	}//MENU
	printf("Agora que montamos sua arvore podemos fazer algumas operacoes com ela.");
	printf("Escolha dentre as seguintes:\n");
	printf("1.Inserir novos membros(em trios);\n");
	printf("2.Imprimir as geracoes da familia;\n");
	printf("3.Imprimir os antepassados dum individuo;\n");
	printf("4.Imprimir a arvore em colchetes rotulados;\n");
	printf("5.Calcular o grau de parentesco entre dois membros;\n");
	printf("6.Sair.\n");
	printf("Digite o numero da opcao escolhida:");
	while(menu<6||menu>0){//loop para escolher as operações com a arvore
		scanf("%d",&menu);
			switch(menu){
				case 1://insere outro trio da mesma for que inseriu anteriormente os outros trios
					printf("Nome do filho:");
					scanf("%s",raiz->nome);
					printf("Nome dos pais:\n-");
					scanf("%s",&npai);
					printf("-");
					scanf("%s",&nmae);
					insert(raiz,npai,nmae,nfilho);
				break;
				
				case 2:
					printf("Ate qual geracao voce quer imprimir?");
					scanf("%d",&g);
					gene(raiz,g,um);
				break;
				
				case 3:
					printf("Digite o nome do individuo que deseja saber os antepassados:");
					scanf("%s",&nfilho);
					antp(busca(raiz,nfilho),nfilho);
				break;
				
				case 4:
					brcktng(raiz);
				break;
				
				case 5:	
					printf("Digite o nome das pessoas:-");
					scanf("%s",&npai);
					printf("-");
					scanf("%s",&nmae);
					grau(busca(raiz,npai),busca(raiz,nmae));
				break;
				
				case 6:
					printf("TCHAU!");
					break;
				default:
					printf("OPS! Entrada errada, escolha dentre os numeros dispostos!");
					break;
			}
		printf("\nEscolha novamente:");
	}
	return;
}


