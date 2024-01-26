#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <conio.h>
#define PI 3.141593
#define CARPAN PI/180
#include <string>
#include <process.h>
using namespace std;
float f(float x)
{
	return pow(x,5)-pow(x,4)-pow(x,3)-2*pow(x,2);
}
float df(float x)
{
	return 5*pow(x,4)-4*pow(x,3)-3*pow(x,2)-4*x;
}
void Program1()
{
double j=0; 
char inf[10]="INFINITY";
	cout<<"   Problem 1\n";
	cout<<"   ----------------\n";
	cout<<"\n";
	cout<<"   0 Dereceden 90 dereceye kadar a��lar�n onar artanl� olarak sin, cos, tan, cotan, degerlerini i�eren bir matrisi olu�turan C program�\n";
	cout<<"\n";
cout<<"\t A��: \t Sin: \t\t Cos: \t\t Tan: \t\t Cotan: \t \n";
for(float i=0;i<=90;i+=10)
{
	j=i*CARPAN;
	if(i==0)
	{
		printf("\t %0.0f \t %0.6f \t %0.6f \t %0.6f \t %s \n",i,sin(j),cos(j),tan(j),inf);
	}
	else if(i==90)
	{
		printf("\t %0.0f \t %0.6f \t %0.6f \t %s \t %0.6f \n",i,sin(j),cos(j),inf,1/tan(j));
	}
	else
	{
		printf("\t %0.0f \t %0.6f \t %0.6f \t %0.6f \t %0.6f \n",i,sin(j),cos(j),tan(j),1/tan(j));
	}	
}
	cout<<"\n";
	cout<<"\n";
}
void Program2()
{	
cout<<"   Problem 2\n";
cout<<"   ----------------\n";
cout<<"\n";
cout<<"   y=(x^5+4)/(x^3+2) fonsiyon degerlerini x=(-40,40) aral��� i�in birer artimla hesaplayan ve bu aral�k i�in\n";
cout<<"   fonksiyonun  maximum ve minimum degerlerini bulan C program�\n";
	cout<<"\n";
	double y=0;
	int x=0;
	double deger[81];
	string secim;
	cout<<" x=(-40,40) Aral���nda y degerleri goruntulensin mi? (e/h): ";
	cin>>secim;
	cout<<"\n";
	cout<<" �stenilen aral�kta y de�erleri: \n";
	cout<<" -----------------------------------\n";
	for(int i=-40;i<=40;i++)
	{
			for(i;i<41;i++)
			{
				for(i;i<41;i++)
				{
					y=(pow(i,5)+4)/(pow(i,3)+2);
					deger[x]=y;
					if(secim=="e"||secim=="E")
					{
					printf("(X=%d y=%0.7f)\t",i,deger[x]);
					}
					x++;		
				}
			cout<<"\n";	
			double enbuyuk=deger[0];
			double enkucuk=deger[0];
			int n=sizeof(deger)/sizeof(deger[0]);
			for(int ii;ii<n;ii++)
			{
				if(deger[ii]<enkucuk)
				{
					enkucuk=deger[ii];
				}
			}
				for(int ii;ii<n;ii++)
			{
				if(deger[ii]>enbuyuk)
				{
					enbuyuk=deger[ii];
				}
			}
			cout<<"\n";
			cout<<"En buyuk deger X=-40 i�in =>"<<enbuyuk<<"\n";
			cout<<"En kucuk deger X=1   i�in =>"<<enkucuk<<"\n";		
		}	
}
	cout<<"\n";
	cout<<"\n";	
}
void Program3()
{
cout<<"   Problem 3\n";
cout<<"   ----------------\n";
cout<<"\n";
cout<<"   Bir kare matrisin esas k��egeni �zerindeki elemanlar�n�n toplam�n� ve di�er k��egeni �zerindeki\n";
cout<<"   elemanlar�n�n �arp�m�n� en az i�lem say�s� ve en az �evrimle hesaplatacak bir C program� yaz�n�z...\n";

int matris[5][5]={26,18,-3,27,15,66,-46,89,-13,34,76,12,95,82,34,-1,22,-56,13,42,89,90,-83,7,5};
int toplam=0;
int y=4;
int carpim=1;
cout<<"\n";
for(int i=0;i<5;i++)
{
	cout<<"   |\t";
	for(int j=0;j<5;j++)
	{
		cout<<matris[i][j]<<"   \t";	
	}
	toplam+=matris[i][i];
	cout<<"   |\n";
}
cout<<"\n";
for(int x=0;x<5;x++)
{	
	carpim*=matris[x][y];
	y--;
}
cout<<"   Matrisi i�in esas k��egen �zerindeki elemanlar�n toplam� = "<<toplam<<"\n";
cout<<"   Di�er k��egen �zerindeki elemanlar�n �arp�m� = "<<carpim<<"\n";
cout<<"\n";
cout<<"\n";	
}
int program4()
{
	cout<<"   Problem 2\n";
	cout<<"   ----------------\n";
	cout<<"\n";
	cout<<"   y=(x^2)/(x+1) ve y=(x^3)/(x^3+2) fonksiyonlar�n�n varsa kesim noktalar�ndan birini bulan C program�\n";
	cout<<"\n";
	int itr,maxitr=1000;
	float h,x0,x1,hata=0.001;
	float sonuc=0;
	cout<<"   X0 Girin: ";
	cin>>x0;
	cout<<"   Epsilon degeri girin: ";
	cin>>hata;
	cout<<"\n";
	for(itr=1;itr<=maxitr;itr++)
	{
		h=f(x0)/df(x0);
		x1=x0-h;
		printf("   Tahmin %3d, Fonk.De�eri= %9.5f \n",itr,x1);
		if(fabs(h)<hata)
		{
			printf("   Newton Raphson metodu %3d tahmin ile sonucu %9.5f olarak buldu \n",itr,x1);
	   		sonuc=f(x1);
			printf("   Bu de�er fonksiyonu %f de�erine g�t�r�yor.\n",sonuc);
			return 0;
		}
		x0=x1;
	}
	printf("   Gerekli ��z�m yak�nsam�yor veya tahmin say�s�  yetersiz\n");
	return 1;
	cout<<"\n";
	cout<<"\n";	
}
	float primHesapla(float satismik)
{
	float prim=0;
	if(satismik<=50)
	{
		cout<<"   Sat�� eleman�n�n yapt��� ilk 50 par�al�k k�sm� i�in prim 1.5$\n";
		prim += satismik*1.5;
		printf("   Hesaplanan Prim = %0.6f$",prim);
	}
	else if(satismik<=100)
	{	
		cout<<"   Sat�� eleman�n�n yapt��� ilk 50 par�al�k k�sm� i�in prim 1.5$\n";
		prim += 50*1.5+(satismik-50)*2;
		cout<<"   Geri Kalan "<<(satismik-50)<<" K�sm� i�in ise 2$'d�r\n";
		printf("   Hesaplanan Prim = %0.6f$",prim);
	}
	else if(satismik >100)
	{
		cout<<"   Sat�� eleman�n�n yapt��� ilk 50 par�al�k k�sm� i�in prim 1.5$\n";
		cout<<"   Geri Kalan "<<"50 K�s�m i�in ise 2$'d�r\n";
		if(satismik>50)
		{	
		cout<<"   Geri Kalan "<<(satismik-150)<<" par�al�k K�sm� i�in ise 2.5$'d�r\n";
		}
		else
		{
		cout<<"   Geri Kalan "<<(satismik-50)<<" par�al�k K�sm� i�in ise 2$'d�r\n";
		}
		prim+= 50*1.5+50*2+(satismik-100)*2.5;
		printf("   Hesaplanan Prim = %0.6f$",prim);	
	}
}
void program5()
{
	float SatisMiktar=0;
	cout<<"   Problem 5\n";
	cout<<"   ----------------\n";
	cout<<"   Bir sat�� dan��man� a�a��daki kurallara g�re prim almaktad�r.\n";
	cout<<"   Sat�� <= 50 ise Prim = Sat�� * 1.5$.\n";
	cout<<"   Sat�� <= 100 ise Prim = 50 * 1.5$ + (Sat�� - 50) * 2$.\n";
	cout<<"   Sat�� >100 ise Prim = 50 * 1.5$ + 50 * 2$ + (Sat��-100) * 2.5$";
	cout<<"\n";
	cout<<"   Bu kurallara g�re sat�� eleman�n�n alaca�� primi hesaplayan C program�...\n";
	cout<<"\n";
	cout<<"\n";
	cout<<"   Hesaplamalar\n";
	cout<<"   -----------------\n";
	cout<<"   Sat�� Miktar�n� Girin: ";
	cin>>SatisMiktar;
	cout<<"\n";
	primHesapla(SatisMiktar);
	cout<<"\n";
	cout<<"\n";	
}
main()
{
menu:
system("cls"); 
setlocale(LC_ALL, "Turkish");
int secim=0;
cout<<"\n";
cout<<"\t\t\t\t Gazi �niversitesi\n";
cout<<"\t\t\t\t---------------------------------------------------------\n";
cout<<"\t\t\t\t|\t\t\tALGOR�TMALAR\t\t\t|\n";
cout<<"\t\t\t\t|\t\t\t     ve     \t\t\t|\n";
cout<<"\t\t\t\t|\t     B�G�SAYAR PROGRAMCILI�INA G�R��\t\t|\n";
cout<<"\t\t\t\t---------------------------------------------------------\n";
cout<<"\n";
cout<<"\n";
cout<<"\t\t\t\t\t_______Herhangi Bir Tu�a Bas�n�z______\t\t\t\n";
getch();
system("cls");
cout<<"\n";
cout<<"   PROJE MEN�S�\n";
cout<<"  ----------------\n";
cout<<"  1< 0 Dereceden 90 dereceye kadar a��lar�n onar artanl� olarak sin, cos, tan, cotan, degerlerini i�eren bir matrisi olu�turan C program�\n";
cout<<"  2< y=(x^5+4)/(x^3+2) fonsiyon degerlerini x=(-40,40) aral��� i�in birer artimla hesaplayan ve bu aral�k i�in fonksiyonun  maximum ve minimum degerlerini bulan C program�\n";
cout<<"  3< Bir kare matrisin esas k��egeni �zerindeki elemanlar�n toplam�n� ve di�er k��egen �zerindeki elemanlar�n �arp�m�n� en az islem say�s� ve en az cevrimle hesaplayan C program�\n";
cout<<"  4< y=(x^2)/(x+1) ve y=(x^3)/(x^3+2) fonksiyonlar�n�n varsa kesim noktalar�ndan birini bulan C program�\n";
cout<<"  5< Sat�� eleman� prim hesaplayan C program�\n";
cout<<"  6< Gelistirilen kod ile ilgili aciklamalar\n";
cout<<"\n";
cout<<">>> Se�iminiz.... ";
cin>>secim;
string secim2;
switch(secim){
	case 1: 
	{
			program1:
			system("cls"); 
			Program1();
			cout<<"   Se�iminiz (T=Tekrar Hesapla/M=Men�/C=��k��.)";
			cin>>secim2;
			if(secim2=="T"||secim2=="t")
			{
				goto program1;
			}
				if(secim2=="M"||secim2=="m")
			{
				goto menu;
			}
				if(secim2=="C"||secim2=="c")
			{
				exit(0);
			}
			break;	
	}
	case 2: 
	{
			system("cls"); 
			program2:
			Program2();
			cout<<"   Se�iminiz (T=Tekrar Hesapla/M=Men�/C=��k��.)";
			cin>>secim2;
			if(secim2=="T"||secim2=="t")
			{
				goto program2;
			}
				if(secim2=="M"||secim2=="m")
			{
				goto menu;
			}
				if(secim2=="C"||secim2=="c")
			{
				exit(0);
			}
			break;	
	}
	case 3: 
	{
			system("cls");
			program3: 
			Program3();
			cout<<"   Se�iminiz (T=Tekrar Hesapla/M=Men�/C=��k��.)";
			cin>>secim2;
			if(secim2=="T"||secim2=="t")
			{
				goto program3;
			}
				if(secim2=="M"||secim2=="m")
			{
				goto menu;
			}
				if(secim2=="C"||secim2=="c")
			{
				exit(0);
			}
			break;	
	}
		case 4: 
	{
			system("cls"); 
			program4:
			program4();
			cout<<"   Se�iminiz (T=Tekrar Hesapla/M=Men�/C=��k��.)";
			cin>>secim2;
			if(secim2=="T"||secim2=="t")
			{
				goto program4;
			}
				if(secim2=="M"||secim2=="m")
			{
				goto menu;
			}
				if(secim2=="C"||secim2=="c")
			{
				exit(0);
			}
			break;
	}
			case 5: 
	{
			system("cls");
			program5:
			program5();
			cout<<"   Se�iminiz (T=Tekrar Hesapla/M=Men�/C=��k��.)";
			cin>>secim2;
			if(secim2=="T"||secim2=="t")
			{
				goto program5;
			}
				if(secim2=="M"||secim2=="m")
			{
				goto menu;
			}
				if(secim2=="C"||secim2=="c")
			{
				exit(0);
			}
			break;	
	}
		case 6: 
	{
	aciklamamenu:
	system("cls");
	string secim1;
	cout<<"\n";
	cout<<"\n";
	cout<<"\n";
	cout<<"\t\t\t\t ------------ \t ------------ \t ------------\n";
	cout<<"\t\t\t\t | PROBLEM 1 | \t | PROBLEM 2 | \t | PROBLEM 3 | \n";
	cout<<"\t\t\t\t ------------ \t ------------ \t ------------\n";
	cout<<"\n";
	cout<<"\n";
	cout<<"\n";
	cout<<"\t\t\t\t ------------ \t ------------ \t ------------\n";
	cout<<"\t\t\t\t | PROBLEM 4 | \t | PROBLEM 5 | \t | G) GENEL | \n";
	cout<<"\t\t\t\t ------------ \t ------------ \t ------------\n";
	cout<<"\n";
	cout<<"\n";
	cout<<"\n";
	cout<<"\n";
	cout<<"\n";
	cout<<"\n";
	cout<<"\t\t\t L�TFEN A�IKLAMASINI G�R�NT�LEMEK ���N �STED���N�Z B�L�M� SE��N�Z \n";
	cout<<"\t\t\t\t\t   ANA MEN� ���N M G�R�N�Z  \n";
	cin>>secim1;
	if(secim1=="m"||secim1=="M")
	{
		goto menu;
	}
	if(secim1=="1")
	{
				system("cls");
				cout<<"  PROBLEM 1 ���N A�IKLAMALAR\n";
				cout<<"  --------------------------\n";
				cout<<"  A��klamalar: �stenilen tabloyu olu�turabilmek i�in double tan�ml� j de�i�keni tan�mland�.\n";
				cout<<"               A��lar� hesaplatabilmek i�in math.h k�t�phanesi programla eklendi.\n";
				cout<<"               For d�ng�s� kullan�larak 0-90 derece aras�nda 10 luk art�m ile a��lar d�nd�r�ld�.\n";
				cout<<"               Tabloyu olu�turabilmek i�in formatl� bi�imde karakterler d�zenlendi.\n";
				cout<<"               INFINITY ibaresi i�in string metodu kullan�ld�.\n";
				cout<<"\n";
				cout<<"   Se�iminiz (A=Ana Men�/M=Men�/C=��k��.)\n";
				cin>>secim2;
			if(secim2=="M"||secim2=="m")
			{
				goto aciklamamenu;
			}
				if(secim2=="A"||secim2=="a")
			{
				goto menu;
			}
				if(secim2=="C"||secim2=="c")
			{
				exit(0);
			}	
	}
	if(secim1=="2")
	{
			system("cls");
				cout<<"  PROBLEM 2 ���N A�IKLAMALAR\n";
				cout<<"  --------------------------\n";
				cout<<"  A��klamalar: Fonksiyonun de�erlerini tutan bir double degerler[81] dizisi tan�mland�\n";
				cout<<"               Aral��� hesaplatabilmek i�in int x de�i�keni tan�mland�.\n";
				cout<<"               For d�ng�s� kullan�larak aral�klar i�in y de�erleri tan�mland�\n";
				cout<<"               Bu y de�erleri int y de�i�keninde tutuldu.\n";
				cout<<"               son olarak diziye aktard���m�z y de�erleri yeni bir for d�g�s� ile ekrana yazd�r�rld�.\n";
				cout<<"\n";
				cout<<"   Se�iminiz (A=Ana Men�/M=Men�/C=��k��.)\n";
				cin>>secim2;
			if(secim2=="M"||secim2=="m")
			{
				goto aciklamamenu;
			}
				if(secim2=="A"||secim2=="a")
			{
				goto menu;
			}
				if(secim2=="C"||secim2=="c")
			{
				exit(0);
			}	
	}
	if(secim1=="3")
	{
			system("cls");
				cout<<"  PROBLEM 3 ���N A�IKLAMALAR\n";
				cout<<"  --------------------------\n";
				cout<<"  A��klamalar: 5x5 b�y�kl���nde int matris tan�mlanm��t�r\n";
				cout<<"               Bu matrise say�lar program�n i�ine g�m�l� �ekilde eklenmi�tir\n";
				cout<<"               2 Adet i� i�w For d�ng�s� kullan�larak bu dizi ekrana yazd�r�lm��t�r.\n";
				cout<<"               Esas k��egendeki say�lar int toplam de�i�keni tan�mlanarak bu de�i�kende tutulmu�tur.\n";
				cout<<"               Ters k��egendeki �arp�mlar ayr� bir for d�ng�s� i�erisinde hesaplanm��t�r.\n";
				cout<<"\n";
				cout<<"   Se�iminiz (A=Ana Men�/M=Men�/C=��k��.)\n";
				cin>>secim2;
			if(secim2=="M"||secim2=="m")
			{
				goto aciklamamenu;
			}
				if(secim2=="A"||secim2=="a")
			{
				goto menu;
			}
				if(secim2=="C"||secim2=="c")
			{
				exit(0);
			}	
	}
	if(secim1=="4")
	{
			system("cls");
				cout<<"  PROBLEM 4 ���N A�IKLAMALAR\n";
				cout<<"  --------------------------\n";
				cout<<"  A��klamalar: Foksiyonun k�klerini bulabilmek i�in fonk ad�nda bir fonksiyon tan�mlanm��t�r.\n";
				cout<<"               Bu fonksiyon i�erisinde fonksiyonun de�erleri hesaplanm��t�r.\n";
				cout<<"               Program4 fonksiyonu i�erisinde fonk fonksiyonu �a��r�lm�� ve newton raphson metodu uygulanm��t�r.\n";
				cout<<"               Kullan�c� ba�lang�� de�eri ve epsilon de�erini kendisinin girmesi sa�lanm��t�r.\n";
				cout<<"               Bu de�erler double epsilon x0 de�i�kenlerinde tutulmu�tur.\n";
				cout<<"\n";
				cout<<"   Se�iminiz (A=Ana Men�/M=Men�/C=��k��.)\n";
				cin>>secim2;
			if(secim2=="M"||secim2=="m")
			{
				goto aciklamamenu;
			}
				if(secim2=="A"||secim2=="a")
			{
				goto menu;
			}
				if(secim2=="C"||secim2=="c")
			{
				exit(0);
			}	
	}
	if(secim1=="5")
	{
			system("cls");
				cout<<"  PROBLEM 5 ���N A�IKLAMALAR\n";
				cout<<"  --------------------------\n";
				cout<<"  A��klamalar: Kullan�c�dan al�nan sat�� miktar� satiMiktari de�i�keninde tutulmu�tur.\n";
				cout<<"               Verilen kriterlere uygun prim miktar�n� hesaplayan float PrimHesala fonksiyonu yarat�lm��t�r.\n";
				cout<<"               Kullan�c�dan al�nanv verilere g�re prim hesaplamak i�in bu fonsiyon program5 fonskiyonu i�erisinde �a��r�lm��t�r.\n";
				cout<<"               Son olarak hesaplanan prim miktar� ekrana yazd�r�lm��t�r.\n";
				cout<<"\n";
				cout<<"   Se�iminiz (A=Ana Men�/M=Men�/C=��k��.)\n";
				cin>>secim2;
			if(secim2=="M"||secim2=="m")
			{
				goto aciklamamenu;
			}
				if(secim2=="A"||secim2=="a")
			{
				goto menu;
			}
				if(secim2=="C"||secim2=="c")
			{
				exit(0);
			}		
	}
	if(secim1=="G"||secim1=="g")
	{
			system("cls");
				cout<<"  GENEL A�IKLAMALAR\n";
				cout<<"  --------------------------\n";
				cout<<"  -------->>>: Program�n genelinde her problem ayr� bir fonksiyon olarak ana program�n i�erisinde �a��r�lm��t�r.\n";
				cout<<"               Se�imler switch case yap�s� kullan�larak kontrol edilmi�tir.\n";
				cout<<"               Bu programda C++ ve C komutlar� kar���k kullan�lm��t�r.\n";
				cout<<"\n";
				cout<<"   Se�iminiz (A=Ana Men�/M=Men�/C=��k��.)\n";
				cin>>secim2;
			if(secim2=="M"||secim2=="m")
			{
				goto aciklamamenu;
			}
				if(secim2=="A"||secim2=="a")
			{
				goto menu;
			}
				if(secim2=="C"||secim2=="c")
			{
				exit(0);
			}	
	}		
			break;
		}
	}
}
