#include<bits/stdc++.h>
using namespace std;
int n,c,d;
int a[60];
string b;
int main()
{
    stdin("poker.in",stdin,r);
    stdout("poker.out",stdout,w);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>b;
        c=0;
        if(b[1]=="D")
        {
            c+=13;
        }
        else if(b[1]=="H")
        {
            c+=26;
        }
        else if(b[1]=="S")
        {
            c+=39;
        }
        if(b[2]=="A")
        {
            c+=1;
        }
        else if(b[2]=="T")
        {
            c+=10;
        }
        else if(b[2]=="J")
        {
            c+=11;
        }
        else if(b[2]=="Q")
        {
            c+=12;
        }
        else if(b[2]=="K")
        {
            c+=13;
        }
        else
        {
            c+=b[2]-'0';
        }
        a[c]=1;
    }
    for(int i=1;i<=52;i++)
    {
        if(a[c]==1)
        {
            d++;
        }
    }
    cout<<52-d;
    return 0;
}