#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
cin>>n;
int s;
while(n--){
    cin>>s;
    for(int i=1;i<=s/7;i++){
        cout<<"8";
    }
    cout<<endl;
}
return 0;
}
