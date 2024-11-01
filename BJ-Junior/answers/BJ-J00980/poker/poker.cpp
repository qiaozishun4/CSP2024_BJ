#include<bits/stdc++.h>
using namespace std;
int n;
string s;
map<string,int> mp;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
//    ios::sync_with_stdio(false);
    cin>>n;
    int ans=52;
 //   cout<<n<<endl;
    for(int i=0;i<n;i++){
     //   cout<<"jin"<<endl;
        cin>>s;
 //       cout<<s<<endl;
        if(mp[s]==0) {
            ans--;
      //      cout<<"--"<<endl;
        }
        mp[s]++;
    }
    cout<<ans;
    return 0;
}


