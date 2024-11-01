#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
char s[N][N];
int t[N][N],vs[N][N];
int st[4]{0,1,0,-1};
int ct[4]{1,0,-1,0};
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        int n,m,k,a,b,d,cnt=0;
        cin>>n>>m>>k>>a>>b>>d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>s[i][j];
            }
        }
        memset(vs,0,sizeof(vs));
        memset(t,-1,sizeof(t));
        vs[a][b]=1;
        cnt=1;
        int o=k;
        for(int i=k;i>=1;i--){
            if(d==t[a][b])break;
            t[a][b]=d;
            if(s[a+st[d]][b+ct[d]]=='.'&&a+st[d]>0&&a+st[d]<=n&&b+ct[d]>0&&b+ct[d]<=m){
                a+=st[d],b+=ct[d];
                if(vs[a][b]==0){
                    cnt++;
                    vs[a][b]=1;
                }
            }
            else{
                d=(d+1)%4;
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}

