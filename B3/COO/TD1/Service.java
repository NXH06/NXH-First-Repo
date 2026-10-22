public abstract class Service {
    private int nbUse;
    public Service() {
        nbUse = 0;
    }
    public abstract int getCost();
    protected abstract void executeInner();
    public void execute() {
        nbUse++;
        executeInner();
    }
    public int getNbUse() {
        return this.nbUse;
    }
}