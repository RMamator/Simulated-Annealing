#include <iostream>
#include <math.h>

using namespace std;
int main() {

//Initial Partition
	int A[]={1,2,3,4,5};
	int B[]={6,7,8,9,10};
	
	int a=sizeof(A)/sizeof(*A);
	int b=sizeof(B)/sizeof(*B);
	int row,col,index_partition1,index_partition2,index_weight;
	int flag=0;
	int flaginA=0;
	int cost=0;
	
	int netcount, elementcount;
	cout<<"Enter no. of nets and no. of elements:";
	cin>>netcount>>elementcount;
//Connection array		
	int array[netcount][elementcount];
	
	cout<<"Enter elements:";
	for (row=0;row<netcount;row++) {
		cout<<"\nEnter row number: "<<row+1<<"\n";
		for (col=0;col<elementcount;col++) {
			cin>>array[row][col];
		}
	}
	
	cout<<"\nElements are:\n";
	for (row=0;row<netcount;row++) {
		cout<<"\n";
		for (col=0;col<elementcount;col++) {
			cout<<array[row][col]<<"\t";
		}
	}
//Weight array		
	int weightarray[netcount];
	cout<<"\nEnter Weights of each net:";
	for (index_weight=0;index_weight<netcount;index_weight++) {
		cin>>weightarray[index_weight];
	}
	
	cout<<"\nWeight array is:";
	for (index_weight=0;index_weight<netcount;index_weight++) {
		cout<<weightarray[index_weight]<<"\t";
	}
//Cost calculation	

	for(row=0;row<netcount;row++){
		
		//Check if first element of net is in partition A or not.
		for(index_partition1=0;index_partition1<a;index_partition1++){
			if(array[row][0]==A[index_partition1]){
				flaginA=1;
				for(col=1;col<elementcount;col++){

					//Check how many elements of A and B have common nets.
					/*Read elements in each row of connection array. Hold the index of the net of have even 1 element from other
					 partition. Go to the weightarray and fetch the weight of the net for cutcost.*/

					//	1. Read the connection array rows.
					for (index_partition2=0;index_partition2<b;index_partition2++) {
						if(array[row][col]==B[index_partition2]){
							cout<<"\nIn B:"<<index_partition2;
					//Element found. There is a cut.
					//Fetch weight of net from weightarray and add it to the cost.									
							cost = cost + weightarray[row];
							//goto repeat;
							flag=1;
							break;
						}
					}
					if(flag==1)
						break;
				}				
			}
			if(flag==1)
				break;
		}

		//If the first element is not in partition A, than it must be in patition B.
		if(flaginA!=1){
			for(col=1;col<elementcount;col++){

				//Check how many elements of A and B have common nets.
				/*Read elements in each row of connection array. Hold the index of the net of have even 1 element from other
				 partition. Go to the weightarray and fetch the weight of the net for cutcost.*/

				//	1. Read the connection array rows.
				for (index_partition1=0;index_partition1<a;index_partition1++) {
					if(array[row][col]==A[index_partition1]){
						cout<<"\nIn A:"<<index_partition1;
				//Element found. There is a cut.
				//Fetch weight of net from weightarray and add it to the cost.									
						cost = cost + weightarray[row];
						//goto repeat;
						flag=1;
						break;
					}
				}
				if(flag==1)
					break;
			}				
		}
		flag=0;
		flaginA=0;
	}
	cout<<"\nCost is:"<<cost;		
}