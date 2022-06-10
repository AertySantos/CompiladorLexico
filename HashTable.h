#ifndef __HashTable
#define __HashTable

#include <iostream>
#include <list>
#include <cstring>

using namespace std;

class HashTable
{
private:
    static const int hashGroups = 10;
    list<pair<int, string>> tabela[hashGroups]; // list 1, indice 0, list 2, indice 1...
public:
    bool estaVazia() const;
    int funcaoHash(int chave);
    void inserirItem(int chave, string valor);
    void removerItem(int chave);
    string pesquisarTabela(int chave);
    void mostrarTabela();    
};

bool HashTable::estaVazia() const
    {
        int soma{};
        for (int i{}; i < hashGroups; i++)
        {
            soma += tabela[i].size();
        }
        if(!soma){
            return true;
        }
        return false;
    }

    int HashTable::funcaoHash(int chave){
        return chave % hashGroups; //id
    }

    void HashTable::inserirItem(int chave, string valor){
        int valorHash = funcaoHash(chave);
        auto& celula = tabela[valorHash];
        auto bItr = begin(celula);
        bool existChave = false;
        for(; bItr !=  end(celula); bItr++){
            if(bItr->first == chave){
                existChave = true;
                bItr->second = valor;
                cout<<"Atenção, valor existente. Valor substituido"<<endl;
                break;
            }
        }
        if(!existChave){
            celula.emplace_back(chave,valor);
        }
        return;
    }

    void HashTable::removerItem(int chave){
        int valorHash = funcaoHash(chave);
        auto& celula = tabela[valorHash];
        auto bItr = begin(celula);
        bool existChave = false;
        for(; bItr !=  end(celula); bItr++){
            if(bItr->first == chave){
                existChave = true;
                bItr= celula.erase(bItr);
                cout<<"Atenção, Item removido"<<endl;
                break;
            }
        }
        if(!existChave){
            cout<<"Chave não encontrada"<<endl;
        }
    }
    void HashTable::mostrarTabela(){
        for(int i{}; i < hashGroups; i++){
            if(tabela[i].size() == 0) continue;

            auto bItr = tabela[i].begin();
            for(;bItr != tabela[i].end(); bItr++){
                cout<<"Posição: "<<bItr->first<<"\t Identificador: "<<bItr->second<<endl;
            }
            
        }
        return;
    }
#endif