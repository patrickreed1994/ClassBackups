//Car object - balls & links
class Car
{
public:
	//define the car - MESS WITH THESE THREE ONLY
	int* balls_x;		//x coordinates of each ball
	int* balls_y;		//y coordinates of each ball
	int** links;		//matrix of which balls connect to which other balls
	
	//just for car race -> these affect graphics
	int* balls;		//array of balls that make up car
	int* linkslist;		//array of links that make up car
        
	int nodes;		//how many balls are in the car
        int numlinks;		//how many links in the car
	int iterations;		//race results: iterations = how many frames
	int position;		//race results: position = how far the car went
	
	Car(int);		//constructor for car - int is number of balls
	void constructCar();	//givens ballsx and ballsy, actually makes balls and links foe the car
	void deconstructCar();	//clears the car out of the racetrack
	
	int getCarPosition();	//tells us how good the car was
	void score(int,int);	//sets iterations and positions at the end of the race
	int combinedScore(); //combines iterations and positions into unified score
	
	Car* breed(Car*);	//haven't made: breeds the car with another car returning a new car
	Car* mutate();		//haven't made: new mutant car

	~Car()			//destructor on delete car
	{
		delete balls_x;
		delete balls_y;
		for(int i=0; i<nodes; i++)
			delete links[i];
		delete links;
	}
};
