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
Definition:
A class should have only one reason to change.
A class should have only one responsibility.

The benefits of the Single Responsibility Principle (SRP) include:


Improved Readability: Classes with a single responsibility are easier to understand.
Easier Maintenance: Changes are less likely to cause unintended side effects.
Enhanced Reusability: Well-defined responsibilities promote code reuse.
Simplified Testing: Focused behavior facilitates effective unit testing.
Facilitates Collaboration: Allows for parallel development and teamwork.

************************************************** Application:**********************************************************

Imagine you have a bakery business. You have various roles in your bakery such as baking, decorating, and delivery. Each role has its own responsibilities:

Baker: The baker's responsibility is to bake the cakes and pastries. They focus solely on mixing ingredients, baking cakes, and ensuring they are cooked to perfection.

Decorator: The decorator's responsibility is to decorate the cakes and pastries. They focus solely on adding frosting, decorations, and making the cakes visually appealing.

Delivery Driver: The delivery driver's responsibility is to deliver the cakes and pastries to customers. They focus solely on ensuring the timely and safe delivery of the baked goods to the customers' locations.

Each role has a single responsibility and does not overlap with the responsibilities of the other roles. This ensures that each task is performed efficiently and effectively without unnecessary complexity. 
Additionally, if there are any changes or updates needed in one role, it won't affect the responsibilities of the other roles. 
This adherence to the Single Responsibility Principle helps in maintaining a well-organized and smoothly functioning bakery business.

--------------------------------
2. Open/Close Principle
--------------------------------
Definition:
"The Open/Closed Principle (OCP) states that software entities should be open for extension but closed for modification."
The Open/Closed Principle encourages developers to design systems in a way that allows for future changes and enhancements without altering existing code.
Instead of modifying existing code to accommodate new requirements, developers should extend the system by adding new code that builds upon the existing functionality.

The benefits of the Open/Closed Principle (OCP) include:

Enhanced Maintainability: Existing code remains unchanged, making maintenance easier.
Promotes Reusability: Encourages the creation of reusable components and modules.
Minimizes Risk: Reduces the risk of introducing bugs or regressions in existing code.
Facilitates Scalability: Systems can evolve and adapt to changing requirements more easily.
Supports Parallel Development: Enables multiple teams to work on different parts of the system simultaneously.
Encourages Modular Design: Promotes a modular architecture, improving code organization and readability.

************************************************** Application:**********************************************************

Consider a restaurant that offers a variety of dishes on its menu. The restaurant wants to introduce a new promotion where customers can receive a discount on certain menu items during specific hours of the day.
Instead of directly modifying the existing menu items to incorporate the discount, the restaurant follows  the Open/Closed Principle by extending the functionality without modifying the existing code.

Here's how the restaurant applies the Open/Closed Principle:

Original Menu: The restaurant has an existing menu with various dishes and their prices. This menu is closed for modification; once it's created and tested, it remains unchanged.

New Promotion: To introduce the discount promotion, the restaurant creates a new menu or promotional menu that includes the discounted items. 
This new menu extends the functionality of the original menu without modifying it. It specifies the discounted items and their prices during the promotion period.

Switching Menus: During the promotion hours, the restaurant switches to the promotional menu, offering customers the discounted items. After the promotion ends, the restaurant switches back to the original menu. 
This switching of menus allows the restaurant to maintain the original menu's integrity while still offering promotional discounts.

In this example, the restaurant adheres to the Open/Closed Principle by extending the functionality (introducing a discount promotion) without modifying the existing menu. 
This approach allows the restaurant to maintain a stable and reliable menu system while still accommodating changes and promotions.

--------------------------------
3. Liskov Substitution Principle
--------------------------------

Definition:
"The Liskov Substitution Principle (LSP) states that objects of a superclass should be replaceable with objects of its subclasses without affecting the correctness of the program."

The benefits of the Liskov Substitution Principle (LSP) include:

Modularity: Encourages well-defined and cohesive inheritance hierarchies.
Reusability: Subclasses can be reused in different contexts without modification.
Reduced Coupling: Minimizes dependencies between classes, leading to lower coupling.
Polymorphism: Enables uniform treatment of objects of different subclasses.
Correctness: Ensures that substituting subclasses for their superclass doesn't lead to unexpected behavior.
Extensibility: Supports additional new functionality through subclassing without breaking existing code.

************************************************** Application:**********************************************************

Let's consider a scenario where we have a system that manages vehicles. We have a base class Vehicle with derived classes Car and Bicycle. 
According to the LSP, objects of subclasses should be substitutable for objects of their superclass without altering the correctness of the program.

In our transportation system:

Vehicle: The base class defines common properties and behaviors shared by all vehicles, such as startEngine() and move().

Car: The Car class inherits from Vehicle and implements its methods. It adds specific behaviors like openTrunk() and accelerate().

Bicycle: The Bicycle class also inherits from Vehicle and implements its methods. It adds behaviors like ringBell() and pedal().

