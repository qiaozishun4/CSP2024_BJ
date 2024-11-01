#include<bits/stdc++.h>
using namespace std;

const int N=100005;

int n,a[N],cnt,cnt1,ans;

bool cmp(int a,int b){
    return a<=b;
}

int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    scanf("%d",&n);
    ans=n;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    sort(a+1,a+n+1,cmp);
    cnt1=1;
    for(int i=2;i<=n;i++){
        if(a[i]>a[i-1]){
            cnt+=cnt1;
            cnt1=1;
        }
        if(a[i]==a[i-1]){
            cnt1++;
        }
        if(cnt>0){
            cnt--;
            ans--;
        }
    }
    printf("%d",ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
