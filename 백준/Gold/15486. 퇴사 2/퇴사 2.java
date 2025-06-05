import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static int N;
    static int[] t, p, dp;

    public static void main(String[] args) throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        t = new int[N+2];
        p = new int[N+2];
        dp = new int[N+2];

        for (int i = 1; i <= N; i++) {
            st = new StringTokenizer(br.readLine());
            t[i] = Integer.parseInt(st.nextToken());
            p[i] = Integer.parseInt(st.nextToken());
        }

        for (int i=1; i<=N; i++) {
            dp[i] = Math.max(dp[i], dp[i-1]);

            if (i+t[i]<=N+1) {
                dp[i+t[i]] = Math.max(dp[i+t[i]], dp[i]+p[i]);
            }
        }

        System.out.println(Math.max(dp[N], dp[N+1]));
    }
}
