#ifndef PARSER1_H
#define PARSER1_H
#include "Lex_scanner.h"
#include <iostream>
#include <iomanip>   
#include <fstream>
#include <string>
#include <vector>
// Function Defination
void pmain(string);
void programmer();
bool matchtoken(symbol);
void args();
void argslist();
void mode();
void declarativepart();
void SequenceOS();
void identiferlist();
void typemark();
void moreargs();
void errorfun();
void proendtest();
void valuecheck();
void eoffun();
//Golbal Varialbes
vector <symbol> ptokenvector;
int tokenpos = 0;
int linenum = 1;
int proendernum = 1;
bool match = false;
typedef enum{procedute_er, is_er, id_er, begin_er, end_er, semicolon_er, pro_end_er, num_er}error;
error error_tk;

void pmain(string file) {
	lex_main(file);
	ptokenvector = return_tokenvector();
	proendtest();
	programmer();
	eoffun();
}
/*This function implements the following grammer.
Programmer-> procedure idt Args is
DeclarativePart
Procedures
begin
SeqOfStatements
end
idt*/
void programmer()
{
	
	if (matchtoken(PROCEDUREt))
	{
					
			if (matchtoken(IDENTIFERt))
			{
				args();
				if (matchtoken(ISt))
				{
					declarativepart();
					while(ptokenvector[tokenpos] == PROCEDUREt )
					{
						programmer();
					}
					if (matchtoken(BEGINt))
					{
						SequenceOS();
						if (matchtoken(ENDt))
						{
								if (matchtoken(IDENTIFERt))
								{	
									if (matchtoken(SEMICOLONt))
									{

									}
									else
									{
										error_tk = semicolon_er;
										errorfun();
									}
								}
								else
								{
									error_tk = id_er;
									errorfun();
								}
						}
						else
						{
							error_tk = end_er;
							errorfun();
						}
					}
					
				}
				else
				{
					error_tk = is_er;
					errorfun();
				}
			}
			else
			{
				error_tk = id_er;
				errorfun(); 
			}
			

	}
	else
	{
		error_tk = procedute_er;
		errorfun();
	}

}
// Matches existing token to the desired token
bool matchtoken(symbol a)
{
	if (ptokenvector[tokenpos] == a)
	{
		tokenpos++;
		while (ptokenvector[tokenpos] == LINEt)
		{
			tokenpos++;
			linenum++;
		}
		return true;

	}
	else if(ptokenvector[tokenpos] == LINEt)
	{
		tokenpos++;
		while (ptokenvector[tokenpos] == LINEt)
		{
			tokenpos++;
			linenum++;
		}
		matchtoken(a);
	}
	else
	{
		return false;
	}

}
/*This function implements the following grammer.
* Args->( ArgList ) | empty
*/
void args()
{
	if (matchtoken(OPENt))
	{
		argslist();
		if (matchtoken(CLOSEt))
		{

		}
		else
		{

		}
	}
	else
	{
		
	}
}

/*This function implements the following grammer.
ArgList-> 
Mode
IdentifierList
match(:)
TypeMark
MoreArgs
*/
void argslist()
{
	mode();
	identiferlist();
	if (matchtoken(COLONt))
	{
		typemark();
		moreargs();
	}
	
}

void mode()
{
	switch (tokenvec[tokenpos])
	{
		
	case INt:
		matchtoken(INt);
		break;
	case OUTt:
		matchtoken(OUTt);
		break;
	case INOUTt:
		matchtoken(INOUTt);
		break;
	default:
		break;
	}
}
void declarativepart()
{
	if (matchtoken(IDENTIFERt))
	{
		identiferlist();

	}
	if (matchtoken(COLONt))
	{
		typemark();
		if (matchtoken(SEMICOLONt))
		{
			declarativepart();
		}
	}


}
// does not check for anything.
void SequenceOS()
{
	while (ptokenvector[tokenpos] != ENDt)
	{
		tokenpos++;
	}

}
/*This function implements the following grammer.
identiferlist ->
idt|
identiferList
idt
*/
void identiferlist()
{
	if (matchtoken(IDENTIFERt))
	{
		identiferlist();
	}
	if (matchtoken(COMMAt))
	{
		
		if (matchtoken(IDENTIFERt))
		{
			identiferlist();
		}
	}
	
}

// checks for typemarks
inline void typemark()
{
	switch (ptokenvector[tokenpos])
	{
	case INTEGERt:
		matchtoken(INTEGERt);
		break;
	case CHARt:
		matchtoken(CHARt);
		break;
	case FLOATt:
		matchtoken(FLOATt);
		break;
	case CONSTANTt:
		matchtoken(CONSTANTt);
		matchtoken(ASSIGNOPt);
		valuecheck();
		break;

	default:
		break;
	}
}
/*This function implements the following grammer.
MoreArgs->
match(;)

ArgList | empty
*/
inline void moreargs()
{
	if (matchtoken(SEMICOLONt))
	{
		argslist();
	}
	
}

inline void errorfun()
{
	
	switch (error_tk)
	{

	case procedute_er:
		cout << "On line: " << linenum << "Expected a procedure" << endl;
		break;
	case is_er:
		cout << "On line: " << linenum << "Expected a is" << endl;
		break;
	case id_er:
		cout << "On line: " << linenum << "Expected a identifer" << endl;
		break;
	case begin_er:
		cout << "On line: " << linenum << "Expected a begin" << endl;
		break;
	case end_er:
		cout << "On line: " << linenum << "Expected a end" << endl;
		break;
	case semicolon_er:
		cout << "On line: " << linenum << "Expected a semicolon" << endl;
		break;
	case pro_end_er:
		cout << "The " << proendernum << " precedure and end identifer do not match" << endl;
		cout << "Corresponding procedure and end idetifers should match." << endl;
		break;
	case num_er:
		cout << "On line: " << linenum << "Expected a number or a real" << endl;
	default:
		break;
	}
	exit(0);
}

inline void proendtest()
{	/*
	TEST
	for (int i = 0; i < pro_end_vector.size(); i++)
	{
		cout << pro_end_vector.at(i);
	}*/
	string tempone;
	string temptwo;
	int pe_pos = 1;
	tempone = pro_end_vector.front();
	temptwo = pro_end_vector.back();

	if (tempone == temptwo)
	{
		proendernum++;
		while (pe_pos < pro_end_vector.size() - 1)
		{
			tempone = pro_end_vector.at(pe_pos);
			temptwo = pro_end_vector.at(pe_pos + 1);

			if (tempone == temptwo)
			{
				proendernum++;
				pe_pos = pe_pos + 2;
				
			}
			else
			{
				pe_pos = pe_pos + 2;
				error_tk = pro_end_er;
				errorfun();
			}
		}
	}
	else
	{
		error_tk = pro_end_er;
		errorfun();
	}
}

inline void valuecheck()
{
	if (matchtoken(NUMt))
	{

	}
	else
	{
		error_tk = num_er;
		errorfun();
	}
}
// Checks for EOFt
void eoffun()
{
	if (ptokenvector[tokenpos] == EOFt)
	{
		cout << "Parsed sucessfully" << endl;
	}
	else
	{
		cout << "Unexpected token found instead of EOFt" << endl;
	}
}


#endif