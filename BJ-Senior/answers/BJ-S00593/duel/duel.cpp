#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+5;
int mp[MAXN][3];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;
    cin>>n;
    int x;
    int num=n;
    int maxnum=0;
    for(int i=1;i<=n;i++){
        cin>>x;
        mp[x][1]++,mp[x][2]++;
        maxnum=max(maxnum,x);
    }
    int l=1,r=2;
    for(l=1;l<=maxnum;l++){
        while(mp[l][1]>0){
            for(r=r;r<=maxnum;r++){
                if(mp[r][2]>=0&&r>l){
                    if(mp[l][1]>=mp[r][2]){
                        mp[l][1]-=mp[r][2];
                        num-=mp[r][2];
                        mp[r][2]=0;
                    }
                    else if(mp[l][1]<mp[r][2]){
                        num-=mp[l][1];
                        mp[r][2]-=mp[l][1];
                        mp[l][1]=0;
                        break;
                    }
                }
            }
            //cout<<l<<" "<<r<<endl;
            if(r>maxnum) break;
        }
        if(r>maxnum) break;
    }
    cout<<num;
    return 0;
}
