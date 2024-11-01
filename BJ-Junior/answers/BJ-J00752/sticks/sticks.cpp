#include <bits/stdc++.h>

using namespace std;

int iA[15] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int main()
{
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);

	int iT = 0;

	cin >> iT;

	for (int i = 1; i <= iT; i++)
	{
		int iN = 0;
		bool bFlag = false;

		cin >> iN;

		for (int j = 0; j <= 100000; j++)
		{
			int iSum = 0;

			int iK = j;

			while (0 < iK)
			{
				iSum += iA[iK%10];
				iK/=10;
			}

			if (iSum == iN)
			{
				bFlag = true;
				cout << j << endl;
				break;
			}
		}

		if (!bFlag)
		{
			cout << "-1" << endl;
		}
	}

	fclose(stdin);
	fclose(stdout);

	return 0;
}
