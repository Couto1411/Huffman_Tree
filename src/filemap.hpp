#ifndef FILE_ENTRY
#define FILE_ENTRY
#include <algorithm>
#include <fstream>
#include <unordered_map>
#include "tree.hpp"

using namespace std;
class Hash
{
    private:
        unordered_map <string, pair<int,float>> umap;
    public:
        ~Hash();
        Hash();
    void preencheMap(string nomeArquivo);
    void printHash();
    void normalize();
    void createTree(Tree **TREE);
};
bool cmp(pair<string, pair<int,float>>& a,pair<string, pair<int,float>>& b);
bool cmpTree(Tree*&a,Tree*& b);
void writeFile(Tree **T, string nome);

#endif