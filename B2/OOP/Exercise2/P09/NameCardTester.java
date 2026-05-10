public class NameCardTester {
    private static void testNameCardWithConstructor() {
        NameCard nc = new NameCard("NXH1", 1234500000, "nxh1@mail.com");
        nc.print();
    }
    private static void testNameCardWithSetter() {
        NameCard nc = new NameCard();
        nc.setName("NXH2");
        nc.setPhone(1020304050);
        nc.setEmail("nxh2@mail.com");
        nc.print();
    }
    public static void main(String[] args) {
        testNameCardWithConstructor();
        testNameCardWithSetter();
    }
}
// NOTE: if the decimal Integer starts with a zero, it will be interpreted as an octal literal
// for example, 0102030405 --> 17314053 (!?!?)