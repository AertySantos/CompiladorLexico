#include "preCompilador.h"
#include <iostream>
#include<fstream>
#include <string>
using namespace std;

PreCompilador::PreCompilador(){
  textoSup = "";//variavel para guardar o texto superior
  inclusao = "";//texto do novo aquivo
  textoInf = "";//variavel para guardar o texto inferior
  arquivoInc = "";//arquivo para acessar
  
}

void PreCompilador::iniciar(){
  
  leituraIfs();
  escritaIfs();
  
  leituraInclude();
  escritaInclude();
  
  cout<<"Pre Compilador executado!";
}

void PreCompilador::leituraInclude(){//verificação dos includers
  
    string texto = "", txt ="", comando = "",localInc = "";
    string txtInclude = "#include";
    bool arquivoInc = false, IncVez = true;
    bool txtSup = true;
    bool txtInf = false;
    
    ifstream leitor;
    leitor.open("codigoPre.c", ios::in);//codigo a ser pre-compilado
    int i = 0;
  
    if(leitor.is_open()){//verifica se o arquivo esta aberto
      char c;
      bool trata = false;
      
        while (!leitor.eof()) {//enquanto nao chegar ao fim do arquivo
          
                c = ' ';//limpa c, para nao repetir o ultimo caractere
                leitor.get(c);//lê caracter a caracter
                //cout << c;
          
                if((c == '#')&&(txtSup)){//se tem # no codigo fz verificação
                  trata = true;
                  txtSup = false;
                }
          
                if(txtSup){
                  setTextoSup(getTextoSup() + c);
                }

                if(txtInf){
                  setTextoInf(getTextoInf() + c);
                }
          
                if(arquivoInc){//faz tratamento do #include
                  trataInclude(c, &localInc, &arquivoInc, &txtInf);
                }

                if(trata){
                  comando += c;
                  if(comando.size() >= 3 && comando.size()<= 8){
                    if(comando == txtInclude){//identifica um #include
                      arquivoInc = true;
                      localInc = "";
                    }
                  }
                  if(comando.size() > 8){
                    trata = false;
                    comando = "";
                  }
                }

            }
      leitor.close();//fecha o arquivo
      }
    
    setArquivoInc(localInc.erase(0,1));
}

void PreCompilador::leituraIfs(){
  
    string texto = "", txt ="", comando = "";
    string txtIf = "#if";
    string txtElse = "#else";
    string txtEndif = "#endif";
    string erro = "";
    bool arqIf = false;
    bool arqElse = false;
    bool txtSup = true;
    bool txtInf = false;
    int testeIf = 1;
    
    ifstream leitor;
    leitor.open("codigo.c", ios::in);//codigo a ser pre-compilado
    
    if(leitor.is_open()){//verifica se o arquivo esta aberto
      char c;
      bool trata = false;
      
        while (!leitor.eof()) {//enquanto nao chegar ao fim do arquivo
          
                c = ' ';//limpa c, para nao repetir o ultimo caractere
                leitor.get(c);//lê caracter a caracter
                //cout << c;
          
                if(c == '#'){//se tem # no codigo fz verificação
                  trata = true;
                  txtSup = false;
                }
          
                if(txtSup){
                  setTextoSup(getTextoSup() + c);
                }

  
                if(arqIf){//faz tratamento do #if,#else e #endif
                  trataIf(c, &condicao, &arqIf, &txtSup, &arqElse);
                }

                if(trata){
                  comando += c;
                  
                  if(comando.size() >= 3 && comando.size()<= 8){
                    if(comando == txtIf){//identifica um #if
                      arqIf = true;
                      trata = false;
                      comando = "";
                      testeIf++;
                      
                    }else if(comando == txtElse){//identifica um #else
                      trata = false;
                      comando = "";
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
                      }
                      //cout << c;
                    }
                  }
                  
                  if(comando.size() > 7){//se for maior que sete carcters guardo o comando
                    trata = false;
                    setTextoSup(getTextoSup() + comando);
                    txtSup = true;
                    comando = "";
                  }
                }

            }
      leitor.close();//fecha o arquivo
      
    }
    
    //cout <<getTextoSup()<<endl;//teste
  
    if(testeIf > 1){
      cout << "ERRO: falta #endif\n";
    }
    cout <<erro<<endl;//teste
    //setCondicao(condicaoIfs.erase(0,1));
    //cout << endl<<condicaoIfs;//teste
    
}

void PreCompilador::trataIf(char c, string*txt, bool*arq, bool*ts, bool*arqelse){
    char c2 = c;  
    if(c2 == '\n'){ //chegou ao fim da condição
      *arq = false;
      *ts = verificaCondicao(*txt);
      *arqelse = !*ts;
      *txt = "";
      
    }else{//pega a condição if
      *txt += c2;
    }
}

bool PreCompilador::verificaCondicao(string str){
  if(str == " defined __USE_XOPEN"){
    if(__USE_XOPEN){
      return true;
    }
  }
  
  if(str == " defined __USE_UNIX98 || defined __USE_XOPEN2K"){
    if(__USE_UNIX98 || __USE_XOPEN2K){
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

void PreCompilador::trataInclude(char c, string*txtInc, bool*arqinc, bool *txinf){
    char c2 = c;  
    if(c2 == '>'){//fecha 
      *arqinc = false;
      *txinf = true;
    }else if(c2 != '<' && c2 != '>'){//pega o que esta dentro do include <include>
      *txtInc += c2;
    }
}

void PreCompilador::escritaInclude(){
  //remove("codigoPre.c");
  //cout<<getTextoSup();
  ofstream escritor;
  escritor.open("codigoPre.c", ios::out | ios::trunc);
  escritor << getTextoSup();
  setInclusao();//inclui o texto do arquivo a ser incluido
  escritor << getInclusao();
  escritor << getTextoInf();
  escritor.close();
 // cout<< getInclusao();
  limpar();
}

string PreCompilador::getInclusao(){  
  return inclusao;
}

void PreCompilador::setInclusao(){//inclui novo arquivo de texto
  ifstream leitor;
  leitor.open(getArquivoInc(), ios::in);//arquivo a ser incluido 
  
  if(leitor.is_open()){//verifica se o arquivo esta aberto
    char letra;
    while (!leitor.eof()) {//enquanto nao chegar ao fim do arquivo
      letra = ' ';//limpa para nao repetir o ultimo caractere
      leitor.get(letra);//lê caracter a caracter
      inclusao += letra;
    }
    leitor.close();//fecha o arquivo
  }else{
    cout << "erro ao abrir o arquivo " << getArquivoInc();
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

void PreCompilador::limpar(){
  textoSup = "";
  textoInf = "";
  inclusao = "";
  arquivoInc = "";
  condicao = "";
}