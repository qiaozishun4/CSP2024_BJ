#include <bits/stdc++.h>
using namespace std;
int n,ans;
map<string,int> mp;
string t1[10]={" ","D","C","H","S"};
string t2[20]={" ","A","2","3","4","5","6","7","8","9","T","J","Q","K"};
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        string s;
        cin>>s;
        mp[s]++;
    }
    for(int i=1;i<=4;i++){
        for(int j=1;j<=13;j++){
            string s;
            s=t1[i]+t2[j];
            //cout<<s<<" ";
            if(mp[s]==0){
                ans++;
                //cout<<s<<" ";
            }
        }
        //cout<<endl;
    }
    cout<<ans;
    return 0;
}

