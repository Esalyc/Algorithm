import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());
        int a;
        int[] DP = new int[11];
        DP[1] = 1;
        DP[2] = 2;
        DP[3] = 4;
        for(int i = 0; i < n; i++) {
            a = Integer.parseInt(br.readLine());

            for(int j = 4; j <= a; j++) {
                DP[j] = DP[j-1] + DP[j-2] + DP[j-3];
            }

            bw.write(DP[a] + "\n");
        }

        bw.flush();
        bw.close();
    }
}