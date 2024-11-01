#include <bits/stdc++.h>
using namespace std;
int main(){
    int times,num,n=0,ans=0,nstart=0,nans,panduan=0;
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>times;
    for(int i=1;i<=times;i++){
        cin>>num;
        n=0,ans=0,nstart=0;
        for(int cishu=0;cishu<100000;cishu++){
            nstart++;
            n=nstart;
            ans=0;
            for(int w=6;w>=0;w--){
                nans=n%10;
                n=n/10;
                if(nans==0){
                    ans=ans+6;
                }
                else if(nans==1){
                    ans=ans+2;
                }
                else if(nans==2){
                    ans=ans+5;
                }
                else if(nans==3){
                    ans=ans+5;
                }
                else if(nans==4){
                    ans=ans+4;
                }
                else if(nans==5){
                    ans=ans+5;
                }
                else if(nans==6){
                    ans=ans+6;
                }
                else if(nans==7){
                    ans=ans+3;
                }
                else if(nans==8){
                    ans=ans+7;
                }
                else if(nans==9){
                    ans=ans+6;
                }
                if(n==0){
                    break;
                }
            }
            if(ans==num){
                cout<<nstart<<endl;
                panduan=1;
                break;
            }
        }
        if(panduan==0){
            cout<<"-1"<<endl;
        }
    }
    return 0;

}
