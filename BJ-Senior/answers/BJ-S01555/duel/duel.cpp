#include <iostream>
#include <algorithm>
#include <cstring>
#define N 100001
using namespace std;
int n,a[N],kill[N],killed[N];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    scanf("%d",&n);
    for(int i = 1; i <= n; ++i)
        kill[i] = false, killed[i] = false;
    for(int i = 1; i <= n; ++i)
        scanf("%d",&a[i]);
    sort(a + 1, a + n + 1);//upper sort
    for(int i = 1; i <= n; ++i){
        if(killed[i] == true)
            continue;
        for(int j=i;j<=n;++j){
            if(a[j] > a[i] && killed[j] == false && kill[j] == false) {
                kill[j] = true, killed[i] = true;
                break;
            }
        }
    }
    int ans=0;
    for(int i=1;i<=n;++i)
        if(killed[i]==false){
            ++ans;
        }
    printf("%d\n",ans);
    return 0;
}
