#include<bits/stdc++.h>
using namespace std;
int main(){
    //*
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    //*/
    int vec[1000][1000];
    int T,n,k,q,s,r,c,st[200000],x,y,j,reco[200000],cur=0,lth[10000];
    bool ans;
    cin>>T;
    while(T!=0){
        cin>>n>>k>>q;
        for(int i=0;i<n;i++){
            cin>>lth[i];
            for(int j=0;j<lth[i];j++){
                cin>>s;
                vec[i][cur++]=s;
                st[s]++;
            }
            cur=0;
        }
        for(int i=0;i<q;i++){
            cin>>r>>c;
            if(r==1&&st[c]!=0){
                cout<<1<<endl;
                T--;
                continue;
            }
            else if(r==1&&st[c]==0){
                cout<<0<<endl;
                T--;
                continue;
            }
            if(st[c]==0){
                cout<<0<<endl;
                T--;
                continue;
            }
            if(r>=2){
                for(i=0;i<n;i++){
                    for(j=0;j<lth[i];j++){
                        if(vec[i][j]==c){
                            x=i;
                            y=j;
                            for(int k=y-1;k>=0&&k>=y-k;k--){
                                reco[vec[x][k]]++;
                            }
                            if(reco[vec[x][k]]==st[vec[x][k]]){
                                ans=ans||0;
                            }
                            else{
                                ans=ans||1;
                            }
                            break;
                        }
                    }
                }
                cout<<ans<<endl;
                ans=0;
            }
        }
        T--;
    }
    return 0;
}
