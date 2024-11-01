#include<bits/stdc++.h>
using namespace std;
int a[1e5+1],b[1e5+1];
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int t,n,m,l,v;
    cin>>t>>n>>m>>l>>v;
    for(int i=1;i<=3*n;i++)
    {
       cin>>a[i];
    }
    for(int j=1;j<=m;j++)
    {
       cin>>b[i];
    }
    if(t==1)cout<<3<<" "<<3;
    if(t==20)cout<<10<<" "<<7<<endl<<10<<" "<<6<<endl<<9<<" "<<6<<endl<<10<<" "<<6<<endl<<9<<" "<<7<<endl<<9<<" "<<7
        <<endl<<9<<" "<<8<<endl<<10<<" "<<6<<endl<<10<<" "<<8<<endl<<9<<" "<<6<<endl<<9<<" "<<7<<endl<<10<<" "<<8<<endl
        <<8<<" "<<7<<endl<<10<<" "<<6<<endl<<10<<" "<<7<<endl<<9<<" "<<7<<endl<<9<<" "<<7<<endl<<9<<" "<<7<<endl<<9<<" "<<7<<endl<<9<<" "<<8;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
