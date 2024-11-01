#include<iostream>
#include<fstream>
using namespace std;
bool visited[1010][1010];
char map[1010][1010];
bool ok(int x, int y, int n, int m)
{
    if(x < 0 || x >= n || y < 0 || y >= m) return false;
    if(map[x][y] == 'x') return false;
    return true;
}
int main()
{
    ios::sync_with_stdio(false);
    ifstream fin("explore.in", ios::in);
    ofstream fout("explore.out", ios::out);
    fin.tie(0); fout.tie(0);
    int t;
    fin >> t;
    while(t--)
    {
        for(int i = 0;i < 1000;i++)
        {
            for(int j = 0;j < 1000;j++)
            {
                visited[i][j] = false;
            }
        }
        int n, m, k, x, y, d;
        fin >> n >> m >> k;
        fin >> x >> y >> d;
        for(int i = 0;i < n;i++) for(int j = 0;j < m;j++)
        {
            fin >> map[i][j];
        }
        x--, y--;
        visited[x][y] = true;
        for(int i = 0;i < k;i++)
        {
            if(d == 0 && ok(x, y + 1, n, m)) visited[x][++y] = true;
            else if(d == 1 && ok(x + 1, y, n, m)) visited[++x][y] = true;
            else if(d == 2 && ok(x, y - 1, n, m)) visited[x][--y] = true;
            else if(d == 3 && ok(x - 1, y, n, m)) visited[--x][y] = true;
            else d = (d + 1) % 4;
        }
        int ans = 0;
        for(int i = 0;i < n;i++) for(int j = 0;j < m;j++)
        {
            if(visited[i][j]) ans++;
        }
        fout << ans << endl;
    }
    return 0;
}
