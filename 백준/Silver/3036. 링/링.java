import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int n0 = sc.nextInt();

        for (int i = 1; i < N; i++) {
            int nn = sc.nextInt();
            int mc = getMaxCom(n0, nn);
            int upper = n0 / mc;
            int lower = nn / mc;
            System.out.println(upper + "/" + lower);
        }
    }

    private static int getMaxCom(int a, int b) {
        int tmp;
        if (a < b) {
            tmp = a;
            a = b;
            b = tmp;
        }
        while (b != 0) {
            tmp = a % b;
            a = b;
            b = tmp;
        }
        return a;
    }
}