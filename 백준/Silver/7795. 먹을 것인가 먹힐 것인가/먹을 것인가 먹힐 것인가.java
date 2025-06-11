import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static int T, N ,M;
    static int[] a, b;

    public static void main(String[] args) throws IOException {
        T = Integer.parseInt(br.readLine());

        while(T-- > 0){
            StringTokenizer st = new StringTokenizer(br.readLine());
            N = Integer.parseInt(st.nextToken());
            M = Integer.parseInt(st.nextToken());
            a = new int[N]; b = new int[M];

            st = new StringTokenizer(br.readLine());
            for(int i=0; i<N; i++) a[i] = Integer.parseInt(st.nextToken());

            st = new StringTokenizer(br.readLine());
            for(int i=0; i<M; i++) b[i] = Integer.parseInt(st.nextToken());

            Arrays.sort(b);

            int result = 0;
            for (int i=0; i<N; i++) result += lessBCnt(a[i]);
            System.out.println(result);
        }
    }

    static int lessBCnt(int aNum) {
        int left = 0;
        int right = b.length;

        while (left<right) {
            int mid = (left+right)/2;
            if (b[mid]<aNum) left = mid+1;
            else right = mid;
        }

        return left;
    }
}
