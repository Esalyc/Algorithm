import java.util.Scanner;


public class Main {
    static int vertexCount, edgeCount;
    static int[][] graph;

    static boolean[] visited;
    static int count = 0;
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        vertexCount = sc.nextInt();
        graph = new int[vertexCount+1][vertexCount+1];
        visited = new boolean[vertexCount+1];

        edgeCount = sc.nextInt();
        for (int i = 0; i < edgeCount; i++) {
            int u, v;
            u = sc.nextInt();
            v = sc.nextInt();
            graph[u][v] = 1;
            graph[v][u] = 1;
            sc.nextLine();
        }

        for(int i = 1; i <= vertexCount; i++) {
            if(!visited[i]) {
                DFS(i);
                count++;
            }
        }
        System.out.println(count);

    }
    static void DFS(int v) {
        int u;
        visited[v]= true;
        for (u = 1; u <= vertexCount; u++)
            if(graph[v][u] == 1 && !visited[u])
                DFS(u);
    }
}
