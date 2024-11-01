#include<bits/stdc++.h>
using namespace std;
int c[15]={6,2,5,5,4,5,6,3,7,6};long long n,k;
string dp[100100];bool brk=0;
long long T;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
//cout<<"l";

    dp[0]="-1";
    dp[1]="-1";
    dp[2]="1";
    dp[3]="7";
    dp[4]="4";
    dp[5]="2";
    dp[6]="6";
    dp[7]="8";
    for(int i=1;i<=10003;i++){
        if(dp[i][0]!='-'){
           string t=dp[i]+'0';//cout<<t<<" ";
            if(!dp[i+6][0] or t.size()<dp[i+6].size() or(t.size()==dp[i+6].size() and t<dp[i+6]))dp[i+6]=t;
            t=dp[i]+'1';
            if(!dp[i+2][0] or t.size()<dp[i+2].size() or(t.size()==dp[i+2].size() and t<dp[i+2]))dp[i+2]=t;
           t=dp[i]+'2';
           if(!dp[i+5][0] or t.size()<dp[i+5].size() or(t.size()==dp[i+5].size() and t<dp[i+5]))dp[i+5]=t;
           t=dp[i]+'4';
           if(!dp[i+4][0] or t.size()<dp[i+4].size() or(t.size()==dp[i+4].size() and t<dp[i+4]))dp[i+4]=t;
           t=dp[i]+'7';
           if(!dp[i+3][0] or t.size()<dp[i+3].size() or(t.size()==dp[i+3].size() and t<dp[i+3]))dp[i+3]=t;
            t=dp[i]+'8';
            if(!dp[i+7][0] or t.size()<dp[i+7].size() or(t.size()==dp[i+7].size() and t<dp[i+7]))dp[i+7]=t;
        }

    }


     cin>>T;
    for(int i=1;i<=T;i++){
        cin>>n;
        cout<<dp[n]<<endl;

    }


   return 0;


}