#include<bits/stdc++.h>
using namespace std;
int nums[10]={6,2,5,5,4,5,6,3,7,6};
int pn[]={0,1,2,4,6,7,8};
int n,t,ans[50005];
long long finans=LONG_MAX;
long long change(int a[]){
    long long res=0;
    for(int i=0;a[i]!=-1;i++){
        res=res*10+a[i];
    }
    return res;
}
void calc (int pren,int m){
    if(m==0){
        for(int i=1;i<7;i++){
            ans[m]=pn[i];
            if(pren-nums[pn[i]]>0){
                calc(pren-nums[pn[i]],m+1);
            }
            else if(pren-nums[pn[i]]==0){
                int f1=change(ans);
                if(f1<finans)finans=f1;
                //cout<<f1<<endl;
            }
            ans[m]=-1;
        }
    }
    else{
        for(int i=0;i<7;i++){
            ans[m]=pn[i];
            if(pren-nums[pn[i]]>0){
                calc(pren-nums[pn[i]],m+1);
            }
            else if(pren-nums[pn[i]]==0){
                int f1=change(ans);
                if(f1<finans)finans=f1;
                //cout<<f1<<endl;
            }
            ans[m]=-1;
        }
    }
}
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    while(t--){
        finans=INT_MAX;
        for(int i=0;i<50005;i++){
            ans[i]=-1;
        }
        cin>>n;
        if(n%7==0){
            for(int i=0;i<n/7;i++){
                cout<<8;
            }
            cout<<endl;
            continue;
        }
        else if(n%7==1){
            cout<<10;
            for(int i=0;i<(n-1)/7-1;i++){
                cout<<8;
            }
            cout<<endl;
            continue;
        }
        calc(n,0);
        if(finans!=INT_MAX)cout<<finans;
        else cout<<-1;
        cout<<endl;
    }

}
