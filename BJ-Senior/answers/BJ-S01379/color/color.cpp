#include<bits/stdc++.h>
using namespace std;
int t;
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    scanf("%d",&t);
    while(t--){
        int n,a[200005];
        int cnt[200005];
        memset(cnt,0,sizeof(cnt));
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            cnt[a[i]]++;
        }
        int c1[200005],c2[200005],t1=0,t2=0;
        c1[0]=0,c2[0]=0;
        for(int i=1;i<=n;i++){
            if(c1[t1]==a[i])
                c1[++t1]=a[i];
            else if(c2[t2]==a[i])
                c2[++t2]=a[i];
            else if(cnt[c1[t1]]&&c1[t1]<=c2[t2]&&cnt[c2[t2]])
                c1[++t1]=a[i];
            else if(cnt[c1[t1]]==0)
                c1[++t1]=a[i];
            else
                c2[++t2]=a[i];
            cnt[a[i]]--;
        }
        int ans=0;
        for(int i=2;i<=t1;i++){
            if(c1[i]==c1[i-1])
                ans+=c1[i];
        }
        for(int i=2;i<=t2;i++){
            if(c2[i]==c2[i-1])
                ans+=c2[i];
        }
        printf("%d\n",ans);
    }
    return 0;
}
