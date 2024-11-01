#include<bits/stdc++.h>
using namespace std;
int T,n,m,L,V,ans;
typedef long long ll;
struct pii{
    int le,ri;
};

struct node{
    int l,v,a;
};
ll sq(int x){return x*x;}
int cs(int v1,int a){
    if (a==0) return 0;
    int x=(9-v1*v1)/(2*a);
    return x;
}
bool cmp(pii a,pii b){return a.le<b.le;}


vector<int> ckr;vector<int> tong[1000005];
set<int> y;
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin >> T;
    while(T--){
        y.clear();pii qj[100005];
        node u[100005];int c[100005];
        memset(tong,0,sizeof(tong));
        cin >> n >> m >> L >> V;
        for (int i=1;i<=n;i++){
            cin >> u[i].l >> u[i].v >> u[i].a;
            int le=0,ri=0;
            int l=u[i].l,v=u[i].v,a=u[i].a;
            //cout << l << " " << v << " " << a << endl;
            if (a==0){
                if (v>V) le=l,ri=L;
            }
            else if (a>0){
                if (v<=V){le = l+cs(v,a),ri=L;}
                else le = l,ri=L;
            }
            else if(v>V){
                le=l,ri = l+cs(v,a);
            }
            //cout << le << " " << ri << endl;
            qj[i].le=le,qj[i].ri=ri;
            for (int j=le;j<=ri;j++) tong[j].push_back(i);
        }
        //sort(qj+1,qj+n+1,cmp);
        //for (int i=1;i<=n;i++) cout << qj[i].le << " " << qj[i].ri << endl;
        /*for (int i=1;i<=L;i++){
            for (int j=0;j<tong[i].size();j++) cout << tong[i][j] << " ";
            cout << endl;
        }*/
        //cout << endl;
        for (int i=1;i<=m;i++){
            cin >> c[i];int tmp=y.size();
            for (int j=0;j<tong[c[i]].size();j++){
                ckr.push_back(tong[c[i]][j]);

                y.insert(tong[c[i]][j]);
                //cout << tong[c[i]][j] << " ";
            }
            if (y.size()>tmp) ans++;
            //cout<< endl;
        }
        for (int i=0;i<m;i++)
        int l=0,r=m;
        cout << y.size() << " " << ans << endl;
    }
    return 0;
}