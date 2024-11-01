#include<bits/stdc++.h>
using namespace std;
int n,ans=0;
bool f[100005];
int a[100005];
struct node{
    int x,q;
}r[100005];
bool cnt(node X,node Y){
    return X.x<Y.x;
}
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>r[i].x;
        a[r[i].x]++;
    }
    sort(r+1,r+n+1,cnt);
    for(int i=1;i<=n;i++){
        if(r[i-1].x<r[i].x){
            r[i].q=r[i-1].x;
        }else{
            r[i].q=r[i-1].q;
        }
    }
    for(int i=2;i<=n;i++){
        if(r[i].x>r[i].q&&r[i].q!=0&&a[r[i].q]!=0){
            a[r[i].q]--;
        }
    }
    for(int i=1;i<=100000;i++){
        ans+=a[i];
    }cout<<ans;
    return 0;
}
