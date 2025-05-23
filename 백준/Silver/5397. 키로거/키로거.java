import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());

        while (T>0){
            String str = br.readLine();
            LinkedList<Character> linkedList = new LinkedList<>();
            int idx=0;

            for(char c:str.toCharArray()){
                if(c=='-'){
                    if(idx <= 0) continue;
                    idx--;
                    linkedList.remove(idx);
                }
                else if(c=='<'){
                    if(idx <= 0) continue;
                    idx--;
                }
                else if(c=='>'){
                    if(idx >= linkedList.size()) continue;
                    idx++;
                }
                else{
                    linkedList.add(idx, c);
                    idx++;
                }
            }

            StringBuilder sb = new StringBuilder();
            for(char c:linkedList) sb.append(c);
            System.out.println(sb);

            T--;
        }
    }
}
