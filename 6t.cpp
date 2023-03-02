#include <omp.h> 
#include <iostream>
#include <ctime>

using namespace std;

int main(int argc, char *argv[]) 
{
	srand(time(NULL));
	int len, maxi;
	cout << "Input length: ";
	cin >> len;
	
	double timer[7];
	int *arr = new int [len];
	
	for(int i = 0; i < len; i++)
	{ 
	arr[i] = rand()%100000;
	}
	 
	timer[0] = omp_get_wtime();
	
#pragma omp parallel num_threads(1) reduction(max:maxi)
	{
	#pragma omp for 
		for(int i = 0; i < len; i++)
			{
				if (arr[i] > maxi)
				{
					maxi = arr[i];
				}
			}
	printf("Num_threads_1: %d\n", omp_get_num_threads());
	}
	
	timer[1] = omp_get_wtime();
	
	cout << "\tMax_1 = " << maxi << endl;
	cout << "\tTime_1 = " << timer[1] - timer[0] << endl;
	
	maxi = 0;
	
	timer[2] = omp_get_wtime();
	
#pragma omp parallel num_threads(2) reduction(max:maxi)
	{
	#pragma omp for 
		for(int i = 0; i < len; i++)
			{
				if (arr[i] > maxi)
				{
					maxi = arr[i];
				}
			}
	printf("Num_threads_2: %d\n", omp_get_num_threads());
	}
	
	timer[3] = omp_get_wtime();
	
	cout << "\tMax_2 = " << maxi << endl;
	cout << "\tTime_2 = " << timer[3] - timer[2] << endl;
	
	maxi = 0;
	
	timer[4] = omp_get_wtime();
	
#pragma omp parallel num_threads(3) reduction(max:maxi)
	{
	#pragma omp for 
		for(int i = 0; i < len; i++)
			{
				if (arr[i] > maxi)
				{
					maxi = arr[i];
				}
			}
	printf("Num_threads_3: %d\n", omp_get_num_threads());
	}
	
	timer[5] = omp_get_wtime();
	
	cout << "\tMax_3 = " << maxi << endl;
	cout << "\tTime_3 = " << timer[5] - timer[4] << endl;
	
	maxi = 0;
	
	timer[6] = omp_get_wtime();
	
#pragma omp parallel num_threads(4) reduction(max:maxi)
	{
	#pragma omp for 
		for(int i = 0; i < len; i++)
			{
				if (arr[i] > maxi)
				{
					maxi = arr[i];
				}
			}
	printf("Num_threads_4: %d\n", omp_get_num_threads());
	}
	
	timer[7] = omp_get_wtime();
	
	cout << "\tMax_4 = " << maxi << endl;
	cout << "\tTime_4 = " << timer[7] - timer[6] << endl;

	return 0;

}