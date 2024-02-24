/*
--------------------------------------------------------
3. Liskov Substitution Principle
--------------------------------------------------------
If class B is subtype of class A, then we should be able to replace object of A with B without breaking the behaviour of the program.
subclass should extend the capability of parent class not narrow it down
*/

/*
#include<iostream>
using namespace std;

class Bike
{
	public:
	virtual void turnOnEngine()=0;
	virtual void accelerate()=0;
};

class MoterCycle: public Bike
{
	 bool isEngineOn;
	 int speed;
	 
	 public:
	 void turnOnEngine()
	 {
		// turn on the engine
		isEngineOn=true;

		if(isEngineOn)
		{
			cout<<"Engine is On!!!"<<endl;
		}
		else
		{
			cout<<"Engine is not on"<<endl;
		}
	}
	
	void accelerate()
	{
		// increae the speed
		speed=speed+20;

		cout<<"Speed of Bike is: "<<speed<<"km/h"<<endl;
	}
};


// here Bicycle class breaking the behaviour as engine is absent in bicycle
// so Liskov principle says to extend but here we are narrowing it down, so program will crash here.

class Bicycle:public Bike
{
	public:
	void turnOnEngine() 
	{
    	cerr << "Error: Bicycles do not have engines." << endl;
	}
	
	void accelerate()
	{
		// This method is empty since bicycles don't accelerate in the same way as motorbikes
        cout << "Pedaling to increase speed." << endl;
	}
};

int main() {
    // Example usage
    MoterCycle bike1;
    bike1.turnOnEngine();
    bike1.accelerate();

    Bicycle bike2;
    // Attempting to turn on the engine of a Bicycle will throw a logic_error
    bike2.turnOnEngine(); // This line will throw a logic_error
    bike2.accelerate();

    return 0;
}
*/


/*
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
3. Liskov Principle explanation:: Another Problem
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

*/

#include<iostream>
#include<vector>

using namespace std;

class Vehicle
{
    public:
    int getNumberOfWheels()
    {
        return 2;
    }
    
    bool hasEngine()
    {
        return true;
    }
};

class MoterCycle:public Vehicle
{
  // here implementation but when MoterCycle object call hasEngine then it will return true(due to inheritance) 
  // and for getNumberOfWheels as well motercycle object will result 2 (due to inheritance)
};

class Car: public Vehicle
{
    int getNumberOfWheels()
    {
        return 4;
    }
};


// This is client code
int main() 
{
    // Creating a vector to hold pointers to Vehicle objects
    vector<Vehicle*> vehicleList;

    // Adding instances of Motorcycle and Car to the vector
    vehicleList.push_back(new MoterCycle());
    vehicleList.push_back(new Car());

    // Iterating over the vector and printing the result of hasEngine function for each vehicle
    for (Vehicle* vehicle : vehicleList) 
    {
        cout << boolalpha << vehicle->hasEngine() <<endl;
    }

    // Freeing memory allocated for each vehicle
    for (Vehicle* vehicle : vehicleList) 
    {
        delete vehicle;
    }

    return 0;
}

//*****************Problem occur when downcasting the capability by adding another class Bicycle*************/

// #include<iostream>
// #include<vector>

// using namespace std;

// class Vehicle
// {
//     public:
//     int getNumberOfWheels()
//     {
//         return 2;
//     }
    
//     bool hasEngine()
//     {
//         return true;
//     }
// };

// class MoterCycle:public Vehicle
// {
//   // here implementation but when MoterCycle object call hasEngine then it will return true(due to inheritance) 
//   // and for getNumberOfWheels as well motercycle object will result 2 (due to inheritance)
// };

// class Car: public Vehicle
// {
//     int getNumberOfWheels()
//     {
//         return 4;
//     }
// };

// class Bicycle: public Vehicle
// {
//     public:
//     bool hasEngine()
//     {
//         return NULL;
//     }
// };


// // This is client code
// int main() 
// {
//     // Creating a vector to hold pointers to Vehicle objects
//     vector<Vehicle*> vehicleList;

//     // Adding instances of Motorcycle and Car to the vector
//     vehicleList.push_back(new MoterCycle());
//     vehicleList.push_back(new Car());
//     vehicleList.push_back(new Bicycle());

//     // Iterating over the vector and printing the result of hasEngine function for each vehicle
//     for (Vehicle* vehicle : vehicleList) 
//     {
//         cout << boolalpha << vehicle->hasEngine() <<endl;
//     }

//     // Freeing memory allocated for each vehicle
//     for (Vehicle* vehicle : vehicleList) 
//     {
//         delete vehicle;
//     }

//     return 0;
// }

//****************************** Solution for this *********************************//
//*************** Add only generic function in the top of the class ***************//


// #include<iostream>
// #include<vector>

// using namespace std;

// class Vehicle
// {
//     public:
//     // common for all the vehicle
//     int getNumberOfWheels()
//     {
//         return 2;
//     }
// };

// class EngineVehicle: public Vehicle
// {
//     bool hasEngine()
//     {
//         return true;
//     }
// };

// class MoterCycle:public EngineVehicle
// {
//    // here implementation but when MoterCycle object call hasEngine then it will return true(due to inheritance) 
//    // and for getNumberOfWheels as well motercycle object will result 2 (due to inheritance)
// };

// class Car: public EngineVehicle
// {
//     int getNumberOfWheels()
//     {
//         return 4;
//     }
// };

// class Bicycle: public Vehicle
// {
//    // will return 2 for wheel count due to inheritance
//    // hasEngine() function will not be implemented as inheritance is done
// };


// This is client code
// *********************for Vehicle class **********************//
// int main() 
// {
//     // Creating a vector to hold pointers to Vehicle objects
//     vector<Vehicle*> vehicleList;

//     // Adding instances of Motorcycle and Car to the vector
//     vehicleList.push_back(new MoterCycle());
//     vehicleList.push_back(new Car());
//     vehicleList.push_back(new Bicycle());

//     // Iterating over the vector and printing the result of hasEngine function for each vehicle
//     for (Vehicle* vehicle : vehicleList) 
//     {
//         cout << vehicle->getNumberOfWheels() <<endl;   // hasEngine will not work as vehicle class is not aware of hasEngine method
//     }

//     // Freeing memory allocated for each vehicle
//     for (Vehicle* vehicle : vehicleList) 
//     {
//         delete vehicle;
//     }

//     return 0;
// }

// *********************for EngineVehicle class **********************//

// int main() 
// {
//     // Creating a vector to hold pointers to Vehicle objects
//     vector<EngineVehicle*> vehicleList;

//     // Adding instances of Motorcycle and Car to the vector
//     vehicleList.push_back(new MoterCycle());
//     vehicleList.push_back(new Car());
//     //vehicleList.push_back(new Bicycle());         // if you uncomment then will give error as EngineVehicle don't know about Bicycle

//     // Iterating over the vector and printing the result of hasEngine function for each vehicle
//     for (EngineVehicle* vehicle : vehicleList) 
//     {
//         cout << vehicle->getNumberOfWheels() <<endl;   // hasEngine will not work as vehicle class is not aware of hasEngine method
//     }

//     // Freeing memory allocated for each vehicle
//     for (Vehicle* vehicle : vehicleList) 
//     {
//         delete vehicle;
//     }

//     return 0;
// }
