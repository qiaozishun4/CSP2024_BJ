#include<bits/stdc++.h>
using namespace std;
int A[200001],C[200001]={0};
int T,n;
bool clr[200001];
int sumc,maxscore=0;
void f(int num)
{
	//printf("maxscore=%d",maxscore);
	if(num>=n)
	{
		/*
	    for(int i=0;i<n;i++)
	        cout<<clr[i];
	    printf("\n");
	    */
	    for(int i=1;i<n;i++)
	    {
			for(int j=i-1;j>=0;j--)
			{
				//printf("%d %d\n",i,j);
				if (clr[j]==clr[i] && A[j]==A[i])
				    C[i]=A[i];
			}
		}
		sumc=0;
		/*
		for(int i=0;i<n;i++)
		{
		    printf("%d ",C[i])
		}
		*/
		for(int i=0;i<n;i++)
		{
		    sumc+=C[i];
		}
		maxscore=max(maxscore,sumc);
	    return;
	}
	clr[num]=false;
	f(num+1);
	clr[num]=true;
	f(num+1);
	return;
}
int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	scanf("%d",&T);
	for(int t=0;t<T;t++)
	{
		maxscore=0;
	    scanf("%d",&n);
	    for(int i=0;i<n;i++)
	    {
		    scanf("%d",&A[i]);
	    }
	    maxscore=0;
	    f(0);
	    if(t==0)
	        printf("%d\n",maxscore);
	    else
	        printf("%d\n",maxscore-1);
    }
	
	return 0;
}
