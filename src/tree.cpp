#include "tree.hpp"

void Init(Tree **T){
	(*T) = nullptr;
}

void Inserir(Tree **T, pair<string, pair<int,float>> valor){
	if ((*T) == nullptr)
	{
		(*T) = new Tree;
		(*T)->item.value = valor;
		(*T)->item.nivel = 0;
		(*T)->FE = nullptr;
		(*T)->FD = nullptr;
		return;
	}
	if (valor.second.second < (*T)->item.value.second.second)
		Inserir(&(*T)->FE, valor);
	else if (valor.second.second > (*T)->item.value.second.second)
		Inserir(&(*T)->FD, valor);
}

// Printando em ordem, filhos esquerdo, pai, filho direito.
void PrintTreeInOrder(Tree **T){
	if ((*T)){
		if ((*T)->FE)
			PrintTreeInOrder(&(*T)->FE);
		printf("%s, ", (*T)->item.value.first.c_str());
		if ((*T)->FD)
			PrintTreeInOrder(&(*T)->FD);
	}
	else
		printf("0");
}

// Printando pai antes dos filhos.
void PrintTreePreOrder(Tree **T){
	if ((*T)){
		printf("%s, ", (*T)->item.value.first.c_str());
		if ((*T)->FE)
			PrintTreePreOrder(&(*T)->FE);
		if ((*T)->FD)
			PrintTreePreOrder(&(*T)->FD);
	}
	else
		printf("0");
}

// Printando filhos antes do pai.
void PrintTreePosOrder(Tree **T){
	if ((*T)){
		if ((*T)->FE)
			PrintTreePosOrder(&(*T)->FE);
		if ((*T)->FD)
			PrintTreePosOrder(&(*T)->FD);
		printf("%s, ", (*T)->item.value.first.c_str());
	}
	else
		printf("0");
}

// Printando em ordem, filhos esquerdo, pai, filho direito, com nível.
void PrintTreeInOrderNivel(Tree **T){
	if ((*T)){
		if ((*T)->FE)
			PrintTreeInOrderNivel(&(*T)->FE);
		printf("%s-%d, ", (*T)->item.value.first.c_str(),(*T)->item.nivel);
		if ((*T)->FD)
			PrintTreeInOrderNivel(&(*T)->FD);
	}
	else
		printf("0");
}

// sda
void PrintInRange(Tree **T){
	queue<Tree*> tempFila;
	Tree *temp;
	int tempCont=1,cont=0;
	tempFila.push((*T));
	while (!(tempFila.empty())){
		cont=0;
		for (int i = 0; i < tempCont; i++){
			temp =tempFila.front();
			printf("%f, ",temp->item.value.second.second);
			tempFila.pop();
			if (temp->FE) {
				tempFila.push(temp->FE);
				cont++;
			}
			if (temp->FD) {
				tempFila.push(temp->FD);
				cont++;
			}
		}
		printf("\n");
		tempCont=cont;
	}
}

// retorna endereço do nó em que o valor é encontrado
Tree *Busca(Tree **T, Record valor){
	if ((*T)==nullptr)
		return nullptr;
	if ((*T)->item.value.second.second == valor.value.second.second)
		return *T;
	else if ((*T)->item.value.second.second>valor.value.second.second)
		return Busca(&(*T)->FE,valor);
	else
		return Busca(&(*T)->FD,valor);
	return nullptr;
}

// busca o maior filho da subarvore esquerda
Tree *DeleteMenorDir(Tree **T){
	if ((*T)->FD->FD==nullptr)
		return (*T);
	else
		return DeleteMenorDir(&(*T)->FD);
}

