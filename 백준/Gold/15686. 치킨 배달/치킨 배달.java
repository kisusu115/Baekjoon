import java.util.Scanner;

public class Main {
    static final int MAX_N = 50;
    static final int MAX_M = 13;

    static int N;
    static int M;
    static int houseN = 0;
    static int chickN = 0;
    static int[][] map;
    static int[][] distance;
    static boolean[] visited;

    static int result = Integer.MAX_VALUE;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        M = sc.nextInt();
        map = new int[N][N];

        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                int ipt = sc.nextInt();
                map[i][j] = ipt;
                if(ipt==1) houseN++;
                if(ipt==2) chickN++;
            }
        }

        distance = new int[chickN][houseN];
        visited = new boolean[chickN];

        int chickCnt=0;
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(map[i][j]==2){
                    initDistArr(chickCnt, i, j);
                    chickCnt++;
                }
            }
        }

        dfs(0, 0);

        System.out.println(result);
    }

    private static void dfs(int depth, int count) {
        if(count==M){
            result = Math.min(result, calculateTotalMinDist());
            return;
        }
        if(depth==chickN) return;

        visited[depth] = true;
        dfs(depth+1, count+1);

        visited[depth] = false;
        dfs(depth+1, count);
    }

    private static void initDistArr(int chickN, int i1, int j1) {
        int houseCnt=0;
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(map[i][j]==1) {
                    distance[chickN][houseCnt] = calculateManhattanDist(i1, j1, i, j);
                    houseCnt++;
                }
            }
        }
    }

    private static int calculateManhattanDist(int i1, int j1, int i2, int j2) {
        return Math.abs(i2-i1) + Math.abs(j2-j1);
    }

    private static int calculateTotalMinDist() {
        int sum = 0;
        int houseCnt=0;
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(map[i][j]==1){
                    sum = sum + getLeastChickDist(houseCnt);
                    houseCnt++;
                }
            }
        }
        return sum;
    }

    private static int getLeastChickDist(int houseN) {
        int leastDist = MAX_N*2;
        for(int i=0;i<chickN;i++){
            if(visited[i]) {
                leastDist = Math.min(leastDist, distance[i][houseN]);
            }
        }
        return leastDist;
    }
}