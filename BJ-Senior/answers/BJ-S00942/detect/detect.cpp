#include<bits/stdc++.h>
using namespace std;
const int N=1e7+5;
int a[N],b[N],c[N],k[N];
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        int n,m,l,v,cnt=0;
        cin>>n>>m>>l>>v;
        for(int i=1;i<=n;i++){
            cin>>a[i]>>b[i]>>c[i];
        }
        for(int i=1;i<=m;i++){
            cin>>k[i];
        }
        for(int i=1;i<=n;i++){
            if(b[i]>v&&a[i]<=k[m])cnt++;
        }
        if(cnt==0)cout<<cnt<<" "<<m<<endl;
        else cout<<cnt<<" "<<m-1<<endl;
    }
    return 0;
}
