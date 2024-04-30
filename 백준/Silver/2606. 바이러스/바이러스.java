import java.util.Arrays;
import java.util.Scanner;

public class Main {
    static int[][] graph;
    static boolean[] visited;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n, m;
        n = sc.nextInt();
        m = sc.nextInt();
        graph = new int[n+1][n+1];
        visited = new boolean[n+1];
        for(int i = 0; i < m; i++) {
            int a, b;
            a = sc.nextInt();
            b = sc.nextInt();
            graph[a][b] = 1;
            graph[b][a] = 1;
        }
        /*for(int i = 0; i <= n; i++) {
            System.out.println(Arrays.toString(graph[i]));
        }*/
        int[] count = new int[n+1];
        count = counting(count,1 ,n);
        //System.out.println("\n" + Arrays.toString(count));
        int result = 0;

        for(int i = 1; i <= n; i++) {
            if(count[i] == 1) result++;
        }
        System.out.print(result);



    }
    static int[] counting(int[] count, int start, int n) {
        visited[start] = true;
        for(int i = 1; i <= n; i++) {
            if(graph[start][i] == 1 && !visited[i]) {
                count[i] = 1;
                //System.out.println("\n" + Arrays.toString(count));
                counting(count, i, n);
            }
        }

        return count;
    }
}