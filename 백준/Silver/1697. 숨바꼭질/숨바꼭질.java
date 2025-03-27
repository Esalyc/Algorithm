import java.io.*;
import java.util.LinkedList;
import java.util.Queue;


public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));      
       
        String[] inp = br.readLine().split(" ");

        int N = Integer.parseInt(inp[0]);
        int K = Integer.parseInt(inp[1]);
        
        

        BFS(0, N, K);
        

        
    }

    static boolean BFS(int count, int currentPostion, int targetPostion) {
        boolean visited[] = new boolean[100001];
        Queue<Integer> BFSQueue = new LinkedList<>();
        BFSQueue.add(currentPostion);
        visited[currentPostion] = true;
        while(!BFSQueue.isEmpty()) {
            int size = BFSQueue.size();
            for(int i = 0; i < size; i ++) {
                currentPostion = BFSQueue.remove();
                if(currentPostion == targetPostion) {
                    System.out.println(count);
                    break;
                }      
                if(currentPostion - 1 >= 0 && !visited[currentPostion - 1]) {
                    visited[currentPostion - 1] = true;
                    BFSQueue.add(currentPostion - 1);
                }
                if(currentPostion + 1 <= 100000 && !visited[currentPostion + 1]) {
                    visited[currentPostion + 1] = true;
                    BFSQueue.add(currentPostion + 1);
                }
                if(currentPostion * 2 <= 100000 && !visited[currentPostion * 2]) {
                    visited[currentPostion * 2] = true;
                    BFSQueue.add(currentPostion * 2);
                }

            }
            count++;                       
        }
        return false;
    }
}