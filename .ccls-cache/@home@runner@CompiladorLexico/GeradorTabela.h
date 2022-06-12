#ifndef __GeradorTabela
#define __GeradorTabela

#include <iostream>
#include <list>
#include "token.h"
#include "HashTable.h"

using namespace std;

class GeradorTabela{
    public:
    HashTable hashTable;
    public:
    void mostrarTokenLidos(list<Token> tokenList){

        for (int i{}; i < tokenList.size(); i++){
            char tkNome = tokenList.front().getNome();
            string tkValor = tokenList.front().getValor();
            cout << i << ":"<< "\t" << tkValor << endl;
            tokenList.pop_front();
        }
    }
    public:
    void GerarTabela(list<Token> tokenList){
        for (int i{}; i < tokenList.size(); i++){
            if (tokenList.front().getNome() == 'i')
            {
                char tkNome = tokenList.front().getNome();
                string tkValor = tokenList.front().getValor();
                hashTable.inserirItem(tkValor, to_string(i) );
                //cout<<i<<":"<<"\t"<<tkNome<<tkValor<<endl;
            }
            tokenList.pop_front();
        }
    }
};
#endif