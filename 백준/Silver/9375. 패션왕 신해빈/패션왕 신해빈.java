import java.io.*;


public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));    

        int numberOfClothes;

        int testCase = Integer.parseInt(br.readLine());
        String[] inp;
        
        for(int i = 0; i < testCase; i++) {
            numberOfClothes = Integer.parseInt(br.readLine());
            String[] clothes = new String[30];
            int[] clothesCount = new int[30];
            int typeCount = 1;
            int result = 1;
            for(int j = 0; j < numberOfClothes; j++) {
                inp = br.readLine().split(" ");
                for(int k = 0; k < typeCount; k++) {
                    if(inp[1].equals(clothes[k])) {
                        clothesCount[k]++;
                        break;
                    }
                    if(k == typeCount - 1) {
                        clothes[k] = inp[1];
                        clothesCount[k] ++;
                        typeCount++;
                        break;
                    } 
                }
            }
            for(int j = 0; j < typeCount - 1; j++) {
                result *= 1 + clothesCount[j];
            }
            System.out.println(result-1);
            

        }
 
    }
}
