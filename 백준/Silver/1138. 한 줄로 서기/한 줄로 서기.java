import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int[] ipts = new int[N+1];
        int[] result = new int[N+1];
        for(int i=1; i<=N; i++){
            ipts[i] = sc.nextInt();
        }

        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                if(result[j]==0){
                    if(ipts[i] != 0) ipts[i]--;
                    else{
                        result[j] = i;
                        break;
                    }
                }
            }
        }
        for(int i=1; i<=N; i++){
            System.out.print(result[i]+" ");
        }
    }
}