#include<bits/stdc++.h>
using namespace std;
int t,n,m,l,v,sp[100005],ad[100005],lc[100005],pc[100005],cnt1;
int get_bit(int ag){
    int lp=0;
    while(ag>0){
        lp++;
        res[40-lp]=ag%2;
        ag=ag/2;
    }
    return lp;
}
void read(int o){
    for(int i=40-o;i<=40-1;i++){
        ans[i-39+o]=res[i];
    }
}
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n>>m>>l>>v;
        for(int i=1;i<=n;i++){
            cin>>sp[i]>>ad[i]>>lc[i];
        }
        for(int i=1;i<=m;i++){
            cin>>pc[i];
        }
        sort(pc+1,pc+1+n);
        for(int i=1;i<=n;i++){
            long long g=(sp+ad*(pc-lc));
            if(g>v){
                cnt1++;
            }
        
        }
        cout<<cnt1<<" "<<8;
        
    }
return 0;
    
}
