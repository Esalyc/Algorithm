import java.util.Scanner;
import java.util.StringTokenizer;


public class Main {
    static int[][] paper;
    static int white = 0;
    static int blue = 0;
    public static void main(String[] args) {
        int length;

        Scanner sc = new Scanner(System.in);

        length = sc.nextInt();

        paper = new int[length][length];

        for(int i = 0; i < length; i++) {
            for(int j = 0; j < length; j++) paper[i][j] = sc.nextInt();
        }
        slice(0, 0, length, length);

        System.out.println(white);
        System.out.println(blue);
    }

    static void slice(int x1, int y1, int x2, int y2) {
        switch (are_equals(x1, y1, x2, y2)) {
            case 1 :
                blue++;
                return;
            case -1 :
                white++;
                return;
        }
        int d = (x2 - x1) / 2;

        slice(x1 + d, y1 + d, x2, y2);
        slice(x1, y1, x2 - d, y2 - d);
        slice(x1, y1 + d, x2 - d, y2);
        slice(x1 + d, y1, x2, y2 - d);




    }
    static int are_equals(int x1, int y1, int x2, int y2) {
        boolean check = paper[y1][x1] == 1;

        for(int i = y1; i < y2; i++) {
            for(int j = x1; j < x2; j++) {
                if(paper[i][j] != (check ? 1 : 0)) return 0;
            }
        }
        return check ? 1 : -1;
    }
}

