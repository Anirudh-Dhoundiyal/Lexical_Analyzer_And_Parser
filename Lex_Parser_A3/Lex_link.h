#ifndef LEX_LINK_H
#define LEX_LINK_H

#include <string>
#include <iostream>
using namespace std;


//Following is a linked list to store and search through the reverse words.
struct r_node
{
	string words;
	r_node* next = NULL;
};

class r_list
{
private:
	r_node* head1, * tail;

public:
	void add_word(string word);

	bool search(struct r_node* head, string x);
	bool searchReserveWord(string x);
	r_list();
};


//Following is a linked list to store and search through the Lines.
struct line_node
{
	string line;
	int line_number;
	line_node* next;
};
class line_read
{
private:
	line_node* head, * tail;

public:
	void add_line(string line_r, int line_number_r);
	line_read() {

		head = NULL;
		tail = NULL;
	}
	string read_line(int x);
};


#endif // !LEX_TABLE_H