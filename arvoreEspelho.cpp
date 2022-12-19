#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
 
struct Node
{
    int valor;
    Node* esq, *dir;
};

Node * novoNode(int valor)
{
    Node* node = new Node;
    node->valor  = valor;
    node->esq  =  node->dir  = NULL;
    return(node);
}
 
int eh_espelho(Node* a, Node* b)
{
    if (a == NULL && b == NULL)
        return 1;
 
    if (a == NULL || b == NULL)
        return 0;
 
    return  a->valor == b->valor &&
            eh_espelho(a->esq, b->dir) &&
            eh_espelho(a->dir, b->esq);
}

Node * cria_espelho(Node* a)
{
	if (a == NULL) {
        Node *raiz = NULL;
        return raiz;
    }
	
    Node *raiz = novoNode(a->valor);
    
    if(a->esq != NULL){
    	raiz->dir = cria_espelho(a->esq);
	}
	if(a->dir != NULL){
    	raiz->esq = cria_espelho(a->dir);
	}	
	return raiz;
}
 
void imprime_arvore(Node* a){
	if(a == NULL) {
		return;
	}
	imprime_arvore(a->esq);
	printf(" %d", a->valor);
	imprime_arvore(a->dir);
} 
 

 
int main()
{
    Node *raiz1 = novoNode(1);
    Node *raiz2 = novoNode(1);
    								
    raiz1->esq = novoNode(3);					  
    raiz1->dir = novoNode(2);						  
    raiz1->dir->esq  = novoNode(5);
    raiz1->dir->dir = novoNode(4);						
 
    raiz2->esq = novoNode(2);
    raiz2->dir = novoNode(3);
    raiz2->esq->esq = novoNode(4);
    raiz2->esq->dir = novoNode(5);
 	
 	int retorno = eh_espelho(raiz1, raiz2);
 	printf("Retorno da funcao eh_espelho : ");
 	printf("%d", retorno);
 
 	printf("\n----------------------------\n");
 
 	Node *espelho = cria_espelho(raiz1);
 	printf("Retorno da arvore : ordem esq/mei/dir \n");
 	imprime_arvore(espelho); 	
    return 0;
}