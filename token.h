#ifndef __TOKEN
#define __TOKEN

#include<string>
using namespace std;

class Token {
private:
	char nome_token;
	string valor_token;
public:
	Token() {
		nome_token = ' ';
		valor_token =  " ";
	}

	Token(char nome, string valor) {
		nome_token = nome;
		valor_token = valor;
	}

	void set(char nome, string valor) {
		nome_token = nome;
		valor_token = valor;
	}

	char getNome() {
		return nome_token;
	}

	string getValor() {
		return valor_token;
	}
};

#endif
