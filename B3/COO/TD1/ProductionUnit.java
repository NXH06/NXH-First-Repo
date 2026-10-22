public class ProductionUnit {
    public void process(ManufacturedProduct product) throws ProductionProblemException {
        this.processCalled++;
        super.process(product);
    }
    @Override
    protected void handleProductProcess(ManufacturedProduct product) {} // Run MockUnit
}

private class MockUnit extends ProductionUnit {
    public int processCalled = 0;
    public int getProductionDuration() {
        return 10;
    }
}
