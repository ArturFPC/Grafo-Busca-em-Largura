#ifndef VERTICE_H
#define VERTICE_H
#include <string>
#include <iostream>
using namespace std;
class vertice
{
    public:
        vertice();
        virtual ~vertice();
        string getCor(){return this->cor;};
        void setCor(string nCor);
        int getD(){return this->d;};
        void setD(int nD);
        int getP(){return this->p;}
        void setP(int nP);
        int getNum(){return this->num;}
        void setNum(int nNum);
    protected:
        string cor;
        int d;
        int p = NULL;//numero do predescessor
        int num;//numero para pegar a posição do vertice na matriz de adjacencia
    private:
};
vertice::vertice()
{
    this->cor = "branco";
    this->d = 999;//utilizei 999 para reprezentar o infinito
    this->p = NULL;
    this->num = 0;
}

vertice::~vertice()
{
    //dtor
}
void vertice::setCor(string nCor){
    this->cor = nCor;
}
void vertice::setD(int nD){
    this->d = nD;
}
void vertice::setP(int nP){
    this->p = nP;
}
void vertice::setNum(int nNum){
    this->num=nNum;
}
#endif // VERTICE_H
