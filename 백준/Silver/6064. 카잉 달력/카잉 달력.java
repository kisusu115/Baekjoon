import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        for(int i=0; i<T; i++){
            int M = sc.nextInt(); int N = sc.nextInt();
            int x = sc.nextInt(); int y = sc.nextInt();

            long MD = sharedMinDup(M, N);
            boolean flag = false;
            for(long year=x; year<=MD; year+=M){
                if(((year-1)%M+1)==x && ((year-1)%N+1)==y){
                    System.out.println(year);
                    flag = true;
                    break;
                }
            }
            if(flag) continue;
            System.out.println(-1);
        }
    }

    private static int sharedMaxSup(int M, int N){
        if(M<N){
            int tmp=M;
            M=N; N=tmp;
        }
        while(N!=0){
            int mod = M%N;
            M=N; N=mod;
        }
        return M;
    }

    private static int sharedMinDup(int M, int N) {
        return M*N/sharedMaxSup(M,N);
    }
}