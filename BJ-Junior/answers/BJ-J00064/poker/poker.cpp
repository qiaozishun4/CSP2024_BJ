#include<bits/stdc++.h>
using namespace std;
int n;
string s[56];
bool check(string s1,int how){
    int flag=0;
    for(int i=how;i<=n;i++){

            if(s1[0]==s[i][0]&&s1[1]==s[i][1]) flag++;
    }
    if(flag>1)
    return 0;
    else return 1;
}
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s[i];
    }
    int num=0;
    for(int i=1;i<=n;i++){
        if(check(s[i],i)) num++;
    }
    cout<<52-num;
    return 0;
}
