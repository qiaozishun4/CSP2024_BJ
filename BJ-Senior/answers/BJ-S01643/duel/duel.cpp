#include<bits/stdc++.h>
using namespace std;
int n,r[100001],ans,c[100001],d[100001],mn=999999,mx;
long a;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    scanf("%d",&n);
    ans=n;
    for(int i=1;i<=n;i++){
        scanf("%d",&r[i]);
        a+=r[i];
        c[r[i]]++;
        mn=min(mn,r[i]);
        mx=max(mx,r[i]);
    }for(int i=1;i<=100001;i++){
        d[i]=d[i-1];
        if(c[i]){
            d[i]+=c[i];
        }
    }for(int i=1;i<=100001;i++){
        int b=(a-1)/n+1;
        int e=max(n/2,d[b])-min(n/2,d[b]);
        int k=0,y=min(n-d[b],d[b]);
        for(int j=b;j<=mx;j++){
            if(c[j]){
                k++;
                a-=c[j];
            }if(k==d[b]){
                ans-=y;
                
                break;
            }
        }k=0;
        for(int j=b;j>=mn;j--){
            if(c[j]){
                k++;
                a-=c[j];
            }if(k==d[b]){
                ans-=y;
                
                break;
            }
        }
    }printf("%d",ans);
}
