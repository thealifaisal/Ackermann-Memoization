// Author: Ali Faisal
// A(4, 1) is limit

#include <iostream>
#define y 100000

using namespace std;

int ackermann(int m, int n);
void clearCache();
void printCache();
int cache[5][y] = {0};

int main()
{
    int m, n;
    
    clearCache();
    
    for (m = 0; m <= 4; m++)
    {
    	for (n = 0; n < 6-m; n++)
        {
        	cache[0][0] = 1;
        	printf("A(%d, %d) = %d\n", m, n, ackermann(m, n));
        	//printCache();
			//clearCache();
		}
	}
	
    return 0;
}

int ackermann(int m, int n)
{
    if(m == 0)
    {
    	// n + 1
    	return cache[m][n] = n+1;
	}
    else if(m > 0 && n == 0)
    {
    	// A(m-1, 1)
    	if(cache[m][n] != -1)
    	{
    		return cache[m][n];
		}
		else
		{
			if(cache[m-1][1] != -1)
			{
				return cache[m][n] = cache[m-1][1];
			}
			else
			{
				return cache[m][n] = ackermann(m-1, 1);
			}
		}
	}
	else if(m > 0 && n > 0)
	{
		// A(m - 1, A(m, n - 1));
		if(cache[m][n] != -1)
		{
			return cache[m][n];
		}
		else
		{
			return cache[m][n] = ackermann(m - 1, ackermann(m, n - 1));
		}
	}
}

void clearCache()
{
	for(int i=0; i<5; i++)
    {
    	for(int j=0; j<y; j++)
    	{
    		cache[i][j] = -1;
		}
	}
}

void printCache()
{
	cout<<"\nCache:\n";
	for(int i=0; i<5; i++)
    {
    	for(int j=0; j<6; j++)
    	{
    		cout<<cache[i][j]<<"\t";
		}
		cout<<"\n";
	}
	cout<<"\n-------------------------------------------\n\n";
}
