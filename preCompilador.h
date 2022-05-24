#ifndef __PreCompilador_H
#define __PreCompilador_H
#include <iostream>
using namespace std;

class PreCompilador{
  private:
    string textoSup;//variavel para guardar o texto superior
    string textoInf;//variavel para guardar o texto inferior
    string inclusao;//texto do arquivo que sera incluido
    string arquivoInc;//arquivo a ser incluido
    string condicao;

  public:
    PreCompilador();//construtor
    void iniciar();//loop precompilação
    void leituraInclude();//leitura e adiçao de includes
    void leituraIfs();
    void escritaInclude();//escreve um novo arquivo apos o codigo inicial ser pre-compilado
    void escritaIfs();
    void trataInclude(char, string*, bool*, bool*);
    void trataIf(char, string*, bool*);
    string getInclusao();
    void  setInclusao();
    string getTextoSup();
    void  setTextoSup(string);
    string getTextoInf();
    void  setTextoInf(string);
    string getArquivoInc();
    void  setArquivoInc(string);
    string getCondicao();
    void  setCondicao(string);
};
#endif