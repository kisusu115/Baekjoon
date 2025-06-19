import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    static final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static final int[] dx = new int[]{1, 0, -1, 0};
    static final int[] dy = new int[]{0, 1, 0, -1};

    static int N, M;
    static char[][] map;
    static boolean[][] visited;

    public static void main(String[] args) throws IOException {
        String line0 = br.readLine();
        N = Integer.parseInt(line0.split(" ")[0]);
        M = Integer.parseInt(line0.split(" ")[1]);
        map = new char[M][N];
        visited = new boolean[M][N];

        for(int x=0; x<M; x++){
            String ipt = br.readLine();
            char[] iptc = ipt.toCharArray();
            for(int y=0; y<N; y++) map[x][y] = iptc[y];
        }

        int powerW = 0; int powerB = 0;

        for(int x=0; x<M; x++){
            for(int y=0; y<N; y++){
                if(visited[x][y]) continue;

                int soldiers = dfs(x,y);
                int powerAdd = soldiers*soldiers;

                if(map[x][y] == 'W') powerW+=powerAdd;
                if(map[x][y] == 'B') powerB+=powerAdd;
            }
        }

        System.out.println(powerW+" "+powerB);
    }

    private static int dfs(int x, int y){
        if(visited[x][y]) return 0;
        visited[x][y] = true;
        int sum = 1;

        for(int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(!isValidX(nx) || !isValidY(ny)) continue;

            if(map[x][y] == map[nx][ny]){
                sum += dfs(nx, ny);
            }
        }
        return sum;
    }

    private static boolean isValidX(int x) {
        return 0 <= x && x < M;
    }

    private static boolean isValidY(int y) {
        return 0 <= y && y < N;
    }
}
