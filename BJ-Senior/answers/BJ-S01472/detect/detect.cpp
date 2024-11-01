#include<bits/stdc++.h>
using namespace std;
int t;
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>t;
    while(t--){
        int n,m,l,V,cnt=0,flag=0,mx=0,d[100005],v[100005],a[100005];
        cin>>n>>m>>l>>V;
        for(int i=1;i<=n;i++){
            cin>>d[i]>>v[i]>>a[i];
        }
        for(int i=1;i<=m;i++){
            int x;
            cin>>x;
            mx=max(x,mx);
        }
        for(int i=1;i<=n;i++){
            if(mx>=d[i]&&v[i]>V){
                cnt++;
                flag=1;
            }
        }
        cout<<cnt<<" "<<m-flag<<endl;
    }
    return 0;
}

