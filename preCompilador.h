#ifndef __PreCompilador_H
#define __PreCompilador_H
#include <iostream>
using namespace std;

class PreCompilador{
  private:
    string texto;//variavel para guardar txt

  public:
    PreCompilador();//construtor
    void leitura();//leitura do codigo inicial
    void escrita();//escreve um novo arquivo apos o codigo inicial ser pre-compilado
    void trataInclude(char, string*, bool*);
    void trataIf(char, string*, bool*);
};
#endif