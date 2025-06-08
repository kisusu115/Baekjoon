import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static int D, K;
    static int[] fibos;

    public static void main(String[] args) throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        D = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        fibos = new int[D];
        fibos[0] = fibos[1] = 1;
        for (int i=2; i<D; i++){
            fibos[i] = fibos[i-1] + fibos[i-2];
        }

        for(int A=1; ;A++){
            if((K-fibos[D-3]*A) % fibos[D-2] == 0){
                int B = (K-fibos[D-3]*A) / fibos[D-2];
                System.out.println(A);
                System.out.println(B);
                return;
            }
        }
    }
}
