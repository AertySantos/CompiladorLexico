#ifndef __PreCompilador_H
#define __PreCompilador_H

#include <iostream>
#include <list>
#include <fstream>
#include <string>

using namespace std;

class PreCompilador
{
private:
  string textoSup;    // variavel para guardar o texto superior
  string textoInf;    // variavel para guardar o texto inferior
  string inclusao;    // texto do arquivo que sera incluido
  string arquivoInc;  // arquivo a ser incluido
  string condicional; // guarda a condicional
  string condicao;    // guarda a condicao
  string ifInvalido;  // quando #if entra em condições não tratadas
  char varAnterior;   // guarda a variavel lida anteriormente
  bool aspas;         // para verificação de aspas
  bool txtDefine;
  list<string> lista;      // lista onde serão incluidos os includeres(evitar repetição)
  list<string> definicao;  // guarda as variaveis definidas
  list<string> atribuicao; // guarda as atribuições das variaveis definidas se houver
  list<bool> contif;       // para verificação de encadeamentos de #if,#ifndef...

public:
  PreCompilador();// construtor
  void iniciar(string arq); // loop precompilação com arquivo de codigo a ser lido
  bool leituraInclude(string); // leitura e adiçao de includes
  void leituraIfs(string);// leitura e verificação de #if,#else,#endif
  void escritaInclude();// escreve um novo arquivo apos o codigo inicial ser pre-compilado
  void escritaIfs();// escreve o arquivo apos a verificação dos #if,#else e #endif
  void trataInclude(char, string *, bool *, bool *, string *);// faz o tratamento dos includes
  bool verificaLista(string);// verifica se uma condição string esta presente na lista
  void trataIf(char, string *, bool *, bool *, bool *, string *, bool *, bool *, bool *); // faz o trato dos #if,#ifndef...
  void trataDefinicao(char, string *, bool *, int *, string *);// trata o #define
  string getInclusao();
  void setInclusao();
  string getTextoSup();
  void setTextoSup(string);
  string getTextoInf();
  void setTextoInf(string);
  string getArquivoInc();
  void setArquivoInc(string);
  bool verificaCondicao(string);
  void setaDefinicao(string);  // seta lista de definição
  void setaAtribuicao(string); // seta lista de atribuição
  char getVarAnterior();
  void setVarAnterior(char);
  bool getTxtDefine();
  void setTxtDefine(bool);
  string getCondicional();
  void setCondicional(string);
  string getIfInvalido();
  void setIfInvalido(string);
  void setContif(bool);
  bool verificaContif(); // verifica o encadeamento de #if,#ifndef...
  void limpar();        // limpa as variaveis entre a inclusao e verificação dos #ifs
  void txtComp();
};

PreCompilador::PreCompilador()
{
  textoSup = "";     // variavel para guardar o texto superior
  inclusao = "";     // texto do novo aquivo
  textoInf = "";     // variavel para guardar o texto inferior
  arquivoInc = "";   // arquivo para acessar
  ifInvalido = "";   // pega a string da condicional
  varAnterior = '0'; // pega a variavel anterior
  aspas = false;     // verificação de aspas
  txtDefine = false;
}

void PreCompilador::iniciar(string arq)
{

  bool op = true;       // variavel que aguarda o fim dos includes
  string arquivo = arq; // primeiro arquivo a ser lido
  //txtComp();
  cout << endl
       << "Iniciando execução...\n"
       << endl; // notificação de inicio

  while (op)
  { // verifica os includes
    op = leituraInclude(arquivo);
    escritaInclude();
    arquivo = "codInclude.c";
  }

  limpar();
  leituraIfs(arquivo); // verifica os #if,#else,#endif
  escritaIfs();        // faz a escrita do arquivo apos ser verificado os #if,#ifndef,#ifdef,#else,#endif

  cout << endl
       << "Pre Compilador executado!\n"
       << endl; // termino da execução do preecompilador
}

