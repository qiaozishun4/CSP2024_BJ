#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
struct op{
    int d,v,a;
}car[maxn];
struct ccc{
    int l,r;
}tz[maxn];
int n,m,L,vtest,T,test[maxn],ans,ans2,ltest;
bool cmp(ccc x,ccc y){
    if(x.l != y.l)return x.l < y.l;
    return x.r<y.r;
}
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>T;
    while(T--){
        ans = ans2 = 0;
        ltest = 0;
        cin>>n>>m>>L>>vtest;
        for(int i = 1 ; i <= n ; i++)cin>>car[i].d>>car[i].v>>car[i].a;
        for(int i = 1 ; i <= m ; i++){
            cin>>test[i];
        }
        for(int i = 1 ; i <= n ; i++){
            int j = 1;
            while(test[j] < car[i].d)j++;
            for(j;j <= m ; j++){
                int dist = test[j] - car[i].d;
                int v2 = pow(car[i].v,2)+2*car[i].a*dist;
                if(v2 > pow(vtest,2)){
                    ans++;
                    //cout<<i<<endl;
                    tz[++ltest].l = j;
                    if(car[i].a > 0){
                        tz[ltest].r = m;
                        //cout<<tz[ltest].l<<" "<<tz[ltest].r<<endl;
                        break;
                    }
                    else{
                        while(pow(car[i].v,2)+2*car[i].a*(test[j]-car[i].d) > pow(vtest,2) && j <= m)j++;
                        j--;
                        tz[ltest].r = j;
                        //cout<<tz[ltest].l<<" "<<tz[ltest].r<<endl;
                        break;
                    }
                }
            }
        }
        sort(tz+1,tz+1+ltest,cmp);
        //for(int i = 1 ; i <= ltest ; i++)cout<<tz[i].l<<" "<<tz[i].r<<endl;
        int mr = tz[1].r;
        for(int i = 2 ; i <= ltest ; i++){
            if(tz[i].l > mr){
                mr = tz[i].r;
                ans2++;
            }
            mr = min(mr,tz[i].r);
        }
        cout<<ans<<" "<<m-ans2-1<<endl;
    }
    return 0;
}