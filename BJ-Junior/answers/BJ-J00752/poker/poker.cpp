#include <bits/stdc++.h>

using namespace std;

string strA[105] = {""};

bool cmp(string strX, string strY)
{
	return strX > strY;
}

int main()
{
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);

	int iN = 0;

	cin >> iN;

	for (int i = 1; i <= iN; i++)
	{
		cin >> strA[i];
	}

	sort(strA+1, strA+1+iN, cmp);

	int iCnt = 0;

	for (int i = 1; i <= iN; i++)
	{
		if (strA[i+1] != strA[i])
		{
			iCnt++;
		}
	}

	iN = iCnt;

	cout << 52-iN << endl;

	fclose(stdin);
	fclose(stdout);

	return 0;
}
