#include<bits/stdc++.h>
using namespace std;
int res[100],ans[100],a[100],n,exs[100][100],get__[100],cnt,anss,t;
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
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        for(int i=1;i<=pow(2,n);i++){
            int u=get_bit(i);
            read(u);
            for(int i=1;i<=n;i++){
                exs[a[i]][++get__[a[i]]]=i;
                if(a[exs[a[i]][get__[a[i]]-1]]==i-1){
                    cnt+=a[i];
                }
            }
            anss=max(cnt,anss);
        }
        cout<<anss<<endl;

    }
    return 0;
}
