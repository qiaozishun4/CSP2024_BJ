#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int n;
int a[N];
int cnt[N];
vector<int> A;

int main()
{
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]), cnt[a[i]]++;
	for (int i = 0; i < N; i++)
		if (cnt[i])
			A.push_back(cnt[i]);
	for (int i = 1, len = A.size(); i < len; i++)
	{
		int tmp = A[i];
		for (int j = 0; j < i && tmp; j++)
			if (tmp >= A[j])
				tmp -= A[j], A[j] = 0;
			else
				A[j] -= tmp, tmp = 0;
		//for (auto x : A)
		//	printf("%d ", x);
		//printf("\n");
	}
	int ans = 0;
	for (auto x : A)
		ans += x;
	printf("%d\n", ans);

	return 0;
}