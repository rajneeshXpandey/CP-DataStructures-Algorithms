#include <bits/stdc++.h>
using namespace std;

// <<-----using DSU------->>
vector<int> par;
vector<vector<int>> mst;
vector<int> ranks;

int get(int a)
{
    if (par[a] == a)
        return a;
    return par[a] = get(par[a]);
}

void unite(int a, int b)
{
    a = get(a);
    b = get(b);
    if (ranks[a] < ranks[b])
        swap(a, b);
    par[b] = a;
    if (ranks[a] == ranks[b])
        ranks[a]++;
}

// <----using BFS to find weather a and b are there in G' = {E' : E-e(w<w_ab)}--->

// bool isPath(vector<int> edges[],vector<bool> &visi,int a,int b){
//   visi[a]=1;
//   if(a==b)
//    return true;
//   for(auto nb : edges[a])
//    {
//        if(!visi[nb])
//           return isPath(edges,visi,nb,b);
//    }
//    return false;

//     queue<int> q;
//     q.push(a);
//     while(!q.empty())
//      {
//          int node = q.front();
//          q.pop();
//          visi[node] = 1;
//          for(auto x : edges[node])
//            {
//                if(!visi[x])
//                  {
//                     if(x==b) return true;
//                     q.push(x);
//                  }
//            }
//      }

//      return false;
// }

bool solve(vector<vector<int>> &edges, int a, int b)
{

    //  <------using BFS to find weather a and b are there in G' = {E' : E-e(w<w_ab)}---->
    // int n = alledges.size();
    // vector<int> edges[n+1];
    // int wt_ab;
    // for (auto v : alledges) {
    //     if (v[0] == a and v[1] == b)
    //        { wt_ab = v[2];
    //        break;}
    // }
    // for (auto v : alledges) {
    //     if (v[2] < wt_ab)
    //     { edges[v[0]].push_back(v[1]);
    //       edges[v[1]].push_back(v[0]);
    //      }
    // }

    // vector<bool> visi(n+1,0);

    // return !(isPath(edges,visi,a,b));

    //   <<------------using Kruskal(DSU)--------------->>
    int n = edges.size();
    par.resize(n + 1);
    for (int i = 0; i <= n; i++)
        par[i] = i;
    int wt_ab = 0;
    ranks.resize(n + 1, 0);
    // for (auto v : edges) {
    //     cout << v[0] << " " << v[1] << " " << v[2] << " " << endl;
    // }
    sort(edges.begin(), edges.end(), [](vector<int> v1, vector<int> v2)
         {
             if (v1[2] < v2[2])
                 return true;
             else
                 return false;
         });

    for (auto v : edges)
    {
        if (v[0] == a and v[1] == b)
        {
            wt_ab = v[2];
            break;
        }
    }

    int cost = 0;
    for (auto &v : edges)
    {
        if (get(v[0]) == get(v[1]))
            continue;
        else
        {
            // mst.push_back(v);
            cost += v[2];
            unite(v[0], v[1]);
        }
    }

    int cost_with_ab = 0;

    par.resize(n + 1);
    for (int i = 0; i <= n; i++)
        par[i] = i;
    ranks.resize(n + 1, 0);

    unite(a, b);
    cost_with_ab = wt_ab;

    for (auto &v : edges)
    {
        if (get(v[0]) == get(v[1]))
            continue;
        else
        {
            // mst.push_back(v);
            cost_with_ab += v[2];
            unite(v[0], v[1]);
        }
    }

    if (cost == cost_with_ab)
        return true;
    return false;
}

int main()
{

//    input goes here

    // return 0;
}

