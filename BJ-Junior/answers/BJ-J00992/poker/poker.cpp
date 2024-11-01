#include<iostream>
using namespace std;

int n;
bool v[10][15];

int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        char c,h;
        int pos1,pos2;
        cin >> c >> h;
        if(c=='D')pos1=1;
        else if(c=='C')pos1=2;
        else if(c=='H')pos1=3;
        else if(c=='S')pos1=4;
        if(h=='A')pos2=1;
        else if(h>='2'&&h<='9')pos2=h-'0';
        else if(h=='T')pos2=10;
        else if(h=='J')pos2=11;
        else if(h=='Q')pos2=12;
        else if(h=='K')pos2=13;
        v[pos1][pos2]=1;
    }
    int cnt=0;
    for(int i=1;i<=4;i++)
    {
        for(int j=1;j<=13;j++)
        {
            if(!v[i][j])cnt++;
        }
    }
    cout << cnt << endl;
}
