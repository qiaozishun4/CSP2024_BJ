#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5;
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
    int n,m,L,V;
    cin>>n>>m>>L>>V;
    int d[N],v[N],a[N],p[N];
    for(int i=1;i<=n;i++) cin>>d[i]>>v[i]>>a[i];
    for(int i=1;i<=m;i++) cin>>p[i];
    int s=n;
    for(int i=1;i<=n;i++){
        int speed=0;
        for(int j=d[i];j<=L;j+=speed){
            speed+=a[i];
            if(speed>=V){
                s--;
            }
        }
    }
    cout<<s<<' '<<n-1<<endl;
    }
    return 0;
}
