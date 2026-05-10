public class Employee {
    private String id;
    private String name;
    private String department;
    private double basicSalary;
    private double extraSalary;
    // Constructor
    public Employee(String id, String name, String department, double basicSalary, double extraSalary) {
        this.id = id;
        this.name = name;
        this.department = department;
        this.basicSalary = basicSalary;
        this.extraSalary = extraSalary;
    }
    // Default constructor (all empty fields)
    public Employee() {
        this.id = "";
        this.name = "";
        this.department = "";
        this.basicSalary = 0;
        this.extraSalary = 0;
    }
    // Setters (always to remember to validate conditions)
    public void setId (String id) {
        if (id != null && !id.trim().isEmpty()) {
            this.id = id;
        }
    }
    public void setName (String name) {
        if (name != null && !name.trim().isEmpty()) {
            this.name = name;
        }
    }
    public void setDepartment (String department) {
        if (department != null && !department.trim().isEmpty()) {
            this.department = department;
        }
    }
    public void setBasicSalary (double basicSalary) {
        if (basicSalary >= 0) {
            this.basicSalary = basicSalary;
        }
    }
    public void setExtraSalary (double extraSalary) {
        if (extraSalary >= 0) {
            this.extraSalary = extraSalary;
        }
    }
    // Getters
    public String getId() {
        return this.id;
    }
    public String getName() {
        return this.name;
    }
    public String getDepartment() {
        return this.department;
    }
    public double calculateIncome () {
        return basicSalary + extraSalary * 2.5;
    }
    public String toFileString() { // for writing data to file
        return id + ", " + name + ", " + department + ", " + basicSalary + ", " + extraSalary;
    }
    public String toDisplayString() { // for printing data to console: hide basic + extra salaries, show net income
        return String.format("%s, %s, %s | %f", id, name, department, calculateIncome());
    }
}