/*
*Node class inspired by github user rileycr (Riley Cooper)
*
*
*/
#include "Node.h"

Node::Node(Shape *data){
	data_ = data;
}

Node::Node(Node *next, Node *prev){
	next_ = next;
	prev_ = prev;
}

void Node::pointers(Node *next, Node *prev){
	next_ = next;
	prev_ = prev;
}

void Node::draw(){
	data_ -> draw();
}

void Node::move(int pixels){
	return data_ -> move(pixels);
}
//added this method
void Node::moveDown(int pixels){
	return data_ -> moveDown(pixels);
}
//added this method
float Node::getCenterY(){
	return data_ -> getCenterY();
}
/*
*Method from class
*/
void Node::reverse(Node* sentinel){
	Node* current_ = sentinel;
	Node* temp;
	do{
		temp = current_ -> next_;
		current_ -> next_ = current_ -> prev_;
		current_ -> prev_ = temp;
		current_  = temp;
	} while(current_ != sentinel);
}
/*
*method from class
*/
void Node::sendBack(Node* sentinel){
	Node* first = sentinel -> prev_;
	sentinel -> prev_ = sentinel -> prev_ -> prev_;
	sentinel -> prev_ -> next_ = sentinel;

	first -> next_ = sentinel -> next_;
	first -> prev_ = sentinel;

	sentinel -> next_ -> prev_ = first;
	sentinel -> next_ = first;

}
//fixed
/*
*links below 
*http://www.codeproject.com/Articles/24684/How-to-create-Linked-list-using-C-C
*http://stackoverflow.com/questions/4083428/c-linked-list-insert-function
*/
void Node::sendFront(Node* sentinel){
	Node* last = sentinel -> next_;
	
	last -> prev_ -> next_ = last -> next_;
	last -> next_ -> prev_ = last -> prev_;

	last -> next_ = sentinel;
	last -> prev_ = sentinel -> prev_;

	sentinel -> prev_ -> next_ = last;
	sentinel -> prev_ = last;

}
