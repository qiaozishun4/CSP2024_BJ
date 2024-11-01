#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

struct car{
    long long d,v,a;
};

struct edge{
    int v,w;
};

int T;
long long n,m,L,V;
car cars[100010];
int detector[100010];
int sumdet[1000010];
int sum;
int in[100010],dp[100010];

int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    ios::sync_with_stdio(false);
    cin >> T;
    while (T--){
        vector<edge> G[100010];
        queue<int> que;
        sum = 0;
        memset(in,0,sizeof(in));
        memset(sumdet,0,sizeof(sumdet));
        memset(dp,0,sizeof(dp));
        cin >> n >> m >> L >> V;
        for (int i = 1;i <= n;i++){
            cin >> cars[i].d >> cars[i].v >> cars[i].a;
        }
        for (int i = 1;i <= m;i++){
            cin >> detector[i];
            sumdet[detector[i]] = 1;
        }
        for (int i = 1;i <= 1000000;i++){
            sumdet[i] += sumdet[i-1];
        }
        for (int i = 1;i <= n;i++){
            int left = 0,right = 0; // detect place x: L <= x <= R;
            if (cars[i].a == 0){
                if (cars[i].v <= V) left = L+1;
                else left = cars[i].d;
                right = L;
            }else if (cars[i].a > 0){
                if (cars[i].v > V) {
                    left = cars[i].d;
                    right = L;
                }else{
                    left = cars[i].d + floor(double(V*V - cars[i].v*cars[i].v)/(2*cars[i].a)) + 1;
                    right = L;
                }
            }else{
                if (cars[i].v > V){
                    left = cars[i].d;
                    right = cars[i].d + ceil(double(V*V - cars[i].v*cars[i].v)/(2*cars[i].a)) - 1;
                }else{
                    left = L+1;
                    right = L;
                }
            }
            if (left <= right && sumdet[right] > sumdet[left-1]){
                sum++;
                int checkl,checkr;
                if (sumdet[left] > sumdet[left-1]) checkl = sumdet[left];
                else checkl = sumdet[left]+1;
                checkr = sumdet[right];
                G[checkl-1].push_back({checkr,1});
                in[checkr]++;
            }
        }
        for (int i = 1;i <= m;i++){
            G[i-1].push_back({i,0});
            in[i-1]++;
        }
        que.push(0);
        while (!que.empty()){
            int top = que.front();
            que.pop();
            for (int i = 0;i < G[top].size();i++){
                edge e = G[top][i];
                in[e.v]--;
                dp[e.v] = max(dp[e.v],dp[top] + e.w);
                if (in[e.v] == 0) que.push(e.v);
            }
        }
        cout << sum << " " << m - dp[m] << endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
