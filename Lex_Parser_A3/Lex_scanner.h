/*Author : Anirudh Dhoundiyal
* Class CSC 446
* Program: LEX SCANNER
* Date: 02/08/2021

*/
#ifndef LEX_SCANNER_H
#define LEX_SCANNER_H

#include "Lex_link.h"
#include "Functions.h"
#include <iostream>
#include <iomanip>   
#include <fstream>
#include <string>
#include <vector>


typedef enum  { BEGINt, MODULEt, CONSTANTt, PROCEDUREt, ISt, IFt, THENt, ELSEt, ELSIFt, WHILEt, LOOPt, FLOATt, INTEGERt, CHARt, GETt, PUTt, ENDt, INt, OUTt, INOUTt, NUMt, ADDOPt, MULOPt, ASSIGNOPt, OPERATORt, IDENTIFERt, LITERALt, OPENt, CLOSEt, COMMAt, COLONt, SEMICOLONt, QUOTEt, PERIODt, unknownt, EOFt, EQUALt, LINEt  }symbol;
r_list reserve_words;
line_read lines;
void lex_main(string program_name);
void read_program(string program_name);
void getpline(int x);
void getnextch(string temp, int pos);
void getNextToken(string temp);
void processLiteral();
void processLexema();
vector<symbol> return_tokenvector();





//Global Variables

string temp;
int line_number;
int value;
double valueR;
symbol token;
int pos = 0;
int line_count = 1;
vector <symbol>tokenvec;
vector <string> pro_end_vector;


void lex_main(string program_name)
{



    read_program(program_name);
    while (temp != "eof")
    {
        pos = 0;
        getpline(line_count++);
        token = LINEt;
        tokenvec.push_back(token);
        getNextToken(temp);

    }
  
}
vector<symbol> return_tokenvector()
{
    return tokenvec;
}

void read_program(string program_name)
{
    string line;
    int line_count = 0;
    ifstream program;
    program.open(program_name);
    if (program.is_open())
    {

        while (getline(program, line))
        {
            upper(line);
            line_count++;
            lines.add_line(line, line_count);
        }

    }
    else if (program.fail())
    {
        cout << "Error in opening file." << endl << "Restart!" << endl;
    }
    program.close();

}

void getpline(int x)
{
    temp = lines.read_line(x);
}


void getNextToken(string temp) {


    int str_size = temp.size();

    if (temp == "eof")
    {
        cout << "This is the end!" << endl;
        token = EOFt;
        tokenvec.push_back(token);

    }

    else
    {
        getnextch(temp, pos);

        for (int i = 0; i < str_size; i++)
        {


            if (isaalpha() || ch == '_')
            {
                lexema += ch;
                pos++;
                 getNextToken(temp);

            }
            else if (isaspace())
            {
                processLexema();

                lexema.clear();
                pos++;
                getNextToken(temp);
            }
            else if (isaseprator())
            {
                processLexema();
                lexema.clear();
                
                if (ch == '.')
                {
                    lexema += "0";
                    lexema += ch;
                    getnextch(temp, pos + 1);
                    while (isanumber())
                    {
                        pos++;
                        if (isanumber())
                        {
                            lexema += ch;
                            pos++;
                            getnextch(temp, pos);
                        }

                    }
                }
                else if (ch == ':')
                {
                    lexema += ch;
                    getnextch(temp, pos + 1);
                    if (ch == '=')
                    {
                        lexema += ch;
                        pos++;

                    }
                    processLexema();
                    lexema.clear();
                    pos++;
                    getNextToken(temp);


                }
                else if (ch == '"')
                {
                    literal += ch;
                    getnextch(temp, pos + 1);
                    while (ch != '"' && ch != '\0')
                    {
                        pos++;
                        getnextch(temp, pos);
                        literal += ch;
                        if (ch == '\0')
                        {
                            pos--;
                        }

                    }
                    processLiteral();
                    literal.clear();
                    pos++;
                    getNextToken(temp);

                }
                else
                {
                    lexema += ch;
                    processLexema();
                    lexema.clear();
                    pos++;
                    getNextToken(temp);
                }
            }
            else if (isaoperator())
            {
                processLexema();
                lexema.clear();
                lexema += ch;

                if (ch == '<' || ch == '>')
                {
                    getnextch(temp, pos + 1);
                    if (ch == '=')
                    {
                        lexema += ch;
                        pos++;
                    }

                }
                processLexema();
                lexema.clear();
                pos++;
                getNextToken(temp);

            }
            else if (isamulop())
            {
                processLexema();
                lexema.clear();
                lexema += ch;
                if (ch == '/')
                {
                    getnextch(temp, pos + 1);
                    if (ch == '=')
                    {
                        lexema += ch;
                        pos++;
                    }

                }
                processLexema();
                lexema.clear();
                pos++;
                getNextToken(temp);

            }
            else if (isaaddop())
            {
                processLexema();
                lexema.clear();
                if (ch == '-')
                {
                    getnextch(temp, pos + 1);
                    if (ch == '-')
                    {
                        return;

                    }
                    else
                    {
                        getnextch(temp, pos);

                    }

                }
                lexema += ch;
                processLexema();
                lexema.clear();
                pos++;
                getNextToken(temp);

            }
            else if (isanumber())
            {
                if (lexema[0] >= 'A' && lexema[0] <= 'Z')
                {
                    lexema += ch;
                    pos++;
                    getNextToken(temp);
                }
                else
                {


                    processLexema();
                    lexema.clear();
                    lexema += ch;
                    while (isanumber() || ch == '.')
                    {
                        getnextch(temp, pos + 1);
                        if (isanumber() || ch == '.')
                        {
                            lexema += ch;
                            pos++;
                        }

                    }

                    processLexema();
                    lexema.clear();
                    pos++;
                    getNextToken(temp);


                }
            }
            else
            {
                processLexema();
                lexema.clear();
            }


        }


    }

    pos = 0;
    return;
}
void getnextch(string temp, int pos)
{

    ch = temp[pos];
}
void processLiteral()
{
    if (literal != "\0")
    {
        if (literal.back() == '\"' && literal.front() == '\"' && literal != "\"")
        {
            cout << setw(5) << "Token" << setw(30) << literal << "          Is a Literal" << endl;
             token = LITERALt;
             tokenvec.push_back(token);
        }
        else
        {
            cout << setw(5) << "Literal" << setw(30) << literal << "         Is ilegal literal" << endl;
            token = unknownt;
            tokenvec.push_back(token);
        }
    }
}

