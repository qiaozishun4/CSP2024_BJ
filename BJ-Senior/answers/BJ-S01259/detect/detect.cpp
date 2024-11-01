#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e7+5;
ll t;
ll n,m,l,y;
ll d[N],v[N],a[N],p[N];
int main(){
    //freopen("detect.in","r",stdin);
    //freopen("detect.out","w",stdout);
    cin>>t;
    int sum=0;
    for(int i=1;i<=t;i++){
        cin>>n>>m>>l>>y;
        for(int j=1;j<=n;j++){
            cin>>d[j]>>v[j]>>a[j];
            if(v[i]>=y) sum++;
        }
        for(int k=1;k<=m;k++){
            cin>>p[k];
        }
        cout<<sum-2<<" "<<sum-2;
    }

    return 0;
}
