#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <string>
#include <iostream>
#include <sstream>      
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;
char ch;
string lexema;
string literal;
void upper(string& x);
bool isaalpha();
bool isaspace();
bool isanumber();
bool isaoperator();
bool isaaddop();
bool isamulop();
bool isaseprator();
bool lexisanumber();
bool lexisaoperator();
bool lexisaaddop();
bool lexisamulop();
bool lexisaseprator();
bool lexisassignop();
bool isNumber(string s);


bool isNumber(string s)
{
	for (int i = 0; i < s.length(); i++)
		if (isdigit(s[i]) == false)
			return false;

	return true;
}
void upper(string& x)
{
	for (int i = 0; x[i] != '\0'; i++)
		x[i] = toupper(x[i]);
}

bool isaalpha()
{
	if (ch >= 'A' && ch <= 'Z') {
		return true;

	}

	return false;
}
bool isaspace()
{
	if (ch == ' ' || ch == '\t')
	{
		return true;
	}
	return false;
}
bool isanumber()
{
	if ((ch >= '0' && ch <= '9') == false) {
		return false;
	}
	return true;
}

bool isaoperator()
{
	string operators[6] = { "=", "/=", "<", "<=" ,">", ">=" };
	string temp_ch;
	temp_ch += ch;
	for (int i = 0; i < 6; i++) {
		if (temp_ch == operators[i]) {
			return true;
		}
	}
	return false;
}
bool isaaddop()
{
	string addop[3] = { "+", "-", "OR" };
	string temp_ch;
	temp_ch += ch;
	for (int i = 0; i < 3; i++) {
		if (temp_ch == addop[i]) {
			return true;
		}
	}
	return false;
}
bool isamulop()
{
	string mulop[5] = { "*", "/", "REM", "MOD", "AND" };
	string temp_ch;
	temp_ch += ch;
	for (int i = 0; i < 5; i++) {
		if (temp_ch == mulop[i]) {
			return true;
		}
	}
	return false;
}
bool isaseprator()
{
	string seprator[7] = { "(", ")", ",", ":", ";", "\"", "." };
	string temp_ch;
	temp_ch += ch;
	for (int i = 0; i < 7; i++) {
		if (temp_ch == seprator[i]) {

			return true;
		}
	}
	return false;
}



bool lexisanumber()
{
	string temp_num;
	temp_num = lexema;
	temp_num.erase(remove(temp_num.begin(), temp_num.end(), '.'), temp_num.end());
	if (isNumber(temp_num))
		return true;



	return false;

}

bool lexisaoperator()
{
	string operators[6] = { "=", "/=", "<", "<=" ,">", ">=" };
	if (lexema.size() == 0) return false;
	for (int i = 0; i < 6; i++) {
		if (lexema == operators[i]) {

			return true;
		}
	}
	return false;
}

bool lexisaaddop()
{
	string addop[3] = { "+", "-", "OR" };
	if (lexema.size() == 0) return false;
	for (int i = 0; i < 3; i++) {
		if (lexema == addop[i]) {
			return true;
		}
	}
	return false;
}

bool lexisamulop()
{
	string mulop[5] = { "*", "/", "REM", "MOD", "AND" };
	if (lexema.size() == 0) return false;
	for (int i = 0; i < 5; i++) {
		if (lexema == mulop[i]) {
			return true;
		}
	}
	return false;
}
bool lexisaseprator()
{
	string seprator[7] = { "(", ")", ",", ":", ";", "\"", "." };
	if (lexema.size() == 0) return false;
	for (int i = 0; i < 7; i++) {
		if (lexema == seprator[i]) {
			return true;
		}
	}
	return false;
}
bool lexisassignop()
{
	string assignop[1] = { ":=" };
	if (lexema.size() == 0) return false;
	for (int i = 0; i < 1; i++) {
		if (lexema == assignop[i]) {
			return true;
		}
	}
	return false;
}

























#endif // FUNCTIONS_H
