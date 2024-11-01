#include<bits/stdc++.h>
using namespace std;
struct gs{
    int a,b,c,d;
}r[100000];
bool cmp(gs x,gs y){
    if(x.a!=y.a) return x.a<y.a;
    return x.b<y.b;
}
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int T;
    cin>>T;
    while(T>0){
        T--;
        int n,m,L,V;
        cin>>n>>m>>L>>V;
        int car[n][3];
        for(int i=0;i<n;i++) cin>>car[i][0]>>car[i][1]>>car[i][2];//d v a
        int cs[m];
        for(int i=0;i<m;i++) cin>>cs[i];
        int ov=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(car[i][2]!=0 && car[i][0]<=cs[j]){
                    if(V*V<((cs[j]-car[i][0])*2*car[i][2]+car[i][1]*car[i][1])){
                        ov++;
                        break;
                    }
                }
                else{
                    if(car[i][0]<=cs[j] && car[i][1]>V){
                        ov++;
                        break;
                    }
                }
            }
        }
        cout<<ov<<" "<<1<<endl;
        

    }
    return 0;
}