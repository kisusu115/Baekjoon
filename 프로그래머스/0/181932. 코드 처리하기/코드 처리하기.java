import java.util.*;

class Solution {
    public String solution(String code) {
        Queue<Character> q = new LinkedList<>();
        char[] codeArr = code.toCharArray();
        boolean mode = false; 
        
        for(int idx=0; idx<code.length(); idx++){
            if(codeArr[idx] == '1') mode = !mode;
            else{
                if(!mode && idx%2==0) q.add(codeArr[idx]);
                if( mode && idx%2==1) q.add(codeArr[idx]);
            }
        }
        StringBuilder sb = new StringBuilder();
        while(!q.isEmpty()) sb.append(q.poll());
        return sb.toString().equals("") ? "EMPTY" : sb.toString();
    }
}