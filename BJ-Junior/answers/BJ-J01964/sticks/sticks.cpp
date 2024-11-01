#include<bits/stdc++.h>
using namespace std;
char stick[]={' ',' ','1','7','4','2','6','8'};
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int q;
    cin>>q;
    while(q--){
        int n;
        string ans="";
        cin>>n;
        if(n<2){
            cout<<-1<<endl;
            continue;
        }
        while(n>=7){
            ans+='8';
            n-=7;
        }
        if(n==1){
            string t="1";
            for(int i=0;i<ans.length()-1;++i) t+=ans[i];
            t+='0';
            ans=t;
        }
        else if(stick[n]!=' ') ans=stick[n]+ans;
        for(int i=1;i<=ans.length();++i){
            if(ans[i-1]=='4'&&ans[i]=='8'){
                ans[i-1]='2';
                ans[i]='0';
            }
            if(ans[i-1]=='7'&&ans[i]=='8'){
                ans[i-1]='2';
                ans[i]='2';
            }
        }
        cout<<ans<<endl;

    }
    return 0;
}
