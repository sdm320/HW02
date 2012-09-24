/*
*Node class inspired by github user rileycr (Riley Cooper)
*
*
*/
#include "cinder\gl\gl.h"
#include "Shape.h"

using namespace ci;

class Node {
public:
	Node(Shape *data);
	Node(Node *next, Node *prev);
	void pointers(Node *next_node, Node *prev_node);
	void draw();
	void reverse(Node* sentinel);
	void sendBack(Node* sentinel);
	void sendFront(Node* sentinel);
	void move(Shape myShape);
	bool containsPoint(Vec2i point);

	Shape *data_;
	Node *next_;
	Node *prev_;
};