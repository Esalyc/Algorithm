import java.io.*;
import java.util.*;

public class Main {
    static ArrayList<Integer> pressedCoordinate;
    static ArrayList<Integer> Coordinate;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int N;
        N = Integer.parseInt(br.readLine());

        Coordinate = new ArrayList<>(N);
        String[] inp = br.readLine().split(" ");
        for(int i = 0; i < N; i++) {
            Coordinate.add(Integer.parseInt(inp[i]));
        }

        HashSet<Integer> tmp = new HashSet<>(Coordinate);
        pressedCoordinate = new ArrayList<>(tmp);
        Collections.sort(pressedCoordinate);

        // 미리 인덱스를 계산하여 저장
        HashMap<Integer, Integer> indexMap = new HashMap<>();
        for (int i = 0; i < pressedCoordinate.size(); i++) {
            indexMap.put(pressedCoordinate.get(i), i);
        }

        // 매번 indexOf를 호출하지 않고, 미리 계산된 인덱스를 사용
        for (Integer item : Coordinate) {
            bw.write(indexMap.get(item) + " ");
        }

        bw.flush();
        bw.close();
    }
}
