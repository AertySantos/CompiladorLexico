#include "preCompilador.h"
#include <iostream>
#include<fstream>
#include <string>
#include<list>
using namespace std;

PreCompilador::PreCompilador(){
  textoSup = "";//variavel para guardar o texto superior
  inclusao = "";//texto do novo aquivo
  textoInf = "";//variavel para guardar o texto inferior
  arquivoInc = "";//arquivo para acessar
  varAnterior = '0';
  aspas = false;
}

void PreCompilador::iniciar(){
  
  bool op = true;
  string arquivo = "codigo.c";
  cout << endl << "Iniciando execução...\n" << endl;
  
  /*while(op){//verifica os includes
    op = leituraInclude(arquivo);
    escritaInclude();
    arquivo = "codigoPre.c";
  }*/
  
  leituraIfs("codigo.c");//verifica os #if,#else,#endif
 // escritaIfs();
  
  cout << endl << "Pre Compilador executado!" << endl;

}

bool PreCompilador::leituraInclude(string nomeArquivo){//verificação dos includers
  
    string texto = "", txt ="", comando = "",localInc = "",salva="";
    string nomArq = nomeArquivo;
    string txtInclude = "#include";
    bool arquivoInc = false, IncVez = true;
    bool txtSup = true;//texto superior
    bool txtInf = false;//texto inferior
    bool retorno = false;//acabou?
    limpar();//limpa as variaveis privadas da classe
  
    ifstream leitor;
    leitor.open(nomArq, ios::in);//codigo a ser pre-compilado
    int i = 0;
  
    if(leitor.is_open()){//verifica se o arquivo esta aberto
      char c, anterior = '\n';
      bool trata = false;
      //int i2 = 0;
      
        while (!leitor.eof()) {//enquanto nao chegar ao fim do arquivo
          
                c = ' ';//limpa c, para nao repetir o ultimo caractere
                leitor.get(c);//lê caracter a caracter
               // cout << c;
          
                if((c == '#')&&(anterior == '\n')){//se tem # no codigo fz verificação
                  trata = true;
                  txtSup = false;
                  //i2++;
                  //cout << i2;
                }

                anterior = c;//para nao pegar include em comentario
          
                if(txtSup){
                  setTextoSup(getTextoSup() + c);
                }

                if(txtInf){
                  setTextoInf(getTextoInf() + c);
                }
          
                if(arquivoInc){//faz tratamento do #include
                  trataInclude(c, &localInc, &arquivoInc, &txtInf, &salva);
                }

                if(trata && !txtInf){
                  
                    salva += c;//salva o arquivo acima quando um include é identificado
                  
                    if(c!=' '){
                      comando += c;
                    }
                   // cout << comando;
                    if(comando.size() >= 3 && comando.size()<= 8){
                      if(comando == txtInclude){//identifica um #include
                        //cout << comando;
                        arquivoInc = true;
                        localInc = "";
                        retorno = true;
                        comando = "";
                        salva = "";
                        trata = false;
                      }
                    }
                    if(comando.size() > 8){
                      trata = false;
                      
                      setTextoSup(getTextoSup() + salva);
                      comando = "";
                      txtSup = true;
                      salva = "";
                    }
                }

            }
      leitor.close();//fecha o arquivo
      
      }else{
        cout << "Falha ao abrir arquivo";
      }
    
  setArquivoInc(localInc);//seto o include para ser incluido na escrita.
  return retorno;
}

