import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {
    static int V, E;
    static int[] parent;

    private static class Edge implements Comparable<Edge>{
        int a, b, cost;

        Edge(int a, int b, int cost){
            this.a=a;
            this.b=b;
            this.cost=cost;
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

        V = Integer.parseInt(st.nextToken());
        E = Integer.parseInt(st.nextToken());
        parent = new int[V+1];

        for(int i=1; i<=V; i++) parent[i] = i;

        for(int i=0; i<E; i++){
            st = new StringTokenizer(br.readLine());
            int A = Integer.parseInt(st.nextToken());
            int B = Integer.parseInt(st.nextToken());
            int C = Integer.parseInt(st.nextToken());

            pq.add(new Edge(A, B, C));
        }

        int result = 0;
        while(!pq.isEmpty()){
            Edge polled = pq.poll();
            if(find(polled.a) == find(polled.b)) continue;

            union(polled.a, polled.b);
            result += polled.cost;
        }
        System.out.println(result);
    }

    private static int find(int n){
        if(parent[n] != n) parent[n] = find(parent[n]);
        return parent[n];
    }

    private static void union(int a, int b){
        int pa = find(a);
        int pb = find(b);
        if(pa < pb) parent[pb] = pa;
        else parent[pa] = pb;
    }
}
