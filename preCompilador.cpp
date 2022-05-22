#include "preCompilador.h"
#include <iostream>
#include<fstream>
using namespace std;

PreCompilador::PreCompilador(){}

void PreCompilador::leitura(){
  
    string texto = "", txt ="", comando = "";
    string txtInclude = "#include";
    string txtIf = "#if";
    string txtElse = "#else";
    string txtEndif = "#endif";
    
  
    ifstream leitor;
    leitor.open("codigo.c", ios::in);//codigo a ser pre-compilado
    int i = 0;
  
    if(leitor.is_open()){//verifica se o arquivo esta aberto
      char c;
      bool trata = false;
      
        while (!leitor.eof()) {//enquanto nao chegar ao fim do arquivo
          
                c = ' ';//limpa c, para nao repetir o ultimo caractere
                leitor.get(c);//lê caracter a caracter
                cout << c;
               
          
                if(c == '#'){//se tem # no codigo fz verificação
                  trata = true;
                }

                if(trata){
                  comando += c;
                  if(comando.size() >= 3 && comando.size()< 8){
                    if(comando == txtInclude){
                     // cout<<"tem include";
                    }else if(comando == txtIf){
                     // cout<<"tem if";
                    }else if(comando == txtElse){
                     // cout<<"tem else";
                    }else if(comando == txtEndif){
                      //cout<<"tem iendif";
                    }
                  }
                  if(comando.size() >= 8){
                    trata = false;
                    comando = "";
                  }
                }
              
            }
      leitor.close();//fecha o 
      }
    
    
}
