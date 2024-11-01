#include<bits/stdc++.h>
using namespace std;
int T;
int n,m;
long double l,v;
long double t[100001],s[100001],p[100001];
vector<long int> pd[100001];
int all[100001];
int ans1,ans2;
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>T;
    while(T--){
        ans1=0,ans2=0;
        cin>>n>>m>>l>>v;
        for(int i=1;i<=n;i++){
            all[i]=0;
            cin>>t[i]>>s[i]>>p[i];
        }
        for(int j=1;j<=m;j++){
            pd[j].clear();
            long double x;
            cin>>x;
            for(int i=1;i<=n;i++){
                if(t[i]<=x&&sqrt(s[i]*s[i]+2*p[i]*(x-t[i]))>v){
                    all[i]++;
                    pd[j].push_back(i);
//                    cout<<"dt:"<<i<<" at"<<j<<endl;
                    if(all[i]==1) ans1++;
                }
            }
        }
//        for(int i=1;i<=n;i++){
//            cout<<"all"<<i<<"="<<all[i]<<endl;
//        }
//        cout<<endl;
        for(int j=1;j<=m;j++){
            for(auto i:pd[j]){
                if(all[i]==1) goto brk;
            }
            ans2++;
            for(auto i:pd[j]){
                all[i]--;
//                cout<<i<<endl;
            }
//            cout<<"kill:"<<j<<endl;
//            for(int i=1;i<=n;i++){
//                cout<<"all"<<i<<"="<<all[i]<<endl;
//            }
//            cout<<endl;
            brk:;
        }
        cout<<ans1<<" "<<ans2<<endl;
    }
    return 0;
}
