#include <bits/stdc++.h>
using namespace std;
int a[500001],srt[100001];
bool cmp(int a,int b){
    return a<b;
}
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;cin>>n;for(int i=0;i<n;i++)cin>>a[i];
    sort(a,a+n,cmp);int cnt=0;
    srt[0]++;
    for(int i=1;i<n;i++){
        if(a[i]!=a[i-1])cnt++;
        srt[cnt]++;
    }int m=srt[0];
    for(int i=1;i<=cnt;i++){
        if(srt[i]>m)m=srt[i];
    }cout<<m<<endl;
}
