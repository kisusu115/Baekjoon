import java.util.*;

public class Main {

    static int[][] arr;
    static int Nm1 = 0;
    static int N0 = 0;
    static int Np1 = 0;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        arr = new int[N][N];

        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                arr[i][j] = sc.nextInt();
            }
        }

        handleArr(0, 0, N);

        System.out.println(Nm1);
        System.out.println(N0);
        System.out.println(Np1);
    }

    static void handleArr(int rowN, int colN, int len){
        boolean isAllSame = checkArr(rowN, colN, len);

        int firstN = arr[rowN][colN];
        if(isAllSame) handleFirstN(firstN);
        else{
            int newLen = len/3;

            handleArr(rowN, colN, newLen);
            handleArr(rowN+newLen, colN, newLen);
            handleArr(rowN+newLen*2, colN, newLen);

            handleArr(rowN, colN+newLen, newLen);
            handleArr(rowN+newLen, colN+newLen, newLen);
            handleArr(rowN+newLen*2, colN+newLen, newLen);

            handleArr(rowN, colN+newLen*2, newLen);
            handleArr(rowN+newLen, colN+newLen*2, newLen);
            handleArr(rowN+newLen*2, colN+newLen*2, newLen);
        }
    }

    static boolean checkArr(int rowN, int colN, int len){
        if(len == 1) return true;

        int firstN = arr[rowN][colN];
        for(int i=rowN; i<rowN+len; i++){
            for(int j=colN; j<colN+len; j++){
                if(arr[i][j] != firstN) return false;
            }
        }

        return true;
    }

    static void handleFirstN(int firstN){
        switch (firstN){
            case -1:
                Nm1++;
                break;
            case 0:
                N0++;
                break;
            case 1:
                Np1++;
                break;
            default:
                break;
        }
    }
}