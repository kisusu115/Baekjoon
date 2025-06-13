import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.Set;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    public static void main(String[] args) throws IOException {
        Set<String> set = new HashSet<>();

        int N = Integer.parseInt(br.readLine());
        int result = 0;
        for(int i=0 ;i<N; i++){
            String ipt = br.readLine();

            if (ipt.equals("ENTER")) {
                set.clear();
                continue;
            }
            if (set.contains(ipt)) continue;

            set.add(ipt);
            result++;
        }
        System.out.println(result);
    }
}
