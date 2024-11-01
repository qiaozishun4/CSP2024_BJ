#include<bits/stdc++.h>
using namespace std;
const int N=1e5+7;
int n,a[N],cnt[N],id[N],val[N],tot,ans,atk,rem;
bool d[N];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        if(!id[a[i]])id[a[i]]=++tot,val[tot]=a[i],++cnt[tot];
        else ++cnt[id[a[i]]];
    }
    ans=n;
    atk=2,rem=cnt[2];
    for(int i=1;i<=tot;i++){
        if(atk==i)atk++,rem=cnt[atk];
        for(;atk<=tot;){
            if(rem>=cnt[i]){
                rem-=cnt[i],ans-=cnt[i];
                break;
            }
            ++atk;
            if(atk<=tot)rem+=cnt[atk];
        }
        if(atk>tot){
            ans-=rem;
            break;
        }
    }
    printf("%d\n",ans);
    return 0;
}
