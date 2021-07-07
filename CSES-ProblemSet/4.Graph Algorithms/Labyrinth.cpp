#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define f first
#define s second

vector<vector<char>> mat;
vector<vector<int>> visi;
vector<vector<int>> path;
bool reach = false;

// 0 = up, 1 = right, 2 = down, 3 = left
string moves = "URDL";
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void bfs(int x, int y)
{
    queue<pii> q;
    q.push({x,y});
    visi[x][y] = 1;
    while(!q.empty()){
        pii curr = q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int a = curr.f+dx[i];
            int b = curr.s+dy[i];
            if (a < 0 || b < 0 || a >= mat.size() || b >= mat[0].size() || mat[a][b] == '#' || visi[a][b])
                continue;
            visi[a][b] = 1;
            path[a][b]=i;
            q.push({a,b});
        }
    }
    
  
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    pii coordA,coordB;
    mat.resize(n, vector<char>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++){
            cin >> mat[i][j];
            if (mat[i][j]=='A')
                coordA = {i,j};
            else if (mat[i][j] == 'B')
                coordB = {i, j};
            }

    visi.resize(n, vector<int>(m, 0));
    path.resize(n, vector<int>(m, 0));

    bfs(coordA.f,coordA.s);

    if (visi[coordB.f][coordB.s]){
        cout << "YES" << '\n';
        vector<int> steps;
        while (coordA != coordB){
            int prevmove = path[coordB.f][coordB.s];
            steps.push_back(prevmove);
            coordB = {coordB.f - dx[prevmove], coordB.s - dy[prevmove]};
        }
        reverse(steps.begin(), steps.end());
        cout << steps.size() << endl;
        for (auto c : steps){
            cout << moves[c];
        }
     }
    else 
     cout<<"NO"<<'\n';
    return 0;
}