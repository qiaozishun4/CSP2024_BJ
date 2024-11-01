#include <bits/stdc++.h>
using namespace std;

const int N=1e5+10;
int d[N],v[N],a[N],p[N];
bool exc[N],vis[N];
vector<int> exc1[N];

int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n,m,l,ev,ans1=0,ans2=0;
        cin>>n>>m>>l>>ev;
        for(int i=1;i<=n;i++){
            cin>>d[i]>>v[i]>>a[i];
        }
        for(int i=1;i<=m;i++){
            cin>>p[i];
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(p[j]<d[i]) continue;
                double x=v[i]*v[i]+2*a[i]*(p[j]-d[i]);
                if(x<0) continue;
                if(sqrt(x)>ev){
                    exc[i]=1;
                    exc1[j].push_back(i);
                }
            }
        }
        for(int i=1;i<=n;i++){
            ans1+=exc[i];
        }
        cout<<ans1<<" "<<0<<endl;
    }
    return 0;
}