void processLexema()
{
    if (lexema.size() > 17)
    {
        token = unknownt;
            tokenvec.push_back(token);
    }

    else if (lexema != "\0")
    {

        if (lexisaseprator())
        {
            string lseprator[7] = { "(", ")", ",", ":", ";", "\"", "." };
            for (int i = 0; i < 7; i++)
            {
                if (lexema == lseprator[i])
                {
                    int tk = i + 27;
                    token = (symbol)tk;
                    tokenvec.push_back(token);
                    cout << setw(5) << "Token" << setw(30) << lexema << "          Is a Seprator" << endl;
                }

            }
            
            
        }
        else if (lexisassignop())
        {
            cout << setw(5) << "Token" << setw(30) << lexema << "          Is an Assignop" << endl;
            token = ASSIGNOPt;
            tokenvec.push_back(token);
        }
        else if (lexisamulop())
        {
            cout << setw(5) << "Token" << setw(30) << lexema << "          Is a Mulop" << endl;
            token = MULOPt;
            tokenvec.push_back(token);
        }
        else if (lexisaaddop())
        {
            cout << setw(5) << "Token" << setw(30) << lexema << "          Is an Addop" << endl;
            token = ADDOPt;
            tokenvec.push_back(token);
        }
        else if (lexisaoperator())
        {
            cout << setw(5) << "Token" << setw(30) << lexema << "          Is an Operator" << endl;
            token = OPERATORt;
            tokenvec.push_back(token);
        }
        else if (lexisanumber())
        {



            size_t found;
            found = lexema.find('.');
            if (found != string::npos)
            {
                valueR = stod(lexema);
                token = NUMt;
                tokenvec.push_back(token);
                cout << setw(5) << "Token" << setw(30) << lexema << "          Is a Double" << "With valueR  " << valueR << endl;
            }
            else
            {
                value = stoi(lexema);
                token = NUMt;
                tokenvec.push_back(token);
                cout << setw(5) << "Token" << setw(30) << lexema << "          Is a Number" << "With value:  " << value << endl;
            }


        }
        else if (reserve_words.searchReserveWord(lexema))
        {
            string p_reserve_words[20] = { "BEGIN", "MODULE", "CONSTANT", "PROCEDURE", "IS", "IF", "THEN", "ELSE", "ELSIF", "WHILE", "LOOP", "FLOAT", "INTEGER", "CHAR", "GET", "PUT", "END", "IN" , "OUT", "INOUT" }; //reserve words
            for (int i = 0; i < 19; i++)
            {
                if (lexema == p_reserve_words[i])
                {
                    token = (symbol)i;
                    tokenvec.push_back(token);

                }

            }
            cout << setw(5) << "Token" << setw(30) << lexema << "          Is a Reserved Word" << endl;
        }
        else if (!reserve_words.searchReserveWord(lexema) && !lexisanumber() && !lexisaoperator() && !lexisaaddop() && !lexisamulop() && !lexisaseprator() && !lexisassignop())
        {   
            if (tokenvec.back() == PROCEDUREt)
            {
                pro_end_vector.push_back(lexema);
            }

            else if (tokenvec.back() == ENDt)
            {
                pro_end_vector.push_back(lexema);
            }
            cout << setw(5) << "Token" << setw(30) << lexema << "          Is an Identifer" << endl;
            token = IDENTIFERt;
            tokenvec.push_back(token);
        }


    }



}

#endif
