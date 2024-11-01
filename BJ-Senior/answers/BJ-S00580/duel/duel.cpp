#include<bits/stdc++.h>
using namespace std;
const int N=1e5+2;
int r[N];
int pl[N];
bool cmp(int a,int b){
    return a<b;
}
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;
    cin>>n;
    bool fl=1;
    for(int i=1;i<=n;i++){
        cin>>r[i];
        if(r[i]>2) fl=0; 
    }
    //cout<<"ok"<<endl;
    if(fl==1){
        int one,two;
        for(int i=1;i<=n;i++){
            if(r[i]==1){
                one++;
            }
            else two++;
        }
        if(one<=two){
            cout<<two;
            return 0;
        }
        cout<<two+one-two;
        return 0;
    }
    else{
        int ans=n;
        sort(r+1,r+n+1,cmp);
        r[0]=0;
        pl[0]=0;
        int t=0;
        for(int i=1;i<=n;i++){
            if(r[i]!=r[i-1]){
                t++;
                pl[t]=i;
                //cout<<"t:"<<t<<"i:"<<i<<endl;
                if(t>=2){
                    if(pl[t]-pl[t-1]<pl[t-1]-pl[t-2]){
                        ans=ans-(pl[t]-pl[t-1]);
                        pl[t-1]=pl[t-2]+(pl[t]-pl[t-1]);
                        
                    }
                    else{
                        ans=ans-(pl[t-1]-pl[t-2]);
                    }
                    //cout<<"ans:"<<ans<<endl;
                }
            }
        }
        cout<<ans;
    }
    return 0;
}