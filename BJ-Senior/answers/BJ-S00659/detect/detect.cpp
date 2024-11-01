#include<bits/stdc++.h>
using namespace std;
int T;
int n, m, L, V;
int p[100005];
int haveTest[1000005];
struct Car{
    int d, a, v;
    int l, r;
}c[100005];
struct UseCar{
    int id;
    int l, r;
    int Useful;
}UCar[100005], UCar1[100005];
bool cmp1(UseCar x, UseCar y){
    if(x.r != y.r)
        return x.r < y.r;
    return x.l < y.l;
}
bool cmp2(UseCar x, UseCar y){
    if(x.l != y.l)
        return x.l < y.l;
    return x.r < y.r;
}
int carCnt;
signed main(){
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    cin>>T;
    while(T--){
        cin>>n>>m>>L>>V;
        //memset(haveTest, 0, sizeof(haveTest));
        carCnt = 0;
        for(int i = 1;i <= n;i++){
            cin>>c[i].d>>c[i].v>>c[i].a;
            if(c[i].v > V){
                if(c[i].a >= 0){
                    c[i].l = c[i].d;
                    c[i].r = L;
                }
                else{
                    double d = c[i].d + (1.0 * V * V - 1.0 * c[i].v * c[i].v) / 2 / 1.0 / c[i].a;
                    c[i].l = c[i].d;
                    c[i].r = floor(d);
                    if(d - c[i].r - 1 > -1e-14)
                        c[i].r++;
                    if(abs(c[i].r * 1.0 - d) < 1e-14)
                        c[i].r--;
                    //    cout<<d<<endl;
                    //printf("%.3lf\n", d);
                    c[i].r = min(c[i].r, L);
                }
            }
            if(c[i].v <= V){
                if(c[i].a <= 0){
                    c[i].l = L + 1;
                    c[i].r = L;
                }
                else{
                    double d = c[i].d + (1.0 * V * V - 1.0 * c[i].v * c[i].v) / 2 / 1.0 / c[i].a;
                    c[i].l = ceil(d);
                    c[i].r = L;
                    if(c[i].l - d - 1 > -1e-14)
                        c[i].l--;
                    if(abs(c[i].l * 1.0 - d) < 1e-14)
                        c[i].l++;
                    //cout<<d<<' '<<c[i].l<<' '<<abs(c[i].l - d)<<' ';
                    //cout<<d<<endl;
                    //printf("%.3lf\n", d);
                    c[i].l = max(c[i].l, c[i].d);
                    c[i].l = min(c[i].l, L + 1);
                }
            }
            //cout<<i<<' '<<c[i].l<<' '<<c[i].r<<endl;
        }
        for(int i = 1;i <= m;i++){
            cin>>p[i];
            haveTest[p[i]]++;
        }
        for(int i = 1;i <= L + 2;i++)
            haveTest[i] += haveTest[i - 1];//, cout<<i<<' '<<haveTest[i]<<endl;
        int ans1 = 0, ans2 = 0;
        for(int i = 1;i <= n;i++){
            int k = 0;
            if(c[i].l == 0)
                k = haveTest[c[i].r];
            else
                k = haveTest[c[i].r] - haveTest[c[i].l - 1];
            //cout<<i<<' '<<c[i].l<<' '<<c[i].r<<' '<<haveTest[c[i].r]<<' '<<haveTest[c[i].l - 1]<<endl;
            if(k > 0){
                ans1++;
                carCnt++;
                UCar[carCnt].l = c[i].l, UCar[carCnt].r = c[i].r;
                UCar[carCnt].Useful = 1;
            }
        }
        cout<<ans1<<' ';
        if(ans1 == 0){
            cout<<m<<endl;
            for(int i = 0;i <= L + 2;i++)
                haveTest[i] = 0;
            continue;
        }
        sort(UCar + 1, UCar + carCnt + 1, cmp1);
        for(int i = 1;i <= carCnt;i++){
            UCar1[i].id = i;
            UCar1[i].l = UCar[i].l, UCar1[i].r = UCar[i].r, UCar1[i].Useful = 1;
        }
        sort(UCar1 + 1, UCar1 + carCnt + 1, cmp2);
        int cnt1 = 1, cnt2 = 0;
        /*for(int i = 1;i <= carCnt;i++)
                cout<<i<<' '<<UCar[i].l<<' '<<UCar[i].r<<endl;
        for(int i = 1;i <= carCnt;i++)
                cout<<i<<' '<<UCar1[i].l<<' '<<UCar1[i].r<<' '<<UCar1[i].id<<endl;*/
        p[m + 1] = 1e9;
        for(int i = 1;i <= m;i++){
            if(p[i + 1] <= UCar[cnt1].r)
                continue;
            while(cnt2 < carCnt && UCar1[cnt2 + 1].l <= p[i]){
                cnt2++;
                UCar[UCar1[cnt2].id].Useful = 0;
                //cout<<cnt2<<' '<<UCar1[cnt2].id<<endl;
            }
            while(cnt1 <= carCnt){
                if(UCar[cnt1].Useful != 0)
                    break;
                cnt1++;
            }
            ans2++;
            //cout<<i<<' '<<cnt1<<' '<<cnt2<<endl;
            if(cnt1 > carCnt)
                break;
        }
        cout<<m - ans2<<endl;

        for(int i = 0;i <= L;i++)
                haveTest[i] = 0;
    }
    return 0;
}
