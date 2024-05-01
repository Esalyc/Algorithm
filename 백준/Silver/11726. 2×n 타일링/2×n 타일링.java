import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());
        bw.write(Integer.toString(fib(n) % 10007));

        bw.flush();
        bw.close();
    }

    static int fib(int n) {
        if(n == 1) return 1;
        if(n == 2) return 2;
        int[] DP = new int[n+1];
        DP[1] = 1;
        DP[2] = 2;

        for(int i = 3; i <=n; i++) {
            DP[i] = (DP[i-1] + DP[i-2]) % 10007;
        }
        return DP[n];

    }
}