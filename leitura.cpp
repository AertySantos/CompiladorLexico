#include <iostream>
#include <fstream>
#include <list>
#include <string>

using namespace std;

string palavrasReservadas[18] = { "break","char","const","continue","default","do","double","else","float","for","if","int","long","return","string","struct","void","while"};
char espacosBranco[4] = {' ','\n','\t','\b'};
char delimitadores[20] = { ';',',','.','(',')','{','}','=','+','-','/','*','&','!','|','\'','[',']','<','>'};

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

bool checarSeIguaisCaseInsensitive(string str1, string str2) {
	if(str1.length() == str2.length()) {
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

class leitor {
	private:
		string entrada;			//	entrada: texto
		list<string> saida;		//  saida: lista de string
		int i;					//  iterador	
		string buffer;			//  buffer

	public:
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

		bool checarSeEspaco(char ch) {	
			for (char c: espacosBranco) {
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
						buffer.push_back('/"');
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
					if (isalnum(c) || checarSeDelimitador(c) ) {
						buffer.push_back(c);
					}
					else {
						cout << "Erro de caractere invalido: "  << c << endl;
						exit(EXIT_FAILURE);
					}
					
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

						while (!checarSeDelimitador(c)){	// enquanto 'c' nao for delimitador
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
						saida.push_back(maiorPalavraReservada);		// saída recebe maior palavra reservada encontrada
						if (buffer3 != "") {						// se ha algo depois da palavra reservada
							saida.push_back(buffer3);
						}
						saida.push_back(string(1, delimitador));
						limparBuffer();
					}
				}
				else if (isdigit(c) || c == '.') {	// Caso 2: caractere é um dígito
					buffer.push_back(c);
				}
				else if (c == '\"') {	// Caso 3: texto entre aspas duplas
					
					string bufferTexto = "";
					saida.push_back(string(1, c));	// pega primeira aspas duplas
					int iPosAnterior = pegarValorInteiro(i);		// pega valor de i para retorno caso não houver mais aspas duplas
					while (!fimLeitura()) {
						c = lerProxCaracter();
						if (c == '\"') {
							saida.push_back(bufferTexto);
							saida.push_back(string(1, c)); // pega ultima aspas duplas
							break;
						}
						else {
							bufferTexto.push_back(c);
						}
					}
					if (fimLeitura()) {
						saida.push_back(string(1, '/"'));
						i = pegarValorInteiro(iPosAnterior); // Retorna iterador para posicao anterior	
					}
					
				}
				else {					// Caso 4: caractere é um símbolo
					if (!buffer.empty()) {
						saida.push_back(buffer);
					}
					limparBuffer();
					saida.push_back(string(1, c));
				}
			}
		}

		list<string> ler(string nome) {
			entrada = lerArquivo(nome);
			cout << "ENTRADA:\n" << entrada << endl;

			string textoSemComentario = escandimento(entrada);
			cout << "ESCANDIMENTO:\n" << textoSemComentario << endl;

			quebrarEmLexemas(textoSemComentario);
			return saida;
		}
};

/* EXEMPLO DE CHAMADA */
/*
int main() {
	leitor l;
	list<string> lista = l.ler("exemplos/exemplo2.c");

	cout << "SAIDA:\n";
	for (string s : lista) {
		cout << "<" << s << "> ";
	}
}
*/