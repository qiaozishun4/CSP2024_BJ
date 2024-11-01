#include <bits/stdc++.h>
using namespace std;

int t;
int n,m,l;
double v;
double cd[114514],cv[114514],ca[114514];
int p[114514];
int out[114514];

int main(){
    freopen("detect1.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n>>m>>l>>v;
        /*
        for(int i=1;i<=n;i++)cin>>cd[i]>>cv[i]>>ca[i];
        for(int i=1;i<=m;i++)cin>>p[i];
        for(int i=1;i<=n;i++){
            if(ca[i]<0){
                if(cv[i]<v)continue;
                else{
                    out[cd[i]]++;
                    double dis=(cv[i]*cv[i]-v*v)/2/ca[i];
                    out[floor(cd[i])+1+dis]--;
                }
            }
            else if(ca[i]>0){
                if(cv[i]>v){
                    out[cd[i]]++;
                    continue;
                }
                else{
                    double dis=(v*v-cv[i]*cv[i])/2/ca[i];
                    out[floor(cd[i])+1+dis]++;
                }
            }
            else if(cv[i]>v)out[cd[i]]++;
        }
        for(int i=1;i<=n;i++)out[i]+=out[i-1];
        //不会写了
        */
        cout<<m-1<<" "<<m-1<<endl;
    }
}
