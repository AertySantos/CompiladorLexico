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
    string condicional;//guarda a condicional
    string condicao;//guarda a condicao
    char varAnterior;//guarda a variavel lida anteriormente 
    bool aspas;//para verificação de aspas
    list<string>lista;//lista onde serão incluidos os includeres
    list<string>definicao;//guarda as variaveis definidas
    list<string>atribuicao;//guarda as atribuições das variaveis definidas se houver

  public:
    PreCompilador();//construtor
    void iniciar();//loop precompilação
    bool leituraInclude(string);//leitura e adiçao de includes
    void leituraIfs(string);//leitura e verificação de #if,#else,#endif
    void escritaInclude();//escreve um novo arquivo apos o codigo inicial ser pre-compilado
    void escritaIfs();//escreve o arquivo apos a verificação dos #if,#else e #endif
    void trataInclude(char, string*, bool*, bool*, string*);
    bool verificaLista(string);
    void trataIf(char, string*, bool*, bool*, bool*, string*, bool*);
    void trataDefinicao(char, string*, bool*, int*, string*);
    string getInclusao();
    void  setInclusao();
    string getTextoSup();
    void  setTextoSup(string);
    string getTextoInf();
    void  setTextoInf(string);
    string getArquivoInc();
    void setArquivoInc(string);
    bool verificaCondicao(string);
    void setaDefinicao(string);//seta lista de definição
    void setaAtribuicao(string);//seta lista de atribuição
    char getVarAnterior();
    void setVarAnterior(char);
    string getCondicional();
    void setCondicional(string);
    void limpar();
};
#endif