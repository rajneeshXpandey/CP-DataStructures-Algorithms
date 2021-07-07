#include<bits/stdc++.h>
using namespace std;

vector<vector<char>> mat;
vector<vector<int>> visi;

void dfs(int a,int b){

    if (a < 0 || b < 0 || a >= mat.size() || b >= mat[0].size() || mat[a][b] == '#' || visi[a][b])
        return;

    visi[a][b] = 1;
    dfs(a+1,b);
    dfs(a, b+1);
    dfs(a-1, b);
    dfs(a, b-1);

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m;
    cin>>n>>m;
    mat.resize(n,vector<char> (m));
    for(int i=0;i<n;i++)
      for(int j=0;j<m;j++)
         cin>>mat[i][j];

    visi.resize(n, vector<int>(m,0));
    int rooms = 0;

    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
              if(mat[i][j]=='.' && !visi[i][j])
                {
                 dfs(i,j);   
                 rooms++;
                }
          }
      }

    cout<<rooms<<'\n';   

    return 0;   
}