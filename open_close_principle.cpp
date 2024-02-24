/*
----------------------------------------------
2. open/close principle
----------------------------------------------
open for extension but closed for modification.

let's say we have a class and is live and already tested.
*/

#include<iostream>
using namespace std;

class Marker
{
	string name;
	string color;
	int year;
	int price;
	
	public:

	// Default Constructor
	Marker()
	{
		this->name="";
		this->color="";
		this->year=0;
		this->price=0;
	}
	
	// Perametrized Constructor
	Marker(string name, string color, int year, int price)
	{
		this->name=name;
		this->color=color;
		this->year=year;
		this->price=price;
	}

	int getPrice() const 
	{
        return price;
    }
};

class Invoice
{
	private:
	Marker marker;
	int quantity;
	
	public:

	Invoice(){}

	Invoice(Marker marker, int quantity)
	{
		this->marker=marker;
		this->quantity=quantity;
	}
	
	// 1st Reason to change: let's say gst introduced then need to change calculation logic
	int calculateTotal()
	{
		 int price = marker.getPrice() * quantity;
        // Additional logic for taxes, discounts, etc. can be added here
        return price;
		//int price=((marker.price())*this->quantity);
		//return price;
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

// class InvoiceData
// {
// 	Invoice invoice;
// 	public:
// 	InvoiceData(Invoice invoice)
// 	{
// 		this->invoice=invoice;
// 	}
	
// 	void saveToDB()
// 	{
// 		// save to database
// 	}
// };

// now i am trying to modify something in that class, so this code doesnot follow open/close principle

// class InvoiceData
// {
// 	Invoice invoice;

// 	public:

// 	InvoiceData(Invoice invoice)
// 	{
// 		this->invoice=invoice;
// 	}
	
// 	void saveToDB()
// 	{
// 		// save to database
// 	}
	
// 	// Added extra function for modification
// 	void saveToFile(string file_name)
// 	{
// 		// save invoice in the file with the given name
// 	}
// };

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

int main() 
{
    Marker marker("Marker1", "Red", 2024, 10);
    Invoice invoice(marker, 5);
    cout << "Total: " << invoice.calculateTotal() << endl;

    return 0;
}