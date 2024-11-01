#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
int n, r[100005], r_[100005], sumr, ans, last;
bool flag;
vector<int> book(100005);
vector<int> eat(100005);
// last: 经过第一轮后除了最大的还有多少个没被吃掉
int main()
{
	// freopen("CSP-S/duel/duel4.in", "r", stdin);
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> r[i];
	}
	sort(r + 1, r + n + 1);
	r_[1] = 1;
	for(int i = 2; i <= n; i++)
	{
		if(r[i] != r[i - 1]) sumr++;
		r_[i] = sumr + 1; // 对r进行离散化，方便处理
	}
	sumr++;
	for(int i = 1; i <= n; i++) book[r_[i]]++; // 根据离散化后的数据建立book数组，查询每种攻击力有多少个对应的怪兽
	// cout << "原来book："; for(int i = 1; i <= sumr; i++) cout << book[i] << " "; cout << endl;
	for(int i = 1; i < sumr; i++)
	{
		eat[i + 1] = book[i + 1] - min(book[i], book[i + 1]);
		book[i] = max(book[i] - book[i + 1], 0);
	}
	// 筛：
	for(int i = 1; i <= sumr; i++)
	{
		if(book[i] == 0)
		{
			book.erase(book.begin() + i);
			eat.erase(eat.begin() + i);
			i--;
			sumr--;
		}
	}
	// 如果筛完后还有的话：
	if(sumr > 1) flag = true;
	while(flag)
	{
		// cout << "筛过book："; for(int i = 1; i <= sumr; i++) cout << book[i] << " "; cout << endl;
		// cout << "筛过eat："; for(int i = 1; i <= sumr; i++) cout << eat[i] << " "; cout << endl;
		for(int i = 1; i < sumr; i++)
		{
			book[i] = max(book[i] - eat[i + 1], 0);
			eat[i + 1] = book[i + 1] - min(book[i], book[i + 1]);
		}
		// cout << "现在book："; for(int i = 1; i <= sumr; i++) cout << book[i] << " "; cout << endl;
		// cout << "现在eat："; for(int i = 1; i <= sumr; i++) cout << eat[i] << " "; cout << endl;
		//重来一边：
		for(int i = 1; i <= sumr; i++)
		{
			if(book[i] == 0)
			{
				book.erase(book.begin() + i);
				eat.erase(eat.begin() + i);
				i--;
				sumr--;
			}
		}
		if(sumr > 1) flag = true;
		else flag = false;
		for(int i = 2; i <= sumr; i++)
		{
			if(eat[i] != 0)
			{
				flag = true;
				break;
			}
			if(i == sumr) flag = false;
		}
	}
	for(int i = 1; i <= sumr; i++) ans += book[i];
	cout << ans << endl;
	return 0;
}
/*
思路：
先进行排序
设攻击力/防御力为x的怪兽有k[x]个
则最终答案为
for(int i = 1; i < max(r[1], r[2], ... , r[n]); i++)
{
	sum += max(k[i], k[i + 1]);
}
for(int i = 1; i < max(r[1], r[2], ... , r[n]); i++)
{
	sum += max(k[i], k[i + 1]);
}
*/