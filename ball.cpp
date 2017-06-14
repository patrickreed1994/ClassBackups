#include <iostream>
#include <QtGui>
#include <math.h>
#include "ball.h"

//Constants
extern int Bound,Radius,WIDTH,HEIGHT;
extern float DT;
extern Ball* balls[];

//Constructor for ball
Ball::Ball()
{
	setPos(qrand()%(WIDTH-Bound*2)+Bound,qrand()%(HEIGHT-Bound*2)+Bound);	//sets initial position for the ball
	position=new Vector(x(),y());	//creates the position vector
	mass=(qrand()%10000)/1000.0;	//sets a random mass
	color.setBlue(0); color.setRed(0); color.setGreen(0);	
	switch(qrand()%3)		//gives the balls random base colors, then adjusts the shading based on weight
	{
		case 0:color.setBlue(255-(int)(25*mass)); break;
		case 1:color.setRed(255-(int)(25*mass)); break;
		case 2:color.setGreen(255-(int)(25*mass)); break;
	}

	float speed=qrand()%5+1;	//gives the balls random masses
	float angle=(qrand()%360)*2*3.14/360.0;	//gives the balls random initial angles
	velocity=new Vector(speed*cos(angle),speed*sin(angle));	//creates velocity vector based on speed and angle

	radius=Radius;
}

//Defines bounding rectangle for ball
QRectF Ball::boundingRect() const
{
	return QRectF(-radius,-radius,radius*2,radius*2);
}

// Constructor for wall
Wall::Wall(float p1, float p2, float p3, float p4)
{
	setPos(0,0);
	x1=p1; y1=p2; x2=p3; y2=p4;
}

//Defines bounding rectangle for wall
QRectF Wall::boundingRect() const
{
//	return QRectF(x1,y1,x2-x1,y2-y1);
	return QRectF(0,0,WIDTH,HEIGHT);
}

//Constructor for Link
Link::Link(int b1, int b2, bool isRpe)
{
	setPos(0,0);	//set initial position for link
	ball1=b1; ball2=b2; isRope=isRpe; //instantiates balls and if rope is there
	Vector* v=balls[ball1]->position->sub(balls[ball2]->position); //position vector defined
	length=v->length();	//length defined
	delete v;		//erased position vector since it's no longer needed
}

//Define bounding rect for the link
QRectF Link::boundingRect() const
{
	return QRectF(0,0,WIDTH,HEIGHT);
}

//Graphics
void Ball::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
	painter->setBrush(color);
	painter->drawEllipse(-radius,-radius,radius*2,radius*2);
}
//Graphics
void Wall::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
	QColor color;
	color.setBlue(0); color.setRed(0); color.setGreen(0);
	painter->setBrush(color);
	painter->drawLine(x1,y1,x2,y2);
}
//Graphics
void Link::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
	QColor color;
	color.setBlue(0); color.setRed(255); color.setGreen(0);
	painter->setBrush(color);
	painter->drawLine(balls[ball1]->position->x,balls[ball1]->position->y,balls[ball2]->position->x,balls[ball2]->position->y);
}

//boolean to check if balls overlap
bool Ball::contains(float x, float y)
{
	return (position->x-x)*(position->x-x)+(position->y-y)*(position->y-y)<=radius*radius;
}
//Function to move the ball
void Ball::move()
{
	position->x+=velocity->x*DT;
	position->y+=velocity->y*DT;

}