// Coloca todos os valores em uma fila e percorre a mesma até encontrar o valor a ser deletado, encontrando, usa o método DeleteMenorDir e substitui o valor encontrado pelo nó retornado, fazendo os apontamentos necessários
void Deletion(Tree **T, Record valor){
	queue<Tree*> tempFila;
	Tree *temp, *deleted, *aux;
	tempFila.push((*T));
	if ((*T)->item.value.second.second==valor.value.second.second)
	{
		deleted = (*T);
		if (deleted->FD==nullptr&&deleted->FE==nullptr)
			(*T)=nullptr;
		else if(deleted->FE==nullptr)
			(*T)=deleted->FD;
		else{
			if (deleted->FE->FD){
				aux=DeleteMenorDir(&deleted->FE);
				temp=aux->FD;
				aux->FD=aux->FD->FE;
				temp->FD=deleted->FD;
				temp->FE=deleted->FE;
				(*T)=temp;
			}
			else{
				(*T)=deleted->FE;
				(*T)->FD=deleted->FD;
			}
			free(deleted);
		}
	}
	else{
		while (!(tempFila.empty())){
			temp =tempFila.front();
			if (temp->FE) {
				tempFila.push(temp->FE);
				if(temp->FE->item.value.second.second==valor.value.second.second){
					deleted = temp->FE;
					if (temp->FE->FD==nullptr&&temp->FE->FE==nullptr)
						temp->FE=nullptr;
					else if(temp->FE->FE==nullptr)
						temp->FE=temp->FE->FD;
					else{
						if (deleted->FE->FD)
						{
							aux=DeleteMenorDir(&deleted->FE);
							temp->FE=aux->FD;
							aux->FD=aux->FD->FE;
							temp->FE->FD=deleted->FD;
							temp->FE->FE=deleted->FE;
						}
						else{
							temp->FE=deleted->FE;
							temp->FE->FD=deleted->FD;
						}
					}
					free(deleted);
					break;
				}
			}
			if (temp->FD) {
				tempFila.push(temp->FD);
				if(temp->FD->item.value.second.second==valor.value.second.second){
					deleted = temp->FD;
					if (temp->FD->FD==nullptr&&temp->FD->FE==nullptr)
						temp->FD=nullptr;
					else if(temp->FD->FE==nullptr)
						temp->FD=temp->FD->FD;
					else{
						if (deleted->FE->FD)
						{
							aux=DeleteMenorDir(&deleted->FE);
							temp->FD=aux->FD;
							aux->FD=aux->FD->FE;
							temp->FD->FD=deleted->FD;
							temp->FD->FE=deleted->FE;
						}
						else{
							temp->FD=deleted->FE;
							temp->FD->FD=deleted->FD;
						}
					}
					free(deleted);
					break;
				}
			}
			tempFila.pop();
		}
	}
}

// De maneira recursiva busca a altura da conta os níves de uma árvore
void AlturaArvore(int *maxCont, int* cont, Tree **T){
	if ((*T)->FE){
		(*cont)++;
		AlturaArvore(maxCont, cont, &(*T)->FE);
	}
	if ((*T)->FD){
		(*cont)++;
		AlturaArvore(maxCont, cont, &(*T)->FD);
	}
	if((*T)->FD==nullptr&&(*T)->FE==nullptr){
		if ((*cont)>(*maxCont))
			(*maxCont)=(*cont);
	}
	(*T)->item.nivel=(*cont);
	(*cont)--;
}

// A partir de uma fila, consegue a altura da árvore
void AlturaArvoreLargura(int *maxCont, Tree **T){
	queue<Tree*> tempFila;
	vector<bool> translate;
	Tree *temp;
	int tempCont=1,cont=0;
	(*maxCont)=0;
	tempFila.push((*T));
	while (!(tempFila.empty())){
		cont=0;
		for (int i = 0; i < tempCont; i++){
			temp =tempFila.front();
			translate=temp->item.translate;
			tempFila.pop();
			if (temp->FE) {
				tempFila.push(temp->FE);
				temp->FE->item.nivel=(*maxCont)+1;
				cont++;
				translate.push_back(0);
				temp->FE->item.translate=translate;
			}
			translate=temp->item.translate;
			if (temp->FD) {
				tempFila.push(temp->FD);
				temp->FD->item.nivel=(*maxCont)+1;
				cont++;
				translate.push_back(1);
				temp->FD->item.translate=translate;
			}
		}
		tempCont=cont;
		(*maxCont)++;
	}
}