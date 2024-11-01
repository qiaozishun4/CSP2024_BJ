#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N],b[N];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n,ans;
    cin>>n;
    ans=n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(a[i]==a[j]) continue;
            if(a[i]<a[j] && !b[j] && a[i]!=0 && a[j]!=0){
                a[i]=0;
                b[j]=1;
                ans--;
            }
        }
    }
    cout<<ans<<endl;
}
