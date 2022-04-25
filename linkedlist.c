#include "linkedlist.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
//ATTENTION: Taken from Koç university Comp 201 Lab 5 

int LinkedList_remove_value(LinkedList* l, int value){
	int a=-1;
	int i;
	Node *number= l->root;

	for(i=0; i<LinkedList_length(l); i++){//to find the element number 	
		if (number->content==value){		
			a=i;
		}
	number=number->next;
	}

	if(a==0){//if in the begining
		Node* current = l->root;
		l->root=l->root->next;
		free(current);
		current=NULL;
		return a;	
	}else if(a==(i-1)){//ending 
		Node* current=l->root;
		while(current->next->next !=NULL){
		current= current->next;
		}
		free(current->next);
		current->next= NULL;	
		return a;
	
	}else{//middle
		int j;
		Node* current=l->root;
		for(j=0; j<i; j++){
			if(j==a-1){
			Node* mid =current->next;
		 	current->next=current->next->next;
			free(mid);
			mid = NULL;
			j++;		
			}else{
			current= current->next;
			}
		}	
		return a;
	
	}

    return -1;
}

void LinkedList_init(LinkedList* l, int* arr, int len){
    l->root = NULL; 
    int i;
    for(i=0;i<len;i++){
        LinkedList_insert(l, arr[i]);
    }
} 

int LinkedList_length(LinkedList* l){
    if(l->root == NULL){
        return 0;
    }else{
        int count = 1;
        Node* current = l->root;
        while(current->next != NULL){
            current = current->next;
            count++;
        }
        return count;
    }
}

int LinkedList_remove(LinkedList* l){
    int value = -1;
    if(l->root == NULL){
        return value;
    }else if(l->root->next == NULL){
        value = l->root->content;
        free(l->root);
        l->root = NULL;
        return value;
    }else{
        Node* current = l->root;
        while(current->next->next != NULL){
            current = current->next;
        }
        value = current->next->content;
        free(current->next);
        current->next = NULL;
        return value;
    }
}

void LinkedList_insert(LinkedList* l, int value){
    Node* n = malloc(sizeof(Node));
    n->content = value;
    n->next = NULL;

    if(l->root == NULL){
        l->root = n;
    }else{
        Node* current = l->root;
        while(current->next != NULL){
            current = current->next;
        }
        current->next = n;
    }
}

char* LinkedList_to_string(LinkedList* l, char* str){
    strcat(str, "[ ");
    Node* current = l->root;
    if(current != NULL){
        do{
            char temp[10]  = "";
            sprintf(temp, "%d ", current->content);
            strcat(str, temp);
            current = current->next;
        }while(current != NULL);
    }
    strcat(str, "]");
    return str;
}

