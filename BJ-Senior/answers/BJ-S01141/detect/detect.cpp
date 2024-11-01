#include<bits/stdc++.h>
using namespace std;

double shunshi(int a, double v0, double v1){
    return (v1*v1-v0*v0)/(2*a);
}

double jiasuv(int a, double v0, double t){
    return v0 + a*t;
}

double jiasus(int a, double v0, double t){
    return v0*t + 0.5*a*t*t;
}

struct CARS{
    double d, v0, a, v1, ms, me;
};

struct CNTT{
    int id, cnt = 0;
};

bool cmp(CNTT a, CNTT b){
    return a.cnt > b.cnt;
}

int main(){
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);

    int t;
    cin>>t;
    while(t--){
        double n, m, L, V;
        cin>>n>>m>>L>>V;
        int ansc = 0, ansp = 0;
        CARS c[100005];
        for (int i=0;i<n;i++){
            cin>>c[i].d>>c[i].v0>>c[i].a;
            if (c[i].a == 0){
                c[i].ms = c[i].d;
            }
            //瞬时速度==V时，距离最南端的距离 -> ms;
            if (c[i].a > 0){
                c[i].ms = shunshi(c[i].a, c[i].v0, V) + c[i].d;
                c[i].me = L+1;
            } else {
                c[i].ms = 0;
                double t = ((-1)*c[i].v0) / c[i].a;
                c[i].me = c[i].v0*t + 0.5*c[i].a*t*t + c[i].d;
            }
        }
        double p[100005] = {0}, mp = -1;
        for (int i=0;i<m;i++){
            int x;
            cin>>x;
            p[x] = 1;
            mp = max(mp, p[i]);
        }
        bool flag = false;
        int h = 0;
        vector<CNTT> smy(100005);
        for (int i=0;i<n;i++){
            if (c[i].ms > L) continue;
            for (int j=c[i].ms;j<=c[i].me;j++){
                if (p[j] == 1){
                    smy[j].id = j;
                    smy[j].cnt++;
                    flag = true;
                }
            }
            h++;
            if (flag) ansc++;
            flag = false;
        }
        sort(smy.begin(), smy.end(), cmp);
        set<int> ss;
        int j = 0;
        for (int i=0;i<ansc;i++){
            ss.insert(smy[j].id);
            smy[j].cnt--;
            if (smy[j].cnt == 0) j++;
        }

        cout<<ansc<<' '<<m-ss.size()<<endl;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
