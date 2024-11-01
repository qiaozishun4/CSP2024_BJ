#include <bits/stdc++.h>
#define int int64_t
using namespace std;
struct cars{
    int d;
    int v;
    int a;
    int when_begin;
    int when_end;
};
bool cmp(cars x,cars y){return x.when_begin<y.when_begin;}
int32_t main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int T;
    cin >> T;
    while(T--){
        int n,m,L,V;
        cin >> n >> m >> L >> V;
        vector<cars> car(n+1);
        int Vsqrt=V*V;
        for(int i=0;i<n;i++){
            cin >> car[i].d >> car[i].v >> car[i].a;
            if(car[i].a>0){
                car[i].when_begin=car[i].d+(Vsqrt-car[i].v*car[i].v)/(2*car[i].a);
                car[i].when_end=L;
            }
            else if(car[i].a<0){
                car[i].when_begin=car[i].d;
                car[i].when_end=car[i].d+(Vsqrt-car[i].v*car[i].v)/(2*car[i].a);
            }
            else{
                if(car[i].v>V){
                    car[i].when_begin=car[i].d;
                    car[i].when_end=L;
                }
                else{
                    car[i].when_begin=-1;
                    car[i].when_end=-1;
                }
            }
        }
        vector<pair<int,int>> p(L+1);
        for(int i=0;i<L+1;i++){
            p[i]={0,0};
        }
        int lastet=-1;
        for(int i=0;i<m;i++){
            int input;
            cin >> input;
            p[input].first++;
            lastet=max(lastet,input);
        }
        int ans=0;
        vector<cars> b;
        for(int i=0;i<n;i++){
            if(car[i].when_end==-1&&car[i].when_begin==-1){
                continue;
            }
            if(car[i].when_end==L){
                if(car[i].when_begin<=lastet){
                    ans++;
                    b.push_back(car[i]);
                }
            }
            else{
                for(int j=car[i].when_begin;j<=car[i].when_end;j++){
                    if(p[j].first!=0){
                        ans++;
                        b.push_back(car[i]);
                        break;
                    }
                }
            }
        }
        sort(b.begin(),b.end(),cmp);
        int detecters=1;
        for(int i=0;i<b.size()-1;i++){
            if(b[i].when_end>=b[i+1].when_begin){
                b[i].when_begin=b[i+1].when_begin;
                detecters++;
            }
        }
        cout << ans << " " << m-detecters << endl;
    }
    return 0;
}
