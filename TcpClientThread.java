import java.io.*;
import java.net.*;
import java.util.*;

public class TcpClientThread {
    public static void main(String[] args) {
        try {
            Socket socket = new Socket("localhost", 1559);
            System.out.println("Connected to the server");

            Scanner sc = new Scanner(System.in);
            System.out.println("Enter the number to check if it is prime or not:");
            int number = sc.nextInt();

            // Send number to the server using a separate thread
            Thread senderThread = new Thread(new Sender(socket, number));
            senderThread.start();

            // Receive response from the server
            Thread receiverThread = new Thread(new Receiver(socket));
            receiverThread.start();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}

class Sender implements Runnable {
    private Socket socket;
    private int number;

    public Sender(Socket socket, int number) {
        this.socket = socket;
        this.number = number;
    }

    public void run() {
        try {
            OutputStream os = socket.getOutputStream();
            PrintWriter pw = new PrintWriter(os, true);
            pw.println(number);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}

class Receiver implements Runnable {
    private Socket socket;

    public Receiver(Socket socket) {
        this.socket = socket;
    }

    public void run() {
        try {
            InputStream is = socket.getInputStream();
            BufferedReader br = new BufferedReader(new InputStreamReader(is));
            String response = br.readLine();
            System.out.println("Server response: " + response);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
