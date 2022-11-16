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

        int find_set(int x)
        {
            if (x == parent[x])
                return x;
            return parent[x] = find_set(parent[x]);
        }

        void union_sets(int a, int b)
        {
            a = find_set(a);
            b = find_set(b);
            if (a != b)
            {
                if (rank[a] < rank[b])
                    swap(a, b);
                size[b] += size[a];
                size[a] = 0;
                parent[b] = a;
                if (rank[a] == rank[b])
                    rank[a]++;
            }
        }
};