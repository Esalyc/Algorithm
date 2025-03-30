import java.io.*;
import java.util.HashMap;


public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));      
       
        String[] inp = br.readLine().split(" ");

        int kindsOfCoin = Integer.parseInt(inp[0]);
        int valueBeMaking = Integer.parseInt(inp[1]);

        int[] coins = new int[kindsOfCoin];

        for(int i = 0; i < kindsOfCoin; i++) {
            coins[i] = Integer.parseInt(br.readLine());
        }

        int count = 0;
        int reverse = kindsOfCoin - 1;

        while(valueBeMaking > 0 || reverse >= 0) {
            if((valueBeMaking - coins[reverse]) >= 0) {
                valueBeMaking -= coins[reverse];
                count++;
            }
            else reverse--;
        }

        System.out.println(count);
        

        
    }

    
}
