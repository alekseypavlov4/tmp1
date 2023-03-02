#include <iostream>
#include <ctime>

using namespace std;

int main()
{
	int n = 1000;	
	int arr1[n], arr2[n];
	int res;
	srand(time(0));
	
	for (int i = 0; i < n; i++){
		arr1[i] = -10+rand()%21;
		arr2[i] = -10+rand()%21;
		
		res += arr1[i] * arr2[i];
	}
	
	cout << "result = " << res << endl;
	
	return 0;
}