#include<bits/stdc++.h>
using namespace std;
int n;
bool f[55];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    int sum=52;
    for(int i=1;i<=n;i++){
        string s1;
        cin>>s1;
        int x=0;
        if(s1[0]=='C') x+=13;
        else if(s1[0]=='H') x+=26;
        else if(s1[0]=='S') x+=39;

        if(s1[1]=='A') x++;
        else if(s1[1]=='T') x+=10;
        else if(s1[1]=='J') x+=11;
        else if(s1[1]=='Q') x+=12;
        else if(s1[1]=='K') x+=13;
        else if(s1[1]>='2'&&s1[1]<='9') x+=s1[1]-'0';
        if(f[x]==0){
            f[x]=1;
            sum--;
        }
    }
    cout<<sum;
    return 0;
}