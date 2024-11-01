#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int i1e5=100009;

#define int ll
void test(){
    //输入
    int n,m,bigl,bigv;
    cin>>n>>m>>bigl>>bigv;
    bigv*=bigv;
    int d[i1e5],v[i1e5],a[i1e5];
    for (int i=1;i<=n;i++) cin>>d[i]>>v[i]>>a[i];
    int p[i1e5];
    for (int i=1;i<=m;i++) cin>>p[i];

    // 解决问题
    bool ok[i1e5];
    int cnt=0;
    set<int> so[i1e5];
    memset(ok,1,sizeof(ok));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(p[j]<d[i]) continue;
            if(v[i]*v[i]+2*a[i]*(p[j]-d[i])>bigv){
                ++cnt;
                //ok[j]=false;
                so[j].insert(i);
                break;
                //cout<<"车"<<i<<"车速"<<sqrt(v[i]*v[i]+2*a[i]*(p[j]-d[i]))<<"被"<<j<<"（位置"<<p[j]<<"）检测"<<endl;
            }
        }
    }

    int maxcnt=0;
    for(int k=0;k<1<<m;k++){
        //if(ok[j]){
        //    ++maxcnt;
        //}
        int ccnt=0;
        set<int> nnn;
        for(int j=1;j<=m;j++){
            if(k&(1<<(j-1))){
                ++ccnt;
            } else {
                for (auto &hhh : so[j])
                    nnn.insert(hhh);
            }
        }
        if (nnn.size() == cnt){
            maxcnt=max(maxcnt,ccnt);
        }
    }

    cout<<cnt<<" "<<maxcnt<<endl;
}
#undef int

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("detect.in","r", stdin);
    freopen("detect.out","w", stdout);

    int T;
    cin>>T;
    while (T--) test();

    return 0;
}
