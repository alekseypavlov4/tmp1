#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
    int l = 100;
	int arr[l];
	int max = 0;
	int min = 1001;
	
	srand(time(0));
	
	for (int i = 0; i < l; i++)
	{
        arr[i] = rand() % 1000;
        if (arr[i] < min)
			{
				min = arr[i];
			}
			if (arr[i] > max)
			{
				max = arr[i];
			}
    }
    
    const char* max1 = "chetnoe";
    const char* min1 = "chetnoe";
    
    if (max % 2 == 1)
    {
           max1 = "nechetnoe";
    }
    
    if (min % 2 == 1)
    {
           min1 = "nechetnoe";
    }
    
    cout << "max = " << max << " " << max1 << endl;
	cout << "min = " << min << " " << min1 << endl;
	
	return 0;
}
