#include<bits/stdc++.h>
using namespace std;
int a[100005],b[100005];
int n,cnt;
void duel(int min,int b){
    if(min){
        return;
    }
    for(int i=min-1;i>=1;i--){
        if(a[i]>a[min] && b[i]!=0){
            min--;
            b--;
            b[i]=0;
            duel(min,b);
            return;
        }
        if(i<=0){
            duel(min-1,b);
        }
    }
}
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    cnt=n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        cin>>b[i];
}
    sort(a,n);
    if(a[1]>a[2]) cnt--;
    cout<<duel(n,cnt);
    return 0;
}
