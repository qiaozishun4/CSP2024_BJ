#include<bits/stdc++.h>
using namespace std;
int cnt[14][4];
string num="A23456789TJQK";
string hua="DCHS";
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        char a,b;
        cin>>a>>b;
        for(int k=0;k<4;k++){
            for(int j=0;j<13;j++){
                if(a==hua[k]&&b==num[j]) cnt[j][k]=1;
            }
        }
    }
    
    int ans=0;
    for(int i=0;i<4;i++){
        for(int j=0;j<13;j++){
            if(cnt[j][i]!=1) ans++;
        }
    }
   cout<<ans;
    return 0;
}