public class DataAccessFactory {

	public static CustomerDataAccess getCustomerDataAccessObj() {
		return new CustomerDataAccess();
	}
}