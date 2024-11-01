#include<bits/stdc++.h>
using namespace std;
char a[15]={'A','2','3','4','5','6','7','8','9','T','J','Q','K'};

    bool vva[100];
     bool vvb[100];
     bool vvc[100];
     bool vvd[100];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);

    int n;
    cin>>n;
    string u;
    for(int i=1;i<=n;i++){
        cin>>u;
        if(u[0]=='D'){
            if(u[1]=='A')vva[1]=1;
            if(u[1]=='2')vva[2]=1;
            if(u[1]=='3')vva[3]=1;
            if(u[1]=='4')vva[4]=1;
            if(u[1]=='5')vva[5]=1;
            if(u[1]=='6')vva[6]=1;
            if(u[1]=='7')vva[7]=1;
            if(u[1]=='8')vva[8]=1;
            if(u[1]=='9')vva[9]=1;
            if(u[1]=='T')vva[10]=1;
            if(u[1]=='J')vva[11]=1;
            if(u[1]=='Q')vva[12]=1;
            if(u[1]=='K')vva[13]=1;
        }
        if(u[0]=='H'){
            if(u[1]=='A')vvb[1]=1;
            if(u[1]=='2')vvb[2]=1;
            if(u[1]=='3')vvb[3]=1;
            if(u[1]=='4')vvb[4]=1;
            if(u[1]=='5')vvb[5]=1;
            if(u[1]=='6')vvb[6]=1;
            if(u[1]=='7')vvb[7]=1;
            if(u[1]=='8')vvb[8]=1;
            if(u[1]=='9')vvb[9]=1;
            if(u[1]=='T')vvb[10]=1;
            if(u[1]=='J')vvb[11]=1;
            if(u[1]=='Q')vvb[12]=1;
            if(u[1]=='K')vvb[13]=1;
        }
        if(u[0]=='C'){
            if(u[1]=='A')vvc[1]=1;
            if(u[1]=='2')vvc[2]=1;
            if(u[1]=='3')vvc[3]=1;
            if(u[1]=='4')vvc[4]=1;
            if(u[1]=='5')vvc[5]=1;
            if(u[1]=='6')vvc[6]=1;
            if(u[1]=='7')vvc[7]=1;
            if(u[1]=='8')vvc[8]=1;
            if(u[1]=='9')vvc[9]=1;
            if(u[1]=='T')vvc[10]=1;
            if(u[1]=='J')vvc[11]=1;
            if(u[1]=='Q')vvc[12]=1;
            if(u[1]=='K')vvc[13]=1;
        }
        if(u[0]=='S'){
            if(u[1]=='A')vvd[1]=1;
            if(u[1]=='2')vvd[2]=1;
            if(u[1]=='3')vvd[3]=1;
            if(u[1]=='4')vvd[4]=1;
            if(u[1]=='5')vvd[5]=1;
            if(u[1]=='6')vvd[6]=1;
            if(u[1]=='7')vvd[7]=1;
            if(u[1]=='8')vvd[8]=1;
            if(u[1]=='9')vvd[9]=1;
            if(u[1]=='T')vvd[10]=1;
            if(u[1]=='J')vvd[11]=1;
            if(u[1]=='Q')vvd[12]=1;
            if(u[1]=='K')vvd[13]=1;
        }
    }
    int ans=0;
    for(int i=1;i<=4;i++){
        if(i==1){
            for(int j=1;j<=13;j++){
                if(vva[j]==0)ans++;
            }
        }
        if(i==2){
            for(int j=1;j<=13;j++){
                if(vvb[j]==0)ans++;
            }
        }
        if(i==3){
            for(int j=1;j<=13;j++){
                if(vvc[j]==0)ans++;
            }
        }
        if(i==4){
            for(int j=1;j<=13;j++){
                if(vvd[j]==0)ans++;
            }
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
return 0;}
