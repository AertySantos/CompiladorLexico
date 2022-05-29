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
  
  leituraIfs("codigoPre.c");//verifica os #if,#else,#endif
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
    leitor.open(nomeArquivo, ios::in);//codigo a ser pre-compilado
    
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
      cout << "ERRO: falta #endif "<<endl<< testeIf;
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

void PreCompilador::limpar(){
  textoSup = "";
  textoInf = "";
  inclusao = "";
  arquivoInc = "";
  condicao = "";
}