#include <bits/stdc++.h>
using namespace std;
int stick [10] = {6,2,5,5,4,5,6,3,7,6};
int tj(int n)
{
    int ans = 0;
	while (n!=0)
    {
        ans+=stick[n%10];
        n/=10;
    }
    return ans;
}
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int t;
	cin >>t;
	for (int i = 1;i<=t;i++)
    {
        int n;
        cin >>n;
        if (n<2)
        {
            cout <<-1 <<endl;
            continue;
        }
        if (n%7==0)
        {
			for (int j = n;j>0;j-=7)
			{
				cout <<'8';
			}
			cout <<endl;
		}else if (n%7==1)
		{
			cout <<"10";
			for (int j= n-8;j>0;j-=7)
			{
				cout <<'8';
			}
			cout <<endl
		}
        unsigned long long j = pow(10,int((n-1)/7));
        while (tj(j)!=n)
        {
            j++;
        }
        cout <<j <<endl;
    }
    fclose(stdin);
    fclose(stdout);
}
