import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        StringBuilder sb = new StringBuilder();

        char[] board = sc.nextLine().toCharArray();

        int cntX = 0;
        for(char c:board){
            if(c=='X') {
                if(cntX==4) {
                    sb.append("AAAA");
                    cntX = 0;
                }
                cntX++;
            }
            else {
                if(cntX%2 == 1) {
                    System.out.println(-1);
                    return;
                }
                if(cntX==4) sb.append("AAAA");
                if(cntX==2) sb.append("BB");
                sb.append(".");
                cntX = 0;
            }
        }

        if(cntX%2 == 1) {
            System.out.println(-1);
            return;
        }
        if(cntX==4) sb.append("AAAA");
        if(cntX==2) sb.append("BB");
        System.out.println(sb);
    }
}
