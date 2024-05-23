import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        for(int i = sc.nextInt(); i > 0; i--) {
            int count = 0;
            int M, N, K;
            M = sc.nextInt(); N = sc.nextInt(); K = sc.nextInt();
            Graph a = new Graph(M, N);
            for(int j = 0; j < K; j++) {
                int x, y;
                x = sc.nextInt();
                y = sc.nextInt();
                a.addVertex(new Point(x, y));
            }
            for(int j = 0; j < N; j++) {
                for(int k = 0; k < M; k++) {
                    if(!a.graph[j][k].isVisited && a.graph[j][k].vertex) {
                        count++;
                        a.dfs(new Point(k, j));
                    }
                }
            }
            System.out.println(count);


        }
        sc.close();
    }


}

class Graph {
    Point[][] graph;

    Graph(int x, int y) {
        this.graph = new Point[y][x];
        for(int i = 0; i < y; i++) {
            for(int j = 0; j < x; j++) {
                this.graph[i][j] = new Point(j, i);
                this.graph[i][j].x = j;
                this.graph[i][j].y = i;
            }
        }
    }

    void addVertex(Point a) {
        this.graph[a.y][a.x] = a;
        this.graph[a.y][a.x].vertex = true;

    }


   void dfs(Point a) {
        this.graph[a.y][a.x].isVisited = true;

        if(a.y != 0) {
            if(!this.graph[a.y-1][a.x].isVisited && this.graph[a.y-1][a.x].vertex) {
                dfs(new Point(a.x, a.y - 1));
            }
        }
       if(a.x != 0) {
           if(!this.graph[a.y][a.x-1].isVisited && this.graph[a.y][a.x-1].vertex) {
               dfs(new Point(a.x-1, a.y));
           }
       }
       if(a.y != this.graph.length - 1) {
           if(!this.graph[a.y+1][a.x].isVisited && this.graph[a.y+1][a.x].vertex) {
               dfs(new Point(a.x, a.y+1));
           }
       }
       if(a.x != this.graph[0].length - 1) {
           if(!this.graph[a.y][a.x+1].isVisited && this.graph[a.y][a.x+1].vertex) {
               dfs(new Point(a.x+1, a.y));
           }
       }

   }
}

class Point {
    int x;
    int y;
    boolean isVisited;
    boolean vertex;

    Point(int x, int y) {
        this.x = x;
        this.y = y;
        isVisited = false;
    }
}