/*
--------------------------------------------
4. Interface Segmented Principle
--------------------------------------------

Interface should be such that client should not implement unnecessary function they don't needed.
*/

// #include<iostream>
// using namespace std;

// class RestrurantEmployee
// {
// 	public:

// 	RestrurantEmployee(){}

// 	virtual void washDishes()=0;
// 	virtual void serveCustomers()=0;
// 	virtual void cookFood()=0;
// };

// // Note: here client is waiter

// class Waiter: public RestrurantEmployee
// {
// 	public:
// 	void washDishes()
// 	{
// 		// not my job but need to implement because of abstract class inheritance
// 		cout<<"Wash dishes but that's not my job"<<endl;
// 	}
	
// 	void serveCustomers()
// 	{
// 		// yes and here is my implementation
// 		cout<<"Serving the customers, That's my job"<<endl;
// 	}
	
// 	void cookFood()
// 	{
// 		// not my job and not need to implemented
// 		cout<<"Cooking the food but that's not my job"<<endl;
// 	}
// };

// int main()
// {
// 	Waiter w;
// 	w.serveCustomers();
// 	w.cookFood();
// 	w.washDishes();
// }

// here issue is that customer(waiter) need to implement all the necessary function in which some function is  no needed.
// so the above example is not best example of Interface Segmented Principle
// below we can achieve this principle:::::::::

// make small interface 
#include<iostream>
using namespace std;

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

class Chef{
	public:
	void cookFood()
	{
		cout<<"Cooking Food"<<endl;
	}

	void decideMenu()
	{
		cout<<"Deciding menu"<<endl;
	}
};

class Cleaner
{
	public:
	void washDishes()
	{
		cout<<"Wash dishes"<<endl;
	}
};

int main()
{
	Waiter w;
	w.serveCustomers();
	w.takeOrder();
}