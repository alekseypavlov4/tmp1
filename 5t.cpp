#include <stdio.h> 
#include <omp.h> 
#include <iostream>
#include <ctime>

using namespace std;

int main(int argc, char *argv[]) 
{	
	int len;
	int pr = 0;
	cout << "Input length: ";
	cin >> len;
	double timer[7];
	int *arr1 = new int [len];
	int *arr2 = new int [len];
	
	srand(time(0));
	
	for (int i = 0; i < len; ++i)
	{
		arr1[i] = rand() % 10;
		arr2[i] = rand() % 10;
	}
	
	timer[0] = omp_get_wtime();
	
	#pragma omp parallel num_threads(1) reduction(+:pr)
	{
		#pragma omp for
			for (int i = 0; i < len; i++)
			{
				pr += arr1[i] * arr2[i];
			}
		printf("Num_threads_1 = %d\n", omp_get_num_threads());
	}
	
	timer[1] = omp_get_wtime();
	cout <<	"\tSkalyarnoe umnozhenie_1 = " << pr << endl;
	cout << "\tTime_1 = " << timer[1] - timer[0] << endl;

	pr = 0;
	timer[2] = omp_get_wtime();
	
	#pragma omp parallel num_threads(2) reduction(+:pr)
	{
		#pragma omp for
			for (int i = 0; i < len; i++)
			{
				pr += arr1[i] * arr2[i];
			}
		printf("Num_threads_2 = %d\n", omp_get_num_threads());
	}
	
	timer[3] = omp_get_wtime();
	cout <<	"\tSkalyarnoe umnozhenie_2 = " << pr << endl;
	cout << "\tTime_2 = " << timer[3] - timer[2] << endl;

	pr = 0;
	timer[4] = omp_get_wtime();
	
	#pragma omp parallel num_threads(3) reduction(+:pr)
	{
		#pragma omp for
			for (int i = 0; i < len; i++)
			{
				pr += arr1[i] * arr2[i];
			}
		printf("Num_threads_3 = %d\n", omp_get_num_threads());
	}
	
	timer[5] = omp_get_wtime();
	cout <<	"\tSkalyarnoe umnozhenie_3 = " << pr << endl;
	cout << "\tTime_3 = " << timer[5] - timer[4] << endl;
	
	pr = 0;
	timer[6] = omp_get_wtime();
	
	#pragma omp parallel num_threads(4) reduction(+:pr)
	{
		#pragma omp for
			for (int i = 0; i < len; i++)
			{
				pr += arr1[i] * arr2[i];
			}
		printf("Num_threads_4 = %d\n", omp_get_num_threads());
	}
	
	timer[7] = omp_get_wtime();
	cout <<	"\tSkalyarnoe umnozhenie_4 = " << pr << endl;
	cout << "\tTime_4 = " << timer[7] - timer[6] << endl;
	
	return 0;
}