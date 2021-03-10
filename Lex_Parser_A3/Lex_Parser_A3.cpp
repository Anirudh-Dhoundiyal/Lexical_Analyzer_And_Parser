/*Author : Anirudh Dhoundiyal
* Class CSC 446
* Program: LEX SCANNER
* Date: 02/24/2021

*/
#include "Parser1.h"
#include <iostream>
#include <iomanip>   
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// Gets file name from the linux commandline and sends the line to parser.h
//int main(int argc, char* argv[])
//{
//    if (argc != 2) {
//        cout << "usage:" << argv[0] << "filename" << endl;
//    }
//    else {
//        // initialization
//        pmain(argv[1]);
//    }
//    return 0;
//}
//
int main()
{
	string filename = "one.ada";
	pmain(filename);
		
	 

}
