#include<bits/stdc++.h>
using namespace std;
#define pb emplace_back
typedef long long ll;
int t,n,m,l,V;
int d[100005],v[100005],a[100005],pmax;
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>t;
    while(t--){
        int c1=0;
        cin>>n>>m>>l>>V;
        for(int i=1;i<=n;i++){
            cin>>d[i]>>v[i]>>a[i];
        }
        pmax=0;
        for(int i=1;i<=n;i++){
            int p;
            cin>>p;
            pmax=max(pmax,p);
        }
        for(int i=1;i<=n;i++){
            if(v[i]>V&&d[i]<=pmax)++c1;
        }
        cout<<c1<<" "<<m-1<<endl;
    }
    return 0;
}
