#include <bits/stdc++.h>

using namespace std;

bool visit[5][14];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        string stra;
        cin>>stra;
        char fir=stra[0];
        char sec=stra[1];
        int firr=0;
        int secc=0;
        secc=sec-'0';
        if(sec=='A')secc=1;
        if(sec=='T')secc=10;
        if(sec=='J')secc=11;
        if(sec=='Q')secc=12;
        if(sec=='K')secc=13;
        if(fir=='D')firr=1;
        if(fir=='C')firr=2;
        if(fir=='H')firr=3;
        if(fir=='S')firr=4;
        visit[firr][secc]=1;
    }
    int sum=0;
    for(int i=1;i<=4;i++){
        for(int j=1;j<=13;j++){
            if(visit[i][j]==0)
                sum++;
        }
    }
    cout<<sum;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
