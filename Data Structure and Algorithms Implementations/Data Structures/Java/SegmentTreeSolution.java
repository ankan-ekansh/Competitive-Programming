import java.util.Arrays;

class SegmentTree {
    static class Node {
        int val;
        int idx;

        public Node(int val, int idx) {
            this.val = val;
            this.idx = idx;
        }
    }

    Node[] tree;
    int[] a;
    int n;

    public SegmentTree(int[] a) {
        this.n = a.length;
        this.a = Arrays.copyOf(a, n);
        // this.tree = new int[4 * (n)];
        this.tree = new Node[4 * n];
        // 0 based index
        buildTree(0, 0, n - 1);
    }

    private void buildTree(int treeNodeIdx, int start, int end) {
        if (start == end) {
            // tree[treeNodeIdx] = a[start];
            tree[treeNodeIdx] = new Node(a[start], start);
        }
        else {
            int mid = start + (end - start) / 2;
            buildTree(2 * treeNodeIdx + 1, start, mid);
            buildTree(2 * treeNodeIdx + 2, mid + 1, end);
            // Since this is SegmentTree for range min query
            // tree[treeNodeIdx] will have min of range start, end
            // tree[treeNodeIdx] = Math.min(tree[2 * treeNodeIdx + 1], tree[2 * treeNodeIdx + 2]);
            Node left = tree[2 * treeNodeIdx + 1];
            Node right = tree[2 * treeNodeIdx + 2];
            tree[treeNodeIdx] = left.val <= right.val ? left : right;
        }
    }

    public void update(int treeNodeIdx, int start, int end, int idx, int val) {
        if (start == end) {
            a[idx] = val;
            // tree[treeNodeIdx] = val;
            tree[treeNodeIdx] = new Node(val, idx);
            return;
        }

        int mid = start + (end - start) / 2;

        // if idx is in left subtree
        if (start <= idx && idx <= mid) {
            update(2 * treeNodeIdx + 1, start, mid, idx, val);
        }
        // otherwise go in right subtree
        else {
            update(2 * treeNodeIdx + 2, mid + 1, end, idx, val);
        }
        // once both subtrees are updated, update treeNodeIdx
        // tree[treeNodeIdx] = Math.min(tree[2 * treeNodeIdx + 1], tree[2 * treeNodeIdx + 2]);
        Node left = tree[2 * treeNodeIdx + 1];
        Node right = tree[2 * treeNodeIdx + 2];
        tree[treeNodeIdx] = left.val <= right.val ? left : right;
    }

    public int query(int treeNodeIdx, int start, int end, int l, int r) {
        // when no overlap of l,r with segment
        if (r < start || end < l) {
            // returning int max since the segtree is for range minimum queries
            // return Integer.MAX_VALUE;
            return -1;
        }
        // if segment lies fully in l,r
        if (l <= start && end <= r) {
            // return tree[treeNodeIdx];
            return tree[treeNodeIdx].idx;
        }

        // otherwise partial overlap
        int mid = start + (end - start) / 2;
        int left = query(2 * treeNodeIdx + 1, start, mid, l, r);
        int right = query(2 * treeNodeIdx + 2, mid + 1, end, l, r);
        // Return min of both subtree since this is range minimum query
        // return Math.min(left, right);
        if (left == -1) {
            return right;
        }
        if (right == -1) {
            return left;
        }
        return a[left] <= a[right] ? left : right;
    }
}

public class SegmentTreeSolution {
    public static void main(String[] args) {
        int[] a = { 1, 2, 3, 2, 1, 2, 3, 2, 1 };
        SegmentTree tree = new SegmentTree(a);

        for (int i = 0; i < a.length; i++) {
            for (int j = i; j < a.length; j++) {
                int minIdx = tree.query(0, 0, a.length - 1, i, j);
                System.out.println("For range " + i + "-" + j + ", minIdx = " + minIdx);
            }
        }
    }
}

