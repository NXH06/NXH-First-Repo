public class NameCard {
    private String name;
    private Integer phone;
    private String email;
    // Constructor with parameters
    public NameCard(String name, Integer phone, String email) {
        this.name = name;
        this.phone = phone;
        this.email = email;
    }
    // Constructor without parameters (to be used with setters)
    public NameCard() {}
    // Define getters and setters separately for encapsulation and in case we need to add extra logic before those commands
    public String getName() {
        return this.name;
    }
    public Integer getPhone() {
        return this.phone;
    }
    public String getEmail() {
        return this.email;
    }
    public String setName(String name) {
        return this.name = name;
    }
    public Integer setPhone(Integer phone) {
        return this.phone = phone;
    }
    public String setEmail(String email) {
        return this.email = email;
    }
    public void print() {
        System.out.println("\nName: "+this.name+"\nPhone number: "+this.phone+"\nEmail: "+this.email);
    }
}