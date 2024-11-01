#include<bits/stdc++.h>
using namespace std;
long long t,n,m,l,v,d[10000],w[100000],a[100000],p[100000];
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n>>m>>l>>v;
        for(int j=0;j<n;j++){
            cin>>d[i]>>w[i]>>a[i];
        }
        for(int j=0;j<m;j++){
           cin>>p[i];
        }
    }
    int cnt=0,ans=0;
    for(int i=0;i<n;i++){
        if(w[i]+abs(a[i])>v){
            cnt++;
        }
    }
    cout<<cnt-2<<" "<<ans<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
