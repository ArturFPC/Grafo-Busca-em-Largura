#include <iostream>
#include "grafo.h"
using namespace std;

int main()
{
    vector<vector<int>> ma = {{0,0,0,0,1,0,0,0},{1,0,0,0,0,1,0,0},{0,0,0,1,0,1,1,0},{0,0,1,0,0,0,1,1},{1,0,0,0,0,0,0,0},{0,1,1,0,0,0,1,0},{0,0,1,1,0,1,0,1},{0,0,0,1,0,0,1,0}};
    grafo g;
    g.setMA(ma);
    g.BFS(1);
    g.mostrarGrafo();
    return 0;
}
