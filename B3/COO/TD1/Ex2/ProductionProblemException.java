public class ProductionProblemException extends Exception {
    public ProductionProblemException() {
        super("This production unit does not have enough resources.");
    }
}
