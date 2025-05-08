import java.util.*;

public class Main {
    static int MAX_NUM = 4000000;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();
        if(N==1 || N==2) {
            System.out.println(N-1);
            return;
        }

        boolean[] arrForCheck = new boolean[MAX_NUM+1];
        int[] primes = new int[MAX_NUM+1];

        primes[0] = 0;
        int pIdx=1;
        for(int i=2; i<=N; i++){
            if(arrForCheck[i]) continue;
            primes[pIdx] = i;
            pIdx++;

            for(int idx=i*2; idx<=N; idx+=i){
                if(arrForCheck[idx]) continue;
                arrForCheck[idx] = true;
            }
        }

        int p1=0; int p2=1;
        int sum=primes[p2];
        int cnt=0;

        while (p2 < pIdx) {
            if (sum <= N) {
                if (sum == N) cnt++;
                p2++;
                sum += primes[p2];
            } else {
                p1++;
                sum -= primes[p1];
            }
        }

        System.out.println(cnt);
    }
}