bool PreCompilador::leituraInclude(string nomeArquivo)
{ // verificação dos includers

  string texto = "", txt = "", comando = "", localInc = "", salva = "";
  string nomArq = nomeArquivo;
  string txtInclude = "#include";
  bool arquivoInc = false, IncVez = true;
  bool txtSup = true;   // texto superior
  bool txtInf = false;  // texto inferior
  bool retorno = false; // acabou jessica?

  limpar(); // limpa as variaveis privadas da classe

  ifstream leitor;
  leitor.open(nomArq, ios::in); // codigo a ser pre-compilado
  int i = 0;

  if (leitor.is_open())
  { // verifica se o arquivo esta aberto
    char c, anterior = '\n';
    bool trata = false;

    while (!leitor.eof())
    { // enquanto nao chegar ao fim do arquivo

      c = ' ';       // limpa c, para nao repetir o ultimo caractere
      leitor.get(c); // lê caracter a caracter

      if ((c == '#') && (anterior == '\n'))
      { // se tem # no codigo fz verificação
        trata = true;
        txtSup = false;
      }

      anterior = c; // para nao pegar include em comentario

      if (txtSup)
      {
        setTextoSup(getTextoSup() + c);
      }

      if (txtInf)
      {
        setTextoInf(getTextoInf() + c);
      }

      if (arquivoInc)
      { // faz tratamento do #include
        trataInclude(c, &localInc, &arquivoInc, &txtInf, &salva);
      }

      if (trata && !txtInf)
      {

        salva += c; // salva o arquivo acima quando um include é identificado

        if (c != ' ')
        {
          comando += c;
        }

        if (comando.size() >= 3 && comando.size() <= 8)
        {
          if (comando == txtInclude)
          { // identifica um #include
            arquivoInc = true;
            localInc = "";
            retorno = true;
            comando = "";
            salva = "";
            trata = false;
          }
        }
        if (comando.size() > 8)
        {
          trata = false;

          setTextoSup(getTextoSup() + salva);
          comando = "";
          txtSup = true;
          salva = "";
        }
      }
    }
    leitor.close(); // fecha o arquivo
  }
  else
  {
    cout << "Falha ao abrir arquivo";
  }

  setArquivoInc(localInc); // seto o include para ser incluido na escrita.
  return retorno;
}

