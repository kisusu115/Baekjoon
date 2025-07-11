import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    static int N, CUR_RES_LEN;
    static int[] arr, result;

    public static void main(String[] args) throws IOException {
        N = Integer.parseInt(br.readLine());
        arr = new int[N];
        result = new int[N];

        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i=0; i<N; i++) arr[i] = Integer.parseInt(st.nextToken());

        CUR_RES_LEN = 0;
        for(int i=0; i<N; i++) {
            int idx = lowerBound(arr[i]);
            result[idx] = arr[i];
            if(idx == CUR_RES_LEN) CUR_RES_LEN++;
        }

        System.out.println(CUR_RES_LEN);
    }

    private static int lowerBound(int target){
        int start = 0; int end = CUR_RES_LEN;

        while(start<end){
            int mid = (start+end) / 2;
            if(result[mid] < target) start = mid+1;
            else end = mid;
        }
        return start;
    }
}
