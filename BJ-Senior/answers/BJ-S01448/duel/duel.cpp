#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int n,a[N];
bool vis[N];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",a+i);
    int l=1,r=1;
    sort(a+1,a+1+n);
    while(l<=n && l<=r){
        int tl=l;
        while(a[r]<=a[l] || r<l) r++;
        if(r>n) break;
        while(r<=n && a[l]==a[tl]){
            vis[l]=1;
            l++,r++;
        }
        //l++;
    }
    int ans=0;
    for(int i=1;i<=n;i++) ans+=(!vis[i]);
    printf("%d\n",ans);
    return 0;
}
