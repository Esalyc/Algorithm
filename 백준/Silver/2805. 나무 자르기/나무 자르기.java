import java.io.*;

public class Main {
    static int[] tree;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] inp1 = br.readLine().split(" ");

        int treeCount = Integer.parseInt(inp1[0]);
        int needWood = Integer.parseInt(inp1[1]);
        tree = new int[treeCount];

        String[] inp2 = br.readLine().split(" ");
        int max = 0;
        for(int i = 0; i < treeCount; i++) {
            tree[i] = Integer.parseInt(inp2[i]);
            max = Math.max(tree[i], max);
        }
        System.out.println(binarySearch(max, needWood));


    }

    static int binarySearch(int high, long key) {
        int mid = 0;
        int low = 0;
        long wood;
        while(low <= high) {
            mid = (low + high) / 2;
            wood = 0;
            for (Integer height : tree) {
                wood += Math.max(height - mid, 0);
            }
            if (key == wood) return mid;
            if (key > wood) high = mid - 1;
            else low = mid + 1;
        }
        wood = 0;
        for (Integer height : tree) {
            wood += Math.max(height - mid, 0);
        }
        return high;
    }
}