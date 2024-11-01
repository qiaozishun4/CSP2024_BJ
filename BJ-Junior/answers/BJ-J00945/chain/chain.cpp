#include<bits/stdc++.h>
#define int long long
using namespace std;

struct node{
    int num;
    int id;
};

vector <int> a[400005];
vector <node> b[400005];
int n,k,q;
bool ans=0;

void dfs(int times,int now,int lst,int r,int c){
    //cout<<times<<" "<<now<<" "<<lst<<" "<<r<<" "<<c<<endl;
    if(times==r){
        if(now==c){
            ans=1;
        }

        return;
    }

    for(int i=0;i<b[now].size();i++){
        node x; x=b[now][i];

        if(x.num==lst){
            continue;
        }

        for(int j=x.id+1;j<=x.id+k-1;j++){
            if(j>=a[x.num].size()){
                break;
            }

            dfs(times+1,a[x.num][j],x.num,r,c);
        }
    }
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);

    int t; cin>>t;

    while(t--){
        cin>>n>>k>>q;

        for(int i=1;i<=400000;i++){
            a[i].clear();
        }

        for(int i=1;i<=400000;i++){
            b[i].clear();
        }

        for(int i=1;i<=n;i++){
            int x; cin>>x;

            for(int j=1;j<=x;j++){
                int p; cin>>p;
                a[i].push_back(p);
                b[p].push_back({i,j-1});
            }
        }

        for(int i=1;i<=q;i++){
            int r,c; cin>>r>>c;
            ans=0;
            dfs(0,1,-1,r,c);
            cout<<ans<<endl;
        }
    }
    return 0;
}

