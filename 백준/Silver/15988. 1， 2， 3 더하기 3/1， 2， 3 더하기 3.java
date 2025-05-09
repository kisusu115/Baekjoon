import java.util.*;

public class Main {
    static int MAX_N = 1000000;
    static int DIVIDE = 1000000009;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        long[] dp = new long[MAX_N+1];
        dp[1] = 1; dp[2] = 2; dp[3] = 4;

        for(int i=4; i<=MAX_N; i++){
            dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
            dp[i] %= DIVIDE;
        }

        int T = sc.nextInt();
        while(T>0){
            int N = sc.nextInt();
            System.out.println(dp[N]);
            T--;
        }
    }
}