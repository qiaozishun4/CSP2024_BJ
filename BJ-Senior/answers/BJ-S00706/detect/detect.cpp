#include<bits/stdc++.h>
using namespace std;
int d[100005],v[100005],a[100005],p[100005];
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int t,n,m,l,s,ans=0;
    cin>>t;
    for(int q=0;q<t;q++){
        cin>>n>>m>>l>>s;
        for(int x=0;x<n;x++){
            cin>>d[x]>>v[x]>>a[x];
        }
        for(int y=0;y<m;y++){
            cin>>p[y];
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(p[j]>=d[i]&&sqrt(v[i]*v[i]+2*a[i]*(p[j]-d[i]))>s){
                    ans++;
                    break;
                }
            }
        }
        cout<<ans<<" "<<ans;
    }
    return 0;
}
