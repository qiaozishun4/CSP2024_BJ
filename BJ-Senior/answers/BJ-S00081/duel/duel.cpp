#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N=100005;
int n, a[N], t=1, ans=0;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        t++;
        while(a[i]>=a[t]&&t<=n) t++;
        if(t>n) break;
        ans++;
    }
    return printf("%d",n-ans)&0;
}