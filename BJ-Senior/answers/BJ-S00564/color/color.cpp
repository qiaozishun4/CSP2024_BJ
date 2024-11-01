#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<fstream>
#include<queue>
#include<cstring>
#include<cstdio>
using namespace std;
int p[2000],a;
bool c[2000];
int check(int n){
    if(n==a){
        c[n]=1;
        int cnt=0,b=0,r=0;
        for(int i=1;i<=a;i++){
            if(c[i]){
                if(p[b]==p[i]) cnt+=p[i];
                b=i;
            }
            if(!c[i]){
                if(p[r]==p[i]) cnt+=p[i];
                r=i;
            }
        }
        c[n]=0;
        int sum=0,b1=0,r1=0;
        for(int i=1;i<=a;i++){
            if(c[i]){
                if(p[b1]==p[i]) sum+=p[i];
                b1=i;
            }
            if(!c[i]){
                if(p[r1]==p[i]) sum+=p[i];
                r1=i;
            }
        }
        return max(cnt,sum);
    }
    c[n]=1;
    int x=check(n+1);
    c[n]=0;
    int y=check(n+1);
    return max(x,y);
}
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        cin>>a;
        for(int i=1;i<=a;i++) cin>>p[i];
        cout<<check(1)<<"\n";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
