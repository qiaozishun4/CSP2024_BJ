#include<bits/stdc++.h>
using namespace std;
int n,a[100005],ans,x=1;
bool b[100005];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    ans=n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[i]=1;
    }
    sort(a+1,a+1+n);
    for(int i=2;i<=n;i++){
        if(a[i]>a[x]){
            ans--;
            x++;
        }
    }
    cout<<ans;
    return 0;
}
