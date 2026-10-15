import java.io.*;
import java.net.DatagramPacket;
import java.net.InetAddress;
import java.net.MulticastSocket;

public class MulticastReceiveUDP {
    public static void main(String[] args) throws IOException {
        if (args.length < 1) {
            System.out.println("Usage: java MulticastReceiveUDP <adresse_groupe> <port>");
            System.exit(1);
        }

        int dstPort = Integer.parseInt(args[1]);
        MulticastSocket s = new MulticastSocket(dstPort);

        InetAddress group = InetAddress.getByName(args[0]);
        s.joinGroup(group);
        
        DatagramPacket p = new DatagramPacket(new byte[1024], 1024);
        s.receive(p);

        System.out.println("Adresse: " + p.getAddress() + "\nPort: " + p.getPort() + "\nTaille du message: " + p.getLength());
        System.out.println("Message: " + new String(p.getData()));

        s.leaveGroup(group);
        s.close();
    }
}