/*
 * Max Adelman
 * Aleksander Malakis
 * Fall 2014
 * Assignment E
 * Problem E2
 *
 */

#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <string>
#include <cstring>
#include <stdbool.h>
#include <fstream>
#include <iomanip>

using namespace std;

enum Kind {business, maintenance, other, box, tank, flat, otherFreight, chair, sleeper, otherPassenger};


class Car
{
	protected:
		//all private variables
		string reportingMark;
		int carNumber;
		Kind kind;
        string kindInit;
		bool loaded;
		string destination;

	public:
		//default constructor
		Car()	
		{	
			setUp("",0,"other",false,"NONE");
		}
	
		//copy constructor
		Car(const Car &obj)
		{	
			setUp(obj.reportingMark,obj.carNumber,obj.kindInit,obj.loaded,obj.destination);
		}
		//third constructor
		Car(const string reportingMarkX, const int carNumberX, const string kindX, const bool loadedX, const string destinationX)
		{
			setUp(reportingMarkX, carNumberX, kindX, loadedX, destinationX);

		}	
    
		//deconstructor
		~Car()
		{
		}
/* **********setUp*********
 * takes in string, int, string, bool, and string
 * sets teh private values accoridng to the data input
 *
 */
		void setUp(string reportingMarkOut, int carNumberOut, string kindInit, bool loadedOut, string destinationOut);

/* **********output**********
 * simply outputs the variables in a formatted fashion
 *
 */
		void output();
		
    
        virtual void setKind(const string &kindS);
    
/* **********operator=**********
 * overloads the = operator for car objects
 *
 */
		Car& operator=(const Car & carB);
		
    
    
    
    
		//friend function
		friend bool operator==(const Car&, const Car&);
};

class FraitKhar : public Car
{
    
    public:
    
    FraitKhar()
    {
        setUp("",0,"other",false,"NONE");
    }

    //copy constructor
    FraitKhar(const FraitKhar &obj)
    {
        setUp(obj.reportingMark,obj.carNumber,obj.kindInit,obj.loaded,obj.destination);
    }
    
    FraitKhar(const string reportingMarkX, const int carNumberX, const string kindX, const bool loadedX, const string destinationX)
    {
        setUp(reportingMarkX, carNumberX, kindX, loadedX, destinationX);
        
    }
    
    void setKind(const string &kindS);


};

class PassinjirKarr : public Car
{
    public:
    
    PassinjirKarr()
    {
        setUp("",0,"other",false,"NONE");
    }
    //copy constructor
    PassinjirKarr(const PassinjirKarr &obj)
    {
        setUp(obj.reportingMark,obj.carNumber,obj.kindInit,obj.loaded,obj.destination);
    }
    PassinjirKarr(const string reportingMarkX, const int carNumberX, const string kindX, const bool loadedX, const string destinationX)
    {
        setUp(reportingMarkX, carNumberX, kindX, loadedX, destinationX);
        
    }
    
    void setKind(const string &kindS);

    
};

class StringOfCars
{
	private:
		const static int ARRAY_MAX_SIZE = 10;
		int size;
		Car *AOCPointer[ARRAY_MAX_SIZE];

	public:
		//default constructor
		StringOfCars()
		{
			size = 0;
            
            
            
            for(int i = 0; i < ARRAY_MAX_SIZE; i++)
            {
                
                //AOCPointer[i] = new Car[ARRAY_MAX_SIZE];
                
                Car *myPointer = new Car;
                
                AOCPointer[i] = myPointer;
            }
		}

		//copy constructor
		StringOfCars(const StringOfCars &thing)
		{
            
            
            
			int counter = thing.size;
			
			
            Car *myPointer = new Car;
            
            for(counter = 0; counter >= (thing.size - 1); counter++)
			{
                AOCPointer[counter] = new Car[ARRAY_MAX_SIZE];
				        
                push(*thing.AOCPointer[counter]);
                
			}
		}

		//destructor
		~StringOfCars()
		{
            for(int i = 0; i < size; i++)
            {
                delete AOCPointer[i];
            }
            
			
		}

		void push(const Car &carA);
		void pop(Car *carx);
		void output();

};

//empty constructors
void input(StringOfCars *myCar);
void buildCar(string reportingMarkOut, int carNumberOut, string kindOut, bool loadedOut, string destinationOut);
void buildFraitKhar(string reportingMarkOut, int carNumberOut, string kindOut, bool loadedOut, string destinationOut);
void buildPassinjirKarr(string reportingMarkOut, int carNumberOut, string kindOut, bool loadedOut, string destinationOut);
const string KIND_ARRAY[10] = {"business", "maintenance", "other", "box", "tank", "flat", "otherFreight", "chair", "sleeper", "otherPassenger"};
//bool isEqual(const Car carA, const Car carB);

/* ****************main******************
 *
 */
int main()
{
    StringOfCars string1;
    input(&string1);

	return 0;
}

