#include <iostream>
using namespace std;
int T,n;
int a[10086],cnt[10086];
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i = 1; i <= n; i++){
            scanf("%d",&a[i]);
            cnt[a[i]]++;
        }
        for(int i = 1; i <= n; i++){
            if(cnt[a[i]] <= 1){
                a[i] = -1;
            }
        }

        int ans = 0,x = -1,y = -1;
        for(int i = 1; i <= n; i++){
            if(cnt[a[i]] <= 1 || a[i] == -1){
                continue;
            }
            if(x == a[i] && a[i] != -1){
                ans += a[i];
                cnt[a[i]] -= 2;
                x = -1;
            }else if(y == a[i] && a[i] != -1){
                ans += a[i];
                cnt[a[i]] -= 2;
                y = -1;
            }else if(x == -1){
                x = a[i];
            }else if(x != -1 && y == -1){
                y = a[i];
            }else{
                if(x <= y){
                    x = a[i];
                }else{
                    y = a[i];
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
