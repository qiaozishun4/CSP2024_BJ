#include <bits/stdc++.h>
using namespace std;
/*
impossible
1
7
4
2
6
8
10
18
22
20
28
68
88
*/
string biao[20]={"-1","-1","1","7","4","2","6","8","10","18","22","20","28","68","88"};
string gen8(int x){
    string ans="";
    for(int i=1;i<=x;i++)ans+='8';
    return ans;
}
string gen(int x){
    int mans=x%7;
    if(mans==0){
        return gen8(x/7);
    }else if(mans==1){
        return "10"+gen8(x/7-1);
    }else if(mans==2){
        return "1"+gen8(x/7);
    }else if(mans==3){
        return "200"+gen8(x/7-2);
    }else if(mans==4){
        return "20"+gen8(x/7-1);
    }else if(mans==5){
        return "2"+gen8(x/7);
    }else{
        return "6"+gen8(x/7);
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        if(n<=14)cout<<biao[n];
        else cout<<gen(n);
        cout<<"\n";
    }
    return 0;
}
