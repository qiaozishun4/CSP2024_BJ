#include<bits/stdc++.h>
using namespace std;
int n;
struct poke{
    char name,point;
}a[53];
bool vis[55];
int cnt;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=52;i++){
        if(1<=i&&i<=13) a[i].name='C';
        else if(14<=i&&i<=26) a[i].name='S';
        else if(27<=i&&i<=39) a[i].name='H';
        else a[i].name='D';
        int jj=i%13;
        if(jj==1) a[i].point='A';
        else if(jj==2) a[i].point='2';
        else if(jj==3) a[i].point='3';
        else if(jj==4) a[i].point='4';
        else if(jj==5) a[i].point='5';
        else if(jj==6) a[i].point='6';
        else if(jj==7) a[i].point='7';
        else if(jj==8) a[i].point='8';
        else if(jj==9) a[i].point='9';
        else if(jj==10) a[i].point='T';
        else if(jj==11) a[i].point='J';
        else if(jj==12) a[i].point='Q';
        else if(jj==0) a[i].point='K';
    }
    for(int i=1;i<=n;i++){
        poke ll;
        cin>>ll.name>>ll.point;
        for(int j=1;j<=52;j++){
            if(a[j].name==ll.name&&a[j].point==ll.point){
                vis[j]=1;
                break;
            }
        }
    }
    for(int i=1;i<=52;i++){
        if(!vis[i]){
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}