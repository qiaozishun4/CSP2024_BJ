#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
const int N = 1e5 + 10;
int n,m,L,V;
struct Car{
    int d,v,a;
}car[N];
int p[N];
bool st[N];
bool check(int x,int i){
    int s = p[x] - car[i].d;
    if(1ll * car[i].v * car[i].v + 2ll * car[i].a * s > 1ll * V * V){
        return true;
    }
    return false;
}
void solve1(){
    int ans1 = 0;
    for(int i=1;i<=n;i++){
        if(car[i].a == 0){
            if(car[i].v > V){
                ans1++;
                st[i] = true;
            }
        }
        else if(car[i].a > 0){
            if(car[i].d <= p[m]){
                int s = p[m] - car[i].d;
                if(1ll * car[i].v * car[i].v + 2ll * car[i].a * s > 1ll * V * V){
                    ans1++;
                    st[i] = true;
                }
            }
        }
        else{
            int l = 1,r = m;
            while(l < r){
                int mid = l + r >> 1;
                if(p[mid] >= car[i].d) r = mid;
                else l = mid + 1;
            }
            int s = p[l] - car[i].d;
            if(1ll * car[i].v * car[i].v + 2ll * car[i].a * s > 1ll * V * V){
                ans1++;
                st[i] = true;
            }
        }
    }
    printf("%d ",ans1);
}
void solve2(){
    vector<pair<int,int> > v;
     for(int i=1;i<=n;i++){
        if(st[i]){
            int pos = lower_bound(p + 1,p + m + 1,car[i].d) - p;
            if(car[i].a > 0){
                int l = pos,r = m;
                while(l < r){
                    int mid = l + r >> 1;
                    if(check(mid,i)) r = mid;
                    else l = mid + 1;
                }
                // p[l] ~ p[m]
                v.push_back({l,m});
            }
            else if(car[i].a < 0){
                int l = pos,r = m;
                while(l < r){
                    int mid = l + r + 1 >> 1;
                    if(check(mid,i)) l = mid;
                    else r = mid - 1;
                }
                // p[pos] ~ p[l]
                v.push_back({pos,l});
            }
            else{
                v.push_back({pos,m});
            }
        }
    }
    sort(v.begin(),v.end());
    int ans2 = 0;
    int r = v[0].second;
    for(int i=1;i<v.size();i++){
        if(v[i].first > r){
            ans2++;
            r = v[i].second;
        }
    }
    ans2++;
    printf("%d\n",m - ans2);
}
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int T;
    scanf("%d",&T);
    while(T -- ){
        memset(st,0,sizeof(st));
        bool flag0 = true,flag_big = true,flag_small = true;
        scanf("%d %d %d %d",&n,&m,&L,&V);
        for(int i=1;i<=n;i++){
            scanf("%d %d %d",&car[i].d,&car[i].v,&car[i].a);
        }
        for(int i=1;i<=m;i++) scanf("%d",&p[i]);
        if(flag0){
            int cnt = 0;
            for(int i=1;i<=n;i++){
                if(car[i].v > V && car[i].d <= p[m]){
                    cnt++;
                }
            }
            printf("%d ",cnt);
            if(cnt == 0) printf("%d\n",m);
            else printf("%d\n",m-1);
            continue;
        }
        sort(p + 1,p + m + 1);
        for(int i=1;i<=n;i++){
            if(car[i].a != 0){
                flag0 = false;
            }
            if(car[i].a > 0) flag_small = false;
            if(car[i].a < 0) flag_big = false;
        }
        solve1();
        solve2();
    }
    return 0;
}
