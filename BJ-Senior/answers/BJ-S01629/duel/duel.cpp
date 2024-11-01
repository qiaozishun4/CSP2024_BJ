#include<bits/stdc++.h>
using namespace std;
int n,a[100001],sum,sumi,cnt,sum2,ans;
struct point{
    int a,b;
}f[100001];

int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        if(a[i]!=f[cnt].a){
            cnt++,f[cnt].a=a[i],f[cnt].b++;
        }
        else f[cnt].b++;
    }
    for(int i=1;i<=cnt;i++){
        sum=f[i].b,sumi=i-1;
        while(sum>0&&sumi>0)sum2=sum,sum=max(0,sum-f[sumi].b),f[sumi].b-=(sum2-sum),sumi--;
    }
    for(int i=1;i<=cnt;i++)ans+=f[i].b;
    cout<<ans<<endl;
    return 0;
}
