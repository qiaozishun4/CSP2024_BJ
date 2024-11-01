#include<bits/stdc++.h>
using namespace std;
int n,m;
char a[1004][1004];
int cnt[1004]={6,2,5,5,4,5,6,3,7,6};
int t;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int minn=0x7f7f;
        cin>>n;
        if(n<2){
            cout<<-1;
            continue;
        }
        else if(2<=n && n<=13){
            for(int i=1;i<=9;i++){
                for(int j=0;j<=9;j++){
                    if(cnt[i]+cnt[j]==n && minn>10*cnt[i]+cnt[j]){
                        minn=10*cnt[i]+cnt[j];
                    }
                }
            }
            cout<<minn<<endl;
        }
        else{
            for(int i=1;i<=9;i++){
                for(int j=0;j<=9;j++){
                        for(int k=0;k<=9;k++){
                            if(cnt[i]+cnt[j]+cnt[k]==n && minn>100*cnt[i]+10*cnt[j]+cnt[k]){
                                minn=100*cnt[i]+10*cnt[j]+cnt[k];
                            }
                        }
                }
            }
            cout<<minn<<endl;
        }
    }
    return 0;
}
//zhuwomengdui!!!rp++
