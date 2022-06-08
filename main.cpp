#include <iostream>
#include "preCompilador.h"
#include "leitura.h"
//#include "GeradorToken.h"

using namespace std;

int main() {
  
  PreCompilador pc;
  pc.iniciar("exemplos/codigo.c");
  
  Leitor l;
  list<Token> lista = l.ler("codPrecompilado.c");
  cout << "LEGENDA:\n";
  cout << "\tr:reservada\n\ti:identificador\n\tl:literal\n\tn:numero\n\ts:simbolo\n";
  cout << "SAIDA:\n";
  for (Token t : lista) {
    cout << "\t<"<< t.getNome() << "," << t.getValor() << ">\n";
  }
	
}
