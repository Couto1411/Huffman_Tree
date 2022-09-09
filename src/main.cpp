#include "filemap.hpp"

int main(){
	int altura=0;
	Tree *T = new Tree;
	Hash *map = new Hash;
	string nomeArquivo;
	printf("Escreva o nome do arquivo:\n");
    cin>>nomeArquivo;
	map->preencheMap(nomeArquivo);
	map->normalize();
	map->createTree(&T);
	AlturaArvoreLargura(&altura,&T);
	printf("A árvore das palavras calculadas com o algoritmo de huffman tem altura %d\n", altura);
	writeFile(&T,nomeArquivo);

	return 0;
}
