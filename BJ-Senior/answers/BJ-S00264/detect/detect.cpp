#include<iostream>
#include<cstdio>

using namespace std;
int T;
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin >> T;
    for(int o=1;o<=T;o++){
        int n,m,L,V;
        int d[101010],a[101010],v[101010],p[101010];
        cin >> n >> m >> L >> V;
        for(int i=1;i<=n;i++){
            cin >> d[i] >> v[i] >>a[i];
        }
        for(int i=1;i<=m;i++){
            cin >> p[i];
        }
        int cnt1=0;
        for(int i=1;i<=n;i++){
            if(v[i]>V){
                for(int j=1;j<=m;j++){
                    if(p[j]>=d[i]){
                        cnt1++;
                        break;
                    }
                }
            }
        }
        if(cnt1==0) cout << cnt1 <<" "<<m<<"\n";
        else cout << cnt1 <<" " <<m-1 <<"\n";
    }
    return 0;
}