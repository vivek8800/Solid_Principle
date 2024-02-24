/********************* Single  Responsibility Principle ************************/

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

int main() 
{
    Marker marker("Marker1", "Red", 2024, 10);
    Invoice invoice(marker, 5);
    cout << "Total: " << invoice.calculateTotal() << endl;

    return 0;
}

/*
---------------------------------------uncomment below code is solution------------------------
Solution:- Make different class and each class shouls have only one function or only one reason to change and single responsibility.
Below all class have only single responsibility and only single reason to change
-----------------------------------------------------------------------------------------------
*/

// #include<iostream>
// using namespace std;

// class Marker
// {
// 	string name;
// 	string color;
// 	int year;
// 	int price;
	
// 	public:

// 	// Default Constructor
// 	Marker()
// 	{
// 		this->name="";
// 		this->color="";
// 		this->year=0;
// 		this->price=0;
// 	}
	
// 	// Perametrized Constructor
// 	Marker(string name, string color, int year, int price)
// 	{
// 		this->name=name;
// 		this->color=color;
// 		this->year=year;
// 		this->price=price;
// 	}

// 	int getPrice() const 
// 	{
//         return price;
//     }
// };

// class Invoice
// {
// 	private:
// 	Marker marker;
// 	int quantity;
	
// 	public:

// 	Invoice(){}
// 	Invoice(Marker marker, int quantity)
// 	{
// 		this->marker=marker;
// 		this->quantity=quantity;
// 	}
	
// 	// Reason to change: let's say gst introduced then need to change calculation logic
// 	int calculateTotal()
// 	{
// 		 int price = marker.getPrice() * quantity;
//         // Additional logic for taxes, discounts, etc. can be added here
//         return price;
// 	}
// };

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

// class InvoicePrinter
// {
// 	Invoice invoice;
	
// 	public:
// 	InvoicePrinter(Invoice invoice)
// 	{
// 	this->invoice=invoice;
// 	}
	
// 	void printing()
// 	{
// 		// printing invoice
// 	}
// };

// int main() {
//     Marker marker("Marker1", "Red", 2024, 10);
//     Invoice invoice(marker, 5);
//     cout << "Total: " << invoice.calculateTotal() << endl;
//     return 0;
// }