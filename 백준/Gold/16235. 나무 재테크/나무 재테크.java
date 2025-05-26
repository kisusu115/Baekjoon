import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static int N, M, K;
    static int[][] currNut, addNut;
    static ArrayList<Integer>[][] trees;
    static int[] dx = {0, 1, 1, 1, 0, -1, -1, -1};
    static int[] dy = {1, 1, 0, -1, -1, -1, 0, 1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        currNut = new int[N+1][N+1];
        addNut = new int[N+1][N+1];
        trees = new ArrayList[N+1][N+1];

        for (int i=1; i<=N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j=1; j<=N; j++) {
                addNut[i][j] = Integer.parseInt(st.nextToken());
                currNut[i][j] = 5;
                trees[i][j] = new ArrayList<>();
            }
        }

        for (int i=0; i<M; i++) {
            st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            int z = Integer.parseInt(st.nextToken());
            trees[x][y].add(z);
        }

        for (int i=0; i<K; i++) yearlyCycle();

        int result=0;
        for (int i=1; i<=N; i++) {
            for (int j=1; j<=N; j++) {
                result += trees[i][j].size();
            }
        }
        System.out.println(result);
    }

    private static void yearlyCycle() {
        ArrayList<Integer>[][] newTrees = new ArrayList[N+1][N+1];
        for (int i=1; i<=N; i++) {
            for (int j=1; j<=N; j++) {
                newTrees[i][j] = new ArrayList<>();
            }
        }

        for (int i=1; i<=N; i++) {
            for (int j=1; j<=N; j++) {
                if (trees[i][j].isEmpty()) continue;

                Collections.sort(trees[i][j]);
                int nutFromDeadTree = 0;

                for (int age:trees[i][j]) {
                    if (currNut[i][j] >= age) {
                        currNut[i][j] -= age;
                        age++;

                        newTrees[i][j].add(age);

                        if (age%5==0) {
                            for (int d=0; d<8; d++) {
                                int ni = i + dx[d];
                                int nj = j + dy[d];
                                if (ni>=1 && ni<=N && nj>=1 && nj<=N) {
                                    newTrees[ni][nj].add(1);
                                }
                            }
                        }
                    } else {
                        nutFromDeadTree += age/2;
                    }
                }
                currNut[i][j] += nutFromDeadTree;
            }
        }

        for (int i=1; i<=N; i++) {
            for (int j=1; j<=N; j++) {
                currNut[i][j] += addNut[i][j];
                trees[i][j] = newTrees[i][j];
            }
        }
    }
}
