//============================================================================
// Name        : Hello.cpp
// Author      : fabrice
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<cstdlib>
using namespace std;

/*template<typename T,std::size_t N>
constexpr std::size_type arraySize(T(&)[N]) noexcept
{
	return N;
}*/
void insertion(int a[],int N)
{
	int i,j,v;
  	for(i=1;i<N;i++)
  	{
  		v=a[i]; j=i;
  		while(j>0&&a[j-1]>v)
  		{
  			a[j] = a[j-1];j--;
  		}
  		a[j]=v;
  	}
}
void insertion(int a[],int p[],int N)
{
	 int i,j,v;
	 for(i=0;i<N;i++) p[i]=i;
	 for(i=1;i<N;i++)
	 {
		 v=p[i];j=i;
		 while(j>0&&a[p[j-1]]>a[v])
		 {

			 p[j]=p[j-1];j--;
		 }
		 p[j]=v;
	 }

}
void insertion(int a[],int *p[],int N)
{
	int i,j,*v;
	for(i=0;i<N;i++) p[i]=&a[i];
	for(i=1;i<N;i++)
	{
		v=p[i];j=i;
		while(j>0&& *p[j-1]>*v )
		{
				p[j]=p[j-1];j--;
		}
		p[j]=v;
	}
}
void insitu(int a[],int *p[],int N)
{
	int i,j,k,t;
	for(i=0;i<N;i++)
	{
		if(p[i] != &a[i])
		{
				t=a[i]; k=i;
				do
				{
                     j=k;
                     a[j] = *p[j];
                     k=p[j]-&a[0];
                     p[j] = &a[j];


				}while(i!=k);

				a[j]=t;
		}
	}
}
void insitu(int a[],int p[],int N)
{
	int i,j,k,t;
	for(i=0;i<N;i++)
	{
		if(p[i]!=i)
		{
			t=a[i];k=i;
			do{
				j=k;
				a[j]=a[p[j]];
				k=p[j];
				p[j]=j;

			}while(k!=i);
			a[j]=t;
		}
	}
}
void shellsort(int a[],int N)
{
	int i,j,h,v;
	for(h=1;h<=N/9;h=3*h+1);

	for(;h>0;h/=3)

		for(i=h;i<N;i+=1)

		{
			v=a[i];j=i;
			while(j>=h&&a[j-h]>v)
			{
				a[j]=a[j-h];j-=h;
			}
			a[j]=v;
		}
}
void distributionCounting(int N,int M,int a[])
{
	int b[500];
	int count[535];
	int i,j;
	for(j=0;j<M;j++) count[j]=0;
	for(i=0;i<N;i++) count[a[i]]++;
	for(j=1;j<M;j++)
		count[j]=count[j-1]+count[j];
	for(i=N-1;i>=0;i--)
		b[count[a[i]]--] =a[i];
	for(i=0;i<N;i++) a[i]=b[i];
}
void distributionCounting2(int N,int M,int a[])
{
  int b[31];
  int count[535],i,j;
  for(i=0;i<M;i++) count[i]=0;
  for(i=0;i<N;i++) count[a[i]]++;
  //for(i=1;i<N;i++) count[j] +=count[j-1];
  for(i=0;i<N;i++)
	  {

	    for(j=1;j<=count[a[i]];j++)
	    {
	    	b[a[i]+i-1]=a[i];
	    }

	  };

  for(i=0;i<N;i++) a[i]=b[i];
}
/*void QuickSort(int a[],int N)
{
	int i,l,r;
	l=0;r=N;stackinit();
	for(;;)
	{
		while(r>l)
		{
			i=partition(a,l,r);
			if(i>r-i)
			{
				puh(l);push(i-1); l=i+1;
			}
			else{
				push(i+1);push(r);r=i-1;
			}
			if(stackempty()) break;
			r=pop();l=pop();
		}
	}
}*/
template<typename Container,typename Index>
 auto authAndAccess(Container& c,Index i)
->decltype(c[i])
{
	// authenticateUser();
	return c[i];
}
int select(int a[],int l,int r,int k)
{
	      int i,j,t;

		   i=l-1;j=r-1;

		    	             int v= a[r-1];
		    			    for(;;)
		    			    {
		    			    	while(a[++i]<v);
		    			    	while(a[--j]>v);
		    			    	if(i>=j) break;
		    			    	t=a[j]; a[j]=a[i];a[i]=t;
		    			   }
		    			    a[r]=a[i];a[i]=v;

		    			    if(i>k-1) select(a,l,i-1,k);
		    			    if(i<k-1) select(a,i+1,r,k);
		    			    return a[i];

}
int select(int a[],int N,int k)
{
    int v,t,i,j,l,r;
    r=N;l=0;
    while(l<r)
    {
    	v=a[r];i=l-1;j=r;
    	for(;;)
    	{
    		while(a[++i]<v);
    		while(a[--j]>v);
    		if(j<=i) break;
    		t=a[j]; a[j]=a[i];a[i]=t;
    	}
    	a[r]=a[i];a[i]=v;
    	if(i<k) l= i+1;
    	if(i>k) r=i-1;
    	return a[i];
    }
}
unsigned bits(unsigned x,int k,int j){
	return (x>>k)&~(~0<<j);
}
void radixExchange(int a[],int l,int r,int b)
{
	int t,i,j;
	if(r>l&& b>=0)
	{
		i=l;j=r;
		while(j!=i)
		{
			while( bits(a[i],b,1)==0 && i<j ) i++;
			while( bits(a[j],b,1)!=0 && j>i) j--;
            t=a[i]; a[i]=a[j];a[j]=t;
		}
		if(bits(a[r],b,1) ==0)j++;
		radixExchange(a,l,j-1,b-1);
		radixExchange(a,j,r,b-1);




	}
}
/*int M=2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2;
void straightRadix(int a[],int b[],int N)
{
	int i,j,pass,count[M-1];
	for(pass=0;pass<(w/m)-1;pass++)
	{

	}

}*/
int main() {
	int a[]={44,23,11,55,66,55,66,55,100,534,21,77,88,90,23,43,44,23,11,55,66,55,100,534,523,44,1,5,78,34,33};
	//int *p[7];

	//insertion(a,p,7);
	//insitu(a,p,7);
	//distributionCounting(31,535,a);
//	auto&& uref3 =27;//27 is int and rvalue,
					// so uref3's type is int &&
  radixExchange(a,0,30,12);


for(int i=0;i<31;i++)
{
	cout<< a[i]<<endl;
}
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	return 0;
}
