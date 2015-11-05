#include <stdio.h>
#include <time.h>
#include <stdint.h>
#include IMPL

int main()
{
	uint64_t begin,end;
	unsigned long long int dt;
    double pi,times;
	FILE *fp=fopen("result.txt","w");
	
	dt=0x100000;
	for(dt=0x100000;dt<=0x40000000;dt<<=1)
	{
		begin=clock();
		pi=compute_pi(dt);
		end=clock();
		times = (double)(end - begin) / (CLOCKS_PER_SEC/1000);
		printf("dt = %lluM\n",(dt/(1<<20)));
		printf("pi = %f\n",pi);
		printf("time = %f\n",times);
		fprintf(fp,"%llu\t%f\t%f\n",(dt/(1<<20)),pi,times);
	}
	
	return 0;
}