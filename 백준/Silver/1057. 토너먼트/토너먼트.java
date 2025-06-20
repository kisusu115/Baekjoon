import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    static final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static int N, K, Y;

    public static void main(String[] args) throws IOException {
        String str = br.readLine();
        String[] arr = str.split(" ");
        N = Integer.parseInt(arr[0]);
        K = Integer.parseInt(arr[1]);
        Y = Integer.parseInt(arr[2]);

        int cnt = 0;
        while (K!=Y) {
            K=(K+1)/2;
            Y=(Y+1)/2;
            cnt++;
        }
        System.out.println(cnt);
    }
}
