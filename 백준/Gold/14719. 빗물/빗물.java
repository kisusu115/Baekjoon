import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static int H, W;
    static int[] leftMax, rightMax;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        H = Integer.parseInt(st.nextToken());
        W = Integer.parseInt(st.nextToken());
        int[] blocks = new int[W];

        st = new StringTokenizer(br.readLine());
        for(int i=0; i<W; i++) blocks[i] = Integer.parseInt(st.nextToken());

        leftMax = new int[W];
        rightMax = new int[W];

        leftMax[0] = blocks[0];
        for(int i=1; i<W; i++) {
            leftMax[i] = Math.max(leftMax[i-1], blocks[i]);
        }

        rightMax[W-1] = blocks[W-1];
        for(int i=W-2; i>=0; i--) {
            rightMax[i] = Math.max(rightMax[i+1], blocks[i]);
        }

        int result = 0;
        for(int i=0; i<W; i++) {
            int waterHeight = Math.min(leftMax[i], rightMax[i]) - blocks[i];
            if(waterHeight>0) result += waterHeight;
        }
        System.out.println(result);
    }
}
