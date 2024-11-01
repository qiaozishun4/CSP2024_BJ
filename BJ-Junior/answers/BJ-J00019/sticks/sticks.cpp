#include<bits/stdc++.h>
#include<string>
#include<algorithm>

using namespace std;

int main(){
    int t;
    cin>>t;
    vector<int>v(t,0);
    for(int i=0;i<t;++i){
        cin>>v[i];
    }
    for(auto n:v){
        if(n%7==0){
            for(int i=1;i<=n/7;++i){
                cout<<8;
            }
        }else if(n%7==1 && n!=1){
            for(int i=1;i<=n/7-1;++i){
                cout<<8;
            }
            cout<<9;
        }else{
            vector<int>v={0,1,2,3,4,5,6,7,8,9};
            vector<int>w={0,2,5,5,4,5,6,3,7,6};
            vector<string>dp(n+1,"");
            for(int i=0;i<=9;++i){
                for(int j=w[i];j<=n;++j){
                    string a=to_string(dp[j-w[i]]);
                    string b=to_string(v[i]);
                    string s=a+b;
                    sort(s.begin(),s.end());
                    if(dp[j]==""){
                        dp[j]=s
                    }
                    if(s[0]=='0'){
                        int ind=s.find_first_not_of('0')
                        string ns=s[ind]+s.substr(0,ind)+s.substr(ind+1);
                        dp[j]=min(ns,dp[j]);
                    }else{
                        dp[j]=min(s,dp[j]);
                    }

                }
            }
            if(dp[n]==""){
                cout<<-1;
            }else{
                cout<<dp[n];
            }

        }
        cout<<endl;
    }
}
