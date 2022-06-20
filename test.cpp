// g++ -o test.exe test.cpp lexer.hpp lexer.cpp token.hpp token.cpp rules.hpp

#include "token.hpp"
#include "lexer.hpp"

#include <iostream>
#include <fstream>
#include <string>
using std::string;

string get_file_contents(const string &filename);

int main()
{
	Rules rules(
		{"if", "elif", "else", "for", "while", "return", "continue", "break", "import", "as", "struct", "impl", "func", "var", "null"},
		{"int", "float", "string", "bool", "void", "true", "false"},

		{"+", "-", "*", "/", "%", "^", "++", "--", "=", "+=", "-=", "*=", "/=", "%=", "^=", "==", "!=", "<", ">", "<=", ">=", "&&", "||", "!"},

		{"(", ")", "[", "]", "{", "}", ",", ".", ";", ":"});

	string file_name = "test.txt";
	string src = get_file_contents(file_name);

	Lexer lexer(rules, file_name, src);

	Token token;
	do
	{
		token = lexer.next();
		std::cout << token.to_string(src.c_str()) << std::endl;
	} while (!token.type_is(TOKEN_EOF));

	return 0;
}

string get_file_contents(const string &filename)
{
	std::ifstream file(filename);
	string contents;
	string line;
	while (std::getline(file, line))
	{
		contents += line + "\n";
	}
	return contents;
}