class Solution {
    public int solution(int[] num_list) {
        int eCnt=0; int oCnt=0;
        int eSum=0; int oSum=0;
        
        for(int i=num_list.length-1; i>=0; i--){
            int cur = num_list[i];
            
            if(cur%2 == 0) eSum += cur*Math.pow(10, eCnt++);
            else oSum += cur*Math.pow(10, oCnt++);
        }
        
        return eSum+oSum;
    }
}