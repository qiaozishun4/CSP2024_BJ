#include <bits/stdc++.h>
using namespace std;
int n,a[100002],x;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x;
        a[x]++;
    }
    int l=0,cnt=n,rcnt=0;
    for(int i=1;i<=100000;i++){
        if(a[i]==0) continue;
        if(l==0){
            l=i;
        }
        else if(a[i]==a[l]){
            cnt-=a[l];
            rcnt-=a[l];
            l=i;
        }
        else if(a[i]<a[l]){
            cnt-=a[i];
            rcnt-=a[i];
            l=i;
        }
        else if(a[i]>a[l]){
            cnt-=min(rcnt,a[i]);
            rcnt-=min(rcnt,a[i]);
            l=i;
        }
        rcnt+=a[i];
    }
    cout<<cnt;
    return 0;
}
