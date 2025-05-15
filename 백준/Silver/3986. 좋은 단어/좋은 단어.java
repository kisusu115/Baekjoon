import java.util.Scanner;
import java.util.Stack;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();
        sc.nextLine();
        int cnt = 0;
        for(int i=0; i<N; i++){
            String str = sc.nextLine();
            if(checkString(str)) cnt++;
        }

        System.out.println(cnt);
    }

    private static boolean checkString(String str){
        Stack<Character> stack = new Stack<Character>();
        for(char c : str.toCharArray()){
            if(stack.isEmpty() || stack.peek() != c) stack.push(c);
            else stack.pop();
        }
        if(stack.isEmpty()) return true;
        else return false;
    }
}