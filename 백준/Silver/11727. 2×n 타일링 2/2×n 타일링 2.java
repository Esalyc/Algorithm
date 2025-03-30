import java.io.*;


public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));      
       
        int weight = Integer.parseInt(br.readLine());

        int DP[] = new int[1001];

        DP[1] = 1;
        DP[2] = 3;

        for(int i = 3; i <= weight; i++) {
            DP[i] = (DP[i-1] + (DP[i-2] * 2)) % 10007;
        }

        System.out.println(DP[weight]);
        

        
    }

    
}
