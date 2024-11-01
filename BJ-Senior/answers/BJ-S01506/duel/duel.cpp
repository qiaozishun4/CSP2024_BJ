#include <stdio.h>
#define N 100000

FILE *fin=fopen("duel.in","r");
FILE *fout=fopen("duel.out","w");
int n,list[N],sum=1,aa[N],p=0;

void jh(int *a,int *b)
{
	int c;
	c=*a;
	*a=*b;
	*b=c;

}

int main()
{
	aa[0]=1;
	fscanf(fin,"%d",&n);
	for (int i=0 ; i<n ; i++){
		fscanf(fin,"%d",&list[i]);
	}






	for (int i=0 ; i<n ; i++){
		for(int j=0 ; j<n-i-1 ; j++){
			if(list[j]<list[j+1]) jh(&list[j],&list[j+1]);
		}
	}	

	if(list[0]==list[n-1]) {
		fprintf(fout,"0\n");
		return 0;
	}


	for (int i = 1; i < n; ++i)
	{
		if(list[i]<list[i-1]){
			p++;
			for(int j=0;j<p;j++){
				if(aa[j]){
					aa[j]--;
					break;
				}
				if(j==p-1){
					sum++;
					aa[p]++;
				}
			}
		}
		else if(list[i]==list[i-1]){
			for(int j=0;j<=p;j++){
				if(j==p){
					sum++;
					aa[p]++;
					break;
				}
				if(aa[j])
				{
					aa[j]--;
					break;
				}

			}
		}
		
	}
	fprintf(fout,"%d\n",sum);



	return 0;
}