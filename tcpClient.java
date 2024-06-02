import java.io.*;
import java.net.*;
import java.util.*;

public class tcpClient {
    public static void main(String[] args) {
        try {
            Socket socket = new Socket("localhost", 1559); 
            System.out.println("Connected to the server");
            Scanner sc =new Scanner(System.in);

          
            InputStream is = socket.getInputStream();
            OutputStream os = socket.getOutputStream();

            // Send a number to the server
            PrintWriter pw = new PrintWriter(os, true);
            System.out.println("Enter the no to check it is prime or not");
            pw.println(sc.next()); 
            
            BufferedReader br = new BufferedReader(new InputStreamReader(is));
            String response = br.readLine();
            System.out.println("Server response: " + response);

          
            socket.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
