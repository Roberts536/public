public class CustomerBusinessLogic implements ICustomerDataAccess {
	/*
	 * This class no longer depends on the CustomerDataAccess class,
	 * only on the ICustomerDataAccess interface.
	 */

	private final ICustomerDataAccess _custDataAccess;

	public CustomerBusinessLogic() {
		_custDataAccess = DataAccessFactory.getCustomerDataAccessObj();
	}

	@Override
	public String getCustomerName(int id) {
		return _custDataAccess.getCustomerName(id);
	}
}