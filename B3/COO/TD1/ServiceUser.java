public class ServiceUser {
    private int money;
    public ServiceUser(int money) {
        this.money = money;
    }
    public void init(int code) {
        money = 0;
    }
    public int getMoney() {
        return this.money;
    }
    public void useService(Service service) throws NotEnoughMoneyException {
        if (this.money < service.getCost()) {
            throw new NotEnoughMoneyException();
        }
        service.execute();
        this.money -= service.getCost();
    }
}
