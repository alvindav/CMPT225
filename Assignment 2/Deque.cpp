/*
 * Deque.cpp
 *
 *  Created on: Feb 21, 2018
 *      Author: Alvin
 */

#include "Deque.h"
#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;


/* Constructors and Destructor */
Deque::Deque():left_p(NULL),right_p(NULL),cursor(NULL),current_size(0){}

Deque::Deque( const Deque& dq ):left_p(NULL),right_p(NULL),cursor(NULL),current_size(0){
	//creates a deep copy of Deque& dq
	if(dq.current_size == 0)
		return;

	node * tempCursor = dq.left_p;
	int tempData;
	while(tempCursor != NULL){
		tempData = tempCursor->data;
		push_right(tempData);

		if(tempCursor == dq.cursor)
			cursor = right_p;

		tempCursor = tempCursor->next;
	}
}

Deque::~Deque(){
	//delete all nodes of the deque starting from the left
	cursor = left_p;
	node * toDelete;
	while(cursor){
		toDelete = cursor;
		cursor = cursor->next;
		delete toDelete;
	}
}

/* Insertion operators */
void Deque::push_left( int item ){
	left_p = new node(item, NULL, left_p);
	if(empty()){
		right_p = left_p;
		cursor = left_p;
	}
	else{
		left_p->next->prev = left_p;
	}
	current_size++;
}
void Deque::push_right( int item ){
	right_p = new node(item, right_p, NULL);
	if(empty()){
		left_p = right_p;
		cursor = right_p;
	}
	else{
		right_p->prev->next = right_p;
	}
	current_size++;
}

/* Removal operators */
int Deque::pop_left(){
	node * old_left = left_p; //create pointer to left_p
	int old_data = left_p->data; //store data within left_p

	if(size() == 1){
		left_p = NULL;
		right_p = NULL;
		cursor = NULL;
	}
	else if(size() > 1){
		left_p = left_p->next;
		left_p->prev = NULL;
		if(cursor == old_left)
			cursor = left_p;
	}

	current_size--;
	delete old_left;
	return old_data;
}

int Deque::pop_right(){
	node * old_right = right_p; //create pointer to right_p
	int old_data = old_right->data; //store data within right_p

	if(current_size == 1){
		right_p = NULL;
		left_p = NULL;
		cursor = NULL;
	}
	else if(current_size > 1){
		right_p = old_right->prev;
		right_p->next = NULL;
		if(cursor == old_right)
			cursor = right_p;
	}

	current_size--;
	delete old_right;
	return old_data;
}

/* Size functions */
bool Deque::empty(){
	//returns false iff current_size > 0
	//returns true iff current_size == 0
	return current_size == 0;
}
int Deque::size(){
	return current_size;
}

/* Cursor movement operators*/
bool Deque::cursor_left(){
	//returns false if cursor->prev == NULL OR deque is empty
	//otherwise returns true
	bool possible = false;
	if( !( empty() ) ){
		if(!(cursor->prev == NULL)){
			cursor = cursor->prev;
			possible = true;
		}
	}
	return possible;
}
bool Deque::cursor_right(){
	//returns false if cursor->next == NULL OR deque is empty
	//otherwise returns true
	bool possible = false;
	if( !(empty()) ){
		if(!(cursor->next == NULL)){
			cursor = cursor->next;
			possible = true;
		}
	}
	return possible;
}

/* Accessor functions */
int Deque::peek_left(){
	return left_p->data;
}
int Deque::peek_right(){
	return right_p->data;
}
int Deque::get_cursor(){
	return cursor->data;
}

void Deque::set_cursor(int i){
	//set_cursor takes the node cursor is pointing to, and changes the data
	cursor->data = i;
}

/* Utility functions */
void Deque::display(){
	//displays content of list of nodes
	node * display_cursor = left_p; //start at left
	if(empty()){
		cout << "[] size=0, cursor=NULL." << endl;
		return;
	}
	cout << "[";
	while(display_cursor != NULL){
		cout << display_cursor->data << ";";
		display_cursor = display_cursor->next;
	}
	cout << "] size=" << current_size << ", cursor=" << get_cursor() <<"." << endl;
}
void Deque::verbose_display(){
	//verbose display uses the display function
	//also displays node addresses
	this->display();
	node * display_cursor = left_p; //start at left
	cout << "NODE           PREVIOUS        NEXT" << endl;
	display_cursor = left_p; //start at left
	while(display_cursor != NULL){
		cout << display_cursor << "     " << setw(9);
		cout << display_cursor->prev << "        ";
		cout << display_cursor->next;
		cout << endl;
		display_cursor = display_cursor->next;
	}
	cout << endl << endl;
}


