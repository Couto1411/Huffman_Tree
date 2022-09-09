#ifndef TreeStruc
#define TreeStruc

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Record{
	pair<string, pair<int,float>> value;
	vector<bool> translate;
    int nivel;
};

struct Tree{
	Record item;
	Tree *FE, *FD;
};

void Init(Tree **T);
void Inserir(Tree **T, pair<string, pair<int,float>> valor);
void PrintTreePreOrder(Tree **T);
void PrintTreePosOrder(Tree **T);
void PrintTreeInOrder(Tree **T);
void PrintTreeInOrderNivel(Tree **T);
void PrintInRange(Tree **T);
Tree *Busca(Tree **T, Record valor);
void Deletion(Tree **T, Record valor);
Tree *DeleteMenorDir(Tree **T);
void AlturaArvore(int *maxCont, int *cont, Tree **T);
void AlturaArvoreLargura(int *maxCont, Tree **T);

#endif