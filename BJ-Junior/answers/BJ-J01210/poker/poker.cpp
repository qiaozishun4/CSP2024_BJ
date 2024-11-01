#include<bits/stdc++.h>
using namespace std;
int a[4][14];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        string s;
        cin>>s;
        int x,y;
        if(s[0]=='H')
            x=0;
        else if(s[0]=='D')
            x=1;
        else if(s[0]=='C')
            x=2;
        else if(s[0]=='S')
            x=3;
        if(s[1]>='A' && s[1]<='Z'){
            if(s[1]=='T')
                y=10;
            else if(s[1]=='J')
                y=11;
            else if(s[1]=='Q')
                y=12;
            else if(s[1]=='K')
                y=13;
            else if(s[1]=='A')
                y=1;
        }else{
            y=s[1]-'0';
        }
        a[x][y]=1;
    }
    int sum=0;
    for(int i=0;i<4;i++){
        for(int j=1;j<=13;j++){
            if(!a[i][j]){
                sum++;
            }
        }
    }
    cout<<sum<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
