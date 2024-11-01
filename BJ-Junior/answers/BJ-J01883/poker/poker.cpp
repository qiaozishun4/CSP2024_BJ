#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n,a=0;
    cin>>n;
    if(n==0){
        cout<<52;
        return 0;
    }
    map<string,int>mp;
    string k;
    for(int i=0;i<n;i++){
        cin>>k;
        if(mp[k]>0){
            a++;
        }
        mp[k]++;
    }
    int b=52-n+a;
    cout<<b;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
