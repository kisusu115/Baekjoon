import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    static int N;
    static int[] ipt, resultArr;

    public static void main(String[] args) throws IOException {
        N = Integer.parseInt(br.readLine());
        ipt = new int[N];
        resultArr = new int[N];

        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i=0; i<N; i++) ipt[i] = Integer.parseInt(st.nextToken());
        int length = 0;

        for(int num:ipt) {
            int pos = lowerBound(0, length, num);
            resultArr[pos] = num;
            if(pos==length) length++;
        }

        System.out.println(length);
    }

    private static int lowerBound(int s, int e, int num){
        while(s<e){
            int mid = (s+e)/2;
            if(resultArr[mid]<num) s = mid+1;
            else e = mid;
        }
        return s;
    }
}