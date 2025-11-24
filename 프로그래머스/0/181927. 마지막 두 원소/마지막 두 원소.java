import java.util.*;

class Solution {
    public int[] solution(int[] num_list) {
        int len = num_list.length;
        int[] result = new int[len + 1];
        
        System.arraycopy(num_list, 0, result, 0, len);
        
        result[len] = (num_list[len - 1] > num_list[len - 2]) ? num_list[len - 1]-num_list[len - 2] : num_list[len - 1]*2;
        
        return result;
    }
}