import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static int K, N;
    static long[] wire;

    public static void main(String[] args) throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        K = Integer.parseInt(st.nextToken());
        N = Integer.parseInt(st.nextToken());

        wire = new long[K];
        long maxL = 0;
        for(int i=0; i<K; i++) {
            wire[i] = Integer.parseInt(br.readLine());
            maxL = Math.max(maxL, wire[i]);
        }

        long min = 1; long max = maxL+1;
        while(min<max){
            long mid = (min+max)/2;
            if(wNum(mid) >= N) min = mid+1;
            else max = mid;
        }
        System.out.println(min-1);
    }

    private static long wNum(long length){
        long sum=0;
        for(int i=0; i<K; i++) sum += wire[i]/length;
        return sum;
    }
}
