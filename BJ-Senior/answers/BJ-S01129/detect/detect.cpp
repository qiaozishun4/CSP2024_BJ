#include<iostream>
#include<cstring>
#include<iomanip>
#include<algorithm>
#include<vector>
#define int long long
using namespace std;

struct car{
    int d,a,v;
    bool isdt,isch = 0;
    int st = 0,ed = 0;
    int stid,edid;
}c[100005];

bool cmp(car a,car b){
    if(a.stid == b.stid){
        return a.edid < b.edid;
    }
    return a.stid < b.stid;
}

int p[100005];

int32_t main(){
    ios::sync_with_stdio(0);
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int t;
    cin >> t;
    while(t--){
        memset(p,0,sizeof(p));
        for(int i = 0; i < 100005; i++){
            c[i] = {0,0,0,0,0,0,0,0};
        }
        int n,m,l,V;
        cin >> n >> m >> l >> V;
        for(int i = 0; i < n; i++){
            cin >> c[i].d >> c[i].v >> c[i].a;
            if(c[i].a > 0){
                if(c[i].v <= V){
                    int s = 1ll*(V*V-c[i].v*c[i].v);
                    c[i].isch = 1;
                    c[i].isdt = 1;
                    c[i].st = c[i].d*(2*c[i].a)+s;
                    c[i].ed = l*(2*c[i].a);
                }
                else{
                    c[i].isdt = 1;
                    c[i].st = c[i].d;
                    c[i].ed = l;
                }
            }
            else if(c[i].a == 0){
                if(c[i].v <= V){
                    c[i].isdt = 0;
                }
                else{
                    c[i].isdt = 1;
                    c[i].st = c[i].d;
                    c[i].ed = l;
                }
            }
            else{
                if(c[i].v <= V){
                    c[i].isdt = 0;
                }
                else{
                    int s = 1ll*(V*V-c[i].v*c[i].v);
                    c[i].isch = 1;
                    c[i].isdt = 1;
                    c[i].st = c[i].d*(2*c[i].a);
                    c[i].ed = c[i].d*(2*c[i].a)+s;
                }
            }
            //cout << c[i].isdt << " " << fixed << setprecision(5) << c[i].st << " " << c[i].ed << endl;
        }
        for(int i = 0; i < m; i++){
            cin >> p[i];
        }


        int ans = 0;
        for(int i = 0; i < n; i++){
            int l = -1,r = m;
            while(l+1<r){
                int mid = (l+r)/2;
                if(p[mid]*((2*c[i].a)*c[i].isch+(!c[i].isch)) > c[i].st){
                    r = mid;
                }
                else{
                    l = mid;
                }
            }
            c[i].stid = l+1;
            l = -1,r = m;
            while(l+1<r){
                int mid = (l+r)/2;
                if(p[mid]*(2*c[i].a)*c[i].isch+(!c[i].isch) > c[i].ed){
                    r = mid;
                }
                else{
                    l = mid;
                }
            }
            c[i].edid = r;
            //cout << c[i].stid << " " << c[i].edid << endl;
            if(c[i].stid < c[i].edid){
                ans++;
            }
        }
        cout << ans << " ";


        sort(c,c+n,cmp);
        int cnt = 0;
        vector<int> lst;
        for(int i = 0; i < n; i++){
            if(c[i].isdt == 0 || c[i].edid == c[i].stid){
                continue;
            }
            //  cout << c[i].stid << " " << c[i].edid << " " << cnt << endl;
            if(!lst.empty() && c[i].stid <= lst[lst.size()-1] && lst[lst.size()-1] < c[i].edid){
                continue;
            }
            else if(!lst.empty() && c[i].edid <= lst[lst.size()-1]){
                while(c[i].edid <= lst[lst.size()-1]){
                    lst.pop_back();
                    cnt--;
                }
                lst.push_back(c[i].edid-1);
                cnt++;
            }
            else{
                cnt++;
                lst.push_back(c[i].edid-1);
            }
        }
        cout << m-cnt << endl;
    }
    return 0;
}
