import java.io.*;
import java.net.DatagramPacket;
import java.net.MulticastSocket;
import java.net.InetAddress;

public class MulticastReceiveUDP {
    public static void main(String[] args) throws IOException {
        if (args.length < 1) {
            System.out.println("Usage: java ReceiveUDP <adresse_groupe> <port>");
            System.exit(1);
        }

        int dstPort = Integer.parseInt(args[1]);
        MulticastSocket s = new MulticastSocket(dstPort);

        InetAddress group = InetAddress.getByName(args[0]);
        s.joinGroup(group);
        
        DatagramPacket p = new DatagramPacket(new byte[512], 512);
        s.receive(p);

        System.out.println("Adresse: " + p.getAddress() + "\nPort: " + p.getPort() + "\nTaille du message: " + p.getLength());
        System.out.println("Message: " + new String(p.getData()));

        s.leaveGroup(group);
        s.close();
    }
}