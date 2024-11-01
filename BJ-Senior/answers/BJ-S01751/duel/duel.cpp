#include<bits/stdc++.h>
using namespace std;
int n,a[100001],cnt,t[5];
bool out[100001];
void f(){
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(a[i]<a[j]){
                out[i]=1;
                a[j]=-5;
                break;
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(!out[i]) cnt++;
    }
    return;
}
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n<=20000){
        sort(a+1,a+n+1);
        f();
        cout<<cnt;
    }else{
        for(int i=1;i<=n;i++){
            t[a[i]]++;
        }
        int x=max(t[1],t[2]);
        cout<<x;
    }
    return 0;
}
