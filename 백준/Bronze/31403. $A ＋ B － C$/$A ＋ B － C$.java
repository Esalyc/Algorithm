import java.io.*;


public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));      
       
        String[] inp = new String[3];

        for(int i = 0; i < 3; i++) {
            inp[i] = br.readLine();
        }

        System.out.println(Integer.parseInt(inp[0]) + Integer.parseInt(inp[1]) - Integer.parseInt(inp[2]));
        System.out.println(Integer.valueOf(inp[0] + inp[1]) - Integer.valueOf(inp[2]));
        
    }

    
}
