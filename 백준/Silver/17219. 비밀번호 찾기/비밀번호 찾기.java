import java.io.*;
import java.util.HashMap;


public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));      
       
        String[] inp = br.readLine().split(" ");

        int numberOfSite = Integer.parseInt(inp[0]);
        int numberOfSiteBeFound = Integer.parseInt(inp[1]);

        HashMap<String, String> memoList = new HashMap<String, String>();
        String[] siteBeFound = new String[numberOfSiteBeFound];

        for(int i = 0; i < numberOfSite; i++) {
            inp = br.readLine().split(" ");
            memoList.put(inp[0], inp[1]);
        }
        for(int i = 0; i < numberOfSiteBeFound; i++) {
            siteBeFound[i] = br.readLine();
        }

        for(int i = 0; i < numberOfSiteBeFound; i++) {
            System.out.println(memoList.get(siteBeFound[i]));
        }
        

        
    }

    
}