void PreCompilador::leituraIfs(string nomeArquivo){
  
    string texto = "", txt ="", comando = "", salva = "";
    string txtIf = "#if";
    string txtIfndef = "#ifndef";
    string txtIfdef = "#ifdef"; 
    string txtElse = "#else";
    string txtEndif = "#endif";
    string txtDef = "#define";
    string erro = "";
    bool tratamento = false;
    bool tratamentoDef = false;
    bool arqElse = false;
    bool txtSup = true;
    bool txtInf = false;
    bool def = false;
    bool semCom = true;
    bool operacao = false;
    bool guarda = false;
    int testeIf = 1;
    int ind = 0;
    
    ifstream leitor;
    leitor.open(nomeArquivo, ios::in);//codigo a ser pre-compilado
    
    if(leitor.is_open()){//verifica se o arquivo esta aberto
      char c;
      bool trata = false;
      
        while (!leitor.eof()) {//enquanto nao chegar ao fim do arquivo
          
                c = ' ';//limpa c, para nao repetir o ultimo caractere
                leitor.get(c);//lê caracter a caracter
                //
                //cout << c;
          
                if((c == '#')&&(semCom)){//se tem # no codigo fz verificação
                  
                    trata = true;
                    txtSup = false;
                    salva ="";//apaga o salva
                
                }
                salva += c;//resetar para pega logo apos a pausa txtSup
          
                if(semCom){//caso tenha um ou uns espaços antes do #
                  if(c != ' '){
                    semCom = false;
                  }
                }
          
                if(c == '\n'){
                  semCom = true;
                }
          
                //setVarAnterior(c);//variavel anterior
          
                if(txtSup){
                  setTextoSup(getTextoSup() + c);
                }

                if(tratamento){//faz tratamento do #if,#else e #endif
                  //salva += c;
                  trataIf(c, &condicao, &tratamento, &txtSup, &arqElse, &salva, &operacao, &guarda);
                  
                }else if(tratamentoDef){//faz tratamento da #definicao
            
                  trataDefinicao(c, &condicao, &tratamentoDef, &ind, &salva);//trata definicoes
                  
                }
          
              if(trata){
              
                  if(c != ' '){
                     comando += c; 
                  }
                  
                  if(comando.size() >= 3 && comando.size()<= 8){
                      
                    if(((comando == txtIf)&&(c == ' '))||((comando == txtIfndef)||(comando == txtIfdef))){//identifica um #if                
                      setCondicional(comando);
                      tratamento = true;
                      trata = false;
                      testeIf++;
                      
                      if(comando == txtIfndef){
                    
                        setTextoSup(getTextoSup() + txtIfndef);//pegar o texto #define
                        txtSup = true;//continua gravando o texto
                      }else if(comando == txtIfdef){
                   
                        setTextoSup(getTextoSup() + txtIfdef);//pegar o texto #define
                        txtSup = true;
                      }
                       
                      comando = "";
                     
                      
                    }else if(comando == txtDef){
                              if(operacao){//esta dentro de um #endif
                                 trata = false;
                                 comando = "";
                                 tratamentoDef = true;
                                 txtSup = true;//deixa pegar o texto
                                 setTextoSup(getTextoSup() + txtDef);//pegar o texto #define
                                
                              }else if(testeIf == 1){
                                 trata = false;
                                 comando = "";
                                 tratamentoDef = true;
                                 txtSup = true;//deixa pegar o texto
                                 setTextoSup(getTextoSup() + txtDef);//pegar o texto #define
                                 //salva = txtDef;
                              }
                     
                    }else if(comando == txtElse){//identifica um #else
                      trata = false;
                      comando = "";
                      salva = "";
                      if(arqElse){//saber se copia ou nao o trecho do else
                        txtSup = true;
                      }else{
                        txtSup = false;
                      }
                      
                    }else if(comando == txtEndif){//identifica um #endif
                      trata = false;
                      txtSup = true;
                      comando = "";
                      
                      testeIf--;
                      
                      if(testeIf == 0){
                        testeIf++;
                        erro = "ERRO: falta #if\n";
                        
                      //  setTextoSup(getTextoSup() + salva);//joga o endif de volta para o texto
                      }
                      if(operacao){//#ifndef
                        operacao = false;
                        setTextoSup(getTextoSup() + salva);
                      }
                      if(guarda){//#ifdef ja defini
                        guarda = false;
                        setTextoSup(getTextoSup() + txtEndif);
                      }
                      salva = "";
                      //cout << c;
                    }
                    
                  }
                  
                  if(comando.size() > 8){//se for maior que sete carcters guardo o comando
                    trata = false;
                    setTextoSup(getTextoSup() + salva);
                    txtSup = true;
                    comando = "";
                    salva = "";
                  }
                }
              
            }
      leitor.close();//fecha o arquivo
      
    }
    
    cout <<getTextoSup()<<endl;//teste
  
    if(testeIf > 1){
      cout << "ERRO: falta #endif ->"<<(testeIf - 1)<<endl;
    }
    cout << erro << endl;//teste
    //setCondicao(condicaoIfs.erase(0,1));
    //cout << endl<<condicaoIfs;//teste
   // cout << "ERRO: falta #endif "<<endl<< testeIf;
}

