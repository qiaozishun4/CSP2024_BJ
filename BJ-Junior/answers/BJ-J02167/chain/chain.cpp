#include <iostream>
#include <cstdlib>
#include <queue>
#include <vector>
#define mk make_pair
#define ppi pair<int,int>
using namespace std;

vector<int> v[100005];

int t,n,k,q,r,c;
bool flag;
void dfs(int lvl,int in,int pos){
    if(flag){
        return ;
    }if(lvl>r){
        if(v[in][pos]==c){
            flag=true;
        }return ;
    }for(int jn=1;jn<=n;++jn){
        if(jn==in){
            continue;
        }for(int i=0;i<v[jn].size();++i){
            if(v[jn][i]==v[in][pos]){
                for(int j=i+1;j<i+k && j<v[jn].size();++j){
                    dfs(lvl+1,jn,j);
                }
            }
        }
    }
}

int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>t;
    v[0].push_back(1);
    while(t--){
        cin>>n>>k>>q;
        for(int i=1;i<=n;++i){
            int l,tr;
            cin>>l;
            for(int j=1;j<=l;++j){
                cin>>tr;
                v[i].push_back(tr);
            }
        }while(q--){
            cin>>r>>c;
            flag=false;
            dfs(1,0,0);
            cout<<flag<<'\n';
        }for(int i=1;i<=n;++i){
            v[i].clear();
        }//cout<<"fage";
    }
    return 0;
}
