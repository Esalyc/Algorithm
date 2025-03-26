import java.io.*;
import java.util.*;


public class Main {
    public static final int INF = 987654321;
    static int rows;
    static int cols;
    static Queue<Point> bfsQueue;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));      
       
        String[] inp = br.readLine().split(" ");

        rows = Integer.parseInt(inp[0]);
        cols = Integer.parseInt(inp[1]);

        int[][] map = new int[rows][cols];
        Point AP = new Point(0,0);

        int[][] resultMap = new int[rows][cols];
        boolean[][] visited = new boolean[rows][cols];

        for (int i = 0; i < rows; i++) {
            String[] row = br.readLine().split(" ");
            for (int j = 0; j < cols; j++) {
                map[i][j] = Integer.parseInt(row[j]);
                if(map[i][j] == 2) {
                    AP = new Point(i,j); 
                    visited[i][j] = true;
                }
            }
        }        

        
        
        bfsQueue = new LinkedList<>();
        bfsQueue.add(AP);
        bfsQueue.add(new Point(INF,INF));


        BFS(map, resultMap, visited);
        
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                System.out.print(resultMap[i][j] == map[i][j] && map[i][j] == 0 ? 0 : (map[i][j] == 1 && resultMap[i][j] == 0 ? -1 : resultMap[i][j]));
                System.out.print(" ");
            }
            System.out.println("");
        }
        
    }


    

    static void BFS(int[][] map, int[][] resultMap, boolean[][] visited) {
        int[] dx = {0, 1, 0, -1};
        int[] dy = {1, 0, -1, 0};
        
        int distance = 0;

        while (!bfsQueue.isEmpty()) {
            Point temp = bfsQueue.remove();

            if (temp.y == INF) {
                if (!bfsQueue.isEmpty()) {
                    bfsQueue.add(new Point(INF, INF));
                    distance++;
                }
                continue;
            }

            resultMap[temp.y][temp.x] = distance;

            for (int i = 0; i < 4; i++) {
                int newY = temp.y + dy[i];
                int newX = temp.x + dx[i];
                
                if (inRange(newY, newX) && !visited[newY][newX] && map[newY][newX] != 0) {
                    visited[newY][newX] = true;  
                    bfsQueue.add(new Point(newY, newX)); 
                }
            }
        }
    }

    static boolean inRange(int y, int x) {
        if(y < 0 || x < 0 || y >= rows || x >= cols) return false;
        return true;
    }
}

class Point {
    int y;
    int x;

    Point(int y, int x) {
        this.y = y;
        this.x = x;
    }
}