#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
bool FIO = 1;
int T;
int n , m , v[100005] , a[100005] , d[100005] , V , L , p[100005] , e[100005];
double getD(int d , int v , int a , int V)
{
	return double(V*V-v*v)/2.0/a + d;
}
int main()
{
	if(FIO)
	{
		freopen("detect.in" , "r" , stdin);
		freopen("detect.out" , "w" , stdout);
	}
	cin >> T;
	while(T --)
	{
		cin >> n >> m >> L >> V;
		bool flaga0 = 1 , flagan = 0 , ov;
		int maxd = 0 , cnto = 0 , D , vD , A , e1;
		double E;
		while(n --)
		{
			ov = 0;
			cin >> D >> vD >> A;
			if(A > 0)
			{
				ov = 1;
				E = getD(D , vD , A , V);
				if(E - D < 0)
				{
					e1 = D;
				}
				else
				{
					e1 = int(E) + 1;
				}
				if(e1 > L)
				{
					ov = 0;
					continue;
				}
				//cout << e1 << endl;
			}
			else if(A < 0)
			{
				ov = 1;
				flaga0 = 0;
				flagan = 1;
				E = getD(D , vD , A , V);
				if(E < D)
				{
					ov = 0;
					continue;
				}
			}
			else if(vD > V)
			{
				ov = 1;
			}
			if(ov)
			{
				cnto ++;
				if(A > 0)
			    	d[cnto] = e1;
			    else
			    	d[cnto] = D;
				v[cnto] = vD;
				a[cnto] = A;
			}
		}
		for(int i = 1 ; i <= m ; i ++)
		{
			cin >> p[i];
		}
		if(flaga0)
		{
			sort(d + 1 , d + 1 + cnto);
			int s = 0;
			//cout << p[m] << "  " << d[cnto-1] << endl;
			//cout << V << endl;
			for(int i = cnto ; i >= 1 ; i --)
			{
				if(d[i] <= p[m])
				{
					s = i;
					break;
				}
			}
			if(s == 0)
			{
				m += 1;
			}
			cout << s << " " << m - 1 << endl;
		}
	}
	return 0;
}