import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Collections;
import java.util.StringTokenizer;

public class Main {
    static int N, M;
    static Integer[] pows, boxes;
    static boolean[] visited;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());

        pows = new Integer[N];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) pows[i] = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());
        M = Integer.parseInt(st.nextToken());

        boxes = new Integer[M];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < M; i++) boxes[i] = Integer.parseInt(st.nextToken());

        Arrays.sort(pows, Collections.reverseOrder());
        Arrays.sort(boxes, Collections.reverseOrder());

        if (boxes[0] > pows[0]) {
            System.out.println(-1);
            return;
        }

        int result = 0;
        int moved = 0;
        visited = new boolean[M];

        while (moved<M) {
            int powIdx = 0;
            for (int boxIdx=0; boxIdx<M; boxIdx++) {
                if (powIdx==N) break;
                if (visited[boxIdx]) continue;

                if (pows[powIdx]>=boxes[boxIdx]) {
                    visited[boxIdx] = true;
                    powIdx++;
                    moved++;
                }
            }
            result++;
        }

        System.out.println(result);
    }
}
