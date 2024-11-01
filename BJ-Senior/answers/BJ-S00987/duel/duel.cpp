#include <bits/stdc++.h>
using namespace std;
struct monster{
    int r;
    bool at;
    bool lv;
    int id;
    bool operator<(const monster x)const{
        return r<x.r;
    }
}a[100005];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].r;
        a[i].at=0;
        a[i].lv=1;
        a[i].id=i;
    }
    sort(a+1,a+n+1);
    int p=1,ans=n;
    for(int i=1;i<=n;i++){
        if(a[i].r>a[p].r){
            a[i].at=1;
            a[p].lv=0;
            ans--;
            //cout<<"monster "<<a[i].id<<" killed monster "<<a[p].id<<".\n";
        }
        while(a[p].lv==0||a[p].at==1)p++;
    }
    for(int i=1;i<=n;i++){
        if(a[i].at==0&&a[i].lv==1&&a[i+1].r!=a[i].r&&a[i-1].r!=a[i].r){
            ans--;
        }
    }
    cout<<ans;
    return 0;
}