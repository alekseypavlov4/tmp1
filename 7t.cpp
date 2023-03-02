#include <stdio.h> 
#include <omp.h> 
#include <iostream>
#include <iomanip>

using namespace std;

double chislo_pi(int n, int threads)
{
	double pi = 0;
	double xi;
	double timer[2];

	timer[0] = omp_get_wtime();
	#pragma omp parallel reduction(+:pi) num_threads(threads)
	{
		#pragma omp for private(xi)      
			for (int i = 0; i < n; i++)
			{
				xi = (i + 0.5) * 1/n;
				pi += 4/(1+xi*xi);
			}
	}   
	pi = pi / n;
	timer[1] = omp_get_wtime();
	double d_timer = timer[1] - timer[0];
	
	cout << "Time = " << d_timer << endl;
	cout << "Chislo pi = "<< setprecision(9) << pi << endl << endl;
	
	return d_timer;
}                                  
         
int main(int argc, char *argv[]) 
{
	int n;
	cout << "input n: ";
	cin >> n;
	
	double d_timer[2];
	
    d_timer[1]=chislo_pi(n, 1);
    d_timer[2]=chislo_pi(n, 8);
    
    cout << "Raznica time = " << d_timer[1] - d_timer[2] << endl;
    
	return 0;
}