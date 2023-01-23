class dsu
{
    public:
        vector<int> parent;
        vector<int> size, rank;

        explicit dsu(int n)
        {
            parent.resize(n);
            size.resize(n);
            rank.resize(n);
            for (int x = 0; x < n; x++)
            {
                parent[x] = x;
                size[x] = 1;
                rank[x] = 0;
            }
        }

        int find(int x)
        {
            return (x == parent[x]) ? (x) : (parent[x] = find(parent[x]));
        }

        void unite(int a, int b)
        {
            a = find(a);
            b = find(b);
            if (a == b) return;
            if (rank[a] < rank[b])
                swap(a, b);
            size[b] += size[a];
            size[a] = 0;
            parent[b] = a;
            if (rank[a] == rank[b])
                rank[a]++;
        }
};