/*
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
*/

//************************************** Problem ****************************************//
// #include <iostream>
// using namespace std;

// class WiredKeyboard {
//     // Implementation of WiredKeyboard class
// };

// class WiredMouse {
//     // Implementation of WiredMouse class
// };

// class MacBook {
// private:
//     WiredKeyboard keyboard;
//     WiredMouse mouse;

// public:
//     MacBook() {
//         // Constructor to initialize keyboard and mouse
//     }
    
//     // Add necessary member functions if needed
// };

//************************************** Solution ****************************************//
#include <iostream>
using namespace std;

class Keyboard {
    // Implementation of Keyboard class
};

class Mouse {
    // Implementation of Mouse class
};

class MacBook {
private:
    const Keyboard keyboard;
    const Mouse mouse;
    
public:
    MacBook(const Keyboard& keyboard, const Mouse& mouse) : keyboard(keyboard), mouse(mouse) {
        // Constructor to initialize keyboard and mouse
    }
    
    // Add necessary member functions if needed
};

int main() {
    // Create instances of Keyboard and Mouse
    Keyboard kb;
    Mouse m;
    
    // Create a MacBook instance
    MacBook macbook(kb, m);
    
    // Use the MacBook instance
    // For example:
    // macbook.someFunction();
    
    return 0;
}

//***************************************************************
// -----------for reference(Before)-------------
// #include<iostream>
// using namespace std;

// class MacBook
// {
// 	private:
// 	final WiredKeyboard keyboard;
// 	final Wiredmouse mouse;
	
// 	public:
// 	MacBook()
// 	{
// 		keyboard= new WiredKeyboard();
// 		mouse=new Wiredmouse();
// 	}
// };

// -----------for reference(After)--------------

// class MacBook
// {
// 	private;
// 	final Keyboard keyboard;
// 	final Mouse mouse;
	
// 	public:
// 	MacBook(Keyboard keyboard, Mouse mouse)
// 	{
// 		this->keyboard= keyboard;
// 		this->mouse=mouse;
// 	}
// };
