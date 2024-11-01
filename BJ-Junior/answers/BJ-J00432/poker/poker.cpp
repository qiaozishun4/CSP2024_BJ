#include<bits/stdc++.h>
using namespace std;
int box[130];
bool big_box[450];
void csh(){
    box['D']=box['A']=1;
    box['C']=2;
    box['H']=3;
    box['S']=4;
    box['T']=10;
    box['J']=11;
    box['Q']=12;
    box['K']=13;
    for(int i='2';i<='9';i++) box[i]=i-'0';
}
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    csh();
    for(int i=0;i<n;i++){
        char huase;
        char dianshu;
        cin>>huase>>dianshu;
        int xb=box[huase]*100+box[dianshu];
        big_box[xb]=1;
    }
    char h_b[4]={'D','C','H','S'};
    char d_b[13]={'A','2','3','4','5','6','7','8','9','T','J','Q','K'};
    int ans=0;
    for(int i=0;i<4;i++){
        for(int j=0;j<13;j++){
            int xb=box[h_b[i]]*100+box[d_b[j]];
            if(!big_box[xb]) ans++;
        }
    }
    cout<<ans;
    return 0;
}
