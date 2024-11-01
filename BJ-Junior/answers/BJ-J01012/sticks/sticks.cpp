#include<bits/stdc++.h>
using namespace std;
string ans[100010];
int num[10]={6,2,5,5,4,5,6,3,7,6};
struct node{
    int first,second;
} st[10];
bool cmp(string &a,string &b){
    if(a.size()==b.size())return a<b;
    else return a.size()<b.size();
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    ans[0]="";
    ans[1]="";
    ans[2]="1";
    ans[3]="7";
    ans[4]="4";
    ans[5]="2";
    ans[6]="6";
    ans[7]="8";
    st[0].first=0,st[0].second=6;
    st[1].first=1,st[1].second=2;
    st[2].first=2,st[2].second=5;
    st[3].first=4,st[3].second=4;
    st[4].first=6,st[4].second=6;
    st[5].first=7,st[5].second=3;
    st[6].first=8,st[6].second=7;
    string k;
    for(int i=8;i<=100;i++){
        ans[i]=ans[i-st[0].second]+char(st[0].first+'0');
        for(int j=1;j<=6;j++){
            k=ans[i-st[j].second]+char(st[j].first+'0');
            if(cmp(k,ans[i]))ans[i]=k;
        }
    }
    for(int i=101;i<=1e5;i++){
        ans[i]=ans[i-7]+'8';
    }
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        if(ans[n]=="")cout<<-1<<endl;
        else cout<<ans[n]<<endl;
    }
    return 0;
}
