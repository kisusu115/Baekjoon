import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        char[] str = sc.nextLine().toCharArray();
        char[] tnt = sc.nextLine().toCharArray();

        int strLen = str.length;
        int tntLen = tnt.length;

        char[] result = new char[strLen];
        int idx = 0;

        for (int i = 0; i < strLen; i++) {
            result[idx] = str[i];
            idx++;

            if (idx >= tntLen) {
                boolean matchFlag = true;
                for (int j = 0; j < tntLen; j++) {
                    if (result[idx - tntLen + j] != tnt[j]) {
                        matchFlag = false;
                        break;
                    }
                }
                if (matchFlag) idx -= tntLen;
            }
        }

        if (idx == 0) {
            System.out.println("FRULA");
            return;
        }

        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < idx; i++) {
            sb.append(result[i]);
        }
        System.out.println(sb);
    }
}
