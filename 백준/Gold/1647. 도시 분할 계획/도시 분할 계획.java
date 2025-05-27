import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {
    static int N, M;
    static int[] parent;

    private static class Edge implements Comparable<Edge> {
        int a, b, cost;

        Edge(int a, int b, int cost){
            this.a = a;
            this.b = b;
            this.cost = cost;
        }

        @Override
        public int compareTo(Edge o) {
            return this.cost - o.cost;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        PriorityQueue<Edge> pq = new PriorityQueue<>();

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        parent = new int[N+1];

        for(int i=1; i<=N; i++) parent[i] = i;

        for(int i=0; i<M; i++){
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());

            pq.add(new Edge(a, b, c));
        }

        int result = 0;
        int lastCost = 0;

        while(!pq.isEmpty()){
            Edge polled = pq.poll();
            if(find(polled.a) == find(polled.b)) continue;
            union(polled.a, polled.b);
            result += polled.cost;
            lastCost = polled.cost;
        }

        System.out.println(result - lastCost);
    }

    private static int find(int n) {
        if (parent[n] != n) parent[n] = find(parent[n]);
        return parent[n];
    }

    private static void union(int a, int b){
        a = find(a);
        b = find(b);
        if(a<b) parent[b] = a;
        else parent[a] = b;
    }
}
