import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;
import java.util.Stack;

public class Main {
    static int N;
    static int M;
    static int[][] arr;
    static int[][] dist;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        M = sc.nextInt();
        arr = new int[N+1][N+1];
        dist = new int[N+1][N+1];
        for(int i=0; i<=N; i++) {
            for(int j=0; j<=N; j++) {
                dist[i][j] = -1;
            }
        }

        for(int i=0; i<M; i++){
            int n1 = sc.nextInt();
            int n2 = sc.nextInt();
            arr[n1][n2] = 1;
            arr[n2][n1] = 1;
        }

        int min = Integer.MAX_VALUE;
        int result = 0;
        for (int i=1; i<=N; i++) {
            int sumI = bfs(i);
            if(min > sumI) {
                min = sumI;
                result = i;
            }
        }
        System.out.println(result);
    }

    private static int bfs(int n) {
        Queue<Integer> outerQ = new LinkedList<>();
        Queue<Integer> innerQ = new LinkedList<>();
        dist[n][n] = 0;
        outerQ.add(n);
        int depth = 1;

        while(true){
            int polled = outerQ.remove();
            for(int i=1; i<=N; i++){
                if(dist[n][i] != -1) continue;
                if(arr[polled][i] == 1){
                    innerQ.add(i);
                    dist[n][i] = depth;
                }
            }
            if(!outerQ.isEmpty()) continue;
            while (!innerQ.isEmpty()){
                outerQ.add(innerQ.remove());
            }
            depth++;
            if(outerQ.isEmpty()) break;
        }

        int sum=0;
        for (int i=1; i<=N; i++){
            sum += dist[n][i];
        }
        return sum;
    }
}