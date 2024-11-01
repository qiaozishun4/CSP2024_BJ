#include <bits/stdc++.h>
using namespace std;
const int N=222;
int b[N]={0};
int main()
{
    int n;

    string a;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int y,x;
        cin>>a;
        if(a[1]<='9'&&a[1]>='2')
            y=a[1]-'0';
        else{
            if(a[1]=='A')
                y=1;
                else if(a[1]=='Q')
                y=12;
            else if(a[1]=='K')
                y=13;
            else if(a[1]=='T')
                y=10;
        }
        switch(a[0])
        {
            case 'D':
            x=14;
            break;
                       case 'C':
            x=15;
            break;
            case 'H':
            x=16;
            break;
            case 'S':
            x=17;
            break;
        }
        int m;
        if(x==14&&y==8)
             m=x*y+1;
	else m=x*y;
	b[m]++;
    }
    int s=0;
    for(int i=1;i<=650;i++)
    {
     	if(b[i]>=1)
            s++;
   }
    cout<<52-s;
    return 0;
}
