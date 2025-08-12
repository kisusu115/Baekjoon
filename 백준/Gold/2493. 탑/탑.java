import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;
import java.util.StringTokenizer;

public class Main {
    private static final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    private static int N;
    private static int[] result;

    private static class Tower {
        int height;
        int index;

        Tower(int h, int i){
            this.height = h;
            this.index = i;
        }
    }

    public static void main(String[] args) throws IOException {
        N = Integer.parseInt(br.readLine());
        result = new int[N];
        Stack<Tower> stack = new Stack<>();

        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i=0; i<N; i++){
            int h = Integer.parseInt(st.nextToken());

            while(true){
                if(stack.isEmpty()){
                    result[i] = 0;
                    stack.push(new Tower(h, i));
                    break;
                }

                Tower t = stack.peek();

                if(h > t.height){
                    stack.pop();
                    continue;
                }

                result[i] = t.index+1;
                stack.push(new Tower(h, i));
                break;
            }
        }

        StringBuilder sb = new StringBuilder();
        for(int i: result) sb.append(i).append(" ");
        System.out.println(sb);
    }
}
