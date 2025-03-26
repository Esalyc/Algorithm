import java.io.*;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Queue;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int box[][]; 
        Queue<Coordinate> ripenTomato = new LinkedList<>(); 
        
        String[] dimensions = br.readLine().split(" ");
        int M = Integer.parseInt(dimensions[0]);
        int N = Integer.parseInt(dimensions[1]);

        box = new int[N][M];

        int inp;
        for(int rows = 0; rows < N; rows++) {
            String[] row = br.readLine().split(" ");
            for(int cols = 0; cols < M; cols++) {
                inp = Integer.parseInt(row[cols]);
                box[rows][cols] = inp;
                if(inp == 1) ripenTomato.add(new Coordinate(rows, cols));
            }
        }
        int[] dr = {-1, 1, 0 , 0};
        int[] dc = {0, 0, -1, 1};
        int count = 0;
        while(!ripenTomato.isEmpty()) {
            int size = ripenTomato.size();

            for(int i = 0; i < size; i++) {
                Coordinate cd = ripenTomato.poll();
                int rows = cd.getRows();
                int cols = cd.getCols();

                for(int j = 0; j < 4; j++) {
                    int newRows = rows + dr[j];
                    int newCols = cols + dc[j];

                    if(newRows >= 0 && newCols >= 0 && newRows < N && newCols < M && box[newRows][newCols] == 0) {
                        box[newRows][newCols] = 1;
                        ripenTomato.add(new Coordinate(newRows, newCols));
                    }
                }
            }
            if(!ripenTomato.isEmpty()) count++;
        }

        boolean isAllRipen = true;
        for(int rows = 0; rows < N; rows++) {
            for(int cols = 0; cols < M; cols++) {
                if(box[rows][cols] == 0) isAllRipen = false;
            }
        }
        bw.write(isAllRipen ? String.valueOf(count) : "-1");

        bw.flush();
        bw.close();
    }
}

class Coordinate {
    int rows;
    int cols;

    Coordinate(int rows, int cols) {
        this.rows = rows;
        this.cols = cols;
    }

    public int getRows() {
        return rows;
    }
    public int getCols() {
        return cols;
    }


}