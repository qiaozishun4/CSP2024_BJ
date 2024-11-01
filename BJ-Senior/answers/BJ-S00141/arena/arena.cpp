#include<bits/stdc++.h>
using namespace std;
int T;
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin >> T;
    for(int i=0;i<T;i++){
        int n, m, L, V;
        cin>>n>>m>>L>>V;
        pair<int,int> sec[n];
        int car[n],v[n],a[n],cnt;
        bool flg[n];
        memset(flg,false,n);
        int p[L+1],p1;
        memset(p,0,L+1);
        for(int i = 0;i < n;i ++){
            cin >> car[i] >> v[i] >> a[i];
        }
        for(int i=0;i<m;i++){
            cin>>p1;
            p[p1]=1;
        }
        for(int i =1;i<n;i++){
            p[i]=p[i]+=p[i-1];
        }

        for(int i = 0;i < n;i++){
            int x=floor((V*V-v[i]* v[i])/(2*a[i]));
            if(v[i]>V){
                sec[i].first=car[i];
                sec[i].second=x>0?(x+car[i]):L;
            }
            else{
                sec[i].first=x>0?(car[i]+x):L+1;
                sec[i].second=L+1;
            }
            if(p[sec[i].second]-p[sec[i].first]>0) cnt++;

        }
    }

    return 0;
}
