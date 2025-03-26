import java.util.Scanner;
import static java.lang.Math.pow;

public class Main {
    static int count = 0;

    public static void main(String [] args) {
        Scanner sc = new Scanner(System.in);

        int N, row, col;

        N = sc.nextInt();
        row = sc.nextInt();
        col = sc.nextInt();

        int len = (int)pow(2, N);
        search(len, row+1, col+1);
        System.out.println(count);

    }

    static void search(int len, int row, int col) {
        if(row <= len/2 && col <= len/2) {
            len /= 2;
        } else if (row > len/2 && col > len/2) {
            len /= 2;
            row -= len;
            col -= len;
            count += len*len*3;
        } else if (row > col) {
            len /= 2;
            row -= len;
            count += len*len*2;
        } else {
            len /=2;
            col -= len;
            count += len*len;
        }

        if(len != 1) search(len, row, col);
    }
}

