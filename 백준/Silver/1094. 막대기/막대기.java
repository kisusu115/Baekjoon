import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String bs = Integer.toBinaryString(sc.nextInt());
        int cnt=0;
        for(char c : bs.toCharArray()) if (c=='1') cnt++;
        System.out.println(cnt);
    }
}