#include<bits/stdc++.h>
using namespace std;
int a[14][5];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        string str;
        cin>>str;
        char col=str[0];
        int c;
        if(col=='D')
            c=1;
        else if(col=='C')
            c=2;
        else if(col=='H')
            c=3;
        else
            c=4;
        char num=str[1];
        int k;
        if(num>'9'){
            if(num=='T')
                k=10;
            else if(num=='J')
                k=11;
            else if(num=='K')
                k=13;
            else k=12;
        }else{
            k=num-48;
        }
        a[k][c]++;
    }
    int ans=0;
    for(int i=1;i<=13;i++)
        for(int j=1;j<=4;j++)
            if(a[i][j]) ans++;
    cout<<52-ans;
return 0;
}
