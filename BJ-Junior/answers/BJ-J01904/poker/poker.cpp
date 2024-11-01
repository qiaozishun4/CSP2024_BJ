#include<bits/stdc++.h>
using namespace std;
bool a[4][13];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n,ans=0;
    cin>>n;
    for(int i=0; i<n; i++){
        int x,y;
        string z;
        cin>>z;
        char c=z[0];
        if(c=='D'){
            x=0;
        }
        else if(c=='C'){
            x=1;
        }
        else if(c=='H'){
            x=2;
        }
        else{
            x=3;
        }
        int n=z.length()-1;
        string s=z.substr(1,n);
        if(n==1){
            if(s=="A"){
                y=0;
            }
            else if(s=="J"){
                y=10;
            }
            else if(s=="Q"){
                y=11;
            }
            else if(s=="K"){
                y=12;
            }
            else{
                y=s[0]-'1';
            }
        }
        else{
            y=9;
        }
        if(a[x][y]==0){
            ans++;
        }
        a[x][y]=1;
    }
    cout<<52-ans;
    return 0;
}
