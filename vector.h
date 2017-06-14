#ifndef VECTOR
#define VECTOR

class Vector
{
public:
	float x,y;		//positions for vector
	Vector(float,float);	//vector constructor
	Vector* add(Vector*);	//add vectors
	Vector* sub(Vector*);	//subtract vector
	Vector* mul(float);	//multiply vectors
	float dot(Vector*);	//get dot vector
	Vector* normalize();	//normalize vector to objects
	float length();		//get vector length
	float lengthsquared();	//get vector length squared for distances between objects
	float angle();		//get vector angle
};

#endif
