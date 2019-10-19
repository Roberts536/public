/*
 * A factory to generate an object of a concrete class based on given information.
 */
public class ShapeFactory {


	// A method to get an object of the given type.
	public Shape getShape(String shapeType) {
		if (shapeType == null) {
			return null;
		
		} else if (shapeType.equalsIgnoreCase("CIRCLE")) {
			return new Circle();
		
		} else if (shapeType.equalsIgnoreCase("SQUARE")) {
			return new Square();
		
		} else if (shapeType.equalsIgnoreCase("RECTANGLE")) {
			return new Rectangle();
		}

		return null;
	}
}