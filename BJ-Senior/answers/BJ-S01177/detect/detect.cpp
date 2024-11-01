#include<bits/stdc++.h>
using namespace std;
int a[100005] , b[100005] , c[100005] , d[100005] , f[100005] , maxn;
bool less_dis(int x , int y , int t , int len){
    double dist = 1.0 * x * t + 0.5 * y * t * t;
    double xxx = 1.0 * len;
    return (dist <= xxx);
}
bool more(int len , int first_speed , int plus_speed , int v){
    double l = 0.0 , r = 1.0 * len + 1.0;
    for(int i = 1;i <= 40;i ++){
        double mid = (l + r) / 2;
        if(less_dis(first_speed , plus_speed , mid , len))l = mid;
        else r = mid;
    }
    return (l > v);
}
void dfs(int q , int n , int m , int v , int have){
    if(q > m){
        int cur = 0 , ne[105] , sum = 0;
        for(int i = 1;i <= m;i ++){
            if(f[i])continue;//don't stay
            else ne[++cur] = d[i];
        }
        for(int i = 1;i <= n;i ++){
            if(c[i] > 0){
                if(more(ne[cur] - a[i] , b[i] , c[i] , v))++sum;
            }
            else if(c[i] < 0){
                int xxx = lower_bound(ne + 1 , ne + cur + 1 , a[i]) - ne;
                if(more(ne[xxx] - a[i] , b[i] , c[i] , v))++sum;
            }
            else if(c[i] == 0){
                if(b[i] > v)++sum;
            }
        }
        if(sum == have)maxn = max(maxn , m - cur);
        return;
    }
    f[q] = 0;
    dfs(q + 1 , n , m , v , have);
    f[q] = 1;
    dfs(q + 1 , n , m , v , have);
}
int main(){

    freopen("detect.in" , "r" , stdin);
    freopen("detect.out" , "w" , stdout);
    int T;
    cin >> T;
    while(T--){
        memset(f , -1 , sizeof(f));
        int n , m , s , v , flag = 1 , flag1 = 1 , flag2 = 1 , maxn = 0;
        cin >> n >> m >> s >> v;
        for(int i = 1;i <= n;i ++){
            cin >> a[i] >> b[i] >> c[i];
            if(c[i] != 0)flag = 0;
            if(c[i] < 0)flag1 = 0;
            if(c[i] > 0)flag2 = 0;
            maxn = max(maxn , a[i]);
        }
        for(int i = 1;i <= m;i ++)cin >> d[i];
        if(flag){
            int sum = 0;
            for(int i = 1;i <= n;i ++){
                if(b[i] > v)++sum;
            }
            cout << sum << " ";
            if(sum == 0)cout << m << "\n";
            else{
                for(int i = 1;i <= m;i ++){
                    if(d[i] >= maxn)cout << m - i << "\n";
                    break;
                }
            }
        }
        else if(flag1){
            int sum = 0;
            for(int i = 1;i <= n;i ++){
                if(more(d[m] - a[i] , b[i] , c[i] , v))++sum;
            }
            cout << sum << " ";
            if(sum == 0)cout << m << "\n";
            else cout << m - 1 << "\n";
        }
        else if(flag2){
            int sum = 0 , maxxxx = 0;
            for(int i = 1;i <= n;i ++){
                int xxx = lower_bound(d + 1 , d + m + 1 , a[i]) - d;
                if(more(d[xxx] - a[i] , b[i] , c[i] , v))++sum;
                maxxxx = max(maxxxx , xxx);
            }
            cout << sum << " ";
            if(sum == 0)cout << m << "\n";
            else{
                int last_can_solve = n , need_to_minus = 0;
                for(int i = maxxxx;i >= 1;){
                    int cnt = 0;
                    for(int j = last_can_solve - 1;j >= 1;j --){
                        if(more(d[i] - a[j] , b[j] , c[j] , v))++cnt;
                    }
                    last_can_solve -= cnt;
                    need_to_minus ++;
                    i = lower_bound(d + 1 , d + m + 1 , a[i]) - d;
                    if(last_can_solve < 1)break;
                }
                cout << need_to_minus << "\n";
            }
        }
        else if(n <= 20 && m <= 20){
            int sum = 0;
            for(int i = 1;i <= n;i ++){
                if(c[i] > 0){
                    if(more(d[m] - a[i] , b[i] , c[i] , v))++sum;
                }
                else if(c[i] < 0){
                    int xxx = lower_bound(d + 1 , d + m + 1 , a[i]) - d;
                    if(more(d[xxx] - a[i] , b[i] , c[i] , v))++sum;
                }
                else if(c[i] == 0){
                    if(b[i] > v)++sum;
                }
            }
            cout << sum << " ";
            maxn = 0;
            dfs(1 , n , m , v , sum);
            cout << maxn << " ";
        }
    }
    return 0;
}