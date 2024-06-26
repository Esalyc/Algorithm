import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        int n;
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        int[] DP = new int[1000001];
        DP[1] = 0;

        for(int i = 2; i <= n; i++) {
            DP[i] = DP[i - 1] + 1;

            if (i % 2 == 0) {
                DP[i] = Math.min(DP[i], DP[i / 2] + 1);
            } 
            if (i % 3 == 0) {
                DP[i] = Math.min(DP[i], DP[i / 3] + 1);
            }
        }
        
        System.out.print(DP[n]);


        sc.close();

    }

}