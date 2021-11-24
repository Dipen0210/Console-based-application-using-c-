#include <iostream>

using namespace std;

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

int main()
{
	float B,H,P;
	cout<< "enter the value of flux density in wb/m2: ";
	cin>>B;
	cout<< "enter the value of mmf in A/m: ";
	cin>>H;
	cout<<"\n Air gap of flux is wb "<< airgapflux();
	cout<<"\n Area of the magnet is m2 "<< areaofmagnet(B);
	cout<<"\n Air gap mmf is A/m "<< mmfofairgap();
	cout<<"\n enter the value of iron parts taken as percentage of airgap mmf:";
	cin>>P;
	cout<<"\n Area of the magnet is m2 "<< totalmmf(P);
	cout<<"\n length of magnet is mm "<< lengthofmagnet(H,totalmmf(P));
	return 0;
}
