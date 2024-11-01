#include<iostream>
#include<algorithm>
using namespace std;
int a[100005];
int c[100005];
bool vis[100005];
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        c[a[i]]++;
    }
    sort(a+1,a+n+1);
    int tmp=0;
    int ans=n;
    for(int i=1;i<=1e5;i++){
        //cout<<ans<<' '<<tmp<<endl;
        if(c[i]){
            ans-=min(tmp,c[i]);
            tmp=max(0,tmp-c[i])+c[i];
        }
    }
    cout<<ans<<endl;
    return 0;
}
