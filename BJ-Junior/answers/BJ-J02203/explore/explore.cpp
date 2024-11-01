#include<bits/stdc++.h>
using namespace std;
char a[1024][1024];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T,n,m,k;
    int x,y,d,ans;
    cin>>T;
    while(T>0){
        ans=1;
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>a[i][j];
            }
        }
        for(int i=0;i<k;i++){
            if(d==0){
                if(y+1>m || a[x][y+1]=='x')
                    d++;
                else if(a[x][y+1]!='x'){
                    if(a[x][y+1]=='.')
                        ans++;
                    a[x][y+1]='/';
                    y++;
                }
            }
            else if(d==1){
                if(x+1>n || a[x+1][y]=='x')
                    d++;
                else if(a[x+1][y]!='x'){
                    if(a[x+1][y]=='.')
                        ans++;
                    a[x+1][y]='/';
                    x++;
                }
            }
            else if(d==2){
                if(y-1<1 || a[x][y-1]=='x')
                    d++;
                else if(a[x][y-1]!='x'){
                    if(a[x][y-1]=='.')
                        ans++;
                    a[x][y-1]='/';
                    y--;
                }
            }
            else if(d==3){
                if(x-1<1 || a[x-1][y]=='x')
                    d=0;
                else if(a[x-1][y]!='x'){
                    if(a[x-1][y]=='.')
                        ans++;
                    a[x-1][y]='/';
                    x--;
                }
            }
        }
        cout<<ans<<endl;
        T--;
    }

    return 0;
}
