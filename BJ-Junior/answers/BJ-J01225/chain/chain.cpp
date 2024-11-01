#include<bits/stdc++.h>
using namespace std;
int T,n,k,q,a,b;
int l[200005];
vector<int> s[100005];
bool flag;
void dfs(int ix,int last,int tim){
    if(tim==a){
        if(last==b){
            flag=1;
        }
        return;
    }
    for(int i=1;i<=n;i++){
        if(i==ix){
            continue;
        }
        for(int j=0;j<l[i];j++){
            if(s[i][j]==last){
                for(int m=j+1;m<=min(j+k-1,l[i]-1);m++){
                    dfs(i,s[i][m],tim+1);
                    if(flag) return;
                }
            }
        }
    }
}
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>T;
    while(T--){
        cin>>n>>k>>q;
        for(int i=1;i<=n;i++){
            cin>>l[i];
            for(int j=1;j<=l[i];j++){
                int x;
                cin>>x;
                s[i].push_back(x);
            }
        }
        while(q--){
            flag=0;
            cin>>a>>b;
            dfs(0,1,0);
            cout<<flag<<endl;
        }
    }
    return 0;
}
