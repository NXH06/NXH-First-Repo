import org.junit.jupiter.api.*;
import static org.junit.jupiter.api.Assertions.*;

public abstract class ServiceTest {
    protected Service service;
    protected abstract Service createService();
    @BeforeEach
    public void init() {
        this.service = this.createService();
    }

    @Test
    public void testIsUsedByWhenOk() throws Exception {
        ServiceUser user = new ServiceUser(5 * service.getCost());

        // état avant appel de useService()
        int moneyBefore = user.getMoney();
        int nbUseBefore = service.getNbUse();

        // l'appel
        user.useService(service);
        assertEquals(1, service.getNbUse() - nbUseBefore);
        assertEquals(service.getCost(), moneyBefore - user.getMoney());
    }

    @Test
    public void testIsUsedByWhenNotEnoughMoney() {
        ServiceUser user = new ServiceUser(service.getCost() - 1);
        assertThrows(NotEnoughMoneyException.class, () -> user.useService(service));
        assertEquals(service.getCost() - 1, user.getMoney());
    }
}
