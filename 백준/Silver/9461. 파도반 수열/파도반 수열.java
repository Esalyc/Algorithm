import java.io.*;


public class Main {
    static long[] DP;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));    

        int caseCount = Integer.parseInt(br.readLine());
        DP = new long[101];
        DP[1] = 1; DP[2] = 1; DP[3] = 1; DP[4] = 2; DP[5] = 2;
        
        for(int i = 0; i < caseCount; i++) {
            int inp = Integer.parseInt(br.readLine());
            System.out.println(inp <= 5 ? DP[inp] : P(inp));
        }
    }

    static long P(int N) {
        if(DP[N] == 0) DP[N] = P(N-1) + P(N-5);
        return DP[N];
    }
}

