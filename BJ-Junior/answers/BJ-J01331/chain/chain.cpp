#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<int> v[200005];
int si[200005];
//int is[100005][105];
int can[200005];
int n,k,q;
struct node{
    int x;
    int sum;
    int last;
};
long long qi[200005],qr[200005];
long long maxr;
/*
void bfs(){
    queue<node> q;
    q.push({1,0,-1});
    while(!q.empty()){
        node tp=q.front();
        q.pop();
        //is[tp.x][tp.sum]=1;
        if(tp.sum==maxr){
            continue;
        }
        for(int i=1;i<=n;i++){
            if(i!=tp.last){
                int ll=-1e9;
                for(int j=0;j<si[i];j++){
                    if(j-k+1<=k){
                        q.push({v[i][j],tp.sum+1,i});
                    }
                    if(v[i][j]==tp.x){
                        ll=j;
                    }
                }
            }
        }
    }
}
*/
int main(){
    ios::sync_with_stdio(0);
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        cin>>n>>k>>q;
        for(int i=1;i<=2e5;i++){
            can[i]=0;
        }
        for(int i=1;i<=n;i++){
            vector<int> tp;
            swap(v[i],tp);
            cin>>si[i];
            int ll=-1e9;
            for(int j=0;j<si[i];j++){
                int x;
                cin>>x;
                v[i].push_back(x);
                if(ll>=j-k+1){
                    can[v[i][j]]=1;
                }
                if(v[i][j]==1){
                    ll=j;
                }
            }
        }
        maxr=0;
        for(int i=1;i<=q;i++){
            cin>>qi[i]>>qr[i];
            maxr=max(maxr,qr[i]);
        }
        /*
        for(int i=1;i<=n;i++){
            for(int j=1;j<=maxr;j++){
                is[i][j]=0;
            }
        }
        */
        //bfs();
        for(int i=1;i<=q;i++){
            cout<<can[qr[i]]<<'\n';
        }
    }
    return 0;
}
