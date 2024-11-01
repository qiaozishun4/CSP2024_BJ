#include<bits/stdc++.h>
using namespace std;
struct node{
    int d,v,a;
}q[100002];
int t,n,m,l,v,p[100002];
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n>>m>>l>>v;
        int cnt=0;
        for(int i=1;i<=n;i++){
            cin>>q[i].d>>q[i].v>>q[i].a;
        }
        for(int i=1;i<=m;i++){
            cin>>p[i];
        }
        sort(p+1,p+1+m);
        int minx=1e9;
        for(int i=1;i<=n;i++){
            if(q[i].v>v&&q[i].d<=p[m]){
                cnt++;
                minx=min(minx,q[i].d);
            }
        }
        if(cnt==0) cout<<cnt<<" "<<m<<endl;
        else cout<<cnt<<" "<<m-1<<endl;
    }
    return 0;
}
