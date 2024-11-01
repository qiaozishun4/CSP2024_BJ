#include <iostream>
using namespace std;
const int maxn = 100100;
int r[maxn],num[maxn],n,maxnum = -1111111;
long long ans = 0;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    scanf("%d",&n);
    for(int i = 1; i <= n; i++){
        scanf("%d",&r[i]);
        num[r[i]]++;
        maxnum = max(maxnum,r[i]);
    }
    int killed_on = 1;
    for(int i = 1; i <= maxnum; i++){
        if(num[i] == 0 || i <= killed_on){
            continue;
        }

        int can_kil_other = num[i];
        while(can_kil_other > 0 && killed_on < i){
            int will_died = min(num[killed_on],num[i]);
            //printf("i = %d,willdied = %d\n",i,will_died);
            ans += will_died;
            num[killed_on] -= will_died;
            can_kil_other -= will_died;
            while(num[killed_on] == 0){
                killed_on++;
            }

        }
    }
    printf("%d",n-ans);
    return 0;
}
/*
15
1 2 3 4 5 6
123 123 123 123 123 124
1000 1000 1000

*/
