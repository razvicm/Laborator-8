#include <iostream>
#include <cstdlib>
#include  <ctime>

using namespace std;

void initial(int [], int);
void ordonCresc(int [], int);
void ordonDesc(int [], int);
void invers(int [], int);
void inter(int [], int [], int [], int, int);

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
