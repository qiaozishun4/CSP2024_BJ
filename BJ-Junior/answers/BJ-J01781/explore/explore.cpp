include <bits/stdc++.h>
using namespace std;
string n[1005][1005];
int a,b,k,x,y,d,sum=1;
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
    int q;
    cin >>q;
    for (int qwer=0;qwer<q;qwer++)
    {
        cin >>a >>b >>k;
        cin >>x >>y >>d;
        string s[b];
        for (int i=0;i<a;i++)
        {
			cin >>s[i];
		}
        for (int i=1;i<=a;i++)
        {
            for (int j=1;j<=b;j++)
            {
            
                n[a][b]=s[a][b];
            }
        }
        for (int iiii=0;iiii<k;iiii++)
        {
            if (d==0)
            {
                if ((y+1<=b) && ((n[x][y+1]==".") || (n[x][y+1]=="f")))
                {
                    y++;
                    if (n[x][y]==".")
                    {
                        
                        sum++;
                    }
                    n[x][y]=="f";
                }
                else
                {
                    d++;
                }
            }
            else if (d==1)
            {
                if ((x+1<=a) && ((n[x+1][y]==".") || (n[x+1][y]=="f")))
                {
                    x++;
                    if (n[x][y]==".")
                    {
                        
                        sum++;
                    }
                    n[x][y]=="f";
                }
                else
                {
                    d++;
                }
            }
            else if (d==2)
            {
                if ((y-1>=1) && ((n[x][y-1]==".") || (n[x][y-1]=="f")))
                {
                    y--;
                    if (n[x][y]==".")
                    {
                        
                        sum++;
                    }
                    n[x][y]=="f";
                }
                else
                {
                    d++;
                }
            }
            else
            {
                if ((x-1>=1) && ((n[x-1][y]==".") || (n[x-1][y]=="f")))
                {
                    x--;
                    if (n[x][y]==".")
                    {
                        
                        sum++;
                    }
                    n[x][y]=="f";
                }
                else
                {
                    d=0;
                }
            }
        }
        cout <<sum <<endl;
        sum=1;
    }
    return 0;
}
