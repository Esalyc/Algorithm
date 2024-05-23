import java.util.Scanner;


public class Main {
    static int[] heap;
    static int top = 0;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int testCase = Integer.parseInt(sc.nextLine());
        heap = new int[testCase];
        for(int i = 0; i < testCase; i++) {
            int inp = Integer.parseInt(sc.nextLine());
            if(inp == 0) {
                System.out.println(deleteNode());
            }
            else {
                insertNode(inp);
            }
        }
        sc.close();
    }

    static void insertNode(int key) {
        int i = ++top;
        while(i != 1 && key < heap[i/2]) {
            heap[i] = heap[i/2];
            i /= 2;
        }
        heap[i] = key;
    }
    static int deleteNode() {
        if(top == 0) return 0;
        int max = heap[1];
        int tmp = heap[top--];

        int parent = 1;
        int child = 2;

        while(child <= top) {
            if(child < top && (heap[child] > heap[child + 1])) child++;
            if(tmp <= heap[child]) break;
            heap[parent] = heap[child];
            parent = child;
            child *= 2;
        }
        heap[parent] = tmp;

        return max;
    }


}