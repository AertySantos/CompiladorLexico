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

        int i = 0;
      
        for (Token tk : tokenList)
            {
              char tkNome = tk.getNome();
              string tkValor = tk.getValor();
              cout << i << ":"<< "\t" << tkValor << endl;
              i++;
            }
    }
    public:
    void GerarTabela(list<Token> tokenList){
      int i = 0;
      
        for (Token tk : tokenList)
            {
              if(tk.getNome() == 'i'){
                char tkNome = tk.getNome();
                string tkValor = tk.getValor(); 
                hashTable.inserirItem(tkValor, to_string(i) );
              }
              i++;
            }
    }
};
#endif