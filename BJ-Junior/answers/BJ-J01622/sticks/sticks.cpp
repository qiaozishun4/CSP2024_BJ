#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	short T;
	scanf("%hd",&T);
	int n;
	short s[10]={6,2,5,5,4,5,6,3,7,6};
	for(int i=0;i<T;i++)
	{
		scanf("%d",&n);
		if(n==1)
		{
			cout<<-1<<endl;
			continue;
	    }
	    int div=1,ct=0,cur=1;
	    while(1)
	    {
			div=1;
			ct=0;
			//printf("while\n");
	        while(cur/div)
	        {
				//printf("n=%d,div=%d,%d\n",n,div,n,div);
			    ct+=s[(cur/div)%10];
			    //cout<<ct<<endl;
			    div*=10;
		    }
		    if(ct==n)
		    {
				printf("%d\n",cur);
				break;
			}
			cur++;
		}
		
	    
	    
	}
	return 0;
}