void PreCompilador::leituraIfs(string nomeArquivo)
{

  string texto = "", txt = "", comando = "", salva = "";
  string txtIf = "#if";
  string txtIfndef = "#ifndef";
  string txtIfdef = "#ifdef";
  string txtElse = "#else";
  string txtEndif = "#endif";
  string txtDef = "#define";
  string erro = "Normal";
  bool tratamento = false;
  bool tratamentoDef = false;
  bool arqElse = false;
  bool txtSup = true;
  bool txtInf = false;
  bool def = false;
  bool semCom = true;
  bool operacao = false;
  bool guarda = false;
  bool guardaIf = false;
  int testeIf = 1;

  int ind = 0;

  ifstream leitor;
  leitor.open(nomeArquivo, ios::in); // codigo a ser pre-compilado

  if (leitor.is_open())
  { // verifica se o arquivo esta aberto
    char c;
    bool trata = false;

    while (!leitor.eof())
    { // enquanto nao chegar ao fim do arquivo

      c = ' ';       // limpa c, para nao repetir o ultimo caractere
      leitor.get(c); // lê caracter a caracter

      if ((c == '#') && (semCom) || (c == '_') && (semCom))
      { // se  tem # no codigo fz verificação
        // se começa com _
        trata = true;
        txtSup = false;
        salva = ""; // apaga o salva
      }
      salva += c; // resetar para pega logo apos a pausa txtSup

      if (semCom)
      { // caso tenha um ou uns espaços antes do #
        if (c != ' ')
        {
          semCom = false;
        }
      }

      if (c == '\n')
      {
        semCom = true;
      }

      if (((txtSup) && (verificaContif())) || ((txtSup) && (contif.size() == 1)))
      { // escreve ou não escreve
        // entra no #else
        if (!getTxtDefine())
        { // nao pega texto no define
          setTextoSup(getTextoSup() + c);
        }
      }

      if (tratamento)
      { // faz tratamento do #if,#else e #endif

        trataIf(c, &condicao, &tratamento, &txtSup, &arqElse, &salva, &operacao, &guarda, &guardaIf);
      }
      else if (tratamentoDef)
      { // faz tratamento da #definicao

        trataDefinicao(c, &condicao, &tratamentoDef, &ind, &salva); // trata definicoes
      }

      if (trata)
      {

        if (c != ' ')
        {
          comando += c;
        }

        if (comando.size() >= 3 && comando.size() <= 8)
        {

          if (((comando == txtIf) && (c == ' ')) || ((comando == txtIfndef) || (comando == txtIfdef)))
          { // identifica #if,#ifdef,#ifndef
            setCondicional(comando);
            setIfInvalido(txtIf + ' '); // seto o texto #if
            tratamento = true;
            trata = false;
            testeIf++;
            // contador if verificação de ifs encadeados
            comando = "";
          }
          else if (comando == txtDef)
          {

            if (operacao)
            { // esta dentro de um #endif
              tratamentoDef = true;
            }
            else if (testeIf == 1)
            {
              tratamentoDef = true;
            }
          }
          else if (comando == txtElse)
          { // identifica um #else

            trata = false;
            comando = "";
            salva = "";

            if (arqElse)
            { // saber se copia ou nao o trecho do else
              txtSup = true;
            }
            else
            {
              txtSup = false;
            }
          }
          else if (comando == txtEndif)
          { // identifica um #endif representa um fechamento
            trata = false;
            txtSup = true;
            comando = "";

            if (contif.size() > 0)
            {
              contif.pop_front(); // tira um verificador da lista if
            }

            testeIf--;

            if (testeIf == 0)
            {
              testeIf++;
              erro = "ERRO! : falta #if"; // caso tenha mais #endif que #if
              cout << erro << " -> " << testeIf << endl;
              return;
            }

            if (guardaIf || guarda || operacao)
            { // habilitar caso queira colocar #endif
              if (guardaIf)
              {
                guardaIf = false;
              }
              if (guarda)
              {
                guarda = false;
              }
              if (operacao)
              {
                operacao = false;
              }
            }
            setTxtDefine(false); // para começar a gravar apos sair de #ifndef
            salva = "";          // limpa a variavel de texto
          }
        }

        if ((comando.size() > 8) && (c == '\n'))
        { // se for maior que sete caracters guardo o comando
          trata = false;
          if (!getTxtDefine())
          { // nao pega texto no define
            txtSup = true;
          }
          comando = "";
          salva = "";
        }
      }
    }
    leitor.close(); // fecha o arquivo
  }

  if (testeIf > 1)
  { // possiveis erros nas aberturas e fechamentos de #if,#ifndef,#ifdef
    cout << "ERRO! : falta #endif -> " << (testeIf - 1) << endl;
  }
}

void PreCompilador::trataIf(char c, string *txt, bool *arq, bool *ts, bool *arqelse, string *salve, bool *op, bool *gu, bool *gf)
{
  char c2 = c;
  bool txSup = false;

  if (c2 == '\n')
  { // chegou ao fim da condição

    txSup = verificaCondicao(*txt); // verifica se a condição esta na lista

    if (getCondicional() == "#ifndef")
    { // esta dentro de uma condicional #ifndef

      if (!txSup)
      {             // se não estiver definido será definido
        *op = true; // pegar definicao
        *ts = true; // caso queira gravar o que esta dentro do #ifndef
        setContif(true);
        setTxtDefine(true); // para pegar a definição e evitar grava-la no novo arquivo
      }
      else
      {
        *op = false;
        *gu = true; //#endif
        setContif(false);
      }
      *arq = false; // sai do tratamento
      *txt = "";
    }
    else if (getCondicional() == "#ifdef")
    { // esta dentro de uma condicional #ifdef
      *ts = false;
      *gu = true;
      *arq = false; // sai do tratamento
      *txt = "";
      setContif(false);
    }
    else
    { //é um #if

      if (*gf)
      {               // caso a condição #if esteja fora dos padrões definidos no trabalho
        *arq = false; // sai do tratamento
        *txt = "";
        setContif(false);
      }
      else
      {
        *ts = txSup;     // ts é igual txtSup
        *arq = false;    // sai do tratamento
        *arqelse = !*ts; // ve se vai pegar a parte do else ou a parte do if
        *txt = "";       // limpa o texto condicional
        *salve = "";     // limpa o texto da variavel
        setContif(txSup);
      }
    }
    setIfInvalido("");
  }
  else
  { // pega a condição if
    if (c2 != ' ')
    {
      *txt += c2;

      if (c2 == '=')
      { // delimitando
        *gf = true;
      }
      else if (c2 == '<')
      {
        *gf = true;
      }
      else if (c2 == '>')
      {
        *gf = true;
      }
      else if (c2 == '&')
      {
        *gf = true;
      }
      else if (c2 == '|')
      {
        *gf = true;
      }
    }
    setIfInvalido(getIfInvalido() + c2);
  }
}

