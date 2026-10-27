public abstract class Service {
    protected int nbUse;
    protected int cost;
    public Service() {
        this.nbUse = 0;
    }
    public int getCost() {
        return this.cost;
    }
    public int getNbUse() {
        return this.nbUse;
    }
    /*
    The user uses this service. The user has to pay this se rvice's cost.
    @param user the user of this service
    @throws NotEnoughMoneyException if the user doesn't have enough money to pay this service's cost
    */
    public final void isUsedBy(ServiceUser user) throws NotEnoughMoneyException {
        int availableMoney = user.getMoney();
        if (availableMoney < cost) {
            throw new NotEnoughMoneyException();
        }
        execute();
        nbUse++;
        user.setMoney(availableMoney - cost);
    }
    protected abstract void execute();
}