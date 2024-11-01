#include<bits/stdc++.h>
using namespace std;
int n;
vector<string> a;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    if(n==0){
        cout<<52<<endl;
        return 0;
    }
    for(int i=1;i<=n;i++){
        string s;
        cin>>s;
        a.push_back(s);
    }
    sort(a.begin(),a.end());
    int cnt=1;
    for(int i=1;i<n;i++){
        if(a[i]!=a[i-1]||i==0){
            cnt++;
        }
    }
    cout<<52-cnt<<endl;
    return 0;
}