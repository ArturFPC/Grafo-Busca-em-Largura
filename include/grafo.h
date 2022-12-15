#ifndef GRAFO_H
#define GRAFO_H
#include "vertice.h"
#include <queue>
#include <vector>
class grafo
{
    public:
        grafo();
        virtual ~grafo();
        void enqueue(vertice v);
        vertice dequeue();
        vector<vector<int>> getMA(){return this->mAdjacencia;}
        void setMA(vector<vector<int>> nMA);
        void montarGrafo();
        void BFS(int nVerticeRaiz);
        void mostrarGrafo();
    protected:
        queue<vertice> Q;
        vector<vector<int>> mAdjacencia;
        vector<vertice> v;//vetor para armazenar os vertices pertencentes ao grafo
    private:
};
grafo::grafo()
{
    //ctor
}

grafo::~grafo()
{
    //dtor
}
void grafo::enqueue(vertice v){
    Q.push(v);
}
vertice grafo::dequeue(){
    vertice pF;//primeiro vertice da fila
    pF = Q.front();
    Q.pop();
    return pF;
}
void grafo::setMA(vector<vector<int>> nMA){
    this->mAdjacencia=nMA;
}
void grafo::montarGrafo(){
    for (int i = 0; i< mAdjacencia.size();i++){
        vertice aux;
        aux.setCor("branco");
        aux.setD(999);
        aux.setP(NULL);
        aux.setNum(i);
        this->v.push_back(aux);
    }
}
void grafo::BFS(int nVerticeRaiz){
    montarGrafo();
    v[nVerticeRaiz].setCor("cinzento");
    v[nVerticeRaiz].setD(0);
    v[nVerticeRaiz].setP(NULL);
    enqueue(v[nVerticeRaiz]);
    vertice aux;
    while (!Q.empty()){
        aux = dequeue();
        for (int i=0; i<=mAdjacencia.size();i++){
            if(mAdjacencia[aux.getNum()][i]==1){
                if (v[i].getCor()=="branco"){
                    v[i].setCor("cinzento");
                    v[i].setD(aux.getD()+1);
                    v[i].setP(aux.getNum());
                    enqueue(v[i]);
                }
            }
        }
        v[aux.getNum()].setCor("preto");
    }


}
void grafo::mostrarGrafo(){
    for (int i = 0; i<v.size();i++){
        cout<<"////////////////////"<<endl;
        cout<<"Número do vértice: "<<v[i].getNum()<<endl;
        cout<<"Distância do vertice raiz: "<<v[i].getD()<<endl;
        cout<<"Cor final: "<<v[i].getCor()<<endl;
        cout<<"Número do predescessor: "<<v[i].getP()<<endl;
    }
}
#endif // GRAFO_H
