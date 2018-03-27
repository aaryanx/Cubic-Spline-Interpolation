/*
In two-dimensions, two cubic spline functions can be used together to form a parametric
representation of a complicated curve that turns and twists.

You can fit x = S(t) and y = S'(t), where S and S' are natural cubic spline interpolants.
S and S' give a parametric representation of the curve.

Using at most 20 knots and cubic splines, plot on a computer plotter an outline of your own
SIGNATURE.
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

void spline(double *a, double *t, int samples)
{
	int n, m;
	double h[1000], alpha[1000], l[1000], u[1000], z[1000], c[1000], b[1000], d[1000];
	for(n=0; n<samples-1; n++)
	{
		h[n]=*(t+n+1)-*(t+n);
	}
	for(n=0; n<samples; n++)
	{
		alpha[n]=3/h[n]*(*(a+n+1)-*(a+n))-3/h[n-1]*(*(a+n)-*(a+n-1));
	}
	l[0]=1;
	u[0]=0;
	z[0]=0;
	for(n=1; n<samples-1; n++)
	{
		l[n]=2*(*(t+n+1)-*(t+n-1))-h[n-1]*u[n-1];
		u[n]=h[n]/l[n];
		z[n]=(alpha[n]-h[n-1]*z[n-1])/l[n];
	}
	l[samples-1]=1;
	z[samples-1]=0;
	c[samples-1]=0;
	for(n=samples-2; n>=0; n--)
	{
		c[n]=z[n]-u[n]*c[n+1];
		b[n]=(*(a+n+1)-*(a+n))/h[n]-(h[n]*(c[n+1]+2*c[n])/3);
		d[n]=(c[n+1]-c[n])/3*h[n];
	}
	for(n=0; n<samples-1; n++)
	{
		for(m=0; m<20; m++)
		{
			//printf("%lf %lf %lf %lf \n", *(a+n), b[n], c[n], d[n]);
			printf("%lf \n", *(a+n)+(0.05*m)*b[n]+(pow(0.05*m, 2))*c[n]+(pow(0.05*m, 3))*d[n]);
		}
		printf("\n");
	}
}

main()
{
	int samples, c;
	printf("\n-------------------------\n MID SEM ASSIGNMENT 2015\n-------------------------\n\nChoose the question no.: \n1. Spiral\n2. Signature \n(Press 1 or 2) \n");
	scanf("%d", &c);
	if(c==1)
	{
		int samples;
		double x[10]={1030, 1346, 1546, 1192, 638, 1007, 1769, 1015, 307, 1130};
		double y[10]={1200, 1075, 1391, 1675, 1191, 641, 916, 2000, 891, 216};
		double t[10]={0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
		samples=sizeof(x)/sizeof(double);
		spline(x, t, samples);
		printf("------------------------------------------------- \n \n");
		spline(y, t, samples);
        }
	else if(c==2)
	{
		double x[29]={21.73913, 108.695656, 132.60869, 217.39131, 169.56522, 219.56522, 226.08696, 243.47826, 332.6087, 326.08694, 382.6087, 404.34784, 439.13043, 489.13043, 510.86957, 484.78262, 439.13043, 502.17392, 615.2174, 545.65216, 608.6957, 623.913, 654.34784, 708.6957, 710.86957, 734.7826, 782.6087, 786.95654};


		double y[29]={101.85185, 314.81482, 107.40741, 190.74074, 133.33333, 124.07407, 188.88889, 129.62962, 127.77778, 194.44444, 200.0, 129.62962, 194.44444, 148.14815, 196.2963, 38.88889, 38.88889, 114.81481, 200.0, 138.88889, 120.37037, 192.59259, 131.48148, 192.59259, 137.03703, 194.44444, 196.2963};

		double t[29]={0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28};
		samples=sizeof(x)/sizeof(double);
		spline(x, t, samples);
		printf("------------------------------------------------- \n \n");
		spline(y, t, samples);
	}
	else
		printf("Invalid Option \n");
}
