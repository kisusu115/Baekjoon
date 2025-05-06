import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int P = sc.nextInt();

        for(int i=0; i<P; i++){
            int N = sc.nextInt();
            int M = sc.nextInt();
            doFibo(N, M);
        }
    }

    public static void doFibo(int N, int M){
        int[] fs = new int[3];
        fs[0]=0; fs[1]=1;
        int cnt=2;
        while(true){
            int idx = cnt%3;
            fs[idx] = (fs[(idx+1)%3] + fs[(idx+2)%3]) % M;

            if(fs[idx] == 0 && fs[(idx+2)%3] == 1){
                System.out.println(N+" "+cnt);
                return;
            }
            cnt++;
        }
    }
}