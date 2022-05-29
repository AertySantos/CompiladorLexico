#ifndef __PreCompilador_H
#define __PreCompilador_H
#include <iostream>
#include<list>
using namespace std;

class PreCompilador{
  private:
    string textoSup;//variavel para guardar o texto superior
    string textoInf;//variavel para guardar o texto inferior
    string inclusao;//texto do arquivo que sera incluido
    string arquivoInc;//arquivo a ser incluido
    string condicao;
    bool  aspas;
    list<string>lista;//lista onde serão incluidos os includeres

  public:
    PreCompilador();//construtor
    void iniciar();//loop precompilação
    bool leituraInclude(string);//leitura e adiçao de includes
    void leituraIfs();
    void escritaInclude();//escreve um novo arquivo apos o codigo inicial ser pre-compilado
    void escritaIfs();
    void trataInclude(char, string*, bool*, bool*, string*);
    bool verificaLista(string);
    void trataIf(char, string*, bool*, bool*, bool*);
    string getInclusao();
    void  setInclusao();
    string getTextoSup();
    void  setTextoSup(string);
    string getTextoInf();
    void  setTextoInf(string);
    string getArquivoInc();
    void  setArquivoInc(string);
    bool  verificaCondicao(string);
    void limpar();
};
#endif