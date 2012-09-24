/*
*Node class inspired by github user rileycr (Riley Cooper)
*
*
*/
#include "Node.h"

Node::Node(Shape *data, Node *next, Node *prev){
	data_ = data;
	next_ = next;
	prev_ = prev;
}

Node::Node(Shape *data){
	data_ = data;
}

Node::Node(Node *next, Node *prev){
	next_ = next;
	prev_ = prev;
}

void Node::pointers(Node *next_node, Node *prev_node){
	next_ = next_node;
	prev_ = prev_node;
}

void Node::draw(){
	data_ -> draw();
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
void Node::sendToBack(Node* sentinel){
	Node* first = sentinel -> prev_;
	sentinel -> prev_ = sentinel -> prev_ -> prev_;
	sentinel -> prev_ -> next_ = sentinel;

	first -> next_ = sentinel -> next_;
	first -> prev_ = sentinel;

	sentinel -> next_ -> prev_ = first;
	sentinel -> next_ = first;

}
//Broken
void Node::sendToFront(Node* sentinel){
	Node* last = sentinel -> next_;
	sentinel -> prev_ -> next_ = sentinel -> next_;
	sentinel -> next_ -> prev_ = sentinel -> prev_;

	last -> next_ = sentinel;
	last -> prev_ = sentinel -> prev_;

	sentinel -> prev_ -> next_ = last;
	sentinel -> prev_ = last;
}