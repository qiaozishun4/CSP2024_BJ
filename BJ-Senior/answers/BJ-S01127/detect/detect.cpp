#include<bits/stdc++.h>
using namespace std;
struct car{
    int d,v,a;
}c[100005];
struct st{
    int l,r;
    bool operator <(const st _)const{
        return (l != _.l) ? (l > _.l) : (r > _.r);
    }
}tmp[100005];
int V(int v,int a,int s){
    return v * v + 2 * a * s;
}
int n,m,l,v,p[100005],cnt,ans,ans2;
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int t;
    cin >> t;
    while(t--){
        cin >> n >> m >> l >> v;
        //cerr << v << '\n';
        for(int i = 1;i <= n;i++){
            cin >> c[i].d >> c[i].v >> c[i].a;
        }
        for(int i = 1;i <= m;i++){
            cin >> p[i];
            //cerr << p[i] << " ";
        }
        //cerr << '\n';
        ans = ans2 = 0;
        for(int i = 1;i <= n;i++){
            //cerr << c[i].d << " " << c[i].v << " " << c[i].a << '\n';
            int l = 1,r = m;
            while(l < r){
                int mid = (l + r) / 2;
                if(p[mid] >= c[i].d){
                    r = mid;
                }else{
                    l = mid + 1;
                }
            }
            //cerr << l << ' ';
            if(p[l] < c[i].d){
                //cerr << "1\n";
                continue;
            }
            if(c[i].v > v && c[i].a < 0 && V(c[i].v,c[i].a,p[l] - c[i].d) > v * v){
                ans++;
                int l2 = l,r2 = m;
                while(l2 < r2){
                    int mid = (l2 + r2 + 1) / 2;
                    if(V(c[i].v,c[i].a,p[mid] - c[i].d) > v * v){
                        l2 = mid;
                    }else{
                        r2 = mid - 1;
                    }
                }
                tmp[++cnt].l = l;
                tmp[cnt].r = l2;
                //cerr << "2";
            }
            if(c[i].a > 0 && V(c[i].v,c[i].a,p[m] - c[i].d) > v * v){
                ans++;
                int l2 = l,r2 = m;
                while(l2 < r2){
                    int mid = (l2 + r2) / 2;
                    if(V(c[i].v,c[i].a,p[mid] - c[i].d) <= v * v){
                        l2 = mid + 1;
                    }else{
                        r2 = mid;
                    }
                }
                tmp[++cnt].l = l2;
                tmp[cnt].r = m;
                //cerr << "3";
            }
            if(c[i].a == 0 && c[i].v > v){
                ans++;
                tmp[++cnt].l = l;
                tmp[cnt].r = m;
                //cerr << "4";
            }
            //cerr << '\n';
        }
        //cerr << '\n';
        sort(tmp + 1,tmp + cnt + 1);
        int tmp2 = m + 1;
        for(int i = 1;i <= cnt;i++){
            if(tmp[i].r < tmp2){
                ans2++;
                tmp2 = tmp[i].l;
            }
            //cerr << tmp[i].l << " " << tmp[i].r << '\n';
        }
        cout << ans << " " << m - ans2 <<'\n';
        cnt = 0;
    }
    return 0;
}
