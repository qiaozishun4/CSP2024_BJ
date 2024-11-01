#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+9;
vector<int>v[maxn];
bool flag = 0;
int r,c,n,k,q;
void dfs(int x,int y,int p){
    if(!flag){
        if(x == r){
            if(y == c) flag = 1;
            return ;
        }
        for(int i = 1;i<=n;i++){
            for(int j = 0;j<=v[i].size();j++){
                if(v[i][j] == y && i!=p){
                    for(int i1 = 1;i1<=k-1;i1++){
                        //cout<<v[i][j+i1]<<" ";
                        dfs(x+1,v[i][j+i1],i);
                    }
                }
            }
        }
    }
    return ;
}
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int _;
    cin>>_;
    while(_--){
        cin>>n>>k>>q;
        for(int i = 1;i<=n;i++){
            int n1;
            cin>>n1;
            while(n1--){
                int x;
                cin>>x;
                v[i].push_back(x);
            }
        }
        while(q--){
            cin>>r>>c;
            for(int i = 1;i<=n;i++){
                for(int j = 0;j<=v[i].size();j++){
                    if(v[i][j] == 1){
                        for(int i1 = 1;i1<=k-1;i1++){
                            dfs(1,v[i][j+i1],i);
                        }
                    }
                }
            }
            if(flag){
                cout<<1<<endl;
                flag = 0;
            }else{
                cout<<0<<endl;
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

