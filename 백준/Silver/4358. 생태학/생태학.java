import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    public static void main(String[] args) throws IOException {
        Map<String, Integer> map = new HashMap<>();
        int cnt=0;

        while(true){
            String ipt = br.readLine();
            if(ipt==null || ipt.isEmpty()) break;
            cnt++;

            Integer val = map.getOrDefault(ipt, 0);
            map.put(ipt, val+1);
        }

        List<String> keySet = new ArrayList<>(map.keySet());
        Collections.sort(keySet);

        for(String key: keySet){
            double ratio = (double)map.get(key) / cnt;
            System.out.printf("%s %.4f\n", key, ratio * 100);
        }
    }
}
