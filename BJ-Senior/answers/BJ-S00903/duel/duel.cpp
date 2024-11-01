#include<cstdio>
#include<iostream>
using namespace std;


int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","r",stdout);
	int n,r[n],c=0;
	cin>>n;
	for(int i=0;n<n;i++)
    	{
    		cin>>r[i];
    	}
    	for(int i=0;i<n;i++)
    	{
    		if(r[i]!=0)
    		{
		    for(int j=0;j<n;j++)
		    {
		    	if(j!=i && r[j]!=0)
		    	{
		    	    if(r[j]<r[i])
		    	    {
		    	 	r[j]=0;
		    	 	r[i]=0;
		    	 	c+=1;
		    	 	break;
		    	    }
		    	}
		    }
    		}
	}
    	cout<<c;

    	return 0;
}
