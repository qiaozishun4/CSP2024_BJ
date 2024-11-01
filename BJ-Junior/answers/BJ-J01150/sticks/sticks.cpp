#include<bits/stdc++.h>
using namespace std;
int s[11]={6,2,5,5,4,5,6,3,7,6};
string ans[11];
bool cmp(string a,string b){
    if(a.size()!=b.size()){
        return a.size()<b.size();
    }
    for(int i=0;;i++){
        if(a[i]!=b[i]){
            return a[i]<b[i];
        }
    }
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        int n,cn;
        cin>>n;
        if(n<=1){
            cout<<"-1\n";
            continue;
        }
        if(n<=7){
            if(n==6){
                cout<<"6\n";
                continue;
            }
            for(int i=0;i<=9;i++){
                if(n==s[i]){
                    cout<<i<<"\n";
                    break;
                }
            }
            continue;
        }
        for(int i=1;i<=9;i++){
            cn=n;
            cn-=s[i];
            ans[i]+=char(i+'0');
            if(cn<=1){
                ans[i]+='00000';
            }
            while(cn>7){
                ans[i]+='0';
                cn-=6;
            }
            for(int j=0;j<=9;j++){
                if(cn==s[j]){
                    ans[i]+=char(j+'0');
                    break;
                }
            }
        }
        sort(ans+1,ans+9,cmp);
        cout<<ans[1]<<"\n";
        for(int i=1;i<=9;i++){
            ans[i]="";
        }
    }
    return 0;
}
