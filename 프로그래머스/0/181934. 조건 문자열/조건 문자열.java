class Solution {
    public int solution(String ineq, String eq, int n, int m) {
        Boolean c1 = (ineq.equals("<") && n<=m) || (ineq.equals(">") && n>=m);
        Boolean c2 = eq.equals("=") || (eq.equals("!") && n!=m);
        return c1 && c2 ? 1 : 0;
    }
}