/*
*Scott Mogul
*HW02
*
*/
#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "Resources.h"
#include "cinder/text.h"
#include "cinder/gl/Texture.h"
#include "Node.h"
#include "Shape.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class HW02App : public AppBasic {
	public:
		void setup();	
		void keyDown( KeyEvent event);
		void update();
		void draw();
		
	private:
		Surface* mySurface_; //The Surface object whose pixel array we will modify
		static const int Width=800; //width of visible window
		static const int Height=600; //height of visible window
		static const int Size=1024; //surface size
		static const int pixels=1;
	

		void makeTextBox();

		Node *sentinel;
		Node *nodeOne;
		Node *nodeTwo;
		Node *nodeThree;
		Node *nodeFour;

		double frameNumber;

		gl::Texture *text_texture;
		bool displayMenu;
		TextBox *text_box;
};

void HW02App::setup(){
	mySurface_ = new Surface(Size,Size,false);
	displayMenu = true;
	makeTextBox();
	frameNumber=0.0;
	/*
	*create four circles
	*
	*/
	Shape *shapeOne = new Shape(Vec2f(500, 150), 100);
	Shape *shapeTwo = new Shape(Vec2f(500, 200), 75);
	Shape *shapeThree = new Shape(Vec2f(500, 250), 50);
	Shape *shapeFour = new Shape(Vec2f(500, 290), 35);

	/*
	*put the circles into nodes
	*/
	nodeOne = new Node(shapeOne);
	nodeTwo = new Node(shapeTwo);
	nodeThree = new Node(shapeThree);
	nodeFour = new Node(shapeFour);
	sentinel = new Node(nodeOne, nodeFour);

	/*
	*have nodes point to each other
	*/
	nodeOne -> pointers(nodeTwo, sentinel);
	nodeTwo -> pointers(nodeThree, nodeOne);
	nodeThree -> pointers(nodeFour, nodeTwo);
	nodeFour -> pointers(sentinel, nodeThree);
}
/*
*makeTextBox inspired by github user rileycr (Riley Cooper)
*/
void HW02App::makeTextBox(){
	text_box = new TextBox();
	text_box -> alignment( TextBox::CENTER );
	text_box -> setText("Press ? to close menu \n To reverse the list press r \n Send current item to back of list press b \n Send next item to front of list press f");
	text_box -> setFont(Font("Times", 40));
	text_box->setBackgroundColor(ColorA(0,0,0,0.5));
	text_texture = new gl::Texture(text_box -> render());
}

void HW02App::keyDown( KeyEvent event){
	
	if(event.getChar() == '?'){
		displayMenu = !displayMenu;
	}
	if(event.getChar() == 'r'){
		sentinel ->reverse(sentinel);
	}
	if(event.getCode() == 'b'){
		sentinel -> sendBack(sentinel);
	} 
	if(event.getCode() == 'f'){
		sentinel -> sendFront(sentinel);
	}
}
//Tried to get move working
void HW02App::update(){
	frameNumber += .1;
	Node* current_ = sentinel -> next_;
	do{
		current_ -> move(pixels);
		current_  = current_ -> next_;
		if(frameNumber>.5){
			current_ ->move(-1*frameNumber);
			frameNumber=0.0;
		}
	} while(current_ != sentinel);
}

void HW02App::draw(){
	
	gl::draw(*mySurface_);
	gl::clear( Color8u(50,200,100));
	Node* current_ = sentinel -> next_;
	do{
		current_ -> draw();
		current_  = current_ -> next_;
	} while(current_ != sentinel);

	if(displayMenu)
		gl::draw(*text_texture);
}


CINDER_APP_BASIC( HW02App, RendererGl )