#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
const long double eps = 1e-6;
int T,n,m,totLen,maxV,testPos[N],tot;
struct Car{
    int st,v,a;
}car[N];
vector<int> vec[N];
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>T;
    while(T--){
        cin>>n>>m>>totLen>>maxV;
        for(int i=1;i<=n;i++)
            cin>>car[i].st>>car[i].v>>car[i].a;
        for(int i=1;i<=m;i++)
            cin>>testPos[i],vector<int>().swap(vec[i]);
        sort(testPos+1,testPos+1+m);
        int ans1=0,ans2=0;
        for(int i=1;i<=n;i++)
        {
            int l=0,r=0;
            if (!car[i].a && car[i].v > maxV)
                l = car[i].st, r = totLen;
            else if (!car[i].a && car[i].v <= maxV)
                continue;
            else if (car[i].a > 0 && car[i].v > maxV)
                l = car[i].st, r = totLen;
            else if (car[i].a > 0 && car[i].v <= maxV)
                l = car[i].st + ceil((long double)(maxV * maxV - car[i].v * car[i].v) / 2 / car[i].a + eps), r = totLen;
            else if (car[i].a < 0 && car[i].v > maxV)
                l = car[i].st, r = car[i].st + floor((long double)(maxV * maxV - car[i].v * car[i].v) / 2 / car[i].a - eps);
            else
                continue;
            l = lower_bound(testPos+1,testPos+1+m,l) - testPos;
            r = upper_bound(testPos+1,testPos+1+m,r) - testPos - 1;
            //cout<<i<<' '<<l<<' '<<r<<'\n';
            if (l <= r)
                vec[l].emplace_back(r), ans1++;
        }
        int minR = 1e9;
        for (int i = 1; i <= m; i++) {
            sort(vec[i].begin(), vec[i].end());
            for (int r : vec[i])
                minR = min(minR, r);
            if (minR == i)
                ans2++, minR = 1e9;
        }
        cout << ans1 << ' ' << m - (ans2 + (minR < 1e9)) << '\n';
    }
    return 0;
}
