public class CustomerDataAccess implements ICustomerDataAccess {
	
	public CustomerDataAccess() {}

	@Override
	public String getCustomerName(int id) {
		return("Dummy name");	// Get e.g. from a database
	}
}