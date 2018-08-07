/*
 ============================================================================
 Name        : cpp.c
 Author      : Renan
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct Treeno {
	struct no *Llink;
	struct no *Rlink;
	int info;
} no;

void Preordem(no **Raiz);
void Emordem(no **Raiz);
void Posordem(no **Raiz);
void InsereNo(no **Raiz, int valor);
void InicializaArvore(no **Raiz);
int pesquisano(no **Raiz, int valor);
void contano(no **Raiz, int cont);
void removeno(no **Raiz, int valor);

int main(void) {
	no *a1 = NULL;
	int val;
	InicializaArvore(&a1);
	InsereNo(&a1, 4);
	InsereNo(&a1, 5);
	InsereNo(&a1, 6);
	InsereNo(&a1, 1);
	InsereNo(&a1, 2);
	InsereNo(&a1, 3);
	//printf("\nPré-Ordem: ");
	//Preordem(&a1);
	printf("\nEm-Ordem: ");
	Emordem(&a1);
	//printf("\nPós-Ordem: ");
	//Posordem(&a1);
	//scanf("%d", &val);
	//printf("\nValor pesquisado %d (-1 se não encontrado): %d", val, pesquisano(&a1, val));
	//contano(&a1, 0);
	removeno(&a1, 2);
	printf("\nEm-Ordem: ");
	Emordem(&a1);
	return 0;
}

void InicializaArvore(no **Raiz) {
	*Raiz = NULL;
}

void InsereNo(no **Raiz, int valor) {
	if (*Raiz == NULL) {
		*Raiz = (no*) malloc(sizeof(no));
		(*Raiz)->info = valor;
		(*Raiz)->Llink = NULL;
		(*Raiz)->Rlink = NULL;
	} else {
		if (valor < (*Raiz)->info) {
			InsereNo(&(*Raiz)->Llink, valor);
		} else {
			if (valor > (*Raiz)->info) {
				InsereNo(&(*Raiz)->Rlink, valor);
			} else {
				printf("O Valor já existe!");
			}
		}
	}
}

void Preordem(no **Raiz) {
	if (*Raiz == NULL) {
		return;
	} else {
		printf(" %d ", (*Raiz)->info);
		Preordem(&(*Raiz)->Llink);
		Preordem(&(*Raiz)->Rlink);
	}
}

void Emordem(no **Raiz) {
	if (*Raiz == NULL) {
		return;
	} else {
		Emordem(&(*Raiz)->Llink);
		printf(" %d ", (*Raiz)->info);
		Emordem(&(*Raiz)->Rlink);
	}
}

void Posordem(no **Raiz) {
	if (*Raiz == NULL) {
		return;
	} else {
		Posordem(&(*Raiz)->Llink);
		Posordem(&(*Raiz)->Rlink);
		printf(" %d ", (*Raiz)->info);
	}
}

int pesquisano(no **Raiz, int valor) {
	if (*Raiz != NULL) {
		if ((*Raiz)->info == valor) {
			return valor;
		} else if (valor < (*Raiz)->info) {
			pesquisano(&(*Raiz)->Llink, valor);
		} else if (valor > (*Raiz)->info) {
			pesquisano(&(*Raiz)->Rlink, valor);
		}
	} else {
		return -1;
	}
}

void contano(no **Raiz, int cont) {
	if (*Raiz == NULL) {
		return;
	} else {
		contano(&(*Raiz)->Llink, cont);
		contano(&(*Raiz)->Rlink, cont);
	}
}

void removeno(no **Raiz, int valor) {
	no *p, *p2, *aux;
	p = ((*Raiz)->Llink);
	p2 = ((*Raiz)->Rlink);

	if ((*Raiz) == NULL) {
		return;
	} else {
		if (p != NULL || p2 != NULL) {
			if (p->info != valor && p2->info != valor) {
				if ((*Raiz)->info < valor) {
					removeno(&p, valor);
				} else if ((*Raiz)->info > valor) {
					removeno(&p2, valor);
				} else {
					aux = *Raiz;
					if (p != NULL){
						free(aux);
						(*Raiz)=(*Raiz)->Llink;
					} else {
						free(aux);
						(*Raiz)=(*Raiz)->Rlink;
					}
				}
			} else if (p->info == valor) {
				if (p->Llink != NULL) {
					(*Raiz)->Llink = p->Llink;
					free(p);
				} else {
					(*Raiz)->Llink = p->Rlink;
					free(p);
				}
			} else {
				if (p2->Llink != NULL) {
					(*Raiz)->Llink = p2->Llink;
					free(p2);
				} else {
					(*Raiz)->Llink = p2->Rlink;
					free(p2);
				}
			}
		}
	}
}
