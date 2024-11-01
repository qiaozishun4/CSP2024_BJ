#include <bits/stdc++.h>
using namespace std;
long long T,n,m,k,x,y,d,ans;
char mp[1005][1005];
long long ma[1005][1005];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>T;
    for(long long i = 0;i<T;i++){
        ans = 1;
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(long long j = 0;j<n;j++){
            cin>>mp[j];
        }
        long long ma[1005][1005] = {0};
        ma[x-1][y-1]=1;
        //cout<<"initing is ok"<<endl;
        for(long long j = 0;j<k;j++){
            //first:out or in
            if(d == 0){
                if(y+1>m||mp[x-1][y]=='x')d = (d+1)%4;
                else {
                    //move
                    if(ma[x-1][y]!=1){
                        ans+=1;
                        ma[x-1][y]=1;
                    }
                    y++;
                }
            }else if(d==1){
                if(x+1>n||mp[x][y-1]=='x')d = (d+1)%4;
                else {
                    if(ma[x][y-1]!=1){
                        ans+=1;
                        ma[x][y-1]=1;
                    }
                    x++;
                }
            }else if(d == 2){
                if(y-1<1||mp[x-1][y-2]=='x')d = (d+1)%4;
                else {
                    if(ma[x-1][y-2]!=1){
                        ans+=1;
                        ma[x-1][y-2]=1;
                    }
                    y--;
                }
            }else if(d == 3){
                if(x-1<1||mp[x-2][y-1]=='x')d = (d+1)%4;
                else {
                    if(ma[x-2][y-1]!=1){
                        ans+=1;
                        ma[x-2][y-1]=1;
                    }
                    x--;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}