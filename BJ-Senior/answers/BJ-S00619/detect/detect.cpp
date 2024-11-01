#include<bits/stdc++.h>
using namespace std;
int cnt=0;
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int t,n,L,V,T,m,d[100010],v[100010],a[100010],mm[100010];
    long long vv;
    cin>>T;
    for(int i=1;i<=T;i++){
            cnt=0;
        cin>>n>>m>>L>>V;
        for(int p=1;p<=n;p++){
            cin>>d[p]>>v[p]>>a[p];
        }
        for(int p=1;p<=m;p++){
            cin>>mm[p];
        }
        for(int j=1;j<=n;j++){
                if(mm[m]>=d[j]){
            if(v[j]*v[j]+2*a[j]*(mm[m]-d[j])>V*V) cnt++;}

        }
if(cnt!=0)
        cout<<cnt<<" "<<m-1<<endl;
        else cout<<cnt<<" "<<m<<endl;
    }

return 0;
}
