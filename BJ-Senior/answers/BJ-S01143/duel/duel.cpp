#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,a[N],cnt;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    int k=1;
    while(1){
        if(k>n)break;
        int sxy=lower_bound(a+1,a+n+1,a[k])-a;
        int wqk=upper_bound(a+1,a+n+1,a[k])-a;
        int love=wqk-sxy;
        if(love>cnt)cnt=love;
        k=wqk;
    }
    printf("%d",cnt);
    return 0;
}