Now, let's imagine a scenario where the system needs to calculate the time it takes for vehicles to travel a certain distance. 
According to the LSP, we should be able to substitute any subclass object for a superclass object without affecting the correctness of the program.

For example:

We can substitute a Car object for a Vehicle object and calculate the travel time based on the car's speed.
Similarly, we can substitute a Bicycle object for a Vehicle object and calculate the travel time based on the bicycle's speed.
In this scenario, both Car and Bicycle are substitutable for Vehicle without altering the correctness of the program. 
This adherence to the Liskov Substitution Principle ensures that the system can treat different types of vehicles uniformly, 
promoting flexibility and scalability in the transportation system.

--------------------------------
4. Interface Segmented Principle
--------------------------------

Definition:
"The Interface Segregation Principle (ISP) states that clients should not be forced to depend on interfaces they do not use."

The benefits of the Interface Segregation Principle (ISP) include:

Reduced Dependencies: Classes have fewer dependencies on interfaces they don't use, reducing coupling.
Improved Readability: Smaller interfaces are easier to understand and reason about.
Enhanced Modularity: Promotes a modular design by creating cohesive and independent interfaces.
Promotes Reusability: Smaller interfaces are more reusable, as they are focused on specific functionality.
Facilitates Testing: Easy to test because interfaces have clear and focused responsibilities.
Supports Evolution: Enables the system to evolve and adapt to changing requirements more easily.

************************************************** Application:**********************************************************

real-life example of the Interface Segregation Principle (ISP) can be observed in a software application for managing user roles and permissions.

Consider a scenario where you have a software system that manages user accounts, including user authentication, authorization, and role management. 
In this system, there are different types of users with varying levels of permissions and functionalities:

Admin Users: Admin users have access to all features and functionalities of the system, including user management, content management, and system configuration.

Regular Users: Regular users have limited access compared to admin users. They can perform basic tasks such as viewing content, updating their profiles, and interacting with other users.

Guest Users: Guest users have even more limited access. They can only access publicly available content and perform minimal interactions with the system.

In this scenario, the Interface Segregation Principle can be applied by defining separate interfaces tailored to the specific needs of each user type:

Admin Interface: This interface would include methods for admin-specific functionalities such as user management, content management, and system configuration.

Regular User Interface: This interface would include methods for regular user-specific functionalities such as viewing content, updating profiles, and interacting with other users.

Guest User Interface: This interface would include methods for guest user-specific functionalities such as accessing publicly available content and performing minimal interactions with the system.

By segregating interfaces based on user roles, the system adheres to the Interface Segregation Principle, ensuring that each interface contains only the methods relevant to the specific user type. 
This promotes modularity, flexibility, and maintainability, as changes or updates to one interface do not affect interfaces for other user types. 
Additionally, it allows for easier testing and development of user-specific functionalities, leading to a more robust and scalable software system.

--------------------------------
5. Dependency Inversion Principle
--------------------------------

Definition:
"The Dependency Inversion Principle (DIP) states that high-level modules should not depend on low-level modules. Both should depend on abstractions. 
Abstractions should not depend on details; rather, details should depend on abstractions."

The benefits of the Dependency Inversion Principle (DIP) include:

Reduced Coupling: Decouples modules, making changes easier and minimizing dependencies.
Increased Flexibility: Allows for easy swapping of implementations without affecting other parts of the system.
Enhanced Reusability: Promotes code reuse by defining common interfaces.
Improved Testability: Facilitates unit testing by allowing easy replacement of dependencies with mock objects.
Facilitates Modular Design: Encourages clear separation of concerns and modular architecture.
Supports Evolution and Maintenance: Simplifies maintenance and evolution of software systems over time

************************************************** Application:**********************************************************

Consider a scenario where a person wants to brew a cup of coffee using a coffee maker. Instead of directly interacting with the coffee maker's internal components (e.g., heating element, water pump), 
the person relies on a high-level interface provided by the coffee maker.

Here's how the DIP is applied in this scenario:

High-Level Interface: The coffee maker provides a high-level interface for brewing coffee, such as buttons or touchscreen controls. 
This interface abstracts away the internal details of how the coffee maker operates.

Dependency Inversion: The person depends on the high-level interface provided by the coffee maker, rather than directly interacting with its internal components. 
This allows the person to focus on their task (brewing coffee) without needing to understand the intricate details of the coffee maker's operation.

Flexibility and Extensibility: Because the person interacts with the coffee maker through a high-level interface, 
they can easily switch to a different coffee maker or even a completely different appliance (e.g., a tea kettle) without needing to change their actions significantly. 
This flexibility and extensibility are enabled by adhering to the Dependency Inversion Principle.

The Dependency Inversion Principle is applied in this scenario by allowing the person to depend on a high-level interface provided by the coffee maker,
rather than directly interacting with its internal components. 
This promotes flexibility, extensibility, and ease of use in the interaction between the person and the household appliance.



