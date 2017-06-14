#include <QGraphicsItem>
#include <QGraphicsView>
#include <QTimer>
#include <QWidget>
#include "vector.h"

#ifndef BALL
#define BALL

//Ball constructor
class Ball : public QGraphicsItem
{
public:
	Ball();				//ball item
	QRectF boundingRect() const;	//bounding rect of the ball
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);	//ball graphics
	float mass;			//mass of the ball
	float radius;			//radius of the ball
	Vector* velocity;		//velocity vector
	Vector* position;		//position vector
	void move();			//moves the ball to a new position
	bool contains(float,float);	//checks if balls overlap

	~Ball()				//destroys old position and velocity vectors
	{
		delete velocity;
		delete position;
	}

private:
	QColor color;

};

//Wall constructor
class Wall : public QGraphicsItem
{
public:
	Wall(float,float,float,float);	//wall item
	QRectF boundingRect() const;	//bounding rect of wall
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);	//wall graphics
	float x1,y1,x2,y2;		//defines wall position
};

//link constructor
class Link : public QGraphicsItem
{
public:
	Link(int,int,bool);		//link item, the ints are the balls in the index and the bool is if it exists
	QRectF boundingRect() const;	//bounding rect of link
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);	//link graphics
	int ball1,ball2;		//instantiates balls that the link connects
	float length;			//length of the link
	bool isRope;			//checks if the link exists
};

#endif
