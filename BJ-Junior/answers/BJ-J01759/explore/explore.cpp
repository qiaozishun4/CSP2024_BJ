#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("explore.in");
ofstream fout("explore.out");
const int movex[4] = {1, 0, -1, 0};
const int movey[4] = {0, 1, 0, -1};
int main()
{
    int T;
    fin >> T;
    for(int t = 0; t < T; t++)
    {
        char map[1000][1000] = {};
        bool vis[1000][1000] = {};
        int w, h, k, x, y ,d;
        int ans = 1;
        fin >> h >> w >> k;
        fin >> y >> x >> d;
        x--,y--;
        vis[y][x] = true;
        for(int y = 0; y < h; y++)
        {
            for(int x = 0; x < w; x++)
                fin >> map[y][x];
        }
        /*for(int a = 0; a < h; a++)
        {
            for(int b = 0; b < w; b++)
            {
                if(a == y && b == x)
                {
                    cout << 'o';
                }
                else cout << map[a][b];
            }
            cout << endl;
        }
        cout << endl;*/
        for(int a = 0; a < k; a++)
        {
            int nx = x + movex[d];
            int ny = y + movey[d];
            if(nx >= 0 && nx < w && ny >= 0 && ny < h && map[ny][nx] == '.')
            {
                x = nx, y = ny;
                if(!vis[y][x])
                {
                    ans++;
                    vis[y][x] = true;
                }
            }
            else
                d = (d + 1) % 4;
        }
        fout << ans << endl;
    }
    return 0;
}
