#include <bits/stdc++.h>
using namespace std;
bool card[5][14];int cnt=52;
map<char,int> color,num;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;cin>>n;
    color['D']=0;color['C']=1;color['H']=2;color['S']=3;
    num['A']=1;for(int a=2;a<=9;a++)num[char('0'+a)]=a;
    num['T']=10;num['J']=11;num['Q']=12;num['K']=13;
    while(n--){
        char a,b;cin>>a>>b;
        int x=color[a],y=num[b];
        if(card[x][y]==0){card[x][y]=1;cnt--;}
    }cout<<cnt<<endl;
}
