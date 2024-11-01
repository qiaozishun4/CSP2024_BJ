#include <bits/stdc++.h>

using namespace std;

char cA[1000][1000];
struct stXY
{
	int iX;
	int iY;
};

bool cmp(stXY stX, stXY stY)
{
	if (stX.iX != stY.iX)
	{
		return stX.iX < stY.iX;
	}

	return stX.iY < stY.iY;
}

stXY stXy[1000005];

int main()
{
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);

	int iT = 0;

	cin >> iT;

	for (int i = 1; i <= iT; i++)
	{
		for (int j = 0; j < 1000; j++)
		{
			for (int k = 0; k < 1000; k++)
			{
				cA[j][k]='\0';
			}
		}

		int iN = 0;
		int iM = 0;
		int iK = 0;
		int iX = 0;
		int iY = 0;
		int iCh = 0;

		cin >> iN >> iM >> iK;
		cin >> iX >> iY >> iCh;

		for (int j = 1; j <= iN; j++)
		{
			for (int k = 1; k <= iM; k++)
			{
				cin >> cA[j][k];
			}
		}
		
		int iCnt = 0;

		stXy[0].iX = iX;
		stXy[0].iY = iY;

		for (int j = 1; j <= iK; j++)
		{
			if (0 == iCh)
			{
				if (('\0' != cA[iX][iY+1]) && ('x') != cA[iX][iY+1])
				{
					iY++;
				}
				else
				{
					iCh=(iCh+1)%4;
				}
			}
			else if (1 == iCh)
			{
				if (('\0' != cA[iX+1][iY]) && ('x') != cA[iX+1][iY])
				{
					iX++;
				}
				else
				{
					iCh=(iCh+1)%4;
				}
			}
			else if (2 == iCh)
			{
				if (('\0' != cA[iX][iY-1]) && ('x') != cA[iX][iY-1])
				{
					iY--;
				}
				else
				{
					iCh=(iCh+1)%4;
				}
			}
			else if (3 == iCh)
			{
				if (('\0' != cA[iX-1][iY]) && ('x') != cA[iX-1][iY])
				{
					iX--;
				}
				else
				{
					iCh=(iCh+1)%4;
				}
			}

			stXy[j].iX = iX;
			stXy[j].iY = iY;
		}

		sort(stXy, stXy+1+iK, cmp);

		for (int j = 0; j <= iK; j++)
		{
			if ((stXy[j].iX!=stXy[j+1].iX) ||  (stXy[j].iY!=stXy[j+1].iY))
			{
				iCnt++;
			}
		}

		cout << iCnt << endl;
	}

	fclose(stdin);
	fclose(stdout);

	return 0;
}
