#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int t;
struct c{
    int d,v,a,s,f;
    bool Vv;
}arr[maxn];
int p[maxn], res, q[maxn], ans;
map<int, vector<int>> mp;
map<int, vector<int>> mn;
map<int, int> mq[maxn];
void fA(int V, int m, int i, int* p){
    for(int j = 0; j < m; j++){
        double D = arr[i].d * 1.0 + (V * V - arr[i].v * arr[i].v * 1.0) / (2.0 * arr[i].a);
        if((p[j] >= arr[i].d && p[j] < int(D))){
            mp[p[j]].push_back(i);
            mn[i].push_back(p[j]);
        }
    }

    for(int j = 0; j < m; j++){
        double D = arr[i].d * 1.0 + (V * V - arr[i].v * arr[i].v * 1.0) / (2.0 * arr[i].a);
        if((p[j] >= arr[i].d && double(p[j]) < D)){
            res++;
            arr[i].Vv = 0;
            q[i] = 1;
            return;
        }
    }
}
void fB(int V, int m, int i, int* p){
    for(int j = 0; j < m; j++){
        double D = (V * V - arr[i].v * arr[i].v * 1.0) / (2.0 * arr[i].a);
        if(double(p[j]) > D){
            mp[p[j]].push_back(i);
            mn[i].push_back(p[j]);
        }
    }

    for(int j = 0; j < m; j++){
        double D = (V * V - arr[i].v * arr[i].v * 1.0) / (2.0 * arr[i].a);
        if(double(p[j]) > D){
            res++;
            arr[i].Vv = 0;
            q[i] = 1;
            return;
        }
    }
}

void fC(int i){
    res++;
    arr[i].Vv = 0;
    return;
}

int main() {

    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    cin >> t;
    while(t--){
        int n, m, L, V;
        res = 0;
        cin >> n >> m >> L >> V;
        for(int i = 0; i < n; i++){
            cin >> arr[i].d >> arr[i].v >> arr[i].a;
            arr[i].Vv = (arr[i].v > V ? 1 : 0);
            double sq = sqrt(double(arr[i].v * arr[i].v + 2.0 * arr[i].a * (L - arr[i].d)));
            if(sq > double(V))
                arr[i].Vv = 1;
        }
        for(int i = 0; i < m; i++){
            cin >> p[i];
        }
        for(int i = 0; i < n; i++){
            if(arr[i].Vv){
                if(arr[i].a < 0){
                    fA(V, m, i, p);
                }
                else if(arr[i].a > 0){
                    fB(V, m, i, p);
                }
                else{
                    fC(i);
                    q[i] = 1;
                    for(int j = 0; j < m; j++){
                        if(p[j] >= arr[i].d){
                            mp[p[j]].push_back(i);
                            mn[i].push_back(p[j]);
                        }
                    }
                }
            }
        }

        cout << res << endl;
        res = 0;
        int maxi = 0, cnt = 0;
        for(int i = 0; i < n; i++){
            if(mp[p[i]].size() > maxi){
                maxi = mp[p[i]].size(), cnt = p[i];
            }
        }

        for(int i = 0; i < maxi; i++){
            q[mp[cnt][i]] = 0;
        }
        ans++;
        for(int i = 0; i < n; i++){
            if(q[i]){
                res++;
            }
        }

        cout << m -(ans + res) << endl;

    }
    return 0;
}
