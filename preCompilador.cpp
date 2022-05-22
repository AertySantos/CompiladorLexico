#include "preCompilador.h"
#include <iostream>
#include<fstream>
using namespace std;

PreCompilador::PreCompilador(){}

void PreCompilador::leitura(){
  
    string texto = "", txt ="", comando = "",localInc = "",condicaoIfs ="";
    string txtInclude = "#include";
    string txtIf = "#if";
    string txtElse = "#else";
    string txtEndif = "#endif";
    bool arquivoInc = false;
    bool arqIf = false;
    
    ifstream leitor;
    leitor.open("codigo.c", ios::in);//codigo a ser pre-compilado
    int i = 0;
  
    if(leitor.is_open()){//verifica se o arquivo esta aberto
      char c;
      bool trata = false;
      
        while (!leitor.eof()) {//enquanto nao chegar ao fim do arquivo
          
                c = ' ';//limpa c, para nao repetir o ultimo caractere
                leitor.get(c);//lê caracter a caracter
                //cout << c;
               
          
                if(c == '#'){//se tem # no codigo fz verificação
                  trata = true;
                }

                if(arquivoInc){//faz tratamento do #include
                  trataInclude(c, &localInc, &arquivoInc);
                }

                if(arqIf){//faz tratamento do #if,#else e #endif
                  trataIf(c, &condicaoIfs, &arqIf);
                }

                if(trata){
                  comando += c;
                  if(comando.size() >= 3 && comando.size()<= 8){
                    if(comando == txtInclude){//identifica um #include
                      arquivoInc = true;
                      localInc = "";
                    }else if(comando == txtIf){//identifica um #if
                      arqIf = true;
                      condicaoIfs = "";
                    }else if(comando == txtElse){//identifica um #else
                      arqIf = true;
                    //  condicaoIfs = "";
                    }else if(comando == txtEndif){//identifica um #endif
                      arqIf = true;
                    //  condicaoIfs = "";
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
    cout << endl<<localInc;//teste
    cout << endl<<condicaoIfs;//teste
    
}

void PreCompilador::trataIf(char c, string*txt, bool*arq){
    char c2 = c;  
    if(c2 == '\n'){ //chegou ao fim da condição
      *arq = false;
     // cout << *txt;
    }else{//pega a condição if
      *txt += c2;
    }
}

void PreCompilador::trataInclude(char c, string*txtInc, bool*arqinc){
    char c2 = c;  
    if(c2 == '>'){//fecha 
      *arqinc = false;
      // cout << *txtInc;
    }else if(c2 != '<' && c2 != '>'){//pega o que esta dentro do include <include>
      *txtInc += c2;
    }
}
