#include <iostream>
#include<cstdlib>
#include<ctime>

using namespace std;
int main(){
//The array that will come to this function as an input. This is dummy data right now.
	int a[] = {1,2,3,4,5,6,7,8,9,10};
	int b=0;
	int random1=0;
	int random2=0;
	int temp;
	int *fora, *forA, *forB;

	b=sizeof(a)/sizeof(*a);

//Size of the two partitions from the input. This will give us the two partitions.
	int size=b/2;
	int A[size];
	int B[size];
	
	cout<<size;
	int fill, out;

//Get the two partitions.
	for(fill=0;fill<size;fill++){
		A[fill]=a[fill];
		B[fill]=a[fill+size];
	}
	cout<<"\n";
	for(fill=0;fill<size;fill++){
		cout<<A[fill]<<"\t";
	}
	
	cout<<"\n";
	for(fill=0;fill<size;fill++){
		cout<<B[fill]<<"\t";
	}

//Generate random values of the elements to be swapped.	
	srand(time(NULL));
	random1= rand() % size;
	random2= rand() % size;

//Swap the elements.	
	temp = A[random1];
	A[random1] = B[random2];
	B[random2] = temp;
	
	cout<<"\n";
	for(fill=0;fill<size;fill++){
		cout<<A[fill]<<"\t";
	}
	
	cout<<"\n";
	for(fill=0;fill<size;fill++){
		cout<<B[fill]<<"\t";
	}

//Merge the swapped partitions into one array, like we received it.	
	fora = a;
	forA = A;
	forB = B;
	
//copy(pointer to first element, size of array, pointer of destination address)	
	copy(forA, forA+size, fora);
	copy(forB, forB+size, fora+size);
	
	cout<<"\n";
	for(out=0; out<b;out++){
		cout<<a[out]<<"\t";
	}
	
	cout<<"\n";
	cout<<*fora;
	
	//Retunr the array pointer.
	//return a;
}