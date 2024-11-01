#include<bits/stdc++.h>
using namespace std;
long long q[10000];
string w[100000];
int n,m;
int main(){
freopen("poker.in","r",stdin);
freopen("poker.out","w",stdout);
cin>>n;
for(int i=1;i<=n;i++)
{
    cin>>w[i];


}
sort(w+1,w+n+1);
for(int i=2;i<=n;i++)
{
    if(w[i]==w[i-1])
    {
        w[i-1]='0';

    }

}
sort(w+1,w+n+1);
int i=1;
for(int i=1;i<=n;i++)
{
    if(w[i]==w[i+1]||w[i+1]==w[i+2])
    {
        break;

    }
    else
    {

        m++;
    }

}
cout<<52-m;

}