void PreCompilador::trataIf(char c, string*txt, bool*arq, bool*ts, bool*arqelse, string*salve, bool*op, bool*gu){
    char c2 = c;
    bool txSup = false;
    
      if(c2 == '\n'){ //chegou ao fim da condição
        
      txSup = verificaCondicao(*txt);
     // cout<<endl<<*txt+" "<<*ts<<endl;//....................................................
      if(getCondicional() == "#ifndef"){
        
        if(!txSup){
           *op = true;//pegar definicao
        }else{
          *op = false;
          *gu = true;//#endif
        }
        *arq = false;//sai do tratamento
        *txt = "";
        
      }else if(getCondicional() == "#ifdef"){
        *gu = true;
        *arq = false;//sai do tratamento
        *txt = "";
       
      }else{//é um #if
        *ts = txSup;//ts é igual txtSup
        *arq = false;//sai do tratamento
        *arqelse = !*ts;
        *txt = "";
        *salve = "";
      }
    
    }else{//pega a condição if  
      if(c2 != ' '){
        *txt += c2;
      }
    }
}

void PreCompilador::trataDefinicao(char c2, string* txt, bool* destrava, int* ind, string* salve){
    char c = c2;
    
    if(c == '\n'){ //chegou ao fim da condição
      
      if(*ind == 0){//se for so uma variavel
        setaDefinicao(*txt);//seta a definição
        setaAtribuicao(" ");//seta a definição
        *ind = 1;
        //cout<<*txt+"->variavel definida<-";//..............................................
        *txt = "";//apaga a variavel para pegar a definição
      }else if(*ind == 1){
            setaAtribuicao(*txt);//seta a definição
           // cout<<*txt+"foiiiiiiii";
      }
      
      *destrava = false;//sai do tratamento
      *txt = "";//limpa a variavel acumuladora de texto
      *ind = 0;
      
    }else{//pega a condição if  
      if(c != ' '){
        *txt += c;
        
      }else{
        if(*txt!=""){//se nao estiver vazio
        //cout<<"teste";
          
          if(*ind == 0){
            setaDefinicao(*txt);//seta a definição
             *ind = 1;
          //   cout<<*txt;
            *txt = "";//apaga a variavel para pegar a definição
            
          }else if(*ind == 1){
            setaAtribuicao(*txt);//seta a definição
            //cout<<*txt+"sdssss";
            *txt = "";//apaga a variavel para pegar a definição
            *ind = 2;
          }
         
        }
      }
    }
}

void PreCompilador::setaDefinicao(string def){
  definicao.insert(definicao.begin(),1,def);
}

void PreCompilador::setaAtribuicao(string atr){
  atribuicao.insert(atribuicao.begin(),1,atr);
}

bool PreCompilador::verificaCondicao(string def){
  
   for (string str : definicao) {
    if(str == def){
      return true;
    }
  }
  return false;
}

void PreCompilador::escritaIfs(){
  ofstream escritor;
  escritor.open("codigoPre.c", ios::out);
  escritor << getTextoSup();
  escritor.close();
  limpar();
}

