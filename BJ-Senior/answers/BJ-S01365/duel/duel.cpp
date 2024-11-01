#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n,maxn=-1;
    cin>>n;
    int a[100005]={},b[100005]={},c[100005]={},d[100005]={};
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[a[i]]++;
        c[a[i]]++;
        maxn=max(maxn,a[i]);
    }
    int tnt=1;
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        if(a[i]!=a[i-1]){
            d[tnt++]=a[i];
        }
    }
    int o=2;
    int cnt=n,flag=1,p;
    for(int i=1;i<=maxn;i++){
        if(flag==1&&b[i]!=0){
            flag=0;
            p=i;
            continue;
        }
        if(flag==0&&b[i]!=0){
            flag=2;
            i--;
            continue;
        }
        if(o-1==tnt){
            break;
        }
        if(b[i]>=b[p]){
            c[i]=c[i]-b[p];
            cnt=cnt-b[p];
            b[p]=0;
            c[p]=0;
            p=d[o++];
            continue;
        }
        if(b[i]<b[p]){
            cnt=cnt-b[i];
            c[i]=0;
            b[p]=b[p]-b[i];
            continue;
        }
    }
    cout<<cnt;
    return 0;
}
