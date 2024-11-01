#include <iostream>
#include <queue>
#include <list>
#include <algorithm>
#include <cstdio>
using namespace std;

#define MAX 100010

int r[MAX],n;
list<int>unused;
priority_queue<int,vector<int>,greater<int>>used;

int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i = 0;i<n;i++)
		cin >> r[i];

	sort(r,r+n);
	for(int i = 0;i<n;i++)
		unused.push_back(r[i]);

	auto it=unused.begin();
	auto nt=it;
	nt++;
	while(nt!=unused.end()&&unused.size()>2)
	{
		if(!used.empty())
		{
			if(*it>used.top())
			{
				used.pop();
				used.push(*it);
				unused.erase(it);
				it=nt;
				nt++;
				continue;
			}
		}
		if(*nt>*it)
		{
			used.push(*nt);
			unused.erase(it);
			it=nt;
			if(nt==unused.begin())
			{
				nt++;
				unused.erase(it);
				it=nt;
				nt++;
			}
			else
			{
				nt--;
				unused.erase(it);
				it=nt;
				nt++;
			}
			continue;
		}
		it++;
		nt++;
	}
	if(unused.size()==2)
	{
		it=unused.begin();
		if(!used.empty())
		{
			if(*it>used.top())
			{
				used.pop();
				used.push(*it);
				unused.erase(it);
				goto end;
			}
		}
		nt=it;
		nt++;
		if(*nt>*it)
		{
			used.push(*nt);
			unused.erase(it);
			unused.erase(nt);
		}
	}
	end:;
	if(unused.size()==1)
	{
		it=unused.begin();
		if(!used.empty())
		{
			if(*it>used.top())
			{
				used.pop();
				used.push(*it);
				unused.erase(it);
			}
		}
	}
	cout << used.size()+unused.size() << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
