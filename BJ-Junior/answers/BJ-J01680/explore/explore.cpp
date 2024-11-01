#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);

    int T;
    cin >> T;
    for (int i = 1; i <= T ; i++)
    {
        int n, m, k, x0, y0, d0;
        cin >> n >> m >> k;
        cin >> x0 >> y0 >> d0;
        string Map[n+1][m+1];
        for(int x = 1; x <= n; x++){
            for(int y = 1; y <= m; y++){
                cin >> Map[x][y];
            }
        }

        if(k == 1){
            if (d0 == 0){
                if (y0 + 1 <= m)
                    if (Map[x0][y0+1] != "x") cout << 2 << endl;
                    else cout << 1 << endl;
                else cout << 1 << endl;
            }
            else if (d0 == 1){
                if(x0 + 1 <= n)
                    if (Map[x0+1][y0] != "x") cout << 2 << endl;
                    else cout << 1 << endl;
                else cout << 1 << endl;
            }
            else if (d0 == 2)
                if (y0-1 >= 1)
                    if (Map[x0][y0-1] != "x") cout << 2 << endl;
                    else cout << 1 << endl;
                else cout << 1 << endl;

            else {
                if (x0-1 >= 1)
                    if (Map[x0-1][y0] != "x") cout << 2 << endl;
                    else cout << 1 << endl;
                else cout << 1 << endl;
            }
        }
        else cout << k;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
