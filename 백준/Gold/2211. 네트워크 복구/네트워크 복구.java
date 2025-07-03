import java.io.*;
import java.util.*;

public class Main {
    static final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static final BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    static int N, M;
    static int[] distance;
    static boolean[] visited;
    static ArrayList<Edge>[] graph;

    private static class Edge implements Comparable<Edge>{
        int from;
        int to;
        int cost;

        Edge(int from, int to, int cost){
            this.from = from;
            this.to = to;
            this.cost = cost;
        }

        @Override
        public int compareTo(Edge edge) {
            return this.cost - edge.cost;
        }
    }

    public static void main(String[] args) throws IOException {
        String l1 = br.readLine();
        N = Integer.parseInt(l1.split(" ")[0]);
        M = Integer.parseInt(l1.split(" ")[1]);
        distance = new int[N+1];
        visited = new boolean[N+1];
        graph = new ArrayList[N+1];

        Arrays.fill(distance, Integer.MAX_VALUE);

        for (int i = 0; i <= N; i++) graph[i] = new ArrayList<>();

        for (int i = 0; i < M; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int A = Integer.parseInt(st.nextToken());
            int B = Integer.parseInt(st.nextToken());
            int C = Integer.parseInt(st.nextToken());
            Edge edgeA = new Edge(A, B, C);
            Edge edgeB = new Edge(B, A, C);

            graph[A].add(edgeA);
            graph[B].add(edgeB);
        }

        PriorityQueue<Edge> pq = new PriorityQueue<>();
        pq.add(new Edge(0, 1,0));

        ArrayList<Edge> result = new ArrayList<>();

        while(!pq.isEmpty()){
            Edge polled = pq.poll();
            int target = polled.to;

            if(visited[target]) continue;
            visited[target] = true;

            distance[target] = polled.cost;
            if(target!=1) result.add(polled);

            for(int i=0; i<graph[target].size(); i++){
                Edge e = graph[target].get(i);
                Edge dijkstraEdge = new Edge(target, e.to, distance[target] + e.cost);
                pq.add(dijkstraEdge);
            }
        }

        bw.write(result.size()+"\n");
        for(Edge e:result) bw.write(e.from+" "+e.to+"\n");
        bw.flush();
        bw.close();
    }
}
