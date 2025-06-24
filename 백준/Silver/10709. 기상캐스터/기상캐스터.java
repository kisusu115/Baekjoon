import java.io.*;
import java.util.StringTokenizer;

public class Main {
    static final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static final BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int H, W;
    static int[][] timeC;

    public static void main(String[] args) throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        H = Integer.parseInt(st.nextToken());
        W = Integer.parseInt(st.nextToken());
        timeC = new int[H][W];

        for(int i=0; i<H; i++){
            String ipt = br.readLine();
            char[] iptc = ipt.toCharArray();

            timeC[i][0] = (iptc[0]=='c') ? 0 : -1;
            for(int j=1; j<W; j++){
                if (timeC[i][j-1]==-1) timeC[i][j]=-1;
                else timeC[i][j]=timeC[i][j-1]+1;
                if (iptc[j]=='c') timeC[i][j]=0;
            }
        }

        for(int i=0; i<H; i++){
            for(int j=0; j<W; j++){
                bw.write(timeC[i][j]+" ");
            }
            bw.write("\n");
        }
        bw.flush();
        bw.close();
    }
}
