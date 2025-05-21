import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        int B = Integer.parseInt(st.nextToken());

        int min = 256, max = 0;
        int[] bNum = new int[257];

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < M; j++) {
                int height = Integer.parseInt(st.nextToken());
                bNum[height]++;
                min = Math.min(min, height);
                max = Math.max(max, height);
            }
        }

        int resultT = Integer.MAX_VALUE;
        int resultH = 0;
        for (int h = min; h <= max; h++) {
            int time = 0;
            int block = B;

            for (int i = 0; i <= 256; i++) {
                if (bNum[i] == 0) continue;
                int diff = i - h;
                if (diff > 0) {
                    time += 2 * diff * bNum[i];
                    block += diff * bNum[i];
                } else if (diff < 0) {
                    time += -1 * diff * bNum[i];
                    block -= -1 * diff * bNum[i];
                }
            }
            if (block < 0) continue;

            if (time < resultT || (time == resultT && h > resultH)) {
                resultT = time;
                resultH = h;
            }
        }

        System.out.println(resultT + " " + resultH);
    }
}
