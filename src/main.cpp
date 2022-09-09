#include "filemap.hpp"

int main(){
	int altura=0;
	Tree *T = new Tree;
	Hash *map = new Hash;
	string nomeArquivo;
	printf("Escreva o nome dos arquivos:\n");
    cin>>nomeArquivo;
	map->preencheMap(nomeArquivo);
	map->normalize();
	map->createTree(&T);
	AlturaArvoreLargura(&altura,&T);
	writeFile(&T,nomeArquivo);

	return 0;
}
