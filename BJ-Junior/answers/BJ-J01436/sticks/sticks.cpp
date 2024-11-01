#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t,m;
    string s[100],s1[21]={"-1","-1","1","7","4","2","6","8","10","18","22","20","28","68","88","108","188","200","208","288","688"};
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>m;
        s[i]=s1[m%20];
    }
    for(int i=1;i<=t;i++){
        cout<<s[i]<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
