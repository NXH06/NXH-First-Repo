public class ServiceOne extends Service {
    public ServiceOne() {
        this.cost = 50;
    }
    protected void execute() {
        // éxécuter le service
        System.out.println("\t>> Executing an instance of ServiceOne...");
    }
}
