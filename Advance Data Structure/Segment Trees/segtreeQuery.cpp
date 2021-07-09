#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    long long sum;
    long long sqsum;
    node()
    {
        sum = 0;
        sqsum = 0;
    }
};

class segtree
{
public:
    int n = 0;
    vector<int> a;
    vector<node> tree;
    node nue;
    void init(int N)
    {
        n = N;
        tree.resize(4 * N + 1);
        a.assign(N + 1, 0);
    }
    void put(vector<int> &v)
    {
        a = v;
    }

    void merge(node &curr, node &left, node &right)
    {
        curr.sum = left.sum + right.sum;
        curr.sqsum = left.sqsum+ right.sqsum;
    }
    void leaf(node &curr, int idx)
    {
        curr.sum = a[idx];
        curr.sqsum = a[idx] * a[idx];
    }
    void build(int idx, int ss, int se)
    {
        if (ss == se)
        {
            leaf(tree[idx], ss);
            return;
        }
        int mid = (ss + se) / 2;
        build(2 * idx + 1, ss, mid);
        build(2 * idx + 2, mid + 1, se);
        merge(tree[idx], tree[2 * idx + 1], tree[2 * idx + 2]);
    }
    void build()
    {
        build(0, 0, n - 1);
    }
    node query(int idx, int ss, int se, int qs, int qe)
    {
        if (qe < ss || qs > se)
            return nue;
        if (qs <= ss and qe >= se)
            return tree[idx];
        int mid = (ss + se) / 2;
        node left = query(2 * idx + 1, ss, mid, qs, qe);
        node right = query(2 * idx + 2, mid + 1, se, qs, qe);
        node mer;
        merge(mer, left, right);
        return mer;
    }
    node query(int l, int r)
    {
        return query(0, 0, n - 1, l, r);
    }

    void update(int idx, int ss, int se, int i, int val)
    {
        if (i < ss || i > se)
            return;
        if (ss == se)
        {
            tree[idx].sum = val;
            tree[idx].sqsum = val * val;
            return;
        }
        int mid = (ss + se) / 2;
        update(2 * idx + 1, ss, mid, i, val);
        update(2 * idx + 2, mid + 1, se, i, val);

        merge(tree[idx], tree[2 * idx + 1], tree[2 * idx + 2]);
    }
    void update(int i, int val)
    {
        update(0, 0, n - 1, i, val);
    }
};

vector<long long> solve(int N, int Q, vector<int> A, vector<vector<int>> query)
{
    // Type your code here
    vector<long long> ans;
    segtree st;
    st.init(N);
    st.put(A);
    st.build();
    for (auto &q : query)
    {
        if (q[0] == 0)
        {
            auto s = st.query(q[1] - 1, q[2] - 1);
            long long anss = (s.sum * s.sum - s.sqsum) / 2;
            ans.push_back(anss);
        }
        else
        {
            
            st.update(q[1] - 1, q[2]);
        }
    }
    return ans;
}

int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    int Q;
    cin >> Q;
    vector<int> A(N);
    for (int i_A = 0; i_A < N; i_A++)
    {
        cin >> A[i_A];
    }
    vector<vector<int>> query(Q, vector<int>(3));
    for (int i_query = 0; i_query < Q; i_query++)
    {
        for (int j_query = 0; j_query < 3; j_query++)
        {
            cin >> query[i_query][j_query];
        }
    }

    vector<long long> out_;
    out_ = solve(N, Q, A, query);
    for (int i_out_ = 0; i_out_ < out_.size(); i_out_++)
    {
        cout << out_[i_out_] << endl;
    }
}