import java.util.*;

public class Main {
    static int MAX_NUM = 300000;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        List<List<Integer>> graph = new ArrayList<>();
        boolean[] visited = new boolean[MAX_NUM+1];

        int N = sc.nextInt();
        int M = sc.nextInt();
        int K = sc.nextInt();
        int X = sc.nextInt();

        for (int i = 0; i <= N; i++) {
            graph.add(new ArrayList<>());
        }

        for(int i=0;i<M;i++){
            int s = sc.nextInt();
            int e = sc.nextInt();
            graph.get(s).add(e);
        }

        Queue<Integer> q = new LinkedList<>();
        q.add(X);
        visited[X] = true;

        int level = 0;
        while(!q.isEmpty() && level<K){
            List<Integer> levelVals = new ArrayList<>();
            while(!q.isEmpty()){
                int val = q.remove();
                levelVals.add(val);
            }
            for(int i=0; i<levelVals.size(); i++){
                for(int j=1; j<=N; j++){
                    if(visited[j]) continue;
                    if(graph.get(levelVals.get(i)).contains(j)){
                        visited[j] = true;
                        q.add(j);
                    }
                }
            }
            level++;
        }

        if (q.isEmpty()) {
            System.out.println(-1);
            return;
        }

        List<Integer> rests = new ArrayList<>();

        while(!q.isEmpty()){
            int val = q.remove();
            rests.add(val);
        }

        Collections.sort(rests);

        for(Integer i : rests){
            System.out.println(i);
        }
    }
}