#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int a[100005],t[100005],p[100005];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n,v;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    v=0;
    for(int i=1;i<=n;i++){
        if(t[a[i]]==0){
            t[a[i]]++;
            a[i]=++v;
            p[a[i]]++;
        }
        else{
            t[a[i]]++;
            a[i]=v;
            p[a[i]]++;
        }
    }
    if(v==1){
        cout<<n;
        return 0;
    }
    int Ans1=n,tmpp;
    tmpp=p[1];
    for(int i=2;i<=v;i++){
        if(  p[i]>=tmpp   ){
            Ans1-=tmpp;
            tmpp=p[i];
        }
        else{
            Ans1-=p[i];
        }
    }
    cout<<Ans1;
    return 0;
}
