#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
int T;
int n,m,L,V,ans1,ans2;
struct Type{
    int d,v,a;
}car[100005];
struct BQJ{
    int st,ed;
};
BQJ qjs[100005];
int lqjs;
BQJ qjs2[100005];
int lqjs2;
int p[100005];
const int inf=0x3f3f3f3f;
bool cmp(BQJ a,BQJ b) {
    if (a.st!=b.st) return a.st<b.st;
    return a.ed<b.ed;
}
int main() {
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>T;
    while (T--) {
        ans1=0;ans2=0;lqjs=0;lqjs2=0;
        cin>>n>>m>>L>>V;
        for (int i=1; i<=n;i++) {
            cin>>car[i].d>>car[i].v>>car[i].a;
            if (car[i].a>0) {
                if (car[i].v>V) qjs[lqjs++]=(BQJ) {car[i].d,inf};
                else if (car[i].v==V) qjs[lqjs++]=(BQJ) {car[i].d+1,inf};
                else if (car[i].v<V) {
                    int derta=V*V-car[i].v*car[i].v;
                    int x=derta/(2*car[i].a)+1;
                    qjs[lqjs++]=(BQJ) {car[i].d+x,inf};
                }
            }
            if (car[i].a==0) {
                if (car[i].v>V) qjs[lqjs++]=(BQJ) {car[i].d,inf};
            }
            if (car[i].a<0) {
                if (car[i].v>V) {
                    int derta=V*V-car[i].v*car[i].v;
                    int x=derta/(2*car[i].a);
                    if (x*2*car[i].a==derta) x--;
                    qjs[lqjs++]=(BQJ) {car[i].d,car[i].d+x};
                }
            }
        }
        //for (int i=0;i<lqjs;i++) cout<<qjs[i].st<<' '<<qjs[i].ed<<endl;
        for (int i=1; i<=m;i++)
            cin>>p[i];
        for (int i=0;i<lqjs;i++) {
            int self=-1;
            for (int j=1; j<=m; j++) {
                //cout<<(qjs[i].st<=p[j]&&qjs[i].ed>=p[j]);
                if (qjs[i].st<=p[j]&&qjs[i].ed>=p[j]) {
                    if (self==-1) {
                        self=lqjs2++;
                        qjs2[self].st=j;
                        ans1++;
                    }
                    qjs2[self].ed=j;
                }
            }
            //cout<<endl;
        }
        cout<<ans1<<' ';
        sort(qjs2,qjs2+lqjs2,cmp);
        //for (int i=0;i<lqjs2;i++) {
        //    cout<<qjs2[i].st<<' '<<qjs2[i].ed<<endl;
        //}
        int endnow=-1;
        for (int i=0;i<lqjs2;i++) {
            if (qjs2[i].st>endnow) {
                endnow=qjs2[i].ed;
                ans2++;
            }
            endnow=min(endnow,qjs2[i].ed);
        }
        cout<<m-ans2<<endl;
    }
    return 0;
}
