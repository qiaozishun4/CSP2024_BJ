#include<iostream>
#include<algorithm>
using namespace std;
int n,a[1000001],ans=0,cnt=0,num=1;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=2;i<=n;i++){
        if(a[i]==a[i-1]){
            num++;
        }
        if(a[i]!=a[i-1]){
            cnt+=num;
            num=1;
        }
        if(cnt!=0){
            cnt--;
            ans++;
        }
    }
    cout<<n-ans;
    return 0;
}
