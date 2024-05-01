import java.io.*;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int N, M;
        String[] inp = br.readLine().split(" ");
        N = Integer.parseInt(inp[0]);
        M = Integer.parseInt(inp[1]);

        int[] array = new int[N];
        int[] accSum = new int[N+1];

        inp = br.readLine().split(" ");

        for(int i = 0; i < N; i++) {
            array[i] = Integer.parseInt(inp[i]);
            accSum[i] = i == 0 ? array[i] : accSum[i-1] + array[i];
        }
        //bw.write(Arrays.toString(accSum) + "\n");
        for(int i = 0; i < M; i++) {
            inp = br.readLine().split(" ");

            int start = Integer.parseInt(inp[0]);
            int end = Integer.parseInt(inp[1]);


            bw.write(accSum[end-1] - accSum[start == 1 ? N : start-2] + "\n");
        }

        bw.flush();
        bw.close();
    }
}