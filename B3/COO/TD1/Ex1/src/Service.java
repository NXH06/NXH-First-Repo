public abstract class Service {
    private int nbUse;
    public void init() {
        nbUse = 0;
    }
    public int cost() {return 100;};
    public abstract void execute();
    public int getNumberOfUse() {
        return this.nbUse;
    }
    public void isUsedBy(ServiceUser user) {}
}