import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String ipt = br.readLine();
        int[] nums = new int[9];
        for (char c:ipt.toCharArray()){
            int idx = Integer.parseInt(String.valueOf(c));
            if (idx==9) idx=6;
            nums[idx]++;
        }
        int max=0;
        nums[6] = (nums[6]+1)/2;
        for(int i:nums) max = Math.max(max, i);
        System.out.println(max);
    }
}
