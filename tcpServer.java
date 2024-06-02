import java.net.*;
import java.io.*;
import java.util.*;

public class tcpServer {
    public static void main(String args[]) {
        try {
            ServerSocket ss = new ServerSocket(1559);
            System.out.println("SERVER PORT CREATED ");
            Socket sc = ss.accept();
            System.out.println("Connection Established ");
            InputStream is = sc.getInputStream();
            OutputStream os = sc.getOutputStream();
            System.out.println("STREAMS CREATED ");
            String reply = null;
            Scanner s = new Scanner(is);
            System.out.println("Reading request");
            String req = s.next();
            System.out.println("NUMBER RECIVED is: " + req);
            int num = Integer.parseInt(req);
            boolean flag = false;
            for (int i = 2; i <= num / 2; i++) {
                if (num % i == 0) {
                    flag = true;
                    break;
                }
            }
            if (flag == false) {
                reply = "It is a Prime number";
            } else {
                reply = "It is not a Prime Number";
            }
            PrintWriter pw = new PrintWriter(os, true);
            pw.println(reply);
        } catch (Exception e) {
        }

    }
}