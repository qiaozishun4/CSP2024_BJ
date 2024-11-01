#include <bits/stdc++.h>
using namespace std;

int T;

struct car{
    int d, v, a, id;
};

struct ce{
    int s;
    bool dels;
    vector<int>wuuu_car;
    int num;
};


bool include(ce x, ce y){
    for(int i = 1;i<=x.num;i++){
            bool flag = 0;
        for(int j = 1;j<=y.num;j++){
            if(x.wuuu_car[i] == y.wuuu_car[j]){
                flag = 1;
                break;
            }
        }
        if(flag == 0) return false;
    }
    return true;
}


int main(){
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    cin>>T;
    while(T--){
        ce ces[100005] = {};
        car cars[100005] = {};
        int n, m, l, v;
        cin>>n>>m>>l>>v;
        for(int i = 1;i<=n;i++){
            cars[i].id = i;
            cin>>cars[i].d>>cars[i].v>>cars[i].a;
        }
        for(int i = 1;i<=m;i++){
            ces[i].dels = 0;
            ces[i].num = 0;
            cin>>ces[i].s;
        }
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=m;j++){

                if(cars[i].v * cars[i].v + 2 * cars[i].a * (ces[j].s - cars[i].d) >= 0 && ces[j].s >= cars[i].d && sqrt(cars[i].v * cars[i].v + 2 * cars[i].a * (ces[j].s - cars[i].d)) > v){
                    ces[j].num++;
                    ces[j].wuuu_car.push_back(cars[i].id);
                }

            }
        }
        int maxn = 0;
        int tong[100005] = {};
        for(int i = 1;i<=m;i++){
            for(int j = 1;j<=ces[i].num;j++){
                if(tong[ces[i].wuuu_car[j]] == 0){
                    maxn++;
                    tong[ces[i].wuuu_car[j]]++;
                }
            }
        }
        cout<<maxn<<' ';
        int cnt = 0;
        for(int i = 1;i<=m;i++){
            for(int j = 1;j<=m;j++){
                if(i != j){
                    if(ces[i].num == 0 && !(ces[i].dels || ces[j].dels) || !(ces[i].dels || ces[j].dels) && include(ces[i], ces[j])){
                        cnt++;
                        ces[i].dels = 1;
                    }
                }
            }
        }
        if(ces[m].num == 0) cnt++;
        cout<<cnt<<'\n';
    }
    return 0;
}
