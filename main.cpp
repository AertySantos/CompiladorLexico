#include <iostream>
#include <iterator>
#include "preCompilador.h"
#include "leitura.h"
#include "GeradorTabela.h"

using namespace std;

int main() {
  
  PreCompilador pc;
  pc.iniciar("exemplos/codigo.c");
  
  Leitor l;
  list<Token> lista = l.ler("codPrecompilado.c");
	
  //SAIDA
  cout << "\nLEGENDA:\n\tr:reservada\n\ti:identificador\n\tl:literal\n\tn:numero\n\ts:simbolo\nSAIDA:\n";
  cout << "TODOS OS TOKENS:\n";
  for(Token t : lista) {
    cout <<"<" << t.getNome() << "," <<t.getValor() << "> ";
  }
  cout << "\n\nTODOS OS IDENTIFICADORES:\n";
  for(Token t : lista) {
  	if (t.getNome() == 'i') {
            cout << "\t<" << t.getValor() << "> \n";
        }
    }

    GeradorTabela geradorTabela;
    int tokenListSize = lista.size();

    //Mostra quantidade dos tokens gerado no arquivo
    cout<<"Quantidade de Tokens no arquivo"<<endl;
    cout<<"Foram registrados "<<tokenListSize<<" Tokens\n"<<endl;
    geradorTabela.mostrarTokenLidos(lista);

    //Gerar Tabela de simbolos    
    geradorTabela.GerarTabela(lista);
    //Mostrar Tabela 
    cout<<"\nMostrando Tabela de Símbolos\n"<<endl;
    geradorTabela.hashTable.mostrarTabela();
	
}
