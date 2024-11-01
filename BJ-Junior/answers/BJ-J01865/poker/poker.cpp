#include<bits/stdc++.h>
using namespace std;
int n,c,a[10][18];
char b[3];
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>b;
        if(b[0]=='D'){
            if(b[1]=='A')a[4][1]=1;
            else if(b[1]=='T')a[4][10]=1;
            else if(b[1]=='J')a[4][11]=1;
            else if(b[1]=='Q')a[4][12]=1;
            else if(b[1]=='K')a[4][13]=1;
            else a[4][b[1]-48]=1;
        }
        else if(b[0]=='C'){
            if(b[1]=='A')a[3][1]=1;
            else if(b[1]=='T')a[3][10]=1;
            else if(b[1]=='J')a[3][11]=1;
            else if(b[1]=='Q')a[3][12]=1;
            else if(b[1]=='K')a[3][13]=1;
            else a[3][b[1]-48]=1;
        }
        else if(b[0]=='H'){
            if(b[1]=='A')a[2][1]=1;
            else if(b[1]=='T')a[2][10]=1;
            else if(b[1]=='J')a[2][11]=1;
            else if(b[1]=='Q')a[2][12]=1;
            else if(b[1]=='K')a[2][13]=1;
            else a[2][b[1]-48]=1;
        }
        else{
            if(b[1]=='A')a[1][1]=1;
            else if(b[1]=='T')a[1][10]=1;
            else if(b[1]=='J')a[1][11]=1;
            else if(b[1]=='Q')a[1][12]=1;
            else if(b[1]=='K')a[1][13]=1;
            else a[3][b[1]-48]=1;
        }
    }
    for(int i=1;i<=4;i++)
    {
        for(int j=1;j<=13;j++){
                if(a[i][j]==0)c++;
        }
    }
    cout<<c;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
