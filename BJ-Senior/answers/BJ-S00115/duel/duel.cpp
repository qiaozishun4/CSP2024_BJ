#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int n,a[N];
int l=1,r=1,ans=0;
bool vis[N],qwq[N];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++) vis[i]=qwq[i]=false;
    sort(a+1,a+1+n);
    l=1,r=1;
    
    while(l<=r){
        if(l==n||qwq[n]) break;
        while((a[l]==a[r]||qwq[r])&&r<n) r++;
        //printf("%d %d\n",l,r);
        if(a[l]<a[r]){
            vis[l]=qwq[r]=true;
            l++;
        }
        else{
            break;
        }
        
    }
    /*
    for(int i=1;i<=n;i++) printf("%d ",vis[i]);
    puts("");
    for(int i=1;i<=n;i++) printf("%d ",qwq[i]);
    puts("");
    */
    for(int i=1;i<=n;i++) if(vis[i]) ans++;
    printf("%d\n",n-ans);
    return 0;
}