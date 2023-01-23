// Minimum Spanning Tree using DSU

class dsu
{
    public:
        vector<int> parent;
        vector<int> size, rank;

        explicit dsu(int n){
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

struct Edge
{
    int u, v, weight;
    bool operator<(Edge const &other)
    {
        return weight < other.weight;
    }
};

vector<Edge> MST(vector<vector<Edge>> &adj,vector<Edge> &edges,int n){
        int cost = 0;
        dsu d(n);
        vector<Edge> result;
        sort(edges.begin(), edges.end());
        for (Edge e : edges){
            if (d.find_set(e.u) != d.find_set(e.v)){
                cost += e.weight;
                result.push_back(e);
                d.union_sets(e.u, e.v);
            }
        }
        return result;
} 
