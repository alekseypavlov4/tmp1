#include <stdio.h>
#include <omp.h>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
	int count, num;
	
	omp_set_num_threads(8);

	#pragma omp parallel num_threads(4)
	{
		count = omp_get_num_threads();
		num = omp_get_thread_num();
		
		if (num == 0)
			printf("Vsego nitey: %d\n", count);
		else
			printf("Nit nomer: %d\n", num);
	}
	
	cout << endl;
	
	#pragma omp parallel
	{
		count = omp_get_num_threads();
		num = omp_get_thread_num();
		
		if (num == 0)
			printf("Vsego nitey: %d\n", count);
		else
			printf("Nit nomer: %d\n", num);
	}
	
	return 0;
}