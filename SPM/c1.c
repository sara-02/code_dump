#include <stdio.h>
#include <math.h>

int main(void) {
	float e,d;
	int s; int i;
	printf("For the fifteen atrributes\n");
	float a,EAF=1;
	for(i=1;i<=15;i++)
	{
		printf("Enter the attribute between 0.1-1\n");
		scanf("%f",&a);
		EAF=EAF*a;
	}
	printf("Enter size\n");
	scanf("%d",&s);
	if(s<=50)
	{
		e=2.4*pow(s,1.05);
		e=e*EAF;
		d=2.5*pow(e,0.38);
	}
	else if(s>50 && s<=300)
	{
		e=3*pow(s,1.12);
		e=e*EAF;
		d=2.5*pow(e,0.35);
	}
	else
	{
		e=3.6*pow(s,1.20);
		e=e*EAF;
		d=2.5*pow(e,0.32);
	}
	printf("Effort %f\n",e);
	printf("Duration %f\n",d);
	// yourcode goes here
	return 0;
}

