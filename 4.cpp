#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
#define mod 1000000007
#define N 1e9+2
#define F first
#define S second
#define endl "\n"
using namespace std;

bool isValid(int r, int c, int mxr, int mxc) {
    return r >= 0 && r < mxr && c >= 0 && c < mxc;
}

vector<int> bfs(vector<vector<int>>& grid, vector<int>& coor) {
    int mxr = grid.size();
    int mxc = grid[0].size();
    vector<pair<int, int>> dir = {{1, 0}, {0, -1}, {0, 1}};
    queue<pair<int, int>> q;
    set<pair<int, int>> vis;

    q.push({coor[0], coor[1]});
    vis.insert({coor[0], coor[1]});
    while (!q.empty()) {
        auto x = q.front();
        q.pop();
        auto r=x.first;
        auto c=x.second;
        if (r >= mxr) {
            return {r, c};
        }

        if (isValid(r + 1, c, mxr, mxc) && vis.find({r + 1, c}) == vis.end() && grid[r + 1][c] < grid[r][c]) 
        {
            q.push({r + 1, c});
            vis.insert({r + 1, c});
            continue;
        }

        for (auto& d : dir) 
        {
            int nr = r + d.first;
            int nc = c + d.second;

            if (isValid(nr, nc, mxr, mxc) && vis.find({nr, nc}) == vis.end() && grid[nr][nc] <= grid[r][c]) 
            {
                q.push({nr, nc});
                vis.insert({nr, nc});
            }
        }
    }

    return {-1};
}

signed main() {

   int n,m;
   cin>>n>>m;

    vector<vector<int>> grid(n,vector<int>(m));
    vector<int> coor(2);

    for (int i = 0; i < n; ++i)
    {
       for (int j = 0; j < m; ++j)
       {
          cin>>grid[i][j];
       }
    }
    cin>>coor[0]>>coor[1];

    vector<int> res = bfs(grid, coor);
    if (res.size() == 1 && res[0] == -1) {
        cout << -1<<","<<-1 << endl;
    } else {
        cout<<res[0] <<","<<res[1]<<endl;
    }

    return 0;
}
