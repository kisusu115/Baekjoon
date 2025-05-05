import java.util.*;

public class Main {
    static int MAX_VAL = 1000000001;
    static int treeN = 0;
    static int[] maxTree;
    static int[] minTree;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt(); int M = sc.nextInt();
        int[] arr = new int[N];
        for(int i=0; i<N; i++) arr[i] = sc.nextInt();

        int height = (int)Math.ceil(Math.log(N)/Math.log(2));
        treeN = (int) Math.pow(2, height); // 말단 제외 개수 + 1

        maxTree = new int[treeN*2];
        minTree = new int[treeN*2];

        for(int i=1; i<treeN*2; i++) minTree[i] = MAX_VAL;
        for(int i=0; i<N; i++){
            maxTree[i+treeN] = arr[i];
            minTree[i+treeN] = arr[i];
        }

        for(int i=treeN-1; i>0; i--){
            maxTree[i] = Math.max(maxTree[i*2], maxTree[i*2+1]);
            minTree[i] = Math.min(minTree[i*2], minTree[i*2+1]);
        }

        for(int i=0; i<M; i++){
            int s = sc.nextInt();
            int e = sc.nextInt();
            s-=1; e-=1;
            handleSite(s, e);
        }
    }

    public static void handleSite(int s, int e){
        s+=treeN;
        e+=treeN;

        int max = 0;
        int min = MAX_VAL;

        while(s<=e){
            if(s%2==1){
                max = Math.max(max, maxTree[s]);
                min = Math.min(min, minTree[s]);
                s++;
            }
            if(e%2==0){
                max = Math.max(max, maxTree[e]);
                min = Math.min(min, minTree[e]);
                e--;
            }
            s/=2;
            e/=2;
        }

        System.out.println(min + " " + max);
    }
}