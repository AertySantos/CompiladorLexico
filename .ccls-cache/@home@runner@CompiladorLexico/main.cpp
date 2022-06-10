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
  cout << "LEGENDA:\n\tr:reservada\n\ti:identificador\n\tl:literal\n\tn:numero\n\ts:simbolo\nSAIDA:\n";
  cout << "TODOS OS IDENTIFICADORES\n";
  for(Token t : lista) {
  	if (t.getNome() == 'i') {
            cout << "\t<" << t.getValor() << "> \n";
        }
    }

    /*
    cout << "IDENTIFICADORES COM VALOR <apelido,valor>\n";
    list<Token>::iterator it;
    string apelido_ident;
    string valor_ident;
    for (it = lista.begin(); it != lista.end(); it++) {
        if (it-> getNome()== 'i') {
            apelido_ident = it->getValor();
        }
        if (it->getValor().compare("=") == 0) {
            it++;
            if (it->getValor().compare("=") != 0) { //Checa se não tem dois iguais(comparação)
                valor_ident = it->getValor();
                cout << "\t<" << apelido_ident << "," << valor_ident << "> \n";
            }
        }
    }*/
    GeradorTabela geradorTabela;
    int tokenListSize = lista.size();

    //Mostra quantidade dos tokens gerado no arquivo
    cout<<"Quantidade de Tokens no arquivo"<<endl;
    cout<<"Foram registrados "<<tokenListSize<<" Tokens\n"<<endl;
    geradorTabela.mostrarTokenLidos(lista);

    //Gerar Tabela de simbolos    
    geradorTabela.GerarTabela(lista);
    //Mostrar Tabela 
    cout<<"Mostrando Tabela de Símbolos\n"<<endl;
    geradorTabela.hashTable.mostrarTabela();
	
}
