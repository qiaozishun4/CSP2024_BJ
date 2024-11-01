#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
using namespace std;
const int N=1e5+7;
long long n,a[N],t[N],k=0,tl,tt,ans;
bool b=false;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>tt;
        if(a[tt]==0)t[++k]=tt;
        a[tt]++;
    }
    sort(t+1,t+k+1);
    ans=n;
    for(int i=2;i<=k;i++){
        if(a[t[i]]>a[t[i-1]]){
            ans-=a[t[i-1]];
            int ab=a[t[i]]-a[t[i-1]];
            if(tl>0){
                if(ab>tl){
                    ans-=tl;
                    tl=0;
                }
                else{
                    ans-=ab;
                    tl-=ab;
                }
            }
        }
        else{
            ans-=a[t[i]];
            tl+=a[t[i-1]]-a[t[i]];
        }
    }
    cout<<ans;
    return 0;
}
