/*
 * A class to demonstrate the Dependecy Inversion Principle (DIP), which states that:
 * 1. High-level modules should not depend on low-level modules. Both should depend on abstraction.
 * 2. Abstractions should not depend on details. Details should depend on abstractions.
 *
 * This code follows the walkthrough on www.tutorialsteacher.com, and is not my own work.
 */
public class DependencyInversionDemo {

	public static void main(String[] args) {

		int id = 5;
		CustomerBusinessLogic custBusinessLogic = new CustomerBusinessLogic();
		String name = custBusinessLogic.getCustomerName(id);
		System.out.println("The customer's name is: " + name);

	}

}