#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int T,n,k,q;
bool ok;
vector<int> a[N];
void dfs(int x,int fx,int r,int c){
    if(ok) return;
    /*
    for(int i=1;i<=10-r;i++){
        cout<<"   ";
    }
    cout<<x<<" "<<fx<<" "<<r<<" "<<ok<<endl;
    */
    if(r==0){
        if(x==c) ok=1;
        return;
    }
    for(int i=1;i<=n;i++){
        if(i==fx) continue;
        for(int j=0;j<a[i].size();j++){
            if(a[i][j]==x){
                for(int p=1;p<k&&j+p<a[i].size();p++){
                    dfs(a[i][j+p],i,r-1,c);
                }
            }
        }
    }
}
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>T;
    while(T--){
        cin>>n>>k>>q;
        for(int i=1;i<=n;i++){
            a[i].clear();
            int l;
            cin>>l;
            for(int j=1;j<=l;j++){
                int p;
                cin>>p;
                a[i].push_back(p);
            }
        }
        while(q--){
            int r,c;
            cin>>r>>c;
            ok=0;
            dfs(1,0,r,c);
            cout<<ok<<endl;
        }
    }
    return 0;
}