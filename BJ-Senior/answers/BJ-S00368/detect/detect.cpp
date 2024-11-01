#include <bits/stdc++.h>
using namespace std;
int a[100001];
int b[100001];
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        memset(a,0,sizeof a);
        int n,m,l,v,sum=0;
        cin>>n>>m>>l>>v;
        for(int i=1;i<=n;i++){
            int x;
            cin>>a[i]>>b[i]>>x;
        }
        int x;
        for(int i=1;i<=m;i++) cin>>x;
        for(int i=1;i<=n;i++){
            if(a[i]>x) continue;
            if(b[i]>v) sum++;
        }
        if(sum==0) cout<<sum<<" "<<m<<endl;
        else cout<<sum<<" "<<m-1<<endl;
    }
    return 0;
}