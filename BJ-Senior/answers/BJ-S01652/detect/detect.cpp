#include <bits/stdc++.h>

using namespace std;
const long long N=1e5+5;
int T;
int n,m,l,V;//l表示主干道长度 v表示限速
int d,v,a;
int ans;
int cesu[N];
struct note{
    int d;
    int v;
    int a;
}car[N];
int maxce=-1;
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>T;
    for(int s=0;s<T;s++){
        cin>>n>>m>>l>>V;
        for(int i=0;i<n;i++){
            cin>>car[i].d>>car[i].v>>car[i].a;
        }
        for(int i=0;i<m;i++){
            cin>>cesu[i];
            maxce=max(maxce,cesu[i]);
        }
        for(int i=0;i<n;i++){
            if(car[i].d<=maxce&&car[i].v>V){
                ans++;
            }
        }
        cout<<ans<<" "<<m-1<<endl;
    }
    return 0;
}
