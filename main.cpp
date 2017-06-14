//GENETIC CARS
//
//Template: Michael Black, 2014
//
//main.cpp does the following in order:
//	1) creates a population of cars
//	2) creates a racecourse
//	3) genetically improves the cars by racing them
//	4) creates the window
//	5) shows the winning cars

#include <iostream>
#include <QtGui>
#include <math.h>
#include "main.h"
#include "physicsengine.h"
#include "car.h"

const int GENERATIONS=20;		//how many breeding generations
const int MAXCARS=1000;			//maximum # of cars.  more than this will segfault
const int KILLMAX=20;			//kill all but this many cars
const int INITIAL_POPULATION=30;	//how many cars we start with
const int SIMULATION_LENGTH = 2000;	//length of simulation in frames
const int BREEDRATE = 40;
const int DOMUTATERATE = 30;		//chance of mutating (was 20)
const int MUTATIONRATE = 50;		//how mutated each mutant is (was 30)
const int BALLSINCAR = 10;		//how many balls in each car

int WIDTH=500,HEIGHT=500;		//screen width and height
QGraphicsScene* thescene;		//window component
WindowView* view;			//window
int timeunit=1000/660;			//when we're actually showing the car, do a frame every this many milliseconds

Car* car[MAXCARS];			//cars are stored here
int CarCount=INITIAL_POPULATION;	//keeps track of how many valid cars there are
int currentCar;				//which car we're currently racing

int currentgen;				//current generation of the car

int iterations;				//how many frames we have simulated so far

extern bool simulating;			//TRUE if actively racing a car, FALSE during setup
extern bool dontdographics;		//TRUE if no window is open, FALSE if we want to see the cars in the window


//sets up a timer for visualization
TimerHandler::TimerHandler(int t)
{
	QTimer* timer=new QTimer(this);
	QObject::connect(timer, SIGNAL(timeout()), this, SLOT(onTimer()));
	timer->start(t);
}

//when a timer goes off, ready to show a frame
//this only happens where we're ready to see the winning cars
void TimerHandler::onTimer()
{
	if(!simulating) return;				//if simulation isn't running, exit this function

	doFrame();					//instantiate frame

	int pos=car[currentCar]->getCarPosition();	//defines beginning position of car as current starting position

	iterations++;					//add iteration each time this function is run

	if(iterations>=SIMULATION_LENGTH || pos>=WIDTH)		//if iterations are more than 200 or position is more than screen width
	{
		qDebug() << iterations<<" iterations, position="<<pos<<endl; 
		car[currentCar]->score(iterations,pos);
		//deconstruct the car		
		car[currentCar]->deconstructCar();	

		//proceed to next car
		currentCar++;				
				
		//if currentCar is larger than CarCount, end the simulation
		if(currentCar>=CarCount)
		{
			simulating=FALSE;		
			for (int i=0; i<CarCount; i++)
			{
				qDebug()<<"Car "<<i<<": itr: "<<car[i]->iterations<<", pos: "<<car[i]->position<<endl;
			}
		}
		else
		{
			car[currentCar]->constructCar();//build car
		}
		iterations=0;				//reset iterations to 0
	}
}

WindowView::WindowView(QGraphicsScene *scene, QWidget* parent):QGraphicsView(scene, parent) { }

void WindowView::mousePressEvent(QMouseEvent *event)
{
	if(event->button() == Qt::RightButton)
	{
		simulating=!simulating; return;		//right clicking will start and stop the simulation
	}
}

void WindowView::mouseDoubleClickEvent(QMouseEvent *event)
{
	if(event->button() == Qt::LeftButton)		//if no cars are racing, start it by double clicking
	{
		currentCar=0;
		car[currentCar]->constructCar();
		simulating=TRUE;
	}
}

//TODO: Sort the cars by the scoring mechanism and kill off all but the KILLMAX best
//scoring mechanism
	//1) Car that gets the furthest wins, distance average ball position in the car
	//2) If car distance > 500, then lowest framecount wins
void kill()
{
	for(int i =0; i<CarCount; i++)
	{
		for(int j =0; j<CarCount - 1; j++)
		{
			if(car[j+1]->combinedScore() > car[j]->combinedScore())
			{
				Car* temp = car[j+1];
				car[j+1] = car[j];					
				car[j] = temp;
			}
		}
	}
	CarCount = KILLMAX;
}

//TODO: consider every pair of cars, roll random, if decide to breed
void breed()	
{
	//car[i]->breed(car[j]), add that to our list car[CarCount] = ..., CarCount++

	int breedcarcount = CarCount;
	int crossoverpoint=0;
	for(int dad = 0; dad<breedcarcount; dad++)
	{
		for(int mom=0; mom<breedcarcount; mom++)
		{
			//don't breed with yourself
			if(mom == dad) continue;

			//20% chane of mate
			if (rand()%100<BREEDRATE)
			{

				car[CarCount] = new Car(BALLSINCAR);
				Car* baby=new Car(BALLSINCAR);
				crossoverpoint = rand()%BALLSINCAR;
				//copy stuff over dad
				for(int i=0; i<crossoverpoint; i++)				
				{
					baby->balls_x[i] = car[dad]->balls_x[i];
					baby->balls_y[i] = car[dad]->balls_y[i];
				}
				//copy stuff over mom
				for(int j=crossoverpoint; j<BALLSINCAR; j++)
				{
					baby->balls_x[j] = car[mom]->balls_x[j];
					baby->balls_y[j] = car[mom]->balls_y[j];
				}
				
				//make links? Check this again.
				for(int i=0; i<BALLSINCAR; i++)
				{
					for(int j=i+1; j<BALLSINCAR; j++)
					{
						baby->links[i][j] = car[mom]->links[i][j];
					}
				}

				car[CarCount++] = baby;
			}

		}
	}
}

