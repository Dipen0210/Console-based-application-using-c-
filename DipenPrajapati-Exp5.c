
// ----------------------- Magnet Design Software -----------------------

#include<stdio.h>
#include<conio.h>
#define Bg 0.3
#define Lg 0.006
#define Ag 0.0025
#define Cl 2
	float airgapflux();
	float areaofmagnet(float);
	float mmfofairgap();
	float totalmmf(float);
	float lengthofmagnet(float,float);

float airgapflux()
{
	float phi;
	phi = Bg*Ag;
	return phi;
}
float areaofmagnet(float B)
{
	float area;
	area = (Cl*(airgapflux()))/B;
	return area;
}
float mmfofairgap()
{
	float mmf;
	mmf = 800000*Bg*Lg;
	return mmf;
}

float totalmmf(float P)
{
	float Totalmmf;
	Totalmmf = mmfofairgap()+(mmfofairgap()*P)/100;
	return Totalmmf;	
}

float lengthofmagnet(float H,float x)
{

	float lm;
	lm = (x*1000)/H;
	return lm;
}

float main()
{
	float B,H,P;
	printf("enter the value of flux density in wb/m2: ");
	scanf("%f",&B);
	printf("enter the value of mmf in A/m: ");
	scanf("%f",&H);
	printf("\n Air gap of flux is %f wb ",airgapflux());
	printf("\n Area of the magnet is %f m2 ",areaofmagnet(B));
	printf("\n Air gap mmf is %f A/m ",mmfofairgap());
	printf("\n enter the value of  iron parts taken as percentage of airgap mmf: ");
	scanf("%f",&P);
	printf("\n Area of the magnet is %f m2 ",totalmmf(P));
	printf("\n length of magnet is %1.0f mm",lengthofmagnet(H,totalmmf(P)));
	getch();
}

