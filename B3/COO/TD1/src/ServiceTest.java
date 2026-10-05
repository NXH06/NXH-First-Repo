import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.assertEquals;

public abstract class ServiceTest {
    protected abstract Service createService();
    protected Service service;
    @BeforeEach
    public void init() {
        this.service = this.createService();
    }

    @Test
    public void testIsUsedByWhenOk() throws Exception {
        ServiceUser user = new ServiceUser(2 * service.cost());

        // état avant appel de isUsedBy()
        int moneyBefore = user.getMoney();
        int nbUseBefore = service.getNumberOfUse();

        // l'appel
        service.isUsedBy(user);
        assertEquals(1, service.getNumberOfUse() - nbUseBefore);
        assertEquals(service.cost(), moneyBefore - user.getMoney());
    }

    @Test
    public void testIsUsedByWhenNotEnoughMoney() {
        ServiceUser user = new ServiceUser(-1);
        assertThrows(NotEnoughMoneyException.class, () -> {
            service.isUsedBy(user);
        });
    }
}
