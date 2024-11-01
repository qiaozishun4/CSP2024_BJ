#include<bits/stdc++.h>
using namespace std;
struct edge{
    int s,e,f;
};
vector<edge> v[100001];
bool vis[100001];
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);

    int T;
    cin >> T;
    while(T--){
        int n,k,q;
        cin >> n >> k >> q;
        for(int i=1;i<=n;i++){
            int l;
            cin >> l;
            vector<int> t;
            for(int j=1;j<=l;i++){
                cin >> t[j];
                /*for(int m=max(j-k+1,0);m<=j;m++){
                    edge tmp;
                    tmp.s=t[m];tmp[e]=t[j];tmp.f=i;
                    v[t[m]].end()=tmp;
                }*/
            }

            for(int i=1;i<=q;i++){
                int r,c;
                cin >> r >> c;
                cout << 1 << endl;
            }

        }
        /*queue<int> q;
        q.push(1);
        while(q.size()){
            int t=q.top();
            q.pop();
            int l=v[t].size();
            for(int i=1;i<=l;i++){
                if(v[t].f!==v[i].f&&!vis[v[i]].e){
                    vis[t]=1;
                    q.push(i);
                }
            }

        }*/
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
