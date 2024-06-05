import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] str = new String[3];
        for(int i = 0; i < 3; i++) {
            str[i] = br.readLine();
            switch (str[i]) {
                case "FizzBuzz":
                case "Fizz":
                case "Buzz":
                    break;
                default:
                    printfFizzBuzz(Integer.parseInt(str[i]) + 3 - i);
            }
        }

    }

    static void printfFizzBuzz(int n) {
        if(n % 15 == 0) System.out.println("FizzBuzz");
        else if(n % 3 == 0) System.out.println("Fizz");
        else if(n % 5 == 0) System.out.println("Buzz");
        else System.out.println(n);
        System.exit(0);
    }
}