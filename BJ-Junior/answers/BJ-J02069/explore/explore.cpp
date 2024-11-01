#include<bits/stdc++.h>
using namespace std;
int n,in1,in2;
int xm[5]={1,0,-1,0};
int ym[5]={0,1,0,-1};
int map1[1005][1005];
string s1[10000];
int ans=0;
int in3;
void dfs(int x,int y,int st,int ds,int cx){
    if(st>in3){
        return ;
    }
    if(ds>ans){
        ans=ds;
 //       cout<<x<<" "<<y<<" "<<ans<<endl;

    }
    if(st==in3){
   //     cout<<x<<" "<<y<<" "<<ans<<endl;
        if(ds>ans){
            ans=ds;
        }
        return ;
    }
    else{
        for(int i=cx;i<cx+5;i++){
            if(x+xm[i%4]<=in2&&x+xm[i%4]>0&&y+ym[i%4]<=in1&&y+ym[i%4]>0&&map1[x+xm[i%4]][y+ym[i%4]]!=1&&st+i-cx<in3){
                map1[x+xm[i%4]][y+ym[i%4]]=1;
                int k=ds+1;
 //               cout<<x+xm[i%4]<<" "<<y+ym[i%4]<<" "<<ds+1<<" "<<i%4<<" "<<st+i-cx+1<<endl;
                dfs(x+xm[i%4],y+ym[i%4],st+i-cx+1,k,i%4);
                map1[x+xm[i%4]][y+ym[i%4]]=0;
            }
        }
    }

}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>n;
    while(n--){
        int xn,yn,cx;
        cin>>in1>>in2>>in3>>xn>>yn>>cx;
        for(int i=1;i<=in1;i++){
            cin>>s1[i];
            for(int j=0;j<in2;j++){
                if(s1[i][j]=='.'){
                    map1[j+1][i]=0;

                }
                else{
                    map1[j+1][i]=1;
                }
 //               cout<<map1[j+1][i]<<" ";
            }
 //           cout<<endl;
        }
        dfs(xn,yn,0,1,cx);
        cout<<ans<<endl;
        ans=0;
        memset(map1,0,sizeof(map1));
    }
}