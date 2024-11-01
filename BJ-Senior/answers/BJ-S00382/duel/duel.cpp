#include<bits/stdc++.h>
using namespace std;
int n,a[100005],sum=1,cnt=0,ans;
struct lian{
    int f,b,x;
}l[100005];
bool cmp(int x,int y){
    return x<y;
}
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    ans=n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1,cmp);
    for(int i=2;i<=n;i++){
        if(a[i]==a[i-1]) sum++;
        else{
            ++cnt;
            l[cnt].f=cnt-1;
            l[cnt].b=cnt+1;
            l[cnt].x=sum;
            sum=1;
        }
    }
    ++cnt;
    l[cnt].f=cnt-1;
    l[cnt].b=cnt+1;
    l[cnt].x=sum;
    sum=1;
    for(int i=2;i<=cnt;i++){
        if(l[l[i].f].x>=l[i].x){
            ans-=l[i].x;
            if(i==cnt) break;
            l[l[i].f].b=l[i].b;
            l[l[i].b].f=l[i].f;
        }
        else{
            ans-=l[l[i].f].x;
        }
    }
    cout<<ans;
    return 0;
}