#include <cstdio>
#include <algorithm>
using namespace std;
int n,r[100005],ptr = 1;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    scanf("%d",&n);
    for(int i = 1;i <= n;i++){
        scanf("%d",&r[i]);
    }
    sort(r + 1,r + 1 + n);
    for(int i = 1;i <= n;i++){
        if(r[ptr] < r[i]){
            ptr++;
        }
    }
    printf("%d",n - ptr + 1);
    return 0;
}