bool PreCompilador::verificaContif()
{

  for (bool b : contif)
  {
    if (!b)
    {
      return b;
    }
  }
  return true;
}

void PreCompilador::trataDefinicao(char c2, string *txt, bool *destrava, int *ind, string *salve)
{
  char c = c2;

  if (c == '\n')
  { // chegou ao fim da condição

    if (*ind == 0)
    {                      // se for so uma variavel
      setaDefinicao(*txt); // seta a definição
      setaAtribuicao(" "); // seta a definição
      *ind = 1;
      *txt = ""; // apaga a variavel para pegar a definição
    }
    else if (*ind == 1)
    {
      setaAtribuicao(*txt); // seta a definição
    }

    *destrava = false; // sai do tratamento
    *txt = "";         // limpa a variavel acumuladora de texto
    *ind = 0;
    
  }
  else
  { // pega a condição if
    if (c != ' ')
    {
      *txt += c;
    }
    else
    {
      if (*txt != "")
      { // se nao estiver vazio

        if (*ind == 0)
        {
          setaDefinicao(*txt); // seta a definição
          *ind = 1;

          *txt = ""; // apaga a variavel para pegar a definição
        }
        else if (*ind == 1)
        {
          setaAtribuicao(*txt); // seta a definição
          *txt = "";            // apaga a variavel para pegar a definição
          *ind = 2;
        }
      }
    }
  }
}

void PreCompilador::setaDefinicao(string def)
{
  definicao.insert(definicao.begin(), 1, def);
}

void PreCompilador::setaAtribuicao(string atr)
{
  atribuicao.insert(atribuicao.begin(), 1, atr);
}

bool PreCompilador::verificaCondicao(string def)
{

  for (string str : definicao)
  {
    if (str == def)
    {
      return true;
    }
  }
  return false;
}

void PreCompilador::setContif(bool cif)
{
  contif.insert(contif.begin(), 1, cif);
}

void PreCompilador::escritaIfs()
{
  ofstream escritor;
  escritor.open("codPrecompilado.c", ios::out | ios::trunc);
  escritor << getTextoSup();
  escritor.close();
  limpar();
}

void PreCompilador::trataInclude(char c, string *txtInc, bool *arqinc, bool *txinf, string *txtsal)
{
  char c2 = c;
  if ((c2 == '>') || (c == '\n'))
  { // chegou ao final da condição
    *arqinc = false;

    if (!verificaLista(*txtInc))
    {
      *txinf = true;
      lista.insert(lista.begin(), 1, *txtInc);
    }
    else
    {
      *txtsal = "";
      *txtInc = "";
    }
  }
  else if (c2 != '<' && c2 != '>')
  { // pega o que esta dentro do include <include>
    if ((c2 != ' ') && (c2 != '"'))
    { // retira espacos e aspas
      *txtInc += c2;
    }
  }
}

bool PreCompilador::verificaLista(string novoInc)
{
  for (string str : lista)
  {
    if (str == novoInc)
    {
      return true;
    }
  }
  return false;
}

void PreCompilador::escritaInclude()
{
  // remove("codigoPre.c");
  // cout<<getTextoSup();
  ofstream escritor;
  escritor.open("codInclude.c", ios::out | ios::trunc);
  escritor << getTextoSup();

  if (getArquivoInc()[getArquivoInc().size() - 1] != 'h')
  {
    escritor << getArquivoInc(); // caso nao seja um arquivo
  }
  else
  {
    setInclusao(); // inclui o texto do arquivo a ser incluido
  }
  escritor << getInclusao();
  escritor << getTextoInf();
  escritor.close();
}

