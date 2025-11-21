class Solution {
    public int solution(int a, int d, boolean[] included) {;
        int n = included.length;
        int cnt=0; int sum=0;
                                                           
        for(int i=0; i<n; i++){
            if(included[i]) {
                cnt++;
                sum+=i;
            }
        }
        return cnt*a + sum*d;
    }
}