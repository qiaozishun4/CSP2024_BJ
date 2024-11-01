#include<bits/stdc++.h>
using namespace std;
int n,m,k,sx,sy,d,t;
long long ans;
char c;
bool a[1010][1010],b[1010][1010];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    for(int i=1; i<=t; i++){
        ans=1;
        cin>>n>>m>>k>>sx>>sy>>d;
        for(int i=1; i<=n; i++)
            for(int j=1; j<=m; j++){
                a[i][j]=0;
                b[i][j]=0;
                cin>>c;
                if(c=='x')
                    b[i][j]=1;
            }
        a[sx][sy]=1;
        for(int i=1; i<=k; i++){
            if(d==0){
                if(sy==m||b[sx][sy+1])
                    d++;
                else{
                    sy++;
                    if(!a[sx][sy])
                        ans++;
                    a[sx][sy]=1;
                }
            }
            else if(d==1){
                if(sx==n||b[sx+1][sy])
                    d++;
                else{
                    sx++;
                    if(!a[sx][sy])
                        ans++;
                    a[sx][sy]=1;
                }
            }
            else if(d==2){
                if(sy==1||b[sx][sy-1])
                    d++;
                else{
                    sy--;
                    if(!a[sx][sy])
                        ans++;
                    a[sx][sy]=1;
                }
            }
            else if(d==3){
                if(sx==1||b[sx-1][sy])
                    d=0;
                else{
                    sx--;
                    if(!a[sx][sy])
                        ans++;
                    a[sx][sy]=1;
                }
            }
            //cout<<sx<<" "<<sy<<' '<<i<<' '<<d<<' '<<ans<<endl;
        }
        cout<<ans<<endl;
    }
    return 0;
}
