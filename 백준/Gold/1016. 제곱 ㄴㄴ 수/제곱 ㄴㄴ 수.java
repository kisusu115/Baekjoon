import java.util.Arrays;
import java.util.Scanner;

public class Main {
    static final int MAX_P = 1000_000;
    static long min;
    static long max;
    static boolean[] isPrime;
    static boolean[] isNoNo;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        min = sc.nextLong();
        max = sc.nextLong();
        isPrime = new boolean[MAX_P+1];
        int gap = (int)(max - min);
        isNoNo = new boolean[gap+1];

        Arrays.fill(isPrime, true);
        Arrays.fill(isNoNo, true);

        for(int i=2; i<=MAX_P; i++){
            if(!isPrime[i]) continue;
            for(int j=i*2; j<=MAX_P; j+=i) isPrime[j] = false;

            long d = (long) i*i;
            long start = ((min+d-1)/d)*d;
            for(long n=start; n<=max; n+=d) {
                int idx = (int)(n-min);
                isNoNo[idx] = false;
            }
        }

        int cnt=0;
        for(int i=0; i<=gap; i++) if(isNoNo[i]) cnt++;
        System.out.println(cnt);
    }
}
