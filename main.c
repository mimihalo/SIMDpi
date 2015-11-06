#include <stdio.h>
#include <time.h>
#include <stdint.h>
#include <math.h>
#include IMPL

int main()
{
	uint64_t begin,end;
	unsigned long long int dt;
    double pi,times;
	double rpi=acos(-1.0);
	double err;
	FILE *fp=fopen("result.txt","w");
	
	dt=0x100000;
	for(dt=0x100000;dt<=0x40000000;dt<<=1)
	{
		begin=clock();
		pi=compute_pi(dt);
		end=clock();
		times = (double)(end - begin) / (CLOCKS_PER_SEC/1000);
		err = (pi-rpi)/rpi;
		printf("dt = %lluM\n",(dt/(1<<20)));
		printf("pi = %.10f\n",pi);
		printf("time = %f\n",times);
		printf("error rate = %.10e\n",err);
		fprintf(fp,"%llu\t%.10f\t%f\t%.16f\n",(dt/(1<<20)),pi,times,err);
	}
	
	return 0;
}