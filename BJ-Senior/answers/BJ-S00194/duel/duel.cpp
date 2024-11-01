#include<bits/stdc++.h>
using namespace std;
int n,num,cnt,mi;
int a[int(1e5)+100];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    mi=a[1];
    for(int i=1;i<=n;i++){
        if(a[i]>mi){
            cnt+=num;
            num=0;
            mi=a[i];
        }
        if(a[i]==mi)num++;
        if(cnt!=0)cnt--;
    }
    cout<<cnt+num;
    return 0;
}
