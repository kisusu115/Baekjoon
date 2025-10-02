import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        StringBuilder sb = new StringBuilder();
        String a = sc.next();
        
        for(char c: a.toCharArray()){
            if(c<'a') sb.append((char)(c-'A'+'a'));
            else sb.append((char)(c-'a'+'A'));
        }
        
        System.out.print(sb);
    }
}