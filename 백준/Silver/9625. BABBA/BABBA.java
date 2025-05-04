import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long na = 1; long nb = 0;
        long K = sc.nextInt();

        for(int i=0; i<K; i++){
            long tb = nb;
            nb += na;
            na = tb;
        }

        System.out.println(na + " " + nb);
    }
}
