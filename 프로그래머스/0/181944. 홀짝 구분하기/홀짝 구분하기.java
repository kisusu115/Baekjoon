import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        
        String opt = n%2==1 ? n+" is odd" : n+" is even";
        System.out.print(opt);
    }
}