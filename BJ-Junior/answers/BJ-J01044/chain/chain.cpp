#include <bits/stdc++.h>
using namespace std;
int T,n,k,q,l[100001],r[100001],c[100001],rmax=0,xmax=0,cnt[200001];
vector<int> a[100001];
bool f[101][200001];
struct S{
    int i,j;
};
map<int,vector<S> > pos;
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>T;
    while(T--){
        pos.clear();
        for(int i=1;i<=n;i++){
            a[i].clear();
        }
        cin>>n>>k>>q;
        xmax=0;
        for(int i=1;i<=n;i++){
            cin>>l[i];
            for(int j=1;j<=l[i];j++){
                int x;
                cin>>x;
                cnt[x]++;
                pos[x].push_back((S){i,j});
                a[i].push_back(x);
                if(xmax<x){
                    xmax=x;
                }
            }
        }
        rmax=0;
        for(int i=1;i<=q;i++){
            cin>>r[i]>>c[i];
            if(rmax<r[i]){
                rmax=r[i];
            }
        }
        for(int i=1;i<=rmax;i++){
            for(int j=1;j<=xmax;j++){
                f[i][j]=0;
            }
        }
        for(int i=1;i<=n;i++){
            int m=min(k-1,l[i]-1);
            for(int j=1;j<=m;j++){
                f[1][a[i][j]]=1;
            }
        }
        for(int i=2;i<=rmax;i++){
            for(int j=1;j<=xmax;j++){
                if(!cnt[j]){
                    continue;
                }
                bool flag=0;
                for(int z=0;z<cnt[j];z++){
                    int x=pos[j][z].i,y=pos[j][z].j;
                    int m=max(0,y-k+1);
                    for(int d=y-1;d>=m;d--){
                        if(f[i-1][a[x][d]]){
                            flag=1;
                            break;
                        }
                    }
                    if(flag){
                        break;
                    }
                }
                f[i][j]=flag;
            }
        }
        for(int i=1;i<=q;i++){
            cout<<f[r[i]][c[i]]<<endl;
        }
    }
    return 0;
}