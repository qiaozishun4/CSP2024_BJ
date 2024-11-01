#include<bits/stdc++.h>
using namespace std;
map<char,bool> b[20];
int n,cnt;
char c[5];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    //1
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>c;
        if(c[1]>='2'&&c[1]<='9'){
            b[c[1]-'0'][c[0]]=1;
        }else{
            if(c[1]=='T') b[10][c[0]]=1;
            else if(c[1]=='J') b[11][c[0]]=1;
            else if(c[1]=='Q') b[12][c[0]]=1;
            else if(c[1]=='K') b[13][c[0]]=1;
            else b[1][c[0]]=1;
        }
    }
    for(int i=1;i<=13;i++) if(!b[i]['D']) cnt++;
    for(int i=1;i<=13;i++) if(!b[i]['C']) cnt++;
    for(int i=1;i<=13;i++) if(!b[i]['H']) cnt++;
    for(int i=1;i<=13;i++) if(!b[i]['S']) cnt++;
    cout<<cnt;
    return 0;
}