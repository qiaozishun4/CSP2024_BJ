#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    bool s[15][10]={0};
    cin>>n;
    for(int i=0;i<n;i++){
        char h,d;
        cin>>h>>d;
        if(h=='D'){
            if(d=='T')s[10][1]=1;
            if(d=='J')s[11][1]=1;
            if(d=='Q')s[12][1]=1;
            if(d=='K')s[13][1]=1;
            if(d=='A')s[1][1]=1;
            else{
                int t=d-'0';
                s[t][1]=1;
            }
        }
        if(h=='C'){
            if(d=='T')s[10][2]=1;
            if(d=='J')s[11][2]=1;
            if(d=='Q')s[12][2]=1;
            if(d=='K')s[13][2]=1;
            if(d=='A')s[1][2]=1;
            else{
                int t=d-'0';
                s[t][2]=1;
            }
        }if(h=='H'){
            if(d=='T')s[10][3]=1;
            if(d=='J')s[11][3]=1;
            if(d=='Q')s[12][3]=1;
            if(d=='K')s[13][3]=1;
            if(d=='A')s[1][3]=1;
            else{
                int t=d-'0';
                s[t][3]=1;
            }
        }if(h=='S'){
            if(d=='T')s[10][4]=1;
            if(d=='J')s[11][4]=1;
            if(d=='Q')s[12][4]=1;
            if(d=='K')s[13][4]=1;
            if(d=='A')s[1][4]=1;
            else{
                int t=d-'0';
                s[t][4]=1;
            }
        }

    }
    int sum=0;
    for(int i=1;i<=13;i++){
        for(int j=1;j<=4;j++){
            sum+=s[i][j];
        }
    }
    cout<<52-sum;
    return 0;
    fclose(stdin);
    fclose(stdout);

}
