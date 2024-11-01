#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        int n,m,L,V,cnt=0,maxn=-1;
        cin>>n>>m>>L>>V;
        int d[100005]={},v[100005]={},a[100005]={},p[100005]={};
        for(int j=1;j<=n;j++){
            cin>>d[j]>>v[j]>>a[j];
        }
        for(int j=1;j<=m;j++){
            cin>>p[j];
            maxn=max(maxn,p[j]);
        }
        for(int j=1;j<=n;j++){
            if(d[j]>maxn){
                continue;
            }
            if(v[j]>V){
                cnt++;
            }
        }
        if(cnt==0){
            cout<<cnt<<" "<<m<<endl;
            continue;
        }
        cout<<cnt<<" "<<m-1<<endl;
    }
    return 0;
}
