/*
Basic Code without Optimization

int find(int u)
{
    if(u == representative[u])
        return u;

    else
        return  find(representative[u]);
}

void combine (int u, int v)
{
     u = find(u);
     v = find(v);

     if(u == v)    // already in the same set so no action needed
        return;
    else
       representative[v] = u;
}


/*
    *with optimization*
*/

class dsu
{
public:
    vector<int> parent,size,rank;

    explicit dsu(int a)
    {
        parent.resize(a);
        size.resize(a);
        rank.resize(a);
        for (int i = 0; i < a; i++)
        {
            parent[i] = i;
            size[i] = 1;
            rank[i] = 0;
        }
    }

    int get(int i)
    {
        if (i == parent[i])
            return i;
        return parent[i] = get(parent[i]);
    }

    bool unite(int a, int b)
    {
        a = get(a);
        b = get(b);
        if (a != b)
        {
            if (rank[a] > rank[b])
                swap(a, b);
            parent[a] = b;
            size[b] += size[a];
            size[a] = 0;
            if (rank[a] == rank[b])
                rank[b]++;
            return true;
        }
        return false;
    }
};
