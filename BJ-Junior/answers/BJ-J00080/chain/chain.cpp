#include<bits/stdc++.h>
using namespace std;

const int maxn=1e5+1;
int t,n,k,q,r,c,x,l[maxn];
vector<int> s[maxn],p[maxn];

int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    scanf("%d",&t);
    for(int tt=1;tt<=t;tt++){
        for(int i=1;i<=n;i++) p[i].clear();

        scanf("%d%d%d",&n,&k,&q);
        for(int i=1;i<=n;i++){
            scanf("%d",&l[i]);

            for(int j=1;j<=l[i];j++){
                scanf("%d",&x);
                s[i].push_back(x);
            }
        }

        for(int qq=1;qq<=q;qq++){
            scanf("%d%d",&r,&c);
            for(int i=1;i<=n;i++) p[i].clear();
            for(int i=1;i<=n;i++){
                for(int j=0;j<l[i];j++){
                    int px=0;
                    if(p[i].size()) px=p[i][p[i].size()-1];
                    if(s[i][j]==c){
                        px++;
                    }
                    p[i].push_back(px);
                }
            }
            int ans=0;
            for(int i=1;i<=n;i++){
                for(int j=0;j<l[i];j++){
                    if(s[i][j]==1){
                        if(p[i][min(j+k-1,l[i]-1)]-p[i][j]>=1){
                            ans=1;
                            break;
                        }
                    }
                }
                if(ans) break;
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}
