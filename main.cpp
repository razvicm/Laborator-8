#include <iostream>
#include <cstdlib>
#include  <ctime>
#include  <fstream>

using namespace std;

void initial(int [], int);
void ordonCresc(int [], int);
void ordonDesc(int [], int);
void invers(int [], int);
void inter(int [], int [], int [], int, int);
int prezent(int, int [], int);
void divizibil(int [], int, int &, int &, int &);
void scriu(int [], int);

int main()
{
	int a[100], b[100], c[200];
	int n,i;
	n = 7;
	srand(time(0));
	initial(a, n);
	initial(b, n);
	cout<<"Sirul a este: ";
	for(i=0;i<n;i++){
        cout<<a[i]<<" ";
	}
	cout<<endl;
	cout<<"Sirul b este: ";
	for(i=0;i<n;i++){
        cout<<b[i]<<" ";
	}
	cout<<endl;
	cout<<"Sirul a ordonat crescator este: ";
	ordonCresc(a, n);
	for(i=0;i<n;i++){
        cout<<a[i]<<" ";
	}
	ordonDesc(b, n);
	cout<<endl;
	cout<<"Sirul b ordonat descrescator este: ";
	for(i=0;i<n;i++){
        cout<<b[i]<<" ";
	}

	invers(b, n);
	cout<<endl;
	cout<<"Sirul b inversat este: ";
	for(i=0;i<n;i++){
        cout<<b[i]<<" ";
	}
	inter(a, b, c, n, n);
	//  Afisez sirul c
	cout<<endl;
	cout<<"Sirul c este: ";
	for(int i = 0; i < 2*n; i++)
	   cout << c[i] << ", ";
    int nrdiv3, nrdiv5, nrdiv3si5;
	divizibil(c, 2*n, nrdiv3, nrdiv5, nrdiv3si5);
	cout<<endl;
	cout << "Divizibile prin 3: " << nrdiv3 << " numere," << endl
	     << "Divizibile prin 5: " << nrdiv5 << " numere," << endl
	     << "Divizibile prin 3 si 5: " << nrdiv3si5 << " numere." << endl;
    cout<<endl;
    int v = 12;
	if (prezent(v, c, 2*n) > 0)
		cout << v << " este prezent in sirul c." << endl;
	else
		cout << v << " nu este prezent in sirul c." << endl;
    scriu(c, 2*n);

	return 0;
}

void initial(int a[],int n){
    int i;
    for(i=0; i < n; i++)
        a[i] = rand() % 100 + 1;
}

void ordonCresc(int a[], int n){
    int i,aux,flag;
    do {
        flag = 0;  //  Initializez inafara ciclului de parcurgere a sirului
        for(i = 0; i < n-1; i++) {
            if(a[i] > a[i+1])
            {
                aux = a[i];
                a[i] = a[i+1];
                a[i+1] = aux;
                flag = 1;  //  Marchez ca s-a facut o inversare
            }
        }

    }
    while(flag != 0);
    }
void ordonDesc(int a[], int n){
    int i,aux,flag;
    do {
        flag = 0;  //  Initializez inafara ciclului de parcurgere a sirului
        for(i = 0; i < n-1; i++) {
            if(a[i] < a[i+1])
            {
                aux = a[i];
                a[i] = a[i+1];
                a[i+1] = aux;
                flag = 1;  //  Marchez ca s-a facut o inversare
            }
        }

    }
    while(flag != 0);
}

void invers(int a[],int n){
    int i,j,aux;
    for(i=0, j=n-1; i<j; i++,j--){
        aux=a[i];
        a[i]=a[j];
        a[j]=aux;
    }
}

void inter(int a[], int b[], int rez[], int na, int nb)
{
	int i=0, j=0;
	do
	{
		if(i < na && j < nb)
			if(a[i] <= b[j])
			{
				rez[i+j] = a[i];
				i++;
			}
			else
			{
				rez[i+j] = b[j];
				j++;
			}
		else
			if(i < na)
			{
				rez[i+j] = a[i];
				i++;
			}
			else
			{
				rez[i+j] = b[j];
				j++;
			}
	}
	while(i + j < na + nb);
}

void divizibil(int a[], int n, int& nrdiv3, int& nrdiv5, int& nrdiv3si5){
    int i;
    nrdiv3=nrdiv5=nrdiv3si5=0;
        for(i=0; i<n;i++){
            if (a[i]%3==0)
            nrdiv3++;
            if (a[i]%5==0)
            nrdiv5++;
            if (a[i]%3+a[i]%5==0)
            nrdiv3si5++;
        }
}
int prezent(int x, int v[], int n)
{
   int mini, maxi, mijloc;
   mini = 0;
   maxi = n - 1;
   while (mini <= maxi)
   {
      mijloc = (mini + maxi) / 2;
      if (x < v[mijloc])
         maxi = mijloc - 1;
      else if (x > v[mijloc])
         mini = mijloc + 1;
      else
         return mijloc;    //  Gasit!
   }
   return -1;              //  Absent!
}
void scriu(int a[],int n){
    fstream fd;
   int i;
   fd.open( "fdate.txt", ios::out);
    for(i=0;i<n-1;i++)
        fd<<a[i]<<" ,";
    fd<< a[n-1];
   fd.close();
}
