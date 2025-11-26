import java.io.*;
import java.util.*;
public class EmployeeManager {
    private List<Employee> employees = new ArrayList<>(); // initiate list of employees
    public void inputEmployees() {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter number of employees: ");
        int n = sc.nextInt();
        sc.nextLine(); // consume newline
        for (int i = 0; i < n; i++) {
            System.out.printf(">> Enter information for employee %d. \n", (i + 1));
            System.out.print("ID: ");
            String id = sc.nextLine();
            System.out.print("Name: ");
            String name = sc.nextLine();
            System.out.print("Department: ");
            String department = sc.nextLine();
            System.out.print("Basic salary: ");
            double basic = sc.nextDouble();
            System.out.print("Extra salary: ");
            double extra = sc.nextDouble();
            sc.nextLine(); // consume newline
            Employee e = new Employee(id, name, department, basic, extra);
            employees.add(e);
        }
    }
    public void writeToFile(String fname) {
        try (BufferedWriter out = new BufferedWriter(new FileWriter(fname))) {
            for (Employee e : employees) {
                out.write(e.toFileString()); // BufferedWriter doesn't have println()
                out.newLine();
            }
            System.out.printf(">> Data written to \"%s\"\n", fname);
        } catch (IOException ex) {
            ex.printStackTrace(); // to avoid mixing exceptions into normal logs: System.err.println("Error: " + ex.getMessage());
        }
    }
    public void readFromFile(String fname) {
        employees.clear();
        try (BufferedReader in = new BufferedReader(new FileReader(fname))) {
            String line;
            while ((line = in.readLine()) != null) {
                String[] parts = line.split(",\\s*"); // split line by comma, based on regex
                if (parts.length == 5) {
                    String id = parts[0];
                    String name = parts[1];
                    String department = parts[2];
                    double basic = Double.parseDouble(parts[3]); // data stored as string, so it must be parsed as double
                    double extra = Double.parseDouble(parts[4]);
                    employees.add(new Employee(id, name, department, basic, extra));
                }
            }
            System.out.printf(">> Data read from \"%s\"\n", fname);
        } catch (IOException ex) {
            ex.printStackTrace();
        }
    }
    public void displayEmployees() {
        for (Employee e : employees) {
            System.out.println(e.toDisplayString());
        }
    }
}
