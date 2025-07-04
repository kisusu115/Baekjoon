import java.io.*;
import java.util.*;

public class Main {
    static final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static final BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    static int N, Q;
    static long[] ipts;

    private static class SegmentTree {
        long[] tree;
        int treeSize;

        SegmentTree(long[] iptArr){
            int arrSize = iptArr.length;
            int height = (int) Math.ceil(Math.log(arrSize) / Math.log(2))+1;

            treeSize = (int) Math.pow(2, height);
            this.tree = new long[treeSize];

            initTree(iptArr);
        }

        private void initTree(long[] iptArr){
            int leafStart = treeSize/2;

            for(int i=0; i<iptArr.length; i++) tree[leafStart+i] = iptArr[i];
            for(int i=leafStart-1; i>0; i--) tree[i] = tree[i*2] + tree[i*2+1];
        }

        private void changeValue(int idx, int value){
            int currentIdx = treeSize/2+idx;
            long exist = tree[currentIdx];
            long gap = value - exist;

            while (currentIdx!=0){
                tree[currentIdx] += gap;
                currentIdx /= 2;
            }
        }

        private long areaSum(int start, int end) {
            long result = 0;

            int left = treeSize/2 + start;
            int right = treeSize/2 + end;

            while (left <= right) {
                if (left%2 == 1) result += tree[left++];
                if (right%2 == 0) result += tree[right--];

                left /= 2;
                right /= 2;
            }

            return result;
        }
    }

    public static void main(String[] args) throws IOException {
        String l1 = br.readLine();
        N = Integer.parseInt(l1.split(" ")[0]);
        Q = Integer.parseInt(l1.split(" ")[1]);

        ipts = new long[N];

        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i=0; i<N; i++) ipts[i] = Long.parseLong(st.nextToken());

        SegmentTree tree = new SegmentTree(ipts);

        while(Q-->0) {
            st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());

            int rx = Math.min(x, y);
            int ry = Math.max(x, y);

            bw.write(tree.areaSum(rx-1, ry-1)+"\n");
            tree.changeValue(a-1, b);
        }
        bw.flush();
        bw.close();
    }
}
