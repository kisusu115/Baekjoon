import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static final int MAX_COST = 10000;
    static int N, M;
    static int[] mems, costs;
    static int[][] dp;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        mems = new int[N];
        costs = new int[N];

        st = new StringTokenizer(br.readLine());
        for(int i=0; i<N; i++) mems[i] = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());
        for(int i=0; i<N; i++) costs[i] = Integer.parseInt(st.nextToken());

        int result = MAX_COST+1;
        dp = new int[N][MAX_COST+1];
        dp[0][costs[0]] = mems[0];
        if(mems[0]>=M) result = costs[0];

        for(int c=0; c<=MAX_COST; c++){
            for(int i=1; i<N; i++){
                if(c<costs[i]) dp[i][c] = dp[i-1][c];
                else dp[i][c] = Math.max(dp[i-1][c], dp[i-1][c-costs[i]]+mems[i]);

                if(dp[i][c]>=M) result = Math.min(result, c);
            }
        }

        System.out.println(result);
    }
}