void PreCompilador::trataInclude(char c, string*txtInc, bool*arqinc, bool *txinf, string *txtsal){
    char c2 = c;  
    if((c2 == '>')||(c == '\n')){//chegou ao final da condição
      *arqinc = false;
      
      if(!verificaLista(*txtInc)){
        *txinf = true;
        lista.insert(lista.begin(),1,*txtInc);
        
      }else{
        *txtsal = "";
        *txtInc = "";
      }
     // cout << *txtInc << endl;//------------------------------------------------------
    }else if(c2 != '<' && c2 != '>'){//pega o que esta dentro do include <include>
      if((c2!=' ')&&(c2!='"')){//retira espacos e aspas
        *txtInc += c2;
      }
    }
}

bool PreCompilador::verificaLista(string novoInc){
   for (string str : lista) {
    if(str == novoInc){
      return true;
    }
  }
  return false;
}

void PreCompilador::escritaInclude(){
  //remove("codigoPre.c");
  //cout<<getTextoSup();
  ofstream escritor;
  escritor.open("codigoPre.c", ios::out | ios::trunc);
  escritor << getTextoSup();
  
  if(getArquivoInc()[getArquivoInc().size() -1]!='h'){
    escritor << getArquivoInc();//caso nao seja um arquivo 
  }else{
    setInclusao();//inclui o texto do arquivo a ser incluido
  }
  //cout <<getInclusao();
  escritor << getInclusao();
  escritor << getTextoInf();
  escritor.close();
 // cout<< getInclusao();
 
}

string PreCompilador::getInclusao(){  
  return inclusao;
}

void PreCompilador::setInclusao(){//inclui novo arquivo de texto
  ifstream leitor;
  leitor.open("include/"+getArquivoInc(), ios::in);//arquivo a ser incluido 
  
  if(leitor.is_open()){//verifica se o arquivo esta aberto
    char letra;
    while (!leitor.eof()) {//enquanto nao chegar ao fim do arquivo
      letra = ' ';//limpa para nao repetir o ultimo caractere
      leitor.get(letra);//lê caracter a caracter
      inclusao += letra;
    }
    leitor.close();//fecha o arquivo

    if(getArquivoInc() != ""){
      cout << "Incluindo arquivo "+ getArquivoInc() << endl;
    }
    
  }else{
    ifstream leitor2;
    leitor2.open("lib/gcc/mingw32/9.2.0/include/"+getArquivoInc(), ios::in);//arquivo a ser incluido 
    
    if(leitor2.is_open()){//verifica se o arquivo esta aberto
      char letra2;
        while (!leitor2.eof()) {//enquanto nao chegar ao fim do arquivo
          letra2 = ' ';//limpa para nao repetir o ultimo caractere
          leitor2.get(letra2);//lê caracter a caracter
          inclusao += letra2;
        }
        leitor2.close();//fecha o arquivo

        if(getArquivoInc() != ""){
          cout << "Incluindo arquivo "+ getArquivoInc() << endl;
        }
       // cout << inclusao;
      }else{
         cout << "Não possui o arquivo " << getArquivoInc() << endl;
         inclusao += '\n';
         //inclusao = " #include <"+getArquivoInc()+">";//coloco um espaco para ele nao identificar como include
        //cout << inclusao;
      }
   
  }
}

string PreCompilador::getArquivoInc(){  
  return arquivoInc;
}

void PreCompilador::setArquivoInc(string arq){//inclui novo arquivo de texto
  arquivoInc = arq;
}

string PreCompilador::getTextoSup(){  
  return textoSup;
}

void PreCompilador::setTextoSup(string txts){//inclui novo arquivo de texto
  textoSup = txts;
}

string PreCompilador::getTextoInf(){  
  return textoInf;
}

void PreCompilador::setTextoInf(string txtinf){//inclui novo arquivo de texto
  textoInf = txtinf;
}

char PreCompilador::getVarAnterior(){  
  return varAnterior;
}

void PreCompilador::setVarAnterior(char tx){//inclui novo arquivo de texto
  varAnterior = tx;
}

string PreCompilador::getCondicional(){  
  return condicional;
}

void PreCompilador::setCondicional(string str){//inclui novo arquivo de texto
  condicional = str;
}

void PreCompilador::limpar(){
  textoSup = "";
  textoInf = "";
  inclusao = "";
  arquivoInc = "";
  condicao = "";
}