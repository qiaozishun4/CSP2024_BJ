#include <bits/stdc++.h>
using namespace std;
int t, n, a[200005], cnt = 0, v[200005], ch[200005];
long long ans = 0;
struct nod{
    int x, y, w;
};
vector<nod> e;
int main(){
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    scanf("%d", &t);
    while(t--){
            cnt = 0;
        scanf("%d", &n);
        e.clear();
        memset(ch, 0, sizeof(ch));
        for(int i = 1; i <= n; i++){
            scanf("%d", &a[i]);
        }
        for(int i = 1; i <= n; i++){
            for(int j = i +1; j <= n; j++){
                if(a[i] == a[j]){
                    cnt++;
                    nod tmp;
                    tmp.x = i;
                    tmp.y = j;
                    tmp.w = a[i];
                    e.push_back(tmp);
                    break;
                }
            }
        }
        if(cnt == 0){
            printf("0\n");
            continue;
        }
        if(cnt == 1){
            printf("%d\n", e[0].w);
            continue;
        }
        vector<int> edg[10005];
        for(int i = 0; i < cnt; i++){
            v[i] = 0;
            for(int j = i + 1; j < cnt; j++){
                if(e[i].y > e[j].x + 1){
                    ch[i] = ch[j] = 1;
                    edg[i].push_back(j);
                    edg[j].push_back(i);
                }
            }
        }
        ans = 0;
        for(int i = 0; i < cnt; i++){
            if(ch[i] == 0){
                ans += e[i].w;
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}
