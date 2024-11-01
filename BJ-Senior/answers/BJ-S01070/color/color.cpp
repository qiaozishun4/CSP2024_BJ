#include<bits/stdc++.h>
using namespace std;
int lowbit(int x){
    return x&-x;
}
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        vector<int>s(n);
        for(int i=0;i<n;i++)cin>>s[i];
        int zt=1<<n-1,mxret=0;
        for(int mask=0;mask<zt;mask++){
            int ret=0;
            int redmask=mask;
            int bluemask=!mask;
            for(int j=0;j<n;j++){
                if(redmask&1){
                    int x=s[j];
                    redmask--;
                    int tmp=lowbit(redmask);
                    int wei=0;
                    while(tmp){
                        tmp>>=1;
                        wei++;
                    }
                    int y=s[j+wei];
                    if(x==y&&j!=j+wei){
                        ret+=x;
                        // cout<<x<<endl;
                    }
                }
                else{
                    int x=s[j];
                    bluemask--;
                    int tmp=lowbit(bluemask);
                    int wei=0;
                    while(tmp){
                        tmp>>=1;
                        wei++;
                    }
                    int y=s[j+wei];
                    if(x==y&&j!=j+wei){
                        ret+=x;
                        // cout<<x<<endl;
                    }
                }
                bluemask>>=1;
                redmask>>=1;
            }
            // cout<<"tmp"<<ret<<endl;
            mxret=max(ret,mxret);
        }
        cout<<mxret<<endl;
    }
    return 0;
}
//rp++++++++++ gao 20 pts