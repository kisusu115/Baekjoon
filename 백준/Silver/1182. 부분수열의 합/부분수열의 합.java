import java.util.Scanner;

public class Main {
    static int N;
    static int S;
    static int[] ipts;
    static int cnt=0;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        S = sc.nextInt();
        ipts = new int[N];

        for (int i = 0; i < N; i++) {
            ipts[i] = sc.nextInt();
        }

        dfs(0, 0);

        if(S==0) System.out.println(cnt-1);
        else System.out.println(cnt);
    }

    private static void dfs(int depth, int sum) {
        if(depth==N){
            if(sum==S) cnt++;
            return;
        }
        dfs(depth+1, sum);
        dfs(depth+1, sum+ipts[depth]);
    }
}