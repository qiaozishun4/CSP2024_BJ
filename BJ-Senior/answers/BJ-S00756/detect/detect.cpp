#include<bits/stdc++.h>
using namespace std;
constexpr int N=1e5+7;
struct car{
    double q,s,f;
    bool v=0;
}a[N];
int y[N];
void s(){
    int n,m,l,v;
    cin>>n>>m>>l>>v;int sum=0;
    for(int i=1;i<=n;i++){
        cin>>a[i].q>>a[i].s>>a[i].f;
        if(a[i].f==0){
            if(a[i].s>v){
                a[i].v=1;
                sum++;
            }
        }

    }
    if(sum==n){
            int ans=0;
        for(int i=1;i<=n;i++){
            if(a[i].v==1)ans++;
        }
        cout<<ans<<' '<<n-1;
    return;
    }

}
int main(){
    freopen("detect.in","w",stdin);
    freopen("detect.out","r",stdout);
    int _;
    cin>>_;
    while(_--){}
    s();
    return 0;
}
