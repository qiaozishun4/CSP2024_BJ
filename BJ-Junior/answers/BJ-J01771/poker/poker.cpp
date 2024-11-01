#include<bits/stdc++.h>
using namespace std;
int n,cnt;
struct pk
{
    char x,y;
    int idx,idy;
}a[55];
bool v[5][14];
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin >> n;
	for(int i=1; i<=n; i++)
    {
        cin >> a[i].x >> a[i].y;
        //
        if(a[i].x=='S')
        {
            a[i].idx=1;
        }
        if(a[i].x=='H')
        {
            a[i].idx=2;
        }
        if(a[i].x=='C')
        {
            a[i].idx=3;
        }
        if(a[i].x=='D')
        {
            a[i].idx=4;
        }
        //
        if(a[i].y=='A')
        {
            a[i].idy=1;
        }
        if(a[i].y=='2')
        {
            a[i].idy=2;
        }
        if(a[i].y=='3')
        {
            a[i].idy=3;
        }
        if(a[i].y=='4')
        {
            a[i].idy=4;
        }
        if(a[i].y=='5')
        {
            a[i].idy=5;
        }
        if(a[i].y=='6')
        {
            a[i].idy=6;
        }
        if(a[i].y=='7')
        {
            a[i].idy=7;
        }
        if(a[i].y=='8')
        {
            a[i].idy=8;
        }
        if(a[i].y=='9')
        {
            a[i].idy=9;
        }
        if(a[i].y=='T')
        {
            a[i].idy=10;
        }
        if(a[i].y=='J')
        {
            a[i].idy=11;
        }
        if(a[i].y=='Q')
        {
            a[i].idy=12;
        }
        if(a[i].y=='K')
        {
            a[i].idy=13;
        }
        v[a[i].idx][a[i].idy]=true;
    }
    for(int i=1; i<=4; i++)
    {
        for(int j=1; j<=13; j++)
        {
            if(v[i][j])
            {
                cnt++;
            }
        }
    }
    cout << 52-cnt << '\n';
	return 0;
}
