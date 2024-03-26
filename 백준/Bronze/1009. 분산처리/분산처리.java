import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		int N, a, b, data;
		
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		
		for(int R = 0; R < N; R++) {
			a = sc.nextInt();
			b = sc.nextInt();
			data = 1;
			
			
			
			for(int i = 0; i < b; i++) {
				data *= a;
				data %= 10;
			}
            if(data == 0) data = 10;
			
			System.out.println(data);
		}
		
		sc.close();
	}
}
