import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int K = sc.nextInt();
        int[] direct = new int[12];
        int[] length = new int[12];

        for(int i=0; i<6; i++){
            direct[i] = direct[i+6] = sc.nextInt();
            length[i] = length[i+6] = sc.nextInt();
        }

        for(int i=0; i<9; i++){
            if(direct[i] == direct[i+2] && direct[i+1] == direct[i+3]){
                int sup = (length[i]+length[i+2])*(length[i+1]+length[i+3]);
                int sub = length[i+1] * length[i+2];
                System.out.println((sup-sub)*K);
                return;
            }
        }
    }
}
