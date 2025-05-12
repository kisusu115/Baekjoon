import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        String str = sc.nextLine();
        int pipeCnt=0;
        int resultCnt=0;
        for(int i=0; i<str.length(); i++){
            if(str.charAt(i)=='('){
                pipeCnt++;
            }
            if(str.charAt(i)==')'){
                pipeCnt--;
                if(str.charAt(i-1)=='(') resultCnt+=pipeCnt;
                else resultCnt++;
            }
        }

        System.out.println(resultCnt);
    }
}