public class EmployeeTester {
    public static void main(String[] args) {
        // Use temporary manager object instead of static methods since changes are made to internal data (employees list)
        // However, static methods like in ex2, p11 is fine, since they only use external parameters
        EmployeeManager manager = new EmployeeManager();
        manager.inputEmployees();
        manager.writeToFile("employees.txt");
        manager.readFromFile("employees.txt");
        manager.displayEmployees();
    }
}