#include<bits/stdc++.h>
using namespace std;
#define int long long

int n,m,l,v,k;
int ans1,ans2;
struct aa{
    int l,r;
    bool f;
}a[100005],b[100005];
int pos[100005];
bool cmp(aa x,aa y){
    return x.r < y.r;
}
void sol(){
    cin >> n >> m >> l >> v;
    for(register int i = 1;i <= n;i++){
        a[i].f  = 0;
        int dd,vv,aa;
        cin >> dd >> vv >> aa;
        if(aa == 0 && vv > v){
            a[i].l = dd,a[i].r = l;
            a[i].f = 1;
        }
        if(aa > 0){
            int le = 0,ri = l,an = 1e9;
            while(le <= ri){
                int mid = (le+ri)/2;
                if(vv*vv+2*aa*mid > v*v){
                    ri = mid-1;
                    an = mid;
                }
                else{
                    le = mid+1;
                }
            }
            a[i].f = 1;
            a[i].l = dd+an,a[i].r = l;
        }
        if(aa < 0 && vv > v){
            int le = 0,ri = l,an = 0;
            while(le <= ri){
                int mid = (le+ri)/2;
                if(vv*vv+2*aa*mid > v*v){
                    le = mid+1;
                    an = mid;
                }
                else{
                    ri = mid-1;
                }
            }
            a[i].f = 1;
            a[i].l = dd;
            a[i].r = min(l,dd+an);
        }
    }
    for(register int i = 1;i <= m;i++){
        cin >> pos[i];
    }
    int ma = 0;
    int last = 0;
    sort(a+1,a+1+n,cmp);
    for(register int i = 1;i <= n;i++){
        if(a[i].f){
            int xx = lower_bound(pos+1,pos+1+m,a[i].l)-pos;
            int yy = upper_bound(pos+1,pos+1+m,a[i].r)-pos-1;
            if(xx <= yy){
                ans1++;
            }
            else{
                continue;
            }
            if(a[i].l > ma){
                ma = a[i].l;
                k++;
                b[k].l = xx;
                b[k].r = yy;
                if(xx > last){
                    last = yy;
                    ans2++;
                }
            }
        }
    }
    cout << ans1 << " " << m-ans2;
    cout << endl;
}
signed main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int __;
    cin >> __;
    while(__--){
        ans1 = 0;
        ans2 = 0;
        k = 0;
        sol();
    }
}
