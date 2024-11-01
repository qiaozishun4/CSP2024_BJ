#include<iostream>
using namespace std;
bool a[15][5];int n,cnt;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        char x,y;int m;
        cin>>x>>y;
        if(y=='A')m=1;
        else if(y=='T')m=10;
        else if(y=='J')m=11;
        else if(y=='Q')m=12;
        else if(y=='K')m=13;
        else m=y-'0';
        if(x=='D')a[m][1]=1;
        if(x=='C')a[m][2]=1;
        if(x=='H')a[m][3]=1;
        if(x=='S')a[m][4]=1;
    }
    for(int i=1;i<=13;i++){
        for(int j=1;j<=4;j++){
            if(a[i][j]==0)cnt++;
        }
    }
    cout<<cnt;
    fclose(stdin);fclose(stdout);
    return 0;
}
