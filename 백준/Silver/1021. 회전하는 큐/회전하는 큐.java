import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        LinkedList<Integer> deque = new LinkedList<>();
        ArrayList<Integer> targets = new ArrayList<>();

        int N = sc.nextInt(); int M = sc.nextInt();
        for(int i=0; i<N; i++) deque.add(i+1);
        for(int i=0; i<M; i++) targets.add(sc.nextInt());

        int findIdx = 0;
        int cnt = 0;
        while(findIdx < M){
            int idx = deque.indexOf(targets.get(findIdx));
            int dSize = deque.size();
            if(idx <= dSize - 1 - idx){
                for(int i=0; i<idx; i++){
                    Integer first = deque.getFirst();
                    deque.removeFirst();
                    deque.addLast(first);
                    cnt++;
                }
            }
            else{
                for(int i=0; i<dSize-idx; i++){
                    Integer last = deque.getLast();
                    deque.removeLast();
                    deque.addFirst(last);
                    cnt++;
                }
            }
            deque.removeFirst();
            findIdx++;
        }

        System.out.println(cnt);
    }
}