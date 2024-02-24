/*
Solid Principle:-

S- Single Responsibility Principle
O- open/close principle
L- Liskov Substitution Principle
I- Interface Segmented Principle
D- Dependency Inversion Principle

Advantage:-

0.	Helps us to write better code.
1.	Avoid duplicate code.
2.	Easy to maintain.
3.	Easy to understand.
4.	Flexible Software.
5.	Reduce complexity

--------------------------------
1. Single Responsibility Principle
--------------------------------
A class should have only one reason to change.
A class should have only one responsibility.

Example:-

class Marker
{
	string name;
	string color;
	int year;
	int price;
	
	public:
	
	// constructor
	Marker(string name, string color, int year, int price)
	{
		this->name=name;
		this->color=color;
		this->year=year;
		this->price=price;
	}
};


// Below class doesn't follow single responsibility to change

class Invoice
{
	private:
	Marker marker;
	int quantity;
	
	public:
	Invoice(Marker marker, int quantity)
	{
		this->marker=marker;
		this->quantity=quantity;
	}
	
	// 1st Reason to change: let's say gst introduced then need to change calculation logic
	int calculateTotal()
	{
		int price=((marker.price)*this->quantity);
		return price;
	}
	
	// 2nd Reason to change: let's say changein printing logic
	void printInvoice()
	{
		// print the invoice
	}
	
	// 3rd Reason to change: if storage is changed(like save to file)
	void saveToDB()
	{
		// save the data into database
	}
};

---------------------------------------
Solution:- Make different class and each class shouls have only one function or only one reason to change and single responsibility.
Below all class have only single responsibility and only single reason to change
---------------------------------------

class Invoice
{
	private:
	Marker marker;
	int quantity;
	
	public:
	Invoice(Marker marker, int quantity)
	{
		this->marker=marker;
		this->quantity=quantity;
	}
	
	// Reason to change: let's say gst introduced then need to change calculation logic
	int calculateTotal()
	{
		int price=((marker.price)*this->quantity);
		return price;
	}
};

class InvoiceData
{
	Invoice invoice;
	public:
	InvoiceData(Invoice invoice)
	{
		this->invoice=invoice;
	}
	
	void saveToDB()
	{
		// save to database
	}
};

class InvoicePrinter
{
	Invoice invoice;
	
	public:
	InvoicePrinter(Invoice invoice)
	{
	this->invoice=invoice;
	}
	
	void printing()
	{
		// printing invoice
	}
};


----------------------------------------------
2. open/close principle
----------------------------------------------
open for extension but closed for modification.


// let's say we have a class and is live and already tested.

class InvoiceData
{
	Invoice invoice;
	public:
	InvoiceData(Invoice invoice)
	{
		this->invoice=invoice;
	}
	
	void saveToDB()
	{
		// save to database
	}
};

// now i am trying to modify something in that class, so this code doesnot follow open/close principle

class InvoiceData
{
	Invoice invoice;
	public:
	InvoiceData(Invoice invoice)
	{
		this->invoice=invoice;
	}
	
	void saveToDB()
	{
		// save to database
	}
	
	// Added extra function for modification
	void saveToFile(string file_name)
	{
		// save invoice in the file with the given name
	}
};

// we can improve by using interface of save method and child class can implement according to their method to save

class InvoiceData
{
	public:
	virtual void save(Invoice invoice)=0;	// interface
};

class DatabaseInvoiceDB: public InvoiceData
{
	public:
	void save(Invoice invoice)
	{
		// save to db
	}
};

class FileInvoiceDB: public InvoiceData
{
	public:
	void save(Invoice invoice)
	{
		// save to file
	}
};

// further we want to save our data in mongoDb, just use interface and write our own implementation
// Like this:

class mongoDbInvoiceDB: public InvoiceData
{
	public:
	void save(Invoice invoice)
	{
		// save to mongoDb
	}
};

--------------------------------------------------------
3. Liskov Substitution Principle
--------------------------------------------------------
If aclass B is subtype of class A, then we should be able to replace object of A with B without breaking the behaviour of the program.
subclass should extend the capability of parent class not narrow it down


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
	}
	
	void accelerate()
	{
		// increae the speed
		speed=speed+20;
	}
};


// here Bicycle class breaking the behaviour as engine is absent in bicycle
// so Liskov principle says to extend but here we are narrowing it down, so program will crash here.

class Bicycle:public Bike
{
	public:
	void turnOnEngine()
	{
		throw new AssertionError(detailedMessage: "There is no engine");
	}
	
	void accelerate()
	{
		// do something
	}
};



--------------------------------------------
4. Interface Segmented Principle
--------------------------------------------

Interface should be such that client should not implement unnecessary function they don't needed.

class RestrurantEmployee
{
	public:
	virtual void washDishes()=0;
	virtual void serveCustomers()=0;
	virtual void cookFood()=0;
}

// Note: here client is waiter

class Waiter: public RestrurantEmployee
{
	public:
	void washDishes()
	{
		// not my job
	}
	
	void serveCustomers()
	{
		// yes and here is my implementation
		cout<<"Serving the customers"<<endl;
	}
	
	void cookFood()
	{
		// not my job
	}
};

// here issue is that customer(waiter) need to implement all the necessary function in which some function is  no need to call.
// so the above example is not best example of Segmented Interface Principle
// below we can achieve this principle:::::::::

// make small interface 

class WaiterInterface
{
	virtual void serveCustomers()=0;
	virtual void takeOrder()=0;
};

class ChefInterface
{
	virtual void cookFood()=0;
	virtual void decideMenu()=0;
};

class Helperinterface
{
	virtual void washDishes()=0;
};


//--------Now waiter inherit from WaiterInterface then he not need to implement unnecessary function---------

class Waiter:public WaiterInterface
{
	public:
	void serveCustomers()
	{
		cout<<"Serving the customers"<<endl;
	}
	
	void takeOrder()
	{
		cout<<"Taking orders"<<endl;
	}
};

--------------------------------------------
5. Dependency Inversion Principle
--------------------------------------------
class should depend on interface rather than concreate classes

KeyboardInterface
	|
	|- WiredKeyboard();
	|
	|- BlueToothKeyBoard();
	|
	
MouseInterface
	|
	|- Wiredmouse();
	|
	|- BlueToothMouse();
	|

class MacBook
{
	private;
	final WiredKeyboard keyboard;
	final Wiredmouse mouse;
	
	public:
	MacBook()
	{
		keyboard= new WiredKeyboard();
		mouse=new Wiredmouse();
	}
};



-------------------------
class MacBook
{
	private;
	final Keyboard keyboard;
	final Mouse mouse;
	
	public:
	MacBook(Keyboard keyboard, Mouse mouse)
	{
		this->keyboard= keyboard;
		this->mouse=mouse;
	}
};

++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
3. Liskov Principle explanation::
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

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


// // This is client code
// int main() 
// {
//     // Creating a vector to hold pointers to Vehicle objects
//     vector<Vehicle*> vehicleList;

//     // Adding instances of Motorcycle and Car to the vector
//     vehicleList.push_back(new MoterCycle());
//     vehicleList.push_back(new Car());

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


#include<iostream>
#include<vector>

using namespace std;

class Vehicle
{
    public:
    // common for all the vehicle
    int getNumberOfWheels()
    {
        return 2;
    }
};

class EngineVehicle: public Vehicle
{
    bool hasEngine()
    {
        return true;
    }
};

class MoterCycle:public EngineVehicle
{
   // here implementation but when MoterCycle object call hasEngine then it will return true(due to inheritance) 
   // and for getNumberOfWheels as well motercycle object will result 2 (due to inheritance)
};

class Car: public EngineVehicle
{
    int getNumberOfWheels()
    {
        return 4;
    }
};

class Bicycle: public Vehicle
{
   // will return 2 for wheel count due to inheritance
   // hasEngine() function will not be implemented as inheritance is done
};


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

//*****************************************************************************************