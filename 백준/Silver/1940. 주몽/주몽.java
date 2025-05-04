import java.util.*;

public class Main {
    public static void main(String[] args) {

        ArrayList<Integer> ipts = new ArrayList<>();

        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt(); int M = sc.nextInt();
        for(int i=0; i<N; i++){
            Integer ipt = sc.nextInt();
            ipts.add(ipt);
        }

        Collections.sort(ipts);

        int p1 = 0; int p2 = ipts.size() - 1;
        int cnt = 0;

        if(ipts.size() == 1){
            System.out.println(0);
            return;
        }

        while(p1<p2){
            int sum = ipts.get(p1) + ipts.get(p2);

            if(sum == M){
                cnt++;
                p1++;
                p2--;
            }
            else if(sum < M){
                p1++;
            }
            else{
                p2--;
            }
        }

        System.out.println(cnt);
    }
}