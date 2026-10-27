public interface ManufacturedProduct {
    /* return the amount of resource to be used by a production unit to process this product
    (As a simplification, it is assumed to be independant from the production unit.)
    */
    public int getRequiredResourceQuantity();
    /* @return the total time spent (for now) by all the productions unit that processed this product
    */
    public int getProductionDuration();
    /* increase the production duration for this product
    @param duration the duration to add to the production duration
    */
    public void increaseProductionDuration(int duration);
    /* handle how the unit operates on the product
    @param unit the production unit that works on this product
    */
    public void transformBy(ProductionUnit unit);
}
