public class NotEnoughMoneyException extends Exception {
    public NotEnoughMoneyException() {
        super("Not enough money to use this service.");
    }
    public NotEnoughMoneyException(String message) {
        super(message);
    }
}