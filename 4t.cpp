#include <stdio.h> 
#include <omp.h> 
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) 
{
	int n;
	cout << "Input n: ";
	cin >> n;
	int arr[n];
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
	arr[i] = 1;
	}
		
	omp_set_num_threads(n);
	
#pragma omp parallel shared(arr) reduction(+: sum)
	{
	#pragma omp for
		for (int i = 0; i < n; i++)
		{
			sum += arr[i];
			printf("sum = %d\n", sum);
		}
	}
	
	cout << endl;
	cout << "Sum result_1 (for): " << sum << endl;
	sum = 0;
	
#pragma omp parallel
	{
		int sum1 = 0;
		#pragma omp for
			for (int i = 0; i < n; i++)
			{
			sum1 += arr[i];
			}
		#pragma omp atomic
			sum += sum1;
	}
	
	cout << "Sum result_2 (atomic): " << sum << endl;
	sum = 0;
	
#pragma omp parallel
	{
	#pragma omp critical
		{
			sum += arr[omp_get_thread_num()];
		}
	}
	
	cout << "Sum result_3 (critical): " << sum << endl;
	
	return 0;
}