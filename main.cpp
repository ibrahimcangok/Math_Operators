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
	cout<<"   0 Dereceden 90 dereceye kadar açýlarýn onar artanlý olarak sin, cos, tan, cotan, degerlerini içeren bir matrisi oluþturan C programý\n";
	cout<<"\n";
cout<<"\t Açý: \t Sin: \t\t Cos: \t\t Tan: \t\t Cotan: \t \n";
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
cout<<"   y=(x^5+4)/(x^3+2) fonsiyon degerlerini x=(-40,40) aralýðý için birer artimla hesaplayan ve bu aralýk için\n";
cout<<"   fonksiyonun  maximum ve minimum degerlerini bulan C programý\n";
	cout<<"\n";
	double y=0;
	int x=0;
	double deger[81];
	string secim;
	cout<<" x=(-40,40) Aralýðýnda y degerleri goruntulensin mi? (e/h): ";
	cin>>secim;
	cout<<"\n";
	cout<<" Ýstenilen aralýkta y deðerleri: \n";
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
			cout<<"En buyuk deger X=-40 için =>"<<enbuyuk<<"\n";
			cout<<"En kucuk deger X=1   için =>"<<enkucuk<<"\n";		
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
cout<<"   Bir kare matrisin esas köþegeni üzerindeki elemanlarýnýn toplamýný ve diðer köþegeni üzerindeki\n";
cout<<"   elemanlarýnýn çarpýmýný en az iþlem sayýsý ve en az çevrimle hesaplatacak bir C programý yazýnýz...\n";

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
cout<<"   Matrisi için esas köþegen üzerindeki elemanlarýn toplamý = "<<toplam<<"\n";
cout<<"   Diðer köþegen üzerindeki elemanlarýn çarpýmý = "<<carpim<<"\n";
cout<<"\n";
cout<<"\n";	
}
int program4()
{
	cout<<"   Problem 2\n";
	cout<<"   ----------------\n";
	cout<<"\n";
	cout<<"   y=(x^2)/(x+1) ve y=(x^3)/(x^3+2) fonksiyonlarýnýn varsa kesim noktalarýndan birini bulan C programý\n";
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
		printf("   Tahmin %3d, Fonk.Deðeri= %9.5f \n",itr,x1);
		if(fabs(h)<hata)
		{
			printf("   Newton Raphson metodu %3d tahmin ile sonucu %9.5f olarak buldu \n",itr,x1);
	   		sonuc=f(x1);
			printf("   Bu deðer fonksiyonu %f deðerine götürüyor.\n",sonuc);
			return 0;
		}
		x0=x1;
	}
	printf("   Gerekli çözüm yakýnsamýyor veya tahmin sayýsý  yetersiz\n");
	return 1;
	cout<<"\n";
	cout<<"\n";	
}
	float primHesapla(float satismik)
{
	float prim=0;
	if(satismik<=50)
	{
		cout<<"   Satýþ elemanýnýn yaptýðý ilk 50 parçalýk kýsmý için prim 1.5$\n";
		prim += satismik*1.5;
		printf("   Hesaplanan Prim = %0.6f$",prim);
	}
	else if(satismik<=100)
	{	
		cout<<"   Satýþ elemanýnýn yaptýðý ilk 50 parçalýk kýsmý için prim 1.5$\n";
		prim += 50*1.5+(satismik-50)*2;
		cout<<"   Geri Kalan "<<(satismik-50)<<" Kýsmý için ise 2$'dýr\n";
		printf("   Hesaplanan Prim = %0.6f$",prim);
	}
	else if(satismik >100)
	{
		cout<<"   Satýþ elemanýnýn yaptýðý ilk 50 parçalýk kýsmý için prim 1.5$\n";
		cout<<"   Geri Kalan "<<"50 Kýsým için ise 2$'dýr\n";
		if(satismik>50)
		{	
		cout<<"   Geri Kalan "<<(satismik-150)<<" parçalýk Kýsmý için ise 2.5$'dýr\n";
		}
		else
		{
		cout<<"   Geri Kalan "<<(satismik-50)<<" parçalýk Kýsmý için ise 2$'dýr\n";
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
	cout<<"   Bir satýþ danýþmaný aþaðýdaki kurallara göre prim almaktadýr.\n";
	cout<<"   Satýþ <= 50 ise Prim = Satýþ * 1.5$.\n";
	cout<<"   Satýþ <= 100 ise Prim = 50 * 1.5$ + (Satýþ - 50) * 2$.\n";
	cout<<"   Satýþ >100 ise Prim = 50 * 1.5$ + 50 * 2$ + (Satýþ-100) * 2.5$";
	cout<<"\n";
	cout<<"   Bu kurallara göre satýþ elemanýnýn alacaðý primi hesaplayan C programý...\n";
	cout<<"\n";
	cout<<"\n";
	cout<<"   Hesaplamalar\n";
	cout<<"   -----------------\n";
	cout<<"   Satýþ Miktarýný Girin: ";
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
cout<<"\t\t\t\t Gazi Üniversitesi\n";
cout<<"\t\t\t\t---------------------------------------------------------\n";
cout<<"\t\t\t\t|\t\t\tALGORÝTMALAR\t\t\t|\n";
cout<<"\t\t\t\t|\t\t\t     ve     \t\t\t|\n";
cout<<"\t\t\t\t|\t     BÝGÝSAYAR PROGRAMCILIÐINA GÝRÝÞ\t\t|\n";
cout<<"\t\t\t\t---------------------------------------------------------\n";
cout<<"\n";
cout<<"\n";
cout<<"\t\t\t\t\t_______Herhangi Bir Tuþa Basýnýz______\t\t\t\n";
getch();
system("cls");
cout<<"\n";
cout<<"   PROJE MENÜSÜ\n";
cout<<"  ----------------\n";
cout<<"  1< 0 Dereceden 90 dereceye kadar açýlarýn onar artanlý olarak sin, cos, tan, cotan, degerlerini içeren bir matrisi oluþturan C programý\n";
cout<<"  2< y=(x^5+4)/(x^3+2) fonsiyon degerlerini x=(-40,40) aralýðý için birer artimla hesaplayan ve bu aralýk için fonksiyonun  maximum ve minimum degerlerini bulan C programý\n";
cout<<"  3< Bir kare matrisin esas köþegeni üzerindeki elemanlarýn toplamýný ve diðer köþegen üzerindeki elemanlarýn çarpýmýný en az islem sayýsý ve en az cevrimle hesaplayan C programý\n";
cout<<"  4< y=(x^2)/(x+1) ve y=(x^3)/(x^3+2) fonksiyonlarýnýn varsa kesim noktalarýndan birini bulan C programý\n";
cout<<"  5< Satýþ elemaný prim hesaplayan C programý\n";
cout<<"  6< Gelistirilen kod ile ilgili aciklamalar\n";
cout<<"\n";
cout<<">>> Seçiminiz.... ";
cin>>secim;
string secim2;
switch(secim){
	case 1: 
	{
			program1:
			system("cls"); 
			Program1();
			cout<<"   Seçiminiz (T=Tekrar Hesapla/M=Menü/C=Çýkýþ.)";
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
			cout<<"   Seçiminiz (T=Tekrar Hesapla/M=Menü/C=Çýkýþ.)";
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
			cout<<"   Seçiminiz (T=Tekrar Hesapla/M=Menü/C=Çýkýþ.)";
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
			cout<<"   Seçiminiz (T=Tekrar Hesapla/M=Menü/C=Çýkýþ.)";
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
			cout<<"   Seçiminiz (T=Tekrar Hesapla/M=Menü/C=Çýkýþ.)";
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
	cout<<"\t\t\t LÜTFEN AÇIKLAMASINI GÖRÜNTÜLEMEK ÝÇÝN ÝSTEDÝÐÝNÝZ BÖLÜMÜ SEÇÝNÝZ \n";
	cout<<"\t\t\t\t\t   ANA MENÜ ÝÇÝN M GÝRÝNÝZ  \n";
	cin>>secim1;
	if(secim1=="m"||secim1=="M")
	{
		goto menu;
	}
	if(secim1=="1")
	{
				system("cls");
				cout<<"  PROBLEM 1 ÝÇÝN AÇIKLAMALAR\n";
				cout<<"  --------------------------\n";
				cout<<"  Açýklamalar: Ýstenilen tabloyu oluþturabilmek için double tanýmlý j deðiþkeni tanýmlandý.\n";
				cout<<"               Açýlarý hesaplatabilmek için math.h kütüphanesi programla eklendi.\n";
				cout<<"               For döngüsü kullanýlarak 0-90 derece arasýnda 10 luk artým ile açýlar döndürüldü.\n";
				cout<<"               Tabloyu oluþturabilmek için formatlý biçimde karakterler düzenlendi.\n";
				cout<<"               INFINITY ibaresi için string metodu kullanýldý.\n";
				cout<<"\n";
				cout<<"   Seçiminiz (A=Ana Menü/M=Menü/C=Çýkýþ.)\n";
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
				cout<<"  PROBLEM 2 ÝÇÝN AÇIKLAMALAR\n";
				cout<<"  --------------------------\n";
				cout<<"  Açýklamalar: Fonksiyonun deðerlerini tutan bir double degerler[81] dizisi tanýmlandý\n";
				cout<<"               Aralýðý hesaplatabilmek için int x deðiþkeni tanýmlandý.\n";
				cout<<"               For döngüsü kullanýlarak aralýklar için y deðerleri tanýmlandý\n";
				cout<<"               Bu y deðerleri int y deðiþkeninde tutuldu.\n";
				cout<<"               son olarak diziye aktardýðýmýz y deðerleri yeni bir for dögüsü ile ekrana yazdýrýrldý.\n";
				cout<<"\n";
				cout<<"   Seçiminiz (A=Ana Menü/M=Menü/C=Çýkýþ.)\n";
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
				cout<<"  PROBLEM 3 ÝÇÝN AÇIKLAMALAR\n";
				cout<<"  --------------------------\n";
				cout<<"  Açýklamalar: 5x5 büyüklüðünde int matris tanýmlanmýþtýr\n";
				cout<<"               Bu matrise sayýlar programýn içine gömülü þekilde eklenmiþtir\n";
				cout<<"               2 Adet iç içw For döngüsü kullanýlarak bu dizi ekrana yazdýrýlmýþtýr.\n";
				cout<<"               Esas köþegendeki sayýlar int toplam deðiþkeni tanýmlanarak bu deðiþkende tutulmuþtur.\n";
				cout<<"               Ters köþegendeki çarpýmlar ayrý bir for döngüsü içerisinde hesaplanmýþtýr.\n";
				cout<<"\n";
				cout<<"   Seçiminiz (A=Ana Menü/M=Menü/C=Çýkýþ.)\n";
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
				cout<<"  PROBLEM 4 ÝÇÝN AÇIKLAMALAR\n";
				cout<<"  --------------------------\n";
				cout<<"  Açýklamalar: Foksiyonun köklerini bulabilmek için fonk adýnda bir fonksiyon tanýmlanmýþtýr.\n";
				cout<<"               Bu fonksiyon içerisinde fonksiyonun deðerleri hesaplanmýþtýr.\n";
				cout<<"               Program4 fonksiyonu içerisinde fonk fonksiyonu çaðýrýlmýþ ve newton raphson metodu uygulanmýþtýr.\n";
				cout<<"               Kullanýcý baþlangýç deðeri ve epsilon deðerini kendisinin girmesi saðlanmýþtýr.\n";
				cout<<"               Bu deðerler double epsilon x0 deðiþkenlerinde tutulmuþtur.\n";
				cout<<"\n";
				cout<<"   Seçiminiz (A=Ana Menü/M=Menü/C=Çýkýþ.)\n";
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
				cout<<"  PROBLEM 5 ÝÇÝN AÇIKLAMALAR\n";
				cout<<"  --------------------------\n";
				cout<<"  Açýklamalar: Kullanýcýdan alýnan satýþ miktarý satiMiktari deðiþkeninde tutulmuþtur.\n";
				cout<<"               Verilen kriterlere uygun prim miktarýný hesaplayan float PrimHesala fonksiyonu yaratýlmýþtýr.\n";
				cout<<"               Kullanýcýdan alýnanv verilere göre prim hesaplamak için bu fonsiyon program5 fonskiyonu içerisinde çaðýrýlmýþtýr.\n";
				cout<<"               Son olarak hesaplanan prim miktarý ekrana yazdýrýlmýþtýr.\n";
				cout<<"\n";
				cout<<"   Seçiminiz (A=Ana Menü/M=Menü/C=Çýkýþ.)\n";
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
				cout<<"  GENEL AÇIKLAMALAR\n";
				cout<<"  --------------------------\n";
				cout<<"  -------->>>: Programýn genelinde her problem ayrý bir fonksiyon olarak ana programýn içerisinde çaðýrýlmýþtýr.\n";
				cout<<"               Seçimler switch case yapýsý kullanýlarak kontrol edilmiþtir.\n";
				cout<<"               Bu programda C++ ve C komutlarý karýþýk kullanýlmýþtýr.\n";
				cout<<"\n";
				cout<<"   Seçiminiz (A=Ana Menü/M=Menü/C=Çýkýþ.)\n";
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
