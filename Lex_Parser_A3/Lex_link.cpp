#include "Lex_link.h"
#include <string>


const int reserve_word_size = 20;


// Searching through reserve words

bool r_list::search(struct r_node* head, string x)
{
    if (head == NULL)
        return false;
    if (x.compare(head->words) == 0)
        return true;
    return search(head->next, x);
}

bool r_list::searchReserveWord(string x)
{

    r_node* current_node;
    current_node = head1;
    bool wrd_exists = false;
    wrd_exists = search(head1, x);
    return wrd_exists;
}

//Constructor for the linked list.
r_list::r_list()
{
    head1 = NULL;
    tail = NULL;
    string p_reserve_words[reserve_word_size] = { "BEGIN", "MODULE", "CONSTANT", "PROCEDURE", "IS", "IF", "THEN", "ELSE", "ELSIF", "WHILE", "LOOP", "FLOAT", "INTEGER", "CHAR", "GET", "PUT", "END", "IN" , "OUT", "INOUT" }; //reserve words
    string temp;
    for (int i = 0; i < reserve_word_size; i++)
    {
        temp = p_reserve_words[i];
        add_word(temp);

    }

}

// Add reserve words
void r_list::add_word(string word)
{
    r_node* tmp = new r_node;
    tmp->words = word;
    tmp->next = NULL;

    if (head1 == NULL)
    {
        head1 = tmp;
        tail = tmp;
    }
    else
    {
        tail->next = tmp;
        tail = tail->next;
    }
}

// Read line
void line_read::add_line(string line_r, int line_number_r)
{
    //cout << line_r << line_number_r << endl;
    line_node* tmp = new line_node;
    tmp->line = line_r;
    tmp->line_number = line_number_r;
    tmp->next = NULL;

    if (head == NULL)
    {
        head = tmp;
        tail = tmp;
    }
    else
    {

        tail->next = tmp;
        tail = tail->next;
    }
}

string line_read::read_line(int x)
{
    string temp;
    line_node* current;
    current = head;

    while (current != nullptr)
    {
        while (current != nullptr) {
            if (current->line_number == x) {
                temp = current->line;
                return temp;
            }

            current = current->next;
        }
        if (current == NULL)
        {
            temp = "eof";
            return temp;
        }
    }


}

