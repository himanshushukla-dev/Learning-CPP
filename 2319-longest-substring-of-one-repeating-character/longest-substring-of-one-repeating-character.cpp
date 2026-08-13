#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Node {
    char lc = 0, rc = 0;
    int prefix_len = 0;
    int suffix_len = 0;
    int max_len = 0;
};

class SegmentTree {
    int n;
    vector<Node> tree;

    Node merge(const Node& left, const Node& right, int len_l, int len_r) {
        Node res;
        res.lc = left.lc;
        res.rc = right.rc;

        res.prefix_len = left.prefix_len;
        if (left.prefix_len == len_l && left.rc == right.lc) {
            res.prefix_len += right.prefix_len;
        }

        res.suffix_len = right.suffix_len;
        if (right.suffix_len == len_r && left.rc == right.lc) {
            res.suffix_len += left.suffix_len;
        }

        res.max_len = max(left.max_len, right.max_len);
        if (left.rc == right.lc) {
            res.max_len = max(res.max_len, left.suffix_len + right.prefix_len);
        }

        return res;
    }

    void build(const string& s, int node, int start, int end) {
        if (start == end) {
            tree[node] = {s[start], s[start], 1, 1, 1};
            return;
        }
        int mid = start + (end - start) / 2;
        build(s, 2 * node, start, mid);
        build(s, 2 * node + 1, mid + 1, end);
        tree[node] = merge(tree[2 * node], tree[2 * node + 1], mid - start + 1, end - mid);
    }

    void update(int node, int start, int end, int idx, char ch) {
        if (start == end) {
            tree[node] = {ch, ch, 1, 1, 1};
            return;
        }
        int mid = start + (end - start) / 2;
        if (idx <= mid) {
            update(2 * node, start, mid, idx, ch);
        } else {
            update(2 * node + 1, mid + 1, end, idx, ch);
        }
        tree[node] = merge(tree[2 * node], tree[2 * node + 1], mid - start + 1, end - mid);
    }

public:
    SegmentTree(const string& s) {
        n = s.length();
        tree.resize(4 * n);
        build(s, 1, 0, n - 1);
    }

    void update(int idx, char ch) {
        update(1, 0, n - 1, idx, ch);
    }

    int getMax() {
        return tree[1].max_len;
    }
};

class Solution {
public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        SegmentTree st(s);
        int k = queryIndices.size();
        vector<int> ans(k);

        for (int i = 0; i < k; ++i) {
            st.update(queryIndices[i], queryCharacters[i]);
            ans[i] = st.getMax();
        }

        return ans;
    }
};