#include <stdio.h> 
#include <omp.h> 
#include <iostream>
#include <ctime>

using namespace std;

double umnoznenie(int n, int threads)
{
	int** matrix1 = new int* [n];
	int** matrix2 = new int* [n];
	int** matrix3 = new int* [n];
	
	double timer[2], d_timer;
	
	for (int i = 0; i < n; i++)
	{
		matrix1[i] = new int [n];
		matrix2[i] = new int [n];
		matrix3[i] = new int [n];
	}
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			matrix1[i][j] = rand()%10;
			matrix2[i][j] = rand()%10;
			matrix3[i][j] = 0;
		}
	}
	
	timer[0] = omp_get_wtime();
	
	#pragma omp parallel num_threads(threads)
	{
		#pragma omp for
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{
					for (int k = 0; k < n; k++)
					{
						matrix3[i][j] += matrix1[i][k] * matrix2[k][j];
					}
				}	
			}
	}
	
	timer[1] = omp_get_wtime( );
	
	d_timer = timer[1] - timer[0];
	cout << "Time: " << d_timer << endl;
	
	return d_timer;
}

int main(int argc, char *argv[]) 
{
	int n, threads;
	srand(time(NULL));
	double delta1, delta2;
	
	cout << "Input n: ";
	cin >> n;

	cout << "Threads: 1" << endl;
	delta1 = umnoznenie(n, 1);
	
	cout << endl << endl;
	
	cout << "Input threads: ";
	cin >> threads;
	delta2 = umnoznenie(n, threads);
	
	cout << endl << endl;
	cout << "effectivity = " << delta1/delta2 << endl;
}