#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct monster{
    ll atk,num;
    ll atkch;
}m[1010101];
ll n,a,dis[1010101],cnt,ans;
bool cmp(monster x,monster y){
    return x.atk<y.atk;
}
int main(){
   freopen("duel.in","r",stdin);
   freopen("duel.out","w",stdout);
   scanf("%lld",&n);
   for(int i=1;i<=n;i++){
        scanf("%lld",&a);
        if(dis[a]==0){
            dis[a]=i;
            m[i].atk=a;
        }else{
            m[dis[a]].num++;
        }
        m[i].num++;
   }
   sort(m+1,m+1+n,cmp);
   ll len=0;
   for(int i=1;i<=n;i++){
        if(m[i].atk!=0){
           len++;
           m[len].num=m[i].num;
           m[len].atk=m[i].atk;
           m[len].atkch=m[i].num;
        }
   }
   for(int i=1;i<=len;i++){
        cnt=1;
        while((i+cnt)<=len&&m[i].num>0&&m[i+cnt].atkch>0){
            if(m[i+cnt].atkch>=m[i].num){
                m[i+cnt].atkch-=m[i].num;
                m[i].num=0;
            }else{
                m[i].num-=m[i+cnt].atkch;
                m[i+cnt].atkch=0;

                cnt++;
            }
        }
   }
    for(int i=1;i<=len;i++){
        ans+=m[i].num;
    }
    printf("%lld",ans);
   fclose(stdin);
   fclose(stdout);
    return 0;
}
