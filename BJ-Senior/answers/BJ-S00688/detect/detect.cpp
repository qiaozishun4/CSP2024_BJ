#include<iostream>
using namespace std;
long long d[100005],u[100005],a[100005],flag[100005];
bool p[100005];
int main(){
    long long T,n,m,l,v,i,dn,cnt,w,sd;
    cin>>T;
    while(T--){
        cin>>n>>m>>l>>v;
        for(i=1;i<=n;i++){
            cin>>d[i]>>u[i]>>a[i];
        }
        for(i=1;i<=m;i++){
            cin>>x;
            p[x]=true;
        }
        dn=0;
        cnt=0;
        for(i=1;i<=n;i++){
            dn++;
            w=d[dn];
            sd=u[dn];
            while(w<=l){
                if(p[w]==1 && sd>v){
                    flag[dn]=p[m];
                    cnt++;
                    break;
                }
                else{
                    w+=sd;
                    sd+=a[dn];
                }
            }
        }
        cout<<cnt<<" "<<n-1;
    }
    return 0;
}