string PreCompilador::getInclusao()
{
  return inclusao;
}

void PreCompilador::setInclusao()
{ // inclui novo arquivo de texto
  ifstream leitor;
  leitor.open("include/" + getArquivoInc(), ios::in); // arquivo a ser incluido

  if (leitor.is_open())
  { // verifica se o arquivo esta aberto
    char letra;
    while (!leitor.eof())
    {                    // enquanto nao chegar ao fim do arquivo
      letra = ' ';       // limpa para nao repetir o ultimo caractere
      leitor.get(letra); // lê caracter a caracter
      inclusao += letra;
    }
    leitor.close(); // fecha o arquivo

    if (getArquivoInc() != "")
    {
      cout << "Incluindo arquivo " + getArquivoInc() << endl;
    }
  }
  else
  {
    ifstream leitor2;
    leitor2.open("lib/gcc/mingw32/9.2.0/include/" + getArquivoInc(), ios::in); // arquivo a ser incluido

    if (leitor2.is_open())
    { // verifica se o arquivo esta aberto
      char letra2;
      while (!leitor2.eof())
      {                      // enquanto nao chegar ao fim do arquivo
        letra2 = ' ';        // limpa para nao repetir o ultimo caractere
        leitor2.get(letra2); // lê caracter a caracter
        inclusao += letra2;
      }
      leitor2.close(); // fecha o arquivo

      if (getArquivoInc() != "")
      {
        cout << "Incluindo arquivo " + getArquivoInc() << endl;
      }
    }
    else
    {
      cout << "Não possui o arquivo " << getArquivoInc() << endl;
      inclusao += '\n';
    }
  }
}

string PreCompilador::getArquivoInc()
{
  return arquivoInc;
}

void PreCompilador::setArquivoInc(string arq)
{ // inclui novo arquivo de texto
  arquivoInc = arq;
}

string PreCompilador::getTextoSup()
{
  return textoSup;
}

void PreCompilador::setTextoSup(string txts)
{ // inclui novo arquivo de texto
  textoSup = txts;
}

string PreCompilador::getTextoInf()
{
  return textoInf;
}

void PreCompilador::setTextoInf(string txtinf)
{ // inclui novo arquivo de texto
  textoInf = txtinf;
}

char PreCompilador::getVarAnterior()
{
  return varAnterior;
}

void PreCompilador::setVarAnterior(char tx)
{ // inclui novo arquivo de texto
  varAnterior = tx;
}

string PreCompilador::getCondicional()
{
  return condicional;
}

void PreCompilador::setCondicional(string str)
{ // inclui novo arquivo de texto
  condicional = str;
}

string PreCompilador::getIfInvalido()
{
  return ifInvalido;
}

void PreCompilador::setIfInvalido(string ifnv)
{ // inclui novo arquivo de texto
  ifInvalido = ifnv;
}

bool PreCompilador::getTxtDefine()
{
  return txtDefine;
}

void PreCompilador::setTxtDefine(bool txdef)
{
  txtDefine = txdef;
}

void PreCompilador::limpar()
{
  textoSup = "";
  textoInf = "";
  inclusao = "";
  arquivoInc = "";
  condicao = "";
}

void PreCompilador::txtComp(){
  cout << endl;
  cout <<"█▀▀█ █▀▀█ █▀▄▀█ █▀▀█ ░▀░ █░░ █▀▀█ █▀▀▄ █▀▀█ █▀▀█   █░░░ █▀▀ █░█ ░▀░ █▀▀ █▀▀█" << endl;
  cout <<"█░░░ █░░█ █░▀░█ █░░█ ▀█▀ █░░ █▄▄█ █░░█ █░░█ █▄▄▀   █░░░ █▀▀ ▄▀▄ ▀█▀ █░░ █░░█" << endl;
  cout <<"█▄▄█ ▀▀▀▀ ▀░░░▀ █▀▀▀ ▀▀▀ ▀▀▀ ▀░░▀ ▀▀▀░ ▀▀▀▀ ▀░▀▀   █▄▄█ ▀▀▀ ▀░▀ ▀▀▀ ▀▀▀ ▀▀▀▀" << endl;
}
#endif