import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static int F, S, G, U, D;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        F = Integer.parseInt(st.nextToken());
        S = Integer.parseInt(st.nextToken());
        G = Integer.parseInt(st.nextToken());
        U = Integer.parseInt(st.nextToken());
        D = Integer.parseInt(st.nextToken());

        int[] visited = new int[F + 1];
        Arrays.fill(visited, -1);

        Queue<Integer> q = new LinkedList<>();
        q.add(S);
        visited[S] = 0;

        while (!q.isEmpty()) {
            int polled = q.poll();

            if (polled == G) {
                System.out.println(visited[polled]);
                return;
            }

            int up = polled + U;
            int down = polled - D;

            if (up <= F && visited[up] == -1) {
                visited[up] = visited[polled] + 1;
                q.add(up);
            }

            if (down >= 1 && visited[down] == -1) {
                visited[down] = visited[polled] + 1;
                q.add(down);
            }
        }

        System.out.println("use the stairs");
    }
}
