#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 10005;
int gcd(int x,int y){
    if(y == 0) return x;
    return gcd(max(x,y)%min(x,y),min(x,y));
}
int lcm(int x,int y){
    return x / gcd(x,y) * y;
}
struct divide_number{
    int fa,son;
    void yuefen(){
        if(fa < 0){
            fa = -fa;
            son = -son;
        }
        int will_divide = gcd(fa,abs(son));
        fa /= will_divide;
        son /= will_divide;
    }
    void build(int x,int y){
        son = x;
        fa = y;
        yuefen();
    }
    bool operator>(divide_number x){
        return 1.0 * fa / son > 1.0 * x.fa / x.son;
    }
};
int T,n,len,m,V;
int d[maxn],v[maxn],a[maxn],p[maxn];
int l[maxn],r[maxn];
int cnt[maxn];
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    scanf("%d",&T);
    while(T--){
        memset(cnt,0,sizeof(cnt));
        memset(l,0,sizeof(l));
        memset(r,0,sizeof(r));
        scanf("%d%d%d%d",&n,&m,&len,&v);
        for(int i = 1; i <= n; i++){
            scanf("%d%d%d",&d[i],&v[i],&a[i]);
            if(a[i] > 0){
                if(v[i] > V){
                    l[i] = d[i];
                    r[i] = len;
                }else if(v[i] < V){
                    l[i] = min(d[i] + ((V*V - v[i]*v[i]) / 2 / a[i]),len);
                    r[i] = len;
                }
            }else if(a[i] == 0){
                if(v[i] > V){
                    l[i] = d[i];
                    r[i] = len;
                }else{
                    l[i] = r[i] = 0;
                }
            }else{
                if(v[i] <= V){
                    l[i] = r[i] = 0;
                }else{
                    l[i] = d[i];
                    r[i] = min(d[i] + ((V*V - v[i]*v[i]) / 2 / a[i]),len);
                }
            }
        }
        for(int i = 1; i <= m; i++){
            scanf("%d",&p[i]);
        }

        int ans1 = 0,ans2 = 0;
        for(int i = 1; i <= n; i++){
            bool flag = 0;
            for(int j = 1; j <= m; j++){
                if(l[i] <= p[j] && p[j] <= r[i]){
                    flag = 1;
                    if(cnt[j] != 1){
                        ans2++;
                    }
                    cnt[j] = 1;
                    break;
                }
            }
            if(flag){
                ans1++;
            }
        }
        printf("%d",ans1,m-ans2);
    }
    return 0;
}
