class Solution {
    public String solution(String str1, String str2) {
        char[] s1 = str1.toCharArray();
        char[] s2 = str2.toCharArray();
        
        String answer = "";
        
        int l = str1.length();
        for(int i=0; i<l; i++){
            answer+=s1[i];
            answer+=s2[i];
        }
        
        return answer;
    }
}