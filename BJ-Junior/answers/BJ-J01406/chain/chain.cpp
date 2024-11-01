#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
long long T;
long long n,k,q;
long long l[N];
long long s[100][100];
long long r,c;
bool flag;
void dfs(long long pre,long long tmp,long long last){
    if(tmp==r&&last==c){
        flag=true;
        return;
    }
    if(tmp>=r)return;
    for(int i=1;i<=n;i++){
        if(i==pre)continue;
        for(int j=1;j<l[i];j++){
            if(s[i][j]==last){
                for(int len=2;len<=k;len++){
                    dfs(i,tmp+1,s[i][j+len-1]);
                }
            }
        }
    }
}
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>n>>k>>q;
        for(int i=1;i<=n;i++){
            cin>>l[i];
            for(int j=1;j<=l[i];j++){
                cin>>s[i][j];
            }
        }
        for(int op=1;op<=q;op++){
            cin>>r>>c;
            flag=false;
            for(int i=1;i<=n;i++){
                for(int j=1;j<=l[i];j++){
                    if(s[i][j]==1){
                        for(int len=2;len<=k;len++){
                            dfs(i,1,s[i][j+len-1]);
                        }
                    }
                }
            }
            if(flag)cout<<1<<endl;
            else cout<<0<<endl;
        }
    }

    return 0;
}
