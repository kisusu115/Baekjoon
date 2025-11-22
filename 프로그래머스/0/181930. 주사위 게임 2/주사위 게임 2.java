class Solution {
    public int solution(int a, int b, int c) {
        if(a==b && b==c){
            return (int) Math.pow(a, 6) * 27;
        }
        if(a==b || b==c || c==a){
            return (a*a+b*b+c*c)*(a+b+c);
        }
        return a+b+c;
    }
}