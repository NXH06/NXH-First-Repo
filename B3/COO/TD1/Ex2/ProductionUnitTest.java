public abstract class ProductionUnitTest {
    private ManufacturedProduct product;
    private MockUnit unit;
    @BeforeEach
    public void init() {
        this.product  new MockProduct();
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
}