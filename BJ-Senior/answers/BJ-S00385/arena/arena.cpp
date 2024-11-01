#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN=1e5+5;
int b[MAXN],c[MAXN];
char d[20][MAXN];
signed main(){
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)   cin>>b[i];
    for(int i=1;i<=m;i++)   cin>>c[i];
    int tmp=1,k;
    for(int i=1;i<=16;i++){
        tmp*=2;
        if(tmp>=n && tmp/2<n){
            k=i;
            break;
        }
    }
    for(int i=k;i>=1;i--){
        int len=1<<(i-1);
        //cout<<len<<' ';
        for(int j=1;j<=len;j++) cin>>d[i][j];
    }
    int T;
    cin>>T;
    while(T--){
        int x1,x2,x3,x4;
        cin>>x1>>x2>>x3>>x4;
        x1^=x2;
        x1^=x3;
        x1^=x4;
        cout<<x1<<endl;
    }
    return 0;
}
