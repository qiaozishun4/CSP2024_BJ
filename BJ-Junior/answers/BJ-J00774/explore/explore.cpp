#include<bits/stdc++.h>
using namespace std;
int t,m[10],n[10],x[10],y[10],d[10],k[10],sx[10],sy[10],cnt=0;
string N[1010];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>n[i]>>m[i]>>k[i];
        cin>>x[i]>>y[i]>>d[i];
        sx[i]=x[i];
        sy[i]=y[i];
        for(int j=1;j<=n[i];j++){
            cin>>N[j];
        }
    }
    for(int i=1;i<=t;i++){
            cnt=0;
        for(int j=1;j<=k[i];j++){
            if(d[i]%4==0&&sy[i]+1<=m[i]&&N[sx[i]][sy[i]+1]=='.'){
                cnt++;
                sy[i]++;
                continue;
            }
            if(d[i]%4==1&&sx[i]+1<=n[i]&&N[sx[i+1]][sy[i]]=='.'){
                cnt++;
                sx[i]++;
                continue;
            }
            if(d[i]%4==2&&sy[i]-1>=1&&N[sx[i]][sy[i]-1]=='.'){
                cnt++;
                sy[i]--;
                continue;
            }
            if(d[i]%4==3&&sx[i]-1>=1&&N[sx[i]-1][sy[i]]=='.'){
                cnt++;
                sx[i]--;
                continue;
            }
            d[i]++;
    }
    cout<<cnt+1<<endl;
}
}
