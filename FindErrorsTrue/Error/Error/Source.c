#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

#define VAL_L 1.2

double FindError(double realR,double Rm,double realL, double l1)
{
	double dRm = fabs(realR - Rm);
	double dL1 = fabs(realL - l1);
	double LminusL1 =fabs(VAL_L - l1);
	return dRm / realR + dL1 / l1 + /* тут не ясно */dL1 / LminusL1;
}
double FindMid(double val [3])
{
	return (val[0] + val[1] + val[2]) / 3;
}
int main()
{
	for (int i = 0; i < 4; ++i)
	{
		double Rm[3] = { 0 }, l1[3] = { 0 }, Rx[3] = { 0 };
		printf("Enter Rm1,Rm2,Rm3:\n");
		scanf("%lf %lf %lf", Rm, Rm + 1, Rm + 2);
		printf("Enter l1[1],l1[2],l1[3]:\n");
		scanf("%lf %lf %lf", l1, l1 + 1, l1 + 2);
		double sumR = 0;
		for (int j = 0; j < 3; ++j)
		{
			Rx[j] = (Rm[j] * l1[j])*(VAL_L - l1[j]);
			
		}

		double realRm = FindMid(Rm);
		double realL = FindMid(l1);
		double eps[3] = { 0 };
		for (int j = 0; j < 3; ++j)
		{
			eps[j] =FindError(realRm, Rm[j], realL, l1[j]);
		}
		double realRx = FindMid(Rx);
		double dRx[3] = { 0 };
		for (int j = 0; j < 3; ++j)
		{
			dRx[j] = fabs(realRx - Rx[j]);
			printf("Rx[%i] = %lf,dRx[%i] = %lf,deRx[%i] = %lf  ,(formula)  %lf;\n", j + 1, Rx[j], j + 1, dRx[j], j + 1, fabs(dRx[j]) /Rx[j] , eps[j]);
		}
		printf("mid Rx = %lf,midEps = %lf, midDRx = %lf\n", realRx, FindMid(eps),FindMid(dRx));
	}
	return 0;
}