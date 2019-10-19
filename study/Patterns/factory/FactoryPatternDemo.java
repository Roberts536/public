/* 
 * This demo follows the walkthrough on TutorialsPoint and is not my own work.
 *
 * In the Factory Pattern, we create an object without exposing the creation 
 * logic to the client and refer to the newly created object using a common 
 * interface.
 */
 public class FactoryPatternDemo {

 	public static void main(String[] args) {

 		ShapeFactory shapeFactory = new ShapeFactory();

 		Shape shape1 = shapeFactory.getShape("Circle");
 		shape1.draw();

		Shape shape2 = shapeFactory.getShape("Rectangle");
 		shape2.draw();

 		Shape shape3 = shapeFactory.getShape("Square");
 		shape3.draw();

 	}

 } 