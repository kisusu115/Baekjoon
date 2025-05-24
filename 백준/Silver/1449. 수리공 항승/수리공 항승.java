import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    private static int MAX_LEN = 1000;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        boolean[] pipe = new boolean[MAX_LEN+1];

        int N = Integer.parseInt(st.nextToken());
        int L = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());
        for(int i=0; i<N; i++){
            int ipt = Integer.parseInt(st.nextToken());
            pipe[ipt] = true;
        }

        int cnt=0;
        for(int i=0; i<=MAX_LEN; i++){
            if(!pipe[i]) continue;
            for(int j=0; j<L; j++) {
                if(i+j > MAX_LEN) break;
                pipe[i+j] = false;
            }
            cnt++;
        }

        System.out.println(cnt);
    }
}
