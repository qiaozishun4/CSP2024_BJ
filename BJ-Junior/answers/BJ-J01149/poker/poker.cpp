#include<bits/stdc++.h>
#define ll long long
using namespace std;
map<string,int> poker;
vector<string> POKER;
char a[4]={'D','C','H','S'};
char turn(int x){
    if(x==1) return 'A';
    if(x==10) return 'T';
    if(x==11) return 'J';
    if(x==12) return 'Q';
    if(x==13) return 'K';
    return x+'0';
}
void init(){
    for(int i=4;i<56;i++){
        int x=i/4;
        string s;
        s=s+a[i%4];
        s=s+turn(x);
        POKER.push_back(s);
    }
}
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    init();
    /*for(auto i:POKER){
        cout<<i<<"\n";
    }*/
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        string pok;
        cin>>pok;
        poker[pok]=1;
    }
    int tot=0;
    for(string i:POKER){
        if(poker[i]==1){
            continue;
        }tot++;
    }
    cout<<tot;
    return 0;
}
