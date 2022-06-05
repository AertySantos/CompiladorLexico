
#include <iostream>
#include <vector>
#include <string>
#include <list>
#include "HashTable.h"
//#include "leitura.h"
using namespace std;

int main(){

    list<string> lista = {"int","main","(",")","{","int",
    "n","=","2",";","n","+","=","1",";","}","\"Este é literal\"",
    "}",">","+","}","+","+"
    };
    /*
    Leitor l;
    list<string> lista1 = l.ler("exemplo2.c");
    cout << "SAIDA:" << endl;
    for (string s : lista1)
    {
        cout << "<" << s << "> ";
    }*/
    HashTable HT;
    int tamanhoLista = lista.size();
    cout<<"Tamanho da lista: "<<tamanhoLista<<endl;
    
    for(int i{}; i < tamanhoLista; i++){
        string s = lista.front();
        
        lista.pop_front();
        
        HT.inserirItem(i+1,s);
    }
    cout<<"Tabela de Simbolos\n"<<endl;

    HT.mostrarTabela();        

}