//TODO: consider every pair of cars, roll random, clone if we decide to
void mutate()
{
	int cloningCount = CarCount;
	for(int i = 0; i< cloningCount; i++)
	{
		if(rand()%100 < DOMUTATERATE)
		{
			Car* mutant = new Car(BALLSINCAR);
			//clones an existing car
			for(int j = 0; j<BALLSINCAR; j++)
			{
				mutant->balls_x[j] = car[i]->balls_x[j];
				mutant->balls_y[j] = car[i]->balls_y[j];	
			}
			for(int l = 0; l<BALLSINCAR;l++)
			{
				for(int k=l+1; k<BALLSINCAR;k++)
					mutant->links[l][k] = car[i]->links[l][k];
			}
			
			//changing the balls
			for(int b = 0; b<BALLSINCAR; b++)
			{
				if(rand()%100 < MUTATIONRATE)
				{
					mutant->balls_x[b]=(qrand()%(50-5+1))+5;
					mutant->balls_y[b]=(qrand()%(50-5+1))+5;
			
				}
			}
			for(int k=0; k<BALLSINCAR; k++)
			{
				for(int m=k+1; m<BALLSINCAR; m++)
				{
					if(rand()%100 < MUTATIONRATE) mutant->links[k][m] = !mutant->links[k][m];	
				}
			}
			car[CarCount++]=mutant;
			
		}	
	}
}


//race course is stored here
extern Wall* walls[];	//create array of walls for course
extern Wall* trackA[];
extern int WallCount;	//create wall count
void makeRaceCourse()	//course function
{
	WallCount=9;	//number of walls for the course - below are their positions

	//Track A Layout
	trackA[0]=new Wall(1,500,499,500);
	trackA[1]=new Wall(-20,132,123,285);
	trackA[2]=new Wall(104,285,203,277);
	trackA[3]=new Wall(202,275,271,344);
	trackA[4]=new Wall(271,344,320,344);
	trackA[5]=new Wall(321,345,354,318);
	trackA[6]=new Wall(354,318,394,324);
	trackA[7]=new Wall(394,324,429,390);
	trackA[8]=new Wall(429,391,498,401);
	
	for(int i=0; i<WallCount; i++)
		walls[i]=trackA[i];	
	for(int j=0; j<WallCount;j++)
		thescene->addItem(walls[j]);	//add walls to the course
}

//docars doe all the racing, breeding, behind the scenes
//when you call this function, the cars are random
//when ended, you have your genetically modified cars, ready to display
void doCars()	
{
	//no window, so don't make the balls/links visible
	dontdographics=TRUE;	//no graphics

	for(int gen=0; gen<GENERATIONS; gen++) {
		qDebug() << "****** GENERATION "<<gen<<" **********" <<endl;	//print generation count
		currentgen = gen;

	//adjust race course to gen count
	makeRaceCourse();

	for (int i=0; i<CarCount; i++)
	{
		car[i]->constructCar();	//construct car

		simulating=TRUE;	//start sim
		int t=0;		//framecount
		int pos;		//how far car has gone
		//runs some maximum of frames and gives up if car never made it to end
		for(t=0; t<SIMULATION_LENGTH; t++)	
		{
			//move everything by one epsilon
			doFrame();
			//retrieve position and save it
			pos=car[i]->getCarPosition();
			if (pos < 0)
				pos=0;
				car[i]->position = 0;
			if (pos >= 500)
				pos = 500;
			//if pos exceeds width, stop sim
			if(pos>=WIDTH) break;		
		}

		qDebug() << t<<" iterations, position="<<pos<<endl;	//print iterations and position
		car[i]->score(t,pos);					//retrieve score
		simulating=FALSE;					//stop sim
		car[i]->deconstructCar();				//break down car
	}
	for (int i=0; i<CarCount; i++)
	{
		qDebug()<<"Car "<<i<<": itr: "<<car[i]->iterations<<", pos: "<<car[i]->position<<endl;	//print car iterations and position
	}

	kill();
	breed();
	mutate();
}
	kill();
	dontdographics=FALSE;
}


int main(int argc, char **argv)
{
	//seed random num generator
	QApplication app(argc,argv);
	qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));

	//make the window
	thescene=new QGraphicsScene();
	thescene->setSceneRect(0,0,WIDTH,HEIGHT);

	//make the race course
	//makeRaceCourse();

	//make the initial population of cars
	for (int i=0; i<CarCount; i++)
		car[i]=new Car(BALLSINCAR);

	doCars();

	currentCar=0;
	car[currentCar]->constructCar();
	simulating=TRUE;

	view=new WindowView(thescene);
	view->setWindowTitle("Genetic Cars");
	view->resize(WIDTH+50,HEIGHT+50);
	view->show();
	view->setMouseTracking(true);

	TimerHandler timer(timeunit);

	return app.exec();
}
