#include<bits/stdc++.h>
using namespace std;
int n,a[100005],b[100005];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int zhi=1;
    for(int i=1;i<=n;i++){
        if(a[i]>a[zhi]&&b[i]!=1){
            a[zhi]=0;
            zhi++;
            b[i]=1;
        }
    }
    int sum=0;
    for(int i=1;i<=n;i++){
        if(a[i]!=0){
            sum++;
        }
    }
    cout<<sum<<"\n";
    return 0;
}
