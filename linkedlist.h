#include "node.h"
//ATTENTION: Taken from Koç university Comp 201 Lab 5 
typedef struct LinkedList
{
    Node* root;
} LinkedList;

void LinkedList_init(LinkedList* l, int* arr, int len);

int LinkedList_length(LinkedList* l);

int LinkedList_remove(LinkedList* l); 

void LinkedList_insert(LinkedList* l, int value); 

int LinkedList_remove_value(LinkedList* l, int value);  

char* LinkedList_to_string(LinkedList* l, char* str);
