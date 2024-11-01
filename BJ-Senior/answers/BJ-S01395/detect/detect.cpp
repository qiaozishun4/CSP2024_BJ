#include<bits/stdc++.h>
using namespace std;
int di[100010],vi[100010],ai[100010];
int p[100010];
int pp[30];
int n,v;
//int tmp[1000010];
double getv(double v0,double a0,double dx) {
    double tmp2=sqrt(2*a0*dx+v0*v0);
    //cout<<"getv:v0="<<v0<<",a0="<<a0<<",dx="<<dx<<"->v="<<tmp<<'\n';
    return tmp2;
}
set<int>ps;
set<int>pss;
int solve2(int m) {
//    int now=m;
    //p[0]=-1;
    int ans=0;
    for(int i=1; i<=n; i++) {
        auto tmp=pss.lower_bound(di[i]);
        if(tmp==pss.end())continue;
        int tmp2=(*tmp);
        if(ai[i]<0) {//jiansu
            if(getv(vi[i],ai[i],tmp2-di[i])>v) {
                ans++;

                //cout<<i<<' '<<vi[i]<<'\n';
            }
        } else if(ai[i]>0) { //jiasu
            if(getv(vi[i],ai[i],pp[m]-di[i])>v) {
                //cout<<i<<' '<<vi[i]<<'\n';
                ans++;
            }
        } else { //yunsu
            //if(getv(vi[i],ai[i],tmp[di[i]]-di[i])>v) {
            //ans++;
            //if(vi[i]<=v)cout<<"error on"<<i<<'\n';
            //cout<<i<<' '<<vi[i]<<'\n';
            //}
            if(vi[i]>v)ans++;
        }
    }return ans;
}
int main() {

    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--) {
//        memset(tmp,-1,sizeof(tmp));
        ps.clear();
        bool aidydy0=1;
        int m,l;

        cin>>n>>m>>l>>v;//cout<<"vo:"<<v<<'\n';
        for(int i=1; i<=n; i++) {
            cin>>di[i]>>vi[i]>>ai[i];
            if(ai[i]<0)aidydy0=0;
        }
        for(int i=1; i<=m; i++) {
            cin>>p[i];
            ps.insert(p[i]);
        }
        //sub1
//        int now=m;
        p[0]=-1;
        int ans=0;
        for(int i=1; i<=n; i++) {
            auto tmp=ps.lower_bound(di[i]);
            if(tmp==ps.end())continue;
            int tmp2=*tmp;
            if(ai[i]<0) {//jiansu
                if(getv(vi[i],ai[i],tmp2-di[i])>v) {
                    ans++;

                    //cout<<i<<' '<<vi[i]<<'\n';
                }
            } else if(ai[i]>0) { //jiasu
                if(getv(vi[i],ai[i],p[m]-di[i])>v) {
                    //cout<<i<<' '<<vi[i]<<'\n';
                    ans++;
                }
            } else { //yunsu
                //if(getv(vi[i],ai[i],tmp[di[i]]-di[i])>v) {
                //ans++;
                //if(vi[i]<=v)cout<<"error on"<<i<<'\n';
                //cout<<i<<' '<<vi[i]<<'\n';
                //}
                if(vi[i]>v)ans++;
            }
        }
        cout<<ans<<' ';
        //sub2
        //tsA&B:
        if(aidydy0) {
            if(ans)
                cout<<m-1<<'\n';
            else cout<<m-0<<'\n';
            continue;
        } else if(m<=20) {
            int ans2=m;
            //int m2=0;
            for(int j=1; j<=(1<<m); j++) {
                int m2=0;
                pss.clear();
                for(int k=1; k<=m; k++) {
                    if(j&(1<<(k-1))) {
                        m2++;
                        pp[m2]=p[k];
                        pss.insert(pp[m2]);
                    }
                }
                if(solve2(m2)==ans)ans2=min(ans2,m2);
            }
            cout<<m-ans2<<'\n';
        }else{
            cout<<"IDK...\n";
        }
    }
    return 0;
}
