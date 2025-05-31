import java.io.BufferedWriter;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.math.BigInteger;
import java.util.Scanner;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();
        System.out.println(BigInteger.TWO.pow(N).subtract(BigInteger.ONE));

        if(N<=20) {
            hanoi(N, 1, 3);
            bw.flush();
        }

        bw.close();
    }

    private static void hanoi(int height, int start, int end) throws IOException {
        if (height == 1) {
            bw.write(start+" "+end+"\n");
            return;
        }

        hanoi(height-1, start, 6-start-end);
        bw.write(start+" "+end+"\n");
        hanoi(height-1, 6-start-end, end);
    }
}
