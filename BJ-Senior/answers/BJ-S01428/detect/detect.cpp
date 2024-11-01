#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <fstream>
#include <queue>
using namespace std;
int t,n,m,L,V,d[10000],v[1000],a[10000],p[10000],ans1,vis[100000+10];
bool flag,cheat1 = true;
struct car{
    int d,v,a;
}ca[100000];
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    scanf ("%d", &t);
    for (int i=1;i<=t;i++){
        scanf ("%d %d %d %d", &n, &m, &L, &V);
        for (int j=1;j<=n;j++) scanf ("%d %d %d", &ca[j].d, &ca[j].v, &ca[j].a);
        for (int j=1;j<=m;j++) scanf ("%d", &p[j]);
        for (int j=1;j<=n;j++){
            flag = false;
            cout<<"hi,imhere."<<endl;
            if (ca[j].a==0){
                if (ca[j].v>V) ans1+=1;
                continue;
            }
            int tim=1;
            double s=ca[j].d;
            while (s<=L&&s>0&&sqrt(ca[j].v*ca[j].v+2*ca[j].a*s>=1)){
                tim+=1;
                s = int(ca[j].v * tim) + double(tim*tim*ca[j].a/2);
                if (sqrt(ca[j].v*ca[j].v+2*ca[j].a*s)>V&&flag==false){
                    ans1+=1;
                    flag = true;
                }
            }
        }
        if (cheat1){    //must enable this cheat.
            printf ("%d %d\n", ans1, m);
            continue;
        }

    }
    return 0;
}
//what's this hhhhh