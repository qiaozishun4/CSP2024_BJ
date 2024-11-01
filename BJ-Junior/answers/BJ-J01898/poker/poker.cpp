#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("porker.in","r",stdin);
    freopen("porker.out","w",stdout);
    int n;
    cin>>n;
    map<string,int> m;
    int cnt=0;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        if(m[s]==0){
            m[s]=1;
            cnt++;
        }
    }
    cout<<52-cnt;
    return 0;
}
