# include <bits/stdc++.h>
using namespace std;
int ans,d,x,y,t,m,n,k;

int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while(t--){
        ans = 0;
        cin>>n>>m>>k;
        char MAP[n+1][m+1];
        int a[n+1][m+1];
        cin>>x>>y>>d;
        for(int j = 1;j <= n;j ++){
            for(int k = 1;k <= m;k ++)
                cin>>a[j][k];
                a[j][k] = 0;
        }
        a[x][y] = 1;
        ans++;
        for(int j = 1;j <= k;j ++){
            if(d == 0){
                if(MAP[x][y+1] != 'x'){
                    y++;
                    if(a[x][y] == 0){
                        a[x][y] = 1;
                        ans++;

                    }
                }
                else{
                    d = (d+1)%4;
                }

            }
            else if(d == 2){
                if(MAP[x][y-1] != 'x'){
                    y--;
                    if(a[x][y] == 0){
                        a[x][y] = 1;
                        ans++;

                    }
                }
                else{
                    d = (d+1)%4;
                }

            }

            else if(d == 1){
                if(MAP[x-1][y] != 'x'){
                    x--;
                    if(a[x][y] == 0){
                        a[x][y] = 1;
                        ans++;

                    }
                }
                else{
                    d = (d+1)%4;
                }

            }
            else if(d == 3){
                if(MAP[x+1][y] != 'x'){
                    x++;
                    if(a[x][y] == 0){
                        a[x][y] = 1;
                        ans++;
                        }
                    }
                    else{
                        d = (d+1)%4;
                    }

                }
            }

        cout<<ans<<endl;
    }
    return 0;
}
