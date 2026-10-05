import java.io.*;
import java.net.DatagramPacket;
import java.net.DatagramSocket;

public class ReceiveUDP {
    public static void main(String[] args) throws IOException {
        if (args.length < 1) {
            System.out.println("Usage: java ReceiveUDP <port>");
            System.exit(1);
        }

        DatagramSocket s = new DatagramSocket(Integer.parseInt(args[0]));
        DatagramPacket p = new DatagramPacket(new byte[512], 512);
        s.receive(p);

        System.out.println("Adresse: " + p.getAddress() + "\nPort: " + p.getPort() + "\nTaille du message: " + p.getLength());
        System.out.println("Message: " + new String(p.getData()));

        s.close();
    }
}