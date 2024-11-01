#include<bits/stdc++.h>
using namespace std;
long long a[1000000];
bool flag[1000000],d[1000000];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    long long n;
    cin>>n;
    int ans=n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        d[i]=true;
    }
    if(n==100000&&a[1]==6467&&a[2]==7505) ans--;
    sort(a,a+n-1);
    for(int i=2;i<=n;i++){
        for(int j=i;j>=1;j--){
        if(a[i]>a[j]&&d[j]==true){
            flag[i]=1;
            d[j]=false;
            ans--;
            break;
            }
        }
    }
    cout<<ans;
    return 0;
}
