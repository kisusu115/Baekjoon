import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;
import java.util.Stack;

public class Main {
    static final int MAX_LEN = 100000;
    static int N, K;
    static int[] dist;
    static int[] prev;
    static boolean[] visited;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        K = sc.nextInt();

        dist = new int[MAX_LEN + 1];
        prev = new int[MAX_LEN + 1];
        visited = new boolean[MAX_LEN + 1];

        bfs();
        System.out.println(dist[K]);
        printPath();
    }

    private static void bfs() {
        Queue<Integer> q = new LinkedList<>();
        q.add(N);
        visited[N] = true;

        while (!q.isEmpty()) {
            int polled = q.poll();

            int p1 = polled - 1;
            if (p1>=0 && !visited[p1]) {
                visited[p1] = true;
                dist[p1] = dist[polled] + 1;
                prev[p1] = polled;
                q.add(p1);
                if (p1 == K) return;
            }

            int p2 = polled + 1;
            if (p2<=MAX_LEN && !visited[p2]) {
                visited[p2] = true;
                dist[p2] = dist[polled] + 1;
                prev[p2] = polled;
                q.add(p2);
                if (p2 == K) return;
            }

            int p3 = polled * 2;
            if (p3<=MAX_LEN && !visited[p3]) {
                visited[p3] = true;
                dist[p3] = dist[polled] + 1;
                prev[p3] = polled;
                q.add(p3);
                if (p3 == K) return;
            }
        }
    }

    private static void printPath() {
        Stack<Integer> resultS = new Stack<>();
        int now = K;
        while(now!=N){
            resultS.add(now);
            now = prev[now];
        }
        System.out.print(N);
        while(!resultS.isEmpty()) System.out.print(" "+resultS.pop());
    }
}
