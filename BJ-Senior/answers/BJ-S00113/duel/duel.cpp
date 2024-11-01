#include<bits/stdc++.h>
using namespace std;
int n,r[100002],k;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>r[i];
    }
    sort(r+1,r+1+n);
    k=1;
    for(int i=1;i<=n;i++){
        if(r[i]>r[k]) k++;
    }
    cout<<n-k+1;
    return 0;
}
