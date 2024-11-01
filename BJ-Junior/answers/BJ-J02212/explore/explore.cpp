#include <bits/stdc++.h>

using namespace std;

int t;

int main() {
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin >> t;
    while(t--) {
        int n,m,k,x,y,d,ans=0;
        char Map[1010][1010];
        cin >> n >> m >> k;
        cin >> x >> y >> d;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                cin >> Map[i][j];
        int mx=x,my=y;
        for(int i=1;i<=k;i++) {
            if(d==0)
                y++;
            else if(d==1)
                x++;
            else if(d==2)
                y--;
            else
                x--;

            if(x<1 || y<1 || x>n || y>m || Map[x][y]=='x') {
                if(i==1)
                    ans++;
                if(d==0)
                    y--;
                else if(d==1)
                    x--;
                else if(d==2)
                    y++;
                else
                    x++;
                d = (d+1)%4;

                continue;
            }
            else {
                mx=x,my=y;
                ans++;
                //cout << mx << ',' << my << "->";
            }

        }
        cout << ans << endl;
    }


    return 0;
}
