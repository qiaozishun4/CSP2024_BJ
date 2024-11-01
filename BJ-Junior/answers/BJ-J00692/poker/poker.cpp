#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    map<string,int> s;
    int n,temp=52;
    cin>>n;
    while(n--){
        string str1;
        cin>>str1;
        s[str1]++;
    }
    cout<<52-s.size();
    return 0;
}

