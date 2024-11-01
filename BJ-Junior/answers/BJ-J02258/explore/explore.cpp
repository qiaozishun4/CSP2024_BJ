#include <iostream>
#include <string>
using namespace std;

string ma[1005];
bool h[1005][1005];

int main()
{
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    int t;
    cin >> t;
    while (t--)
    {
      int n, m, k, x0, y0, d0;
      cin >> n >> m >> k;
      cin >> x0 >> y0 >> d0;
      h[x0][y0] = true;
      for (int i = 1; i <= n; i++)
      {
          cin>>ma[i];
      }
      while (k--)
      {
          int x = x0, y = y0;
          if (d0 == 0)
          {
              y++;
          }
          if (d0 == 1)
          {
              x++;
          }
          if (d0 == 2)
          {
              y--;
          }
          if (d0 == 3)
          {
              x--;
          }
          if (ma[x][y - 1] == '.' && 0 < x && x <= n && 0 < y && y <= m)
          {
              x0 = x;
              y0 = y;
              h[x][y] = true;
          }
          else
          {
              d0 = (d0 + 1) % 4;
          }
      }
      int cnt = 0;
      for (int i = 1; i <= n; i++)
      {
          for (int j = 1; j <= m; j++)
          {
              if (h[i][j])
              {
                  cnt++;
              }
          }
      }
      cout << cnt << endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