void input(StringOfCars *myCar)
{
	ifstream inputFile;
	string type;
    string order;
	string reportingMark;
	string carNumberX;
	int carNumber;
    string kind;
	//Kind kind;
	string loadedX;
	bool loaded;
	string destination = "problem";


	inputFile.open("inputE.txt");
	if(inputFile.fail())
	{
		fprintf(stderr, "Error in reading file\n");
        exit(0);
	}
	
	
	while(inputFile.peek() != EOF)
	{
        
        
		string templine;	
		
		inputFile  >> type;
        inputFile >> order;
        cout << order << endl;
		inputFile >> reportingMark;
		inputFile >> carNumber;
		inputFile >> kind;
		inputFile >> loadedX;

        if(loadedX == "true")
        {
            loaded = 1;
        }
        else
        {
            loaded = 0;
        }
	

		while(inputFile.peek() == ' ')
			inputFile.get();	

		getline(inputFile,destination);
        
        if(type == "Car")
        {
            buildCar(reportingMark, carNumber, kind, loaded, destination);
        }
        else if(type == "FreightCar")
        {
            buildFraitKhar(reportingMark, carNumber, kind, loaded, destination);
        }
        else if(type == "PassengerCar")
        {
            buildPassinjirKarr(reportingMark, carNumber, kind, loaded, destination);
        }

   	 }
	inputFile.close();
}

//************************************************************************
void StringOfCars::push(const Car &carA)
{
    Car *point = new Car(carA);
    
    
	AOCPointer[size] = point;

	size++;
		
}

void StringOfCars::pop(Car *carx)
{
    size--;
    
    Car newCar(*AOCPointer[size]);
    *carx = newCar;
    
    
}

void StringOfCars::output()
{
	int printCheck;
	for(printCheck = 0; printCheck < size; printCheck++)
	{
		cout << "This is car number " <<  (printCheck+1) << endl;
		AOCPointer[printCheck]->output();
	}
}	

//declaired as part of the Car function - see above

void Car::setUp(string reportingMarkOut, int carNumberOut, string kindOut, bool loadedOut, string destinationOut)
{
	reportingMark = reportingMarkOut;
	carNumber = carNumberOut;

    setKind(kindOut);
    loaded = loadedOut;
	destination = destinationOut;
}

//declaired as part of the Car function - see above

void Car::output()
{
	cout << "The Reporting Mark is: " <<  reportingMark << endl;
	cout << "The Car Number is:     " << carNumber << endl;
    cout << "The Kind is:           " << KIND_ARRAY[kind] << endl;
	cout << "The Loaded status is:  ";
	if(loaded == true)
	{
		cout << "true" << endl;
	}
	else
	{
		cout << "false" << endl;
	}
	cout << "The destination is:    " << destination << endl << endl;

}

void Car::setKind(const string &kindS)
{
    if(kindS == "business")
    {
        kind = business;
    }
    else if(kindS == "maintenance")
    {
        kind = maintenance;
    }
    else
    {
        kind = other;
    }
    
}

void FraitKhar::setKind(const string &kindS)
{
    if(kindS == "box")
    {
        kind = box;
    }
    else if(kindS == "tank")
    {
        kind = tank;
    }
    else if(kindS == "flat")
    {
        kind = flat;
    }
    else
    {
        kind = otherFreight;
    }
    
}

void PassinjirKarr::setKind(const string &kindS)
{
    if(kindS == "chair")
    {
        kind = chair;
    }
    else if(kindS == "sleeper")
    {
        kind = sleeper;
    }
    else
    {
        kind = otherPassenger;
    }
    
}



/* **********operator==**********
 *
 * friend function of Car which overloads == to check if two cars are equal only using their reportingMark and their carNumber
 *
 */
bool operator==(const Car &a, const Car &b)
{
	if((a.reportingMark == b.reportingMark) && (a.carNumber == b.carNumber))
	{	
		return true;
	}
	else
	{
		return false;
	}

}

/* ********** Car operator= **********

*/

Car & Car::operator=(const Car & carB)
{
	setUp(carB.reportingMark, carB.carNumber, carB.kindInit, carB.loaded, carB.destination);
	return * this;	
}


void buildCar(string reportingMarkOut, int carNumberOut, string kindOut, bool loadedOut, string destinationOut)
{
    Car CarThing(reportingMarkOut,carNumberOut, kindOut, loadedOut,destinationOut);
    
    CarThing.output();

}


void buildPassinjirKarr(string reportingMarkOut, int carNumberOut, string kindOut, bool loadedOut, string destinationOut)
{
    PassinjirKarr passengerCarThing(reportingMarkOut,carNumberOut, kindOut, loadedOut,destinationOut);
    
    passengerCarThing.output();
    
}


void buildFraitKhar(string reportingMarkOut, int carNumberOut, string kindOut, bool loadedOut, string destinationOut)
{
    FraitKhar FreightCarThing(reportingMarkOut,carNumberOut, kindOut, loadedOut,destinationOut);
    
    FreightCarThing.output();
    
}