#include <bits/stdc++.h>
using namespace std;
struct node{
    double di,vi,ai,be=-1,en=-1;
};
vector< vector< long long > > x;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    long long t;
    cin>>t;
    while(t--){
        long long n,m,L,V;
        cin>>n>>m>>L>>V;
        vector<node> v(n+1);
        vector<long long> c(m+1,0);
        for(int i=1;i<=n;i++){
            cin>>v[i].di>>v[i].vi>>v[i].ai;
            if (v[i].vi>V) {
                v[i].be=v[i].di;
                if(v[i].ai>=0) v[i].en=L;
                else{
                    v[i].en=v[i].di+(V*V-v[i].vi*v[i].vi)/(2*v[i].ai);
                }
            }
            else{
                if (v[i].ai>0) v[i].be=v[i].di+(V*V-v[i].vi*v[i].vi)/(2*v[i].ai);v[i].en=L;
            }
        }
        for(int i=1;i<=m;i++){
            cin>>c[i];
        }
        sort(c.begin(),c.end());
        long long sum=0;
        x.assign(n+1,vector<long long>(m+1,0));
        for(int i=1;i<=n;i++){
            bool f=false;
            for(int j=1;j<=m;j++){
                if(v[i].be==-1) break;
                if(c[j]>=v[i].be&&c[j]<=v[i].en){
                    f=true;
                    x[i][j]=1;
                    x[i][0]++;
                    x[0][j]++;
                    //cout<<i<<endl;
                }
            }
            if(f) sum++;
        }
        long long sus=0,u=1;
        for(int i=1;i<=m;i++){
            bool f=false;
            for(int j=1;j<=n;j++){
                if(x[i][j]==0) continue;
                if(x[i][0]-u<=0){
                    f=true;
                    break;
                }
            }
            if(!f) {sus++;u++;}
        }
        cout<<sum<<" "<<sus <<endl;
    }
    return 0;
}