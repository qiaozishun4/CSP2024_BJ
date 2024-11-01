#include<iostream>
#include<algorithm>
using namespace std;
int n,a[100005];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    int s=1,ans=0;
    for(int i=1;i<=n;i++){
        if(a[i]>a[s]){
            ans++;
            s++;
        }
    }
    cout<<n-ans;
    return 0;
}
