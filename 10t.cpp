#include <stdio.h>
#include <mpi.h>
#include <ctime>

#define n 10

using namespace std;

int main(int argc, char *argv[])
{
	srand(time(0));
	int rank, i, size;
	double time_start, time_finish;
	int a[n], b[n];
	MPI_Status status;
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    for(i = 0; i<n; i++)
    {
    	a[i] = (rand() % 9)+1;
    	printf("%d ", a[i]);
	}
	time_start = MPI_Wtime();
	MPI_Reduce(a, b, n, MPI_INT, MPI_MAX, 0, MPI_COMM_WORLD);
	time_finish = MPI_Wtime() - time_start;
		printf("rank=%d reduce time =%lf\n", rank, time_finish);
	if(rank==0)
	{
		cout << endl;
		for(i = 0; i<n; i++)
    	{
    	printf("%d ", b[i]);
    	if((b[i]%2!=0) and (b[i+1]%2!=0))
    		{
				printf("+ ");
			}
		}
		cout << endl;
	}
	MPI_Finalize();
}