#include <bits/stdc++.h>
using namespace std;

int t,n,cl,q;
int l[1145];
int a[1145][1145];
int mov[11][114514];

void dfs(int last,int num,int r){
    mov[r][num]=t;
    if(r>10)return;
    for(int i=1;i<=n&&i!=last;i++){
        for(int j=1;j<=l[i];j++){
            if(a[i][j]==num){
                for(int k=j+1;k-j+1<=cl&&k<l[i];k++){
                    dfs(i,a[i][k],r+1);
                }
            }
        }
    }
}

int main(){
    freopen("chain1.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin>>t;
    for(int tt=1;t>=tt;t--){
        cin>>n>>cl>>q;
        for(int i=1;i<=n;i++){
            cin>>l[i];
            for(int j=1;j<=l[i];j++)cin>>a[i][j];
        }
        dfs(0,1,0);
        while(q--){
            int r,c;
            cin>>r>>c;
            cout<<(a[r][c]==t)<<endl;
        }
    }
    return 0;
}
