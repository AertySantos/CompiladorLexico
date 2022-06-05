#include <iostream>
#include "preCompilador.h"
#include "leitura.h"
//#include "GeradorToken.h"

using namespace std;

int main() {
  
  PreCompilador pc;
  pc.iniciar("codigo.c");
  
  Leitor l;
  list<Token> lista = l.ler("codPrecompilado.c");
  cout << "SAIDA:\n";
  for (Token t : lista) {
    cout << "<" << t.getNome() << "," << t.getValor() << ">\n";
  }
	
}
