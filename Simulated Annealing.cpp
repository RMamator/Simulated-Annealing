#include <iostream>
#include<cstdlib>
#include<ctime>
#include<math.h>

//s0 -> initial solution
//t0 -> initial temperature
//alpha -> cooling rate
//beta -> run increment constant
//maxtime -> maximum allowed time to run

int s0[] = {1,2,3,4,5,6,7,8,9,10};
float t0 = 20.0;
float alpha = 0.85;
float beta = 1.12;
int maxtime= 5000;

//Functions used
int metropolis(int *solution; float temp; int count);
int neighbor(int *input);
int cost(int *input)

using namespace std;
int main() {
	
	//blackbox variables

		//temp.
		float t=t0;
		//runtime per temp.
		int runtime=0;
		//current solution
		int s[sizeof(s0)/sizeof(*s0)];
		//array pointer
		int *fors;
		//iterations per temp.
		int m=100;
		//solution pointer;
		int *final;

	
	for(int i=0; i<4;i++){
		s[i]=s0[i];
	}
	
	fors = s; 
	
	do {
		final = metropolis(fors, t, m);
		runtime = runtime+m;
		t = alpha*t0;
		m = beta*m;
	} while (runtime<=maxtime);
	
	// *final has the solution array address. Get the solution out.
}

int metropolis(int *solution; float temp; int count){
	
	//blackbox varaibles
		
		//new solution pointer
		int *new_s;
		//varaition
		double delta_h;
		//random number generator
		float random1=0;
		
		int newcost = 0;
		int currentcost = 0;
		double exponent, value;
				
		srand(time(NULL));
		random1= ((double) rand()/ (RAND_MAX));
		
	do {
		new_s = neighbor(*solution);
		newcost = cost(new_s);
		currentcost = cost(solution);
		delta_h = newcost-currentcost;
		value = delta_h/temp;
		exponent = exp(-value);
		if(newcost<currentcost || random1<exponent){
			solution = new_s;
		}
		
		count = count-1;
		
	} while (count>0);
}

int neighbor(int *input){
	//The array that will come to this function as an input. This is dummy data right now.
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