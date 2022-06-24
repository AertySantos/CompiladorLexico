#ifndef __LEITOR
#define __LEITOR

#include <fstream>
#include <list>
#include <string>
#include "token.h"

using namespace std;

string palavrasReservadas[18] = { "break","char","const","continue","default","do","double","else","float","for","if","int","long","return","string","struct","void","while" };
char espacosBranco[4] = { ' ','\n','\t','\b' };
char delimitadores[21] = { ';',',','.','(',')','{','}','=','+','-','%','/','*','&','!','|','\'','[',']','<','>' };

string lerArquivo(std::string nomeDoArquivo) {
	string saida;
	char ch;
	fstream fin(nomeDoArquivo, fstream::in);

	while (fin >> noskipws >> ch) {
		saida.push_back(ch);
	}
	fin.close();

	return saida;
}

bool checarSeIguaisCaseInsensitive(string str1, string str2) {
	if (str1.length() == str2.length()) {
		string str1Lower = "";
		string str2Lower = "";
		for (int i = 0; i < str1.length(); i++) {
			str1Lower.push_back(tolower(str1[i]));
			str2Lower.push_back(tolower(str2[i]));
		}
		return str1Lower == str2Lower;
	}
	else {
		return false;
	}
}

int pegarValorInteiro(int a) { // Pegar valor em vez da referência
	string iterador = to_string(a);
	int b = stoi(iterador);
	return b;
}

