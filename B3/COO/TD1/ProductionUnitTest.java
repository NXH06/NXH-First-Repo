import org.junit.jupiter.api.Assert.*;

public abstract class ProductionUnitTest {
    private ManufacturedProduct product;
    private MockUnit unit;
    @BeforeEach
    public void init() {
        this.product = new MockProduct();
        this.unit = new MockUnit();
    }

    @Test
    public void testOperateCountProductionWhenEnoughResource() {
        this.unit.addAvailableResource(100);
        this.unit.operate(this.product);
        this.unit.operate(this.product);
        assertEquals(2, this.unit.getNbprocessedProducts());
        assertEquals(2, this.unit.processCalled());
    }

    @Test
    public void testOperateCountProductWhenNotEnoughResource() {
        this.unit.addAvailableResource(15); // pas assez de ressources pour les 2 exécutions de operate()
        this.unit.operate(this.product);
        this.unit.operate(this.product);
        assertEquals(1, this.unit.getNbProcessedProduct()); // point 4 du cahier des changes
        assertEquals(2, this.unit.processCalled); // point 3 du cahier des changes
    }

    @Test
    public void testProcessThrowsProductionProblemException() {
        this.unit.addAvailableResource(100);
        int initialResources = this.unit.getAvailableProcess();
        int initialDuration = this.product.getProductionDuration;
        this.unit.process(this.product);
        // Point 2a
        assertEquals(this.product.requiredResourceQuantity(), initialResources - this.unit.getAvailableResources());
        // Point 2b
        assertEquals(this.product.getProductionDuration(), initialDuration - this.unit.getProductionDuration());
    }

    private class MockProduct implements ManufacturedProduct {
        private int productionDuration = 0;
        public int requiredResourceQuantity() {
            return 10;
        }
        public int getProductionDuration() {
            return this.productionDuration;
        }
        public void increaseProductionDuration(int duration) {
            this.productionDuration += duration;
        }
    }
}