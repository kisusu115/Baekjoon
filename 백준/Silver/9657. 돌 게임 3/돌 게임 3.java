import java.util.Scanner;

public class Main {
    static final int MAX_N = 1001;
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        boolean[] cyWin = new boolean[MAX_N];
        cyWin[2] = true;

        for(int i=5; i<=N; i++){
            if(cyWin[i-1] || cyWin[i-3] || cyWin[i-4]) ;
            else cyWin[i] = true;
        }

        String result = cyWin[N] ? "CY" : "SK";
        System.out.println(result);
    }
}
