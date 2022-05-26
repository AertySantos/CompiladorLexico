#include <iostream>
#include <fstream>
#include <list>
#include <string>

using namespace std;

string palavrasReservadas[17] = { "break","char","const","continue","default","double","else","float","for","if","int","long","return","struct","void","while"};
char espacosBranco[4] = {' ','\n','\t','\b'};

string lerArquivo(std::string nomeDoArquivo) {
	string saida;
	char ch;
	fstream fin(nomeDoArquivo, fstream::in);

	while(fin >> noskipws >> ch){
		saida.push_back(ch);
	}
	fin.close();

	return saida;
}

class leitor {
	public:
		string entrada;			//	entrada: texto
		list<string> saida;		//  saida: lista de string
		int i;					//  iterador	
		string buffer;			//  buffer

		leitor() {
			i = 0;
			buffer = "";
		}

		void limparBuffer() {
			buffer = "";
		}

		char lerProxCaracter() {
			char c = ' ';
			if (i < entrada.size()) {
				c = entrada[i];
				i++;
			}
			return c;
		}

		bool fimLeitura() {
			return i == entrada.size();
		}

		bool checarSeNaoEspaco(char ch) {	
			for (char c: espacosBranco) {
				if (ch == c) {
					return false;
				}
			}
			return true;
		}

		string escandimento(string texto) {
			string textoSemComentarios = "";
			char c = 'c';
			buffer = "";
			i = 0;

			while (!fimLeitura()) {	
				c = lerProxCaracter();
				if (c == '/') {
					c = lerProxCaracter();
					if (c == '/') {		// Tratar comentario: '//'
						while (!fimLeitura()) {
							c = lerProxCaracter();
							if (c == '\n') {
								break;
							}
						}
					}
					else if (c == '*') { //	Tratar comentario:	"/*'
						while (!fimLeitura()) {
							c = lerProxCaracter();
							if (c == '*') {
								c = lerProxCaracter();
								if (c == '/') {
									break;
								}
							}
						}
					}
					else {
						buffer.push_back('/');
						if (checarSeNaoEspaco(c)) {
							buffer.push_back(c);
						}
					}
				}
				else if (c == '\"') {	// Tratar texto entre aspas duplas: ""
					buffer.push_back(c);
					c = lerProxCaracter();
					buffer.push_back(c);
					while (!fimLeitura()) {
						c = lerProxCaracter();
						if (c == '\"') {
							buffer.push_back(c);
							break;
						}
						else {
							buffer.push_back(c);
						}
					}
					if (fimLeitura()) {  // uma aspas duplas somente
						limparBuffer();
						buffer.push_back(c);
						// falta retornar iterador para posicao anterior
					}
					
				}
				else if (checarSeNaoEspaco(c)) {
					buffer.push_back(c);
				}
			}
			textoSemComentarios.append(buffer);
			return textoSemComentarios;
		}

		void checarPalavraReservada(string buffer) {
			for (string palavraReservada : palavrasReservadas) {
				if (buffer != "" && buffer == palavraReservada) {
					saida.push_back(buffer);
					limparBuffer();
					break;
				}
			}
		}

		void quebrarEmLexemas(string texto) {
			entrada = texto;
			char c = 'c';
			buffer = "";
			i = 0;
			
			while (!fimLeitura()) {
				c = lerProxCaracter();

				// alfanumerico
				if (isalnum(c) || c == '.') {	
					buffer.push_back(c);
					checarPalavraReservada(buffer);
				}
				// texto entre aspas
				else if (c == '\"') {			
					buffer.push_back(c);
					while (!fimLeitura()) {			
						c = lerProxCaracter();
						if (c == '\"') {
							buffer.push_back(c);
							break;
						}
						else {
							buffer.push_back(c);
						}
					}
				}
				// nem alfanumerico nem texto entre aspas
				else {							
					if (!buffer.empty()) {
						saida.push_back(buffer);
					}
					limparBuffer();

					string s;
					s.push_back(c);
					saida.push_back(s);
				}
			}
		}

		list<string> ler(string nome) {
			entrada = lerArquivo(nome);
			//cout << "ENTRADA:\n" << entrada << endl;
			string textoSemComentario = escandimento(entrada);
			//cout << "ESCANDIMENTO:\n" << textoSemComentario << endl;
			quebrarEmLexemas(textoSemComentario);
			/*
			cout << "\nLEXEMAS:\n";
			for (string s : saida) {
				cout << "<" << s << ">" << endl;
			}
			*/
			return saida;
		}
};

/* EXEMPLO DE CHAMADA */
/*
int main() {
	leitor l;
	list<string> lista = l.ler("exemplo.c");
}
*/
