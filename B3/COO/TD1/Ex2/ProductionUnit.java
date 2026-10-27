public abstract class ProductionUnit {
    protected int nbCalledProcesses;
    protected int nbProcessedProducts;
    protected int availableResources;
    protected int productionDuration;

    public ProductionUnit() {
        nbCalledProcesses = 0;
        nbProcessedProducts = 0;
        availableResources = 0;
    }
    public int getNbCalledProcesses() {
        return this.nbCalledProcesses;
    }
    public int getAvailableResources() {
        return this.availableResources;
    }
    public void addAvailableResources(int resource) {
        this.availableResources += resource;
    }
    public int getNbProcessedProducts() {
        return this.nbProcessedProducts;
    }
    public int getProductionDuration() {
        return this.productionDuration;
    }
    public final void operate(ManufacturedProduct product) {
        try {
            nbCalledProcesses++;
            process(product);
        }
        catch (ProductionProblemException e) {
            // e.printStackTrace();
        }

    }
    public void process(ManufacturedProduct product) throws ProductionProblemException {
        if (availableResources < product.getRequiredResourceQuantity()) {
            throw new ProductionProblemException();
        }
        nbProcessedProducts++;
        availableResources -= product.getRequiredResourceQuantity();
        product.increaseProductionDuration(this.productionDuration);
    }
    protected abstract void handleProductProcess(ManufacturedProduct product);
}
