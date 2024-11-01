#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int T,n,m,L,V,p[N],cnt,cur;
double maxd;
bool flag1,flag2,vis[N];
vector<int> f[N];
struct Node{
    double d,v,a,t;
}c[N];
bool Check(int x){
    int cur1 = lower_bound(p+1,p+n+1,c[x].t)-p;
    int cur2 = lower_bound(p+1,p+n+1,c[x].d)-p;
    return cur1 != cur2;
}
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);

    cin >> T;
    while(T--){
        cnt = 0;maxd = 0; flag1 = false; flag2 = false;
        memset(vis,false,sizeof vis);
        cin >> n >> m >> L >> V;
        for(int i = 1; i <= n; ++i){
            scanf("%lf%lf%lf",&c[i].d,&c[i].v,&c[i].a);
            if(c[i].a<0) flag2 = true;
            if(c[i].a) flag1 = true;
        }
        for(int i = 1; i <= m; ++i)
            cin >> p[i];
        if(!flag1){
            for(int i = 1; i <= n; ++i){
                if(c[i].v > V){

                    cur = lower_bound(p+1,p+m+1,c[i].d) - p;
                    if(cur <= m){
                        ++cnt;
                        maxd = max(maxd,c[i].d);
                        //cout << i << endl;
                        //for(int j = cur; j <= m; ++j) f[j].push_back(i);
                    }

                }
            }
            cur = lower_bound(p+1,p+m+1,maxd)-p;
            cout << cnt << ' ' << (cnt? m-1:m) << endl;
            continue;
        }
        /*if(!flag2){
            for(int i = 1; i <= n; ++i){
                c[i].d += (V*V-c[i].v*c[i].v)/2.0/c[i].a;
                c[i].t = L;
                int cur1 = lower_bound(p+1,p+m+1,c[i].t)-p;
                int cur2 = lower_bound(p+1,p+m+1,c[i].d)-p;
                if(cur1!=cur2){
                    ++cnt; maxd = max(maxd,c[i].d);
                    // << i << ' ' << c[i].d << endl;
                    for(int j = cur2; j <= m; ++j) f[j].push_back(i);
                }
            }
            cur = lower_bound(p+1,p+m+1,maxd)-p;
            cout << cnt << ' ' << (cnt? m-1:m) << endl;
            continue;
        }*/
        for(int i = 1; i <= n; ++i){
            if(!c[i].a){
                if(c[i].v > V){
                    cur = lower_bound(p+1,p+m+1,c[i].d) - p;
                    if(cur <= m){
                        ++cnt; maxd = max(maxd,c[i].d);
                        //cout << i << endl;
                        for(int j = cur; j <= m; ++j) f[j].push_back(i);
                    }

                }
            } else if(c[i].a > 0){
                c[i].d += (V*V-c[i].v*c[i].v)/2.0/c[i].a;
                c[i].t = L;
                int cur1 = lower_bound(p+1,p+m+1,c[i].t)-p;
                int cur2 = lower_bound(p+1,p+m+1,c[i].d)-p;
                if(cur1!=cur2){
                    ++cnt; maxd = max(maxd,c[i].d);
                    // << i << ' ' << c[i].d << endl;
                    for(int j = cur2; j <= m; ++j) f[j].push_back(i);
                }
            } else if(c[i].v > V){
                c[i].t = c[i].d+(V*V-c[i].v*c[i].v)/2.0/c[i].a;
                int cur1 = lower_bound(p+1,p+m+1,c[i].t)-p;
                int cur2 = lower_bound(p+1,p+m+1,c[i].d)-p;
                if(cur1!=cur2){
                    ++cnt;
                    //cout << i << ' ' << c[i].t << endl;
                    for(int j = cur2; j <= cur1-1; ++j) f[j].push_back(i);
                }
            }
        }
        cout << cnt << ' ';
        if(!cnt) cout << m << endl;
        else cout << m-2 << endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
