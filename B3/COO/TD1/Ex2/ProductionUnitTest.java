import org.junit.jupiter.api.*;
import static org.junit.jupiter.api.Assertions.*;

public class ProductionUnitTest {
    private ManufacturedProduct product;
    private MockUnit unit;
    @BeforeEach
    public void init() {
        this.product = new MockProduct();
        this.unit = new MockUnit();
    }

    @Test
    public void testOperateCountProductionWhenOk() {
        this.unit.addAvailableResources(100);
        this.unit.operate(this.product);
        this.unit.operate(this.product);
        assertEquals(2, this.unit.getNbProcessedProducts());
        assertEquals(2, this.unit.getNbCalledProcesses());
    }

    @Test
    public void testOperateCountProductWhenNotEnoughResources() {
        this.unit.addAvailableResources(11); // pas assez de ressources pour les 2 exécutions de operate()
        this.unit.operate(this.product);
        this.unit.operate(this.product);
        assertEquals(1, this.unit.getNbProcessedProducts()); // point 4 du cahier des changes
        assertEquals(2, this.unit.getNbCalledProcesses()); // point 3 du cahier des changes
    }

    @Test
    public void testProcess() throws ProductionProblemException {
        this.unit.addAvailableResources(100);
        int initialResources = this.unit.getAvailableResources();
        int initialDuration = this.product.getProductionDuration();
        this.unit.process(this.product);
        // Point 2a
        assertEquals(this.product.getRequiredResourceQuantity(), initialResources - this.unit.getAvailableResources());
        // Point 2b
        assertEquals(this.product.getProductionDuration(), initialDuration - this.unit.getProductionDuration());
    }

    @Test
    public void testProcessThrowsExceptionWhenNotEnoughResources() {
        assertThrows(ProductionProblemException.class, () -> {
            this.unit.process(this.product);
        });
    }

    private class MockUnit extends ProductionUnit {
        // Ces champs sont bien utilisés, tkt
        @SuppressWarnings("unused")
        public int nbCalledProcesses = 0;
        @SuppressWarnings("unused")
        public int productionDuration = 10;
        @Override
        protected void handleProductProcess(ManufacturedProduct product) {
            System.out.println("\t>> MockUnit is manufacturing MockProduct...");
        }
    }
    private class MockProduct implements ManufacturedProduct {
        private int productionDuration = 0;
        public int getRequiredResourceQuantity() {
            return 10;
        }
        public int getProductionDuration() {
            return this.productionDuration;
        }
        public void increaseProductionDuration(int duration) {
            this.productionDuration += duration;
        }
        public void transformBy(ProductionUnit unit) {}
    }
}