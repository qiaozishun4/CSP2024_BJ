#include<bits/stdc++.h>
using namespace std;
long long n,m,d[10005],d1,s,k,l,sum=0;
int wz(int x,int y)
{
    return wz(x,y);
}
int main ()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {

        for(int j=1;j<=m;j++)
        {
            if(d[0]==0)
            {
                cout<<d[i];
            }
            if(d[1]==1)
            {
                cout<<d[i];
            }
            if(d[2]==2)
            {
                cout<<d[i];
            }
            if(d[3]==3)
            {
                cout<<d[i];
            }
            if(s==0){
                cout<<"x";
            }
            if(s==1)
            {
                cout<<".";
            }
            sum++;
        }
    }
    for(int i=1;i<=k;i++){
        if(l==0){
            cout<<wz(x,y+1);
        }
        if(l==1){
           cout<<wz(x+1,y);
        }
        if(l==2){
            cout<<wz(x,y-1);
        }
        if(l==3){
            cout<<wz(x-1,y);
        }
        if(s==0){
            wz(x+1,y+1);
        }
        else{
            d1=(d1+1)/4;
        }
        sum++;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
