#include <bits/stdc++.h>
using namespace std;
const int N=100000+10;
struct node{int id,r,hadat,dead;}a[N],tmp[N];
bool cmp(node s1,node s2){
    return s1.r<s2.r;
}
int n;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i].r);
        a[i].id=i;
    }
    int ans=2e9;
    while(1){
        int tot=0;
        for(int i=1;i<=n;i++)
            if(a[i].dead==0) tmp[++tot]=a[i];
        sort(tmp+1,tmp+1+tot,cmp);
        int maxs=tmp[tot].r;
        int flag1=0,flag2=0;
        for(int i=1;i<=tot;i++){
            if(tmp[i].r!=maxs) flag1=1;
            if(tmp[i].hadat==0) flag2=1;
        }
        if(flag2==0 || flag1==0 || ans==tot){
            printf("%d\n",tot);
            break;
        }
        ans=tot;
        int mins=tmp[1].r;
        int semins=2e9;
        int l1=1,r1=tot,l2=1,r2=tot;
        for(int i=1;i<=tot;i++){
            while(tmp[i].r==mins && i<=tot) i++;
            r1=i-1;
            while(i<=tot && tmp[i].hadat==1) i++;
            semins=tmp[i].r;l2=i;
            while(i<=tot && tmp[i].r==semins) i++;
            r2=i-1;
            break;
        }
        int pos=l2;
        for(int i=l1;i<=r1;i++){
            while(tmp[pos].hadat==1 && pos<=r2) pos++;
            if(pos>r2) break;
            a[tmp[pos].id].hadat=1;
            a[tmp[i].id].dead=1;
            tmp[pos].hadat=1;
            tmp[i].dead=1;
            pos++;
        }
    }
    return 0;
}
