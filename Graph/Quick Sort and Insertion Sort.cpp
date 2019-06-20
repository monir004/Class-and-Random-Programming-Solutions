#include<bits/stdc++.h>
using namespace std;
void insertionsort(vector<int>& arr,int size);
void quicksort(vector<int>& arr, int start, int end);
int partition(vector<int>& arr, int start, int end);
int length;
int main(){
    vector<double>res;
	for(int i=1;i<=6;i++)
    {
        if(i==1)
        {
            clock_t begin = clock();
            vector<int>arr(10000);
            ifstream read("bestcase.txt");
            int num,j=0;
            while(read>>num){
                arr[j++]=num;
            }
            insertionsort(arr,10000);
            clock_t end = clock();
            double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
            res.push_back(time_spent);
            //printf("kdfidhfugd = %lf\n",time_spent);

        }else if(i==2){
            vector<int>arr(10000);
            clock_t begin = clock();
            ifstream read("bestcase.txt");
            int num,j=0;
            while(read>>num){
                arr[j++]=num;
            }
            quicksort(arr,0,9999);
            clock_t end = clock();
            double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
            res.push_back(time_spent);
            //printf("kdfidhfugd = %lf\n",time_spent);
        }else if (i==3){
            vector<int>arr(10000);
            clock_t begin = clock();
            ifstream read("averagecase.txt");
            int num,j=0;
            while(read>>num){
                arr[j++]=num;
            }
            insertionsort(arr,10000);
            clock_t end = clock();
            double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
            res.push_back(time_spent);
            //printf("kdfidhfugd = %lf\n",time_spent);
        }else if(i==4){
            vector<int>arr(10000);
            clock_t begin = clock();
            ifstream read("averagecase.txt");
            int num,j=0;
            while(read>>num){
                arr[j++]=num;
            }
            quicksort(arr,0,9999);
            clock_t end = clock();
            double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
            res.push_back(time_spent);
            //printf("kdfidhfugd = %lf\n",time_spent);
        }else if(i==5){
            vector<int>arr(10000);
            clock_t begin = clock();
            ifstream read("worstcase.txt");
            int num,j=0;
            while(read>>num){
                arr[j++]=num;
            }
            insertionsort(arr,10000);
            clock_t end = clock();
            double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
            res.push_back(time_spent);
            //printf("kdfidhfugd = %lf\n",time_spent);
        }else{
            vector<int>arr(10000);
            clock_t begin = clock();
            ifstream read("worstcase.txt");
            int num,j=0;
            while(read>>num){
                arr[j++]=num;
            }
            quicksort(arr,0,9999);
            clock_t end = clock();
            double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
            res.push_back(time_spent);
           // printf("kdfidhfugd = %lf\n",time_spent);
        }
    }
     cout<<endl<<"------------------Total time elapsed--------------------------"<<endl<<endl;
     cout<<"1.Best case  -----------------Insertion sort ------------"<<res[0]*60<<endl;
     cout<<"2.Best case  ------------------Quick sort --------------- "<<res[1]*60<<endl;
     cout<<endl<<"1.Average case  --------------Insertion sort -------------"<<res[2]*60<<endl;
     cout<<"2.Average case  ---------------Quick sort ----------------"<<res[3]*60<<endl;
     cout<<endl<<"1.Worst case  ----------------Insertion sort -------------"<<res[4]*60<<endl;
     cout<<"2.Worst case  ----------------Quick sort ---------------- "<<res[5]*60<<endl;
}

//insertionsort
void insertionsort(vector<int>& arr,int size){
	//vector<int>arr(length+1);

	for (int i = 0; i < size; i++)
	{
		int j = i;
		while (j > 0 && arr[j - 1] > arr[j])
		{
			swap(arr[j - 1], arr[j]);
			j--;
		}
	}

}

//Quick sort
int partition(vector<int>& arr,int start,int end)
{
	int pivot = arr[end];
	int pIndex = start;
	for (int i = start; i < end; i++){
		if (arr[i] <= pivot) {
			swap(arr[i], arr[pIndex]); pIndex++;
		}
	}
	swap(arr[pIndex], arr[end]);
	return pIndex;
}

void quicksort(vector<int>& arr,int start,int end)
{
	if (start < end) {
		int partitionIndex = partition(arr, start, end);  //partitioning the array into two halves
		quicksort(arr, start, partitionIndex - 1); //dividing into left half
		quicksort(arr, partitionIndex + 1, end);   //dividing inti right half
	}
}
