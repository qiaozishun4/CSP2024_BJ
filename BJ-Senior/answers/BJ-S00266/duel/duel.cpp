#include<bits/stdc++.h>
using namespace std;
int n,a[100005],h[100005],k[100005];
int sum=0;
int cnt=1;
bool flag=1;
void kill(){
    flag=0;
    for(int j=1;j<n;j++){
        if(a[j]<a[j+cnt]&&h[j]!=0&&k[j+cnt]!=0){
            h[j]=0;
            k[j+cnt]=0;
            flag=1;
            sum++;
        }
    }
}
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        h[i]=1;
        k[i]=1;
    }
    sort(a,a+n+1);
    do{
        kill();
        cnt++;
    }while(flag!=0);
    cout<<(n-sum);
    return 0;
}
