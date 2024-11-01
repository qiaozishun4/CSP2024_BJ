#include<bits/stdc++.h>
using namespace std;
int n,num,wei,sumw;
int need[]={6,2,5,5,4,5,6,3,7,6};
string ans;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>n;
    while(n--){
        cin>>num;
        ans="";
        bool flag=0;
        sumw=floor(num/7.0+0.99999999);
        wei=0;
        while(1){
            if(sumw==0)break;
            wei++;
            flag=0;
            if(wei==1){
                for(int i=1;i<=9;i++){
                    if(num-need[i]<=sumw*7-7 && num-need[i]>=sumw*2-2){
                        flag=1;
                        sumw--;
                        num-=need[i];
                        ans+=i+'0';
                        break;
                    }
                }
                if(flag==0){
                    break;
                }
            }else{
                for(int i=0;i<=9;i++){
                    if(num-need[i]<=sumw*7-7 && num-need[i]>=sumw*2-2){
                        flag=1;
                        sumw--;
                        ans+=i+'0';
                        num-=need[i];
                        break;
                    }
                }
            }
        }
        if(flag){
            cout<<ans<<'\n';
        }else{
            cout<<-1<<'\n';
        }
    }
    return 0;
}