class Leitor {
private:
	string entrada;			// entrada: texto de entrada
	list<Token> tokens;		// tokens: lista de tokens
	int i;					// iterador: iterar dentro da lista
	string buffer;			// buffer: salvar palavras

public:
	Leitor() {
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

	bool checarSeEspaco(char ch) {
		for (char c : espacosBranco) {
			if (ch == c) {
				return true;
			}
		}
		return false;
	}

	bool checarSeDelimitador(char ch) {
		for (char c : delimitadores) {
			if (ch == c) {
				return true;
			}
		}
		return false;
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
				if (c == '/') {		// Tratar: comentario: '//'
					while (!fimLeitura()) {
						c = lerProxCaracter();
						if (c == '\n') {
							break;
						}
					}
				}
				else if (c == '*') { //	Tratar: comentario:	"/*'
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
					if (!checarSeEspaco(c)) {
						buffer.push_back(c);
					}
				}
			}
			else if (c == '\"') {	// Tratar: texto entre aspas duplas: ""
				string bufferTexto = "";
				bufferTexto.push_back(c);	// pega primeira aspas duplas

				int iPosAnterior = pegarValorInteiro(i);	// pega valor de i para retorno caso não houver mais aspas duplas
				while (!fimLeitura()) {
					c = lerProxCaracter();
					if (c == '\"') {
						bufferTexto.push_back(c); // pega ultima aspas duplas
						buffer.append(bufferTexto);
						break;
					}
					else {
						bufferTexto.push_back(c);
					}
				}
				if (fimLeitura()) {  // uma aspas duplas somente
					buffer.push_back('\"');
					i = pegarValorInteiro(iPosAnterior); // retorna iterador para posicao anterior	
				}
			}
			else if (c == '#') {		// Tratar:  #
				while (!fimLeitura()) {
					c = lerProxCaracter();
					if (c == '\n') {
						break;
					}
				}
			}
			else if (!checarSeEspaco(c)) {
				if (isalnum(c) || checarSeDelimitador(c)) {
					buffer.push_back(c);
				}
				/*else {
					cout << "Erro de caractere invalido: " << c << endl;
					exit(EXIT_FAILURE);
				}*/

			}
		}
		textoSemComentarios.append(buffer);
		return textoSemComentarios;
	}

	bool checarPalavraReservada(string buffer) {
		for (string palavraReservada : palavrasReservadas) {
			if (checarSeIguaisCaseInsensitive(buffer, palavraReservada)) {
				return true;
			}
		}
		return false;
	}

	void quebrarEmLexemas(string texto) {
		entrada = texto;
		char c = 'c';
		buffer = "";
		i = 0;
		Token token;
		while (!fimLeitura()) {
			c = lerProxCaracter();
			if (isalpha(c)) {		// Caso 1: caractere do alfabeto
				buffer.push_back(c);
				if (checarPalavraReservada(buffer)) {	// achou Palavra reservada, continuar procurando
					string maiorPalavraReservada = buffer;	// maior palvra reservada é o buffer inicialmente
					string buffer2 = "";	// buffer da maior palavra reservada
					string buffer3 = "";	// buffer após palavra reservada
					char delimitador = ' ';	// delimitador

					buffer2.append(buffer);	// buffer2 recebe buffer

					while (!checarSeDelimitador(c)) {	// enquanto 'c' nao for delimitador
						c = lerProxCaracter();			// le o proximo char
						if (!checarSeDelimitador(c)) {
							buffer2.push_back(c);			// buffer palavra reservada maior recebe 'c'
							buffer3.push_back(c);			// buffer apos a palavra recebe 'c'
							if (checarPalavraReservada(buffer2)) {		// se palavra reservada maior for encontrada
								maiorPalavraReservada = buffer2;		// maior palavra reservada recebe buffer palavra reservada maior
								buffer3 = "";							// limpa buffer apos palavra 
							}
						}
						else {
							delimitador = c;
						}
					}
	
					token.set('r', maiorPalavraReservada);	// saída recebe maior palavra reservada encontrada
					tokens.push_back(token);
					
					if (buffer3 != "") {						// se ha algo depois da palavra reservada

						bool checarSeIdentificador = false;
						for (char b : buffer3) {
							if (isalpha(b)) {
								checarSeIdentificador = true;
							}
						}
						if (checarSeIdentificador) {
							token.set('i', buffer3);
							tokens.push_back(token);
						}
						else {
							token.set('n', buffer3);
							tokens.push_back(token);
						}
						
					}
					token.set('s',string(1, delimitador));
					tokens.push_back(token);

					limparBuffer();
				}
			}
			else if (isdigit(c) || c == '.') {	// Caso 2: caractere é um dígito
				buffer.push_back(c);
			}
			else if (c == '\"') {	// Caso 3: texto entre aspas duplas
				string bufferTexto = "";
				token.set('s',string(1, c)); // pega primeira aspas duplas
				tokens.push_back(token);

				int iPosAnterior = pegarValorInteiro(i);		// pega valor de i para retorno caso não houver mais aspas duplas
				while (!fimLeitura()) {
					c = lerProxCaracter();
					if (c == '\"') {
						token.set('l', bufferTexto);
						tokens.push_back(token);

						token.set('s',string(1, c));
						tokens.push_back(token);
						break;
					}
					else {
						bufferTexto.push_back(c);
					}
				}
				if (fimLeitura()) {
					token.set('s', string(1, '\"'));
					tokens.push_back(token);

					i = pegarValorInteiro(iPosAnterior); // Retorna iterador para posicao anterior	
				}
			}
			else {					// Caso 4: caractere é um símbolo
				if (!buffer.empty()) {
					
					bool checarSeIdentificador = false;
					for(char b:buffer) {
						if (isalpha(b)) {
							checarSeIdentificador = true;
						}
					}
					if (checarSeIdentificador) {
						token.set('i', buffer);
						tokens.push_back(token);
					}
					else {
						token.set('n', buffer);
						tokens.push_back(token);
					}
				}
				limparBuffer();
				token.set('s', string(1, c));
				tokens.push_back(token);
			}
		}
	}

	list<Token> ler(string nome) {
		entrada = lerArquivo(nome);
		//cout << "ENTRADA:\n" << entrada << endl;

		string textoSemComentario = escandimento(entrada);
		std::cout << "ESCANDIMENTO:\n" << textoSemComentario << endl;

		quebrarEmLexemas(textoSemComentario);
		return tokens;
	}
};
#endif
