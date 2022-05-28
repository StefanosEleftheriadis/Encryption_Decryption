#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include<algorithm>

using namespace std;

const char table[6][5]={{'A','B','C','D','E'},{'F','G','H','I','J'},{'K','L','M','N','O'},{'P','Q','R','S','T'},{'U','V','W','X','Y'},{'Z','*','*','*','*'}};
const int MaxRow=50;
const int MaxCol=50;

class encryption{
	public:
		encryption();
		void input();
		void print();
		void codemessage();
		void sort();
	private:
		string key;
		string message;
		string code_message;
		string temp_key;
		char code[MaxRow][MaxCol];
		int rowcount;
		int colcount;
		
};

class decryption{
	public:
		decryption();
		void input();
		void print();
		void decodemessage();
		void desort();
		int convert_chr_int(char chara);
	private:
		string key;
		string enc_message;
		string dec_message;
		string temp_key;
		string sort_key;
		char code[MaxRow][MaxCol];
		char decode[MaxRow][MaxCol];
		int rowcount;
		int colcount;
};

