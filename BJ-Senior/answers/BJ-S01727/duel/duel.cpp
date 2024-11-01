#include<iostream>
#include<algorithm>
using namespace std;
int n,cnt,ans,a[100010];
int tmp[100010],b[100010];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    int tmp1=0,tmp2=0;
    if(a[n]<3){
        int tmp1=0,tmp2=0;
        for(int i=1;i<=n;i++)
            if(a[i]==1)tmp1++;
            else tmp2++;
        if(tmp1<tmp2)printf("%d",tmp2);
        else printf("%d",tmp1);
    }else printf("Byebye,CSP-S!");
    return 0;
}
