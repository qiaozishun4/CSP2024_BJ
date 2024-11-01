#include <bits/stdc++.h>
using namespace std;
int t;
int n,m,l,v;
struct car{
    int d;
    int v,a;
    double point;
    double time;
};
car c[100005];
int machine[100005];
struct jiankong{
    int ll,rr;
};
jiankong jk[100005];
int ans1,ans2,now;
bool cmp(jiankong x,jiankong y){
    if(x.ll == y.ll){
        return x.rr < y.rr;
    }
    return x.ll < y.ll;
}
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin >> t;
    while(t--){
        scanf("%d %d %d %d",&n,&m,&l,&v);
        for(int i = 0;i<n;i++){
            scanf("%d %d %d",&c[i].d,&c[i].v,&c[i].a);
            if(c[i].v > v){
                if(c[i].a >= 0){
                    c[i].time = 0;
                    c[i].point = c[i].d;
                }else{
                    c[i].time = (v - c[i].v)/(double)c[i].a;
                    c[i].point = c[i].v * c[i].time + 0.5*c[i].a*pow(c[i].time,2) + c[i].d;
                }
            }else{
                if(c[i].a <= 0){
                    c[i].time = -1;
                    c[i].point = -1;
                }else{
                    c[i].time = (v - c[i].v)/(double)c[i].a;
                    c[i].point = c[i].v * c[i].time + 0.5*c[i].a*pow(c[i].time,2) + c[i].d;
                }
            }
        }
        for(int i = 0;i<m;i++){
            scanf("%d",&machine[i]);
        }
        double left,right,nowl = 0,nowr = 0;int minn = 99999999,maxx = -100,k = 0;
        bool t = 0;
        ans1 = 0,ans2 = 1;
        for(int i = 0;i<n;i++){
            if(c[i].a == 0){
                if(c[i].v > v){
                    left = c[i].d,right = l;
                }else{
                    left = c[i].d,right = -1;
                }
            }else if(c[i].a > 0){
                if(c[i].v > v){
                    left = c[i].d,right = l;
                }else{
                    left = c[i].point,right = l;
                }
            }else{
                if(c[i].v > v){
                    left = c[i].d,right = c[i].point;
                }else{
                    left = c[i].d,right = -1;
                }
            }
            t = 0;
            for(int j = 0;j<m;j++){
                if(machine[j] >= left&&machine[j] <= right){
                    if(t == 0){
                        minn = j;
                    }
                    t = 1;
                    maxx = j;
                }
                if(machine[j] > right)break;
            }
            if(t)ans1++;
            jk[k].ll = minn,jk[k++].rr = maxx;
        }
        cout<<ans1<<' ';
        sort(jk,jk+k,cmp);
        nowr = jk[0].rr;
        for(int i = 1;i<k;i++){
            if(jk[i].ll == 99999999&&jk[i].rr == -100)continue;
            if(jk[i].ll > nowr){
                nowr = jk[i].rr;
                ans2++;
            }
            if(jk[i].rr < nowr){
                nowr = jk[i].rr;
            }
        }
        cout<<m - ans2<<endl;
    }
    return 0;
}
