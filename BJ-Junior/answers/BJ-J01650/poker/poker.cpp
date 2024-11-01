#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    map<string,int>t;
    int sum=52;
    while(n--){
        string s;
        cin>>s;
        if(t[s]==0){
            t[s]++;
            sum--;
        }
    }
    cout<<sum;
    return 0;
}
