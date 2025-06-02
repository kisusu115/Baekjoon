import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    static int TC, N, M, W;
    static ArrayList<Edge> edges;

    public static class Edge {
        int start;
        int end;
        int value;

        Edge (int start, int end, int value) {
            this.start = start;
            this.end = end;
            this.value = value;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        TC = Integer.parseInt(st.nextToken());

        while(TC-->0) {
            st = new StringTokenizer(br.readLine());
            N = Integer.parseInt(st.nextToken());
            M = Integer.parseInt(st.nextToken());
            W = Integer.parseInt(st.nextToken());
            edges = new ArrayList<>();

            for (int i = 0; i < M; i++) {
                st = new StringTokenizer(br.readLine());
                int S = Integer.parseInt(st.nextToken());
                int E = Integer.parseInt(st.nextToken());
                int T = Integer.parseInt(st.nextToken());
                edges.add(new Edge(S, E, T));
                edges.add(new Edge(E, S, T));
            }

            for (int i = 0; i < W; i++) {
                st = new StringTokenizer(br.readLine());
                int S = Integer.parseInt(st.nextToken());
                int E = Integer.parseInt(st.nextToken());
                int T = Integer.parseInt(st.nextToken());
                edges.add(new Edge(S, E, -T));
            }

            for(int i=1; i<=N; i++) edges.add(new Edge(0, i, 0));

            boolean yesFlag = bf(0);
            if(yesFlag) System.out.println("YES");
            else System.out.println("NO");
        }
    }

    private static boolean bf(int startN){
        int[] distance = new int[N+2];
        Arrays.fill(distance, Integer.MAX_VALUE);
        distance[startN] = 0;

        for(int i=0; i<N+1; i++){
            for(Edge edge:edges){
                if(distance[edge.start] != Integer.MAX_VALUE && distance[edge.end] > distance[edge.start] + edge.value){
                    distance[edge.end] = distance[edge.start] + edge.value;
                    if(i==N) return true;
                }
            }
        }

        return false;
    }
}
