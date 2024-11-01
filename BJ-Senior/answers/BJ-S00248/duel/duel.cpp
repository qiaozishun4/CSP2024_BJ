#include<bits/stdc++.h>
using namespace std;
int n,a[100100];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        a[x]++;
    }
    int l=0;
    for(int i=1;i<=100010;i++){
        if(a[i]!=0){
            if(l>=a[i])n-=a[i];
            else n-=l,l=a[i];
        }
    }
    cout<<n;
    return 0;
}
