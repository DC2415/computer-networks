import java.util.*;
public class FrameCharacterCount {
    

    public static void main(String[] args) {
        // receiver
        Scanner sc =new Scanner(System.in);
        String data=sc.next();
        int a=Integer.parseInt(data.charAt(0));
        for(int i=0;i<data.length();i+=a){
            
                System.out.print(data.substring(i, a ));
            

        }
    }
}
