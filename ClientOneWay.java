import java.io.*;
import java.net.*;
public class ClientOneWay {
    public static void main(String[] args) {
        try {
            Socket socket = new Socket("localhost", 9090); 
            BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
            String response = in.readLine();
            System.out.println("Server says: " + response);            
            socket.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
