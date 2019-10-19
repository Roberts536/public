public class FactoryProducer {
	/* 
	 * A FactoryProducer object will produce either a RoundedShapeFactory
	 * or a ShapeFactory according to its isRounded argument.
	 */

	public static AbstractFactory getFactory(boolean isRounded) {
		if (isRounded) {
			System.out.println("Hello world");
			return new RoundedShapeFactory();
		} else {
			return new ShapeFactory();
		}
	}
}