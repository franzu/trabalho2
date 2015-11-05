Trabalho de Computa��o elabora para a disciplina SSC-0300 Linguagens de Programa��o e Suas Aplica��es

Intergrantes:
Francesco Paero Leitao	9312623
Leandro Molina		9312939
GitHub User:franzu

		---Vis�o Geral---
	Os programas deste reposit�rio s�o escritos em linguagem C. E usam o principio da ARVORE BINARIA DE BUSCA
para resolu��o dos exercicios. H� dois codigos em C que podem ser acessados, dois arquivos executaveis respectivos
aos codigos, as bibliotecas ultilizadas, arquivos .txt com entradas exemplo para cada exercicio e um relatorio em
PDF sobre o trabalho.

		---Programas---
1.Arvore Binaria de Busca(ABB) e Opera��es
	� um simples codigo que usa a base da ABB para fazer opera��es nesta mesma arvore. No programa podemos:
inserir,deletar,buscar e imprimir os elementos de diversas formas. O usuario parte de um MENU onde pode escolher dentre
as op��es dadas(e representadas acima) para manipular a arvore. Alem disso, o usuario pode fazer uso das opera�oes do
MENU indefinidamente, at� que escolha a op��o de sair.

2.Arvore Geneal�gica
	Usa o principio a ABB para implementar uma arvore genealogica em C, onde a raiz da arvore � o descendente mais
novo da familia e os ramos se abrem em fun��o dos pais de cada individuo. Ou seja, nao poder�-se colocar irmaos nem primos
na arvore. O programa se difere um pouco da arvore binaria do exercicio anterior no que tange o uso de uma string de compara��o
para identificar as estruturas, nao um numero chave. O programa tambem faz uso de um MENU, que contem as seguintes opcoes:
inserir elemento, imprimir em gera��es, imprimir antepassados dum individuo, calculo de grau de parentesco e imprimir em labbeled
bracketing. Tambem pode-se usar o MENU indefinidamente ate que escolha sair.