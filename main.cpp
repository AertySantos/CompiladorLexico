#include <iostream>
#include "preCompilador.h"
#include "leitura.h"
//#include "GeradorToken.h"

using namespace std;

int main() {
  
  //PreCompilador pc;
  //pc.iniciar();
  
  Leitor l;
  list<string> lista = l.ler("exemplos/exemplo2.c");
  cout << "SAIDA:"<<endl;
  for(string s: lista) {
    cout<< "<" << s << "> ";
  }

}