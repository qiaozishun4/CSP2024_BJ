#include<bits/stdc++.h>
using namespace std;
int t,n,k,q,r,c;
bool b=false;
vector<int> s[100001];
bool h[200001];
void dfs(int k1,int p,int lst){
    if(b){
        return ;
    }
    if(k1==r+1){
        if(lst==c){
            b=true;
        }
        return ;
    }
    for(int k2=1;k2<=n;k2++){
        if(k2==p){
            continue;
        }
        for(int i=0;i<s[k2].size();i++){
            if(s[k2][i]!=lst){
                continue;
            }
            for(int j=2;j<=k;j++){
                if(i+j-1<s[k2].size()){
                    dfs(k1+1,k2,s[k2][i+j-1]);
                }
            }
        }
    }
}
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n>>k>>q;
        for(int i=1;i<=n;i++){
            int l;
            cin>>l;
            s[i].clear();
            for(int j=1;j<=l;j++){
                int x;
                cin>>x;
                s[i].push_back(x);
            }
        }
        memset(h,false,sizeof(h));
        for(int i=1;i<=n;i++){
            for(int j=0;j<s[i].size();j++){
                for(int k1=j+1;k1<=j+k-1&&k1<s[i].size();k1++){
                    if(s[i][j]==1){
                        h[s[i][k1]]=true;
                    }
                }
            }
        }
        while(q--){
            cin>>r>>c;
            if(r==1){
                cout<<h[c]<<endl;
                continue;
            }
            b=false;
            dfs(1,0,1);
            cout<<b<<endl;
        }
    }
}
