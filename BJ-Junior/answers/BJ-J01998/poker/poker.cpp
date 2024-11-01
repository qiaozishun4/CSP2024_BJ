#include <iostream>
#include <cstring>
using namespace std;

bool b[10][100];

int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		string x;
		cin >> x;
		if (x[0] == 'D')
		{
			if(x[1] == 'A')
			{
				b[1][1] = true;
			}
			if(x[1] == '2')
			{
				b[1][2] = true;
			}
			if(x[1] == '3')
			{
				b[1][3] = true;
			}
			if(x[1] == '4')
			{
				b[1][4] = true;
			}
			if(x[1] == '5')
			{
				b[1][5] = true;
			}
			if(x[1] == '6')
			{
				b[1][6] = true;
			}
			if(x[1] == '7')
			{
				b[1][7] = true;
			}
			if(x[1] == '8')
			{
				b[1][8] = true;
			}
			if(x[1] == '9')
			{
				b[1][9] = true;
			}
			if(x[1] == 'T')
			{
				b[1][10] = true;
			}
			if(x[1] == 'J')
			{
				b[1][11] = true;
			}
			if(x[1] == 'Q')
			{
				b[1][12] = true;
			}
			if(x[1] == 'K')
			{
				b[1][13] = true;
			}
		}
		if (x[0] == 'C')
		{
			if(x[1] == 'A')
			{
				b[2][1] = true;
			}
			if(x[1] == '2')
			{
				b[2][2] = true;
			}
			if(x[1] == '3')
			{
				b[2][3] = true;
			}
			if(x[1] == '4')
			{
				b[2][4] = true;
			}
			if(x[1] == '5')
			{
				b[2][5] = true;
			}
			if(x[1] == '6')
			{
				b[2][6] = true;
			}
			if(x[1] == '7')
			{
				b[2][7] = true;
			}
			if(x[1] == '8')
			{
				b[2][8] = true;
			}
			if(x[1] == '9')
			{
				b[2][9] = true;
			}
			if(x[1] == 'T')
			{
				b[2][10] = true;
			}
			if(x[1] == 'J')
			{
				b[2][11] = true;
			}
			if(x[1] == 'Q')
			{
				b[2][12] = true;
			}
			if(x[1] == 'K')
			{
				b[1][13] = true;
			}
		}
		if (x[0] == 'H')
		{
			if(x[1] == 'A')
			{
				b[3][1] = true;
			}
			if(x[1] == '2')
			{
				b[3][2] = true;
			}
			if(x[1] == '3')
			{
				b[3][3] = true;
			}
			if(x[1] == '4')
			{
				b[3][4] = true;
			}
			if(x[1] == '5')
			{
				b[3][5] = true;
			}
			if(x[1] == '6')
			{
				b[3][6] = true;
			}
			if(x[1] == '7')
			{
				b[3][7] = true;
			}
			if(x[1] == '8')
			{
				b[3][8] = true;
			}
			if(x[1] == '9')
			{
				b[3][9] = true;
			}
			if(x[1] == 'T')
			{
				b[3][10] = true;
			}
			if(x[1] == 'J')
			{
				b[3][11] = true;
			}
			if(x[1] == 'Q')
			{
				b[3][12] = true;
			}
			if(x[1] == 'K')
			{
				b[3][13] = true;
			}
		}
		if (x[0] == 'S')
		{
			if(x[1] == 'A')
			{
				b[4][1] = true;
			}
			if(x[1] == '2')
			{
				b[4][2] = true;
			}
			if(x[1] == '3')
			{
				b[4][3] = true;
			}
			if(x[1] == '4')
			{
				b[4][4] = true;
			}
			if(x[1] == '5')
			{
				b[4][5] = true;
			}
			if(x[1] == '6')
			{
				b[4][6] = true;
			}
			if(x[1] == '7')
			{
				b[4][7] = true;
			}
			if(x[1] == '8')
			{
				b[4][8] = true;
			}
			if(x[1] == '9')
			{
				b[4][9] = true;
			}
			if(x[1] == 'T')
			{
				b[4][10] = true;
			}
			if(x[1] == 'J')
			{
				b[4][11] = true;
			}
			if(x[1] == 'Q')
			{
				b[4][12] = true;
			}
			if(x[1] == 'K')
			{
				b[4][13] = true;
			}
		}
    }
    int cnt = 0;
    for (int i = 1;i <= 4;i++)
    {
	    for (int j = 1;j <= 13;j++)
	    {
		    if (b[i][j] == 0)
		    {
		    	cnt++;
	        }
        }
    }
    cout << cnt;
    return 0;	
}
