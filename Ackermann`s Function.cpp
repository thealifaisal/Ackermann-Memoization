#include <iostream>

using namespace std;

int ackermann(int m, int n);
int cache[5][6] = {0};

int main()
{
    int m, n;
    
    for(int i=0; i<5; i++)
    {
    	for(int j=0; j<6; j++)
    	{
    		cache[i][j] = -1;
		}
	}
    
	for (m = 0; m <= 4; m++)
    {
    	for (n = 0; n < 6 - m; n++)
        {
        	printf("A(%d, %d) = %d\n", m, n, ackermann(m, n));
		}
	}
	
    return 0;
}

int ackermann(int m, int n)
{
    if(m == 0)
    {
    	return n + 1;
	}
	
    if(m > 0 && n == 0)
    {
    	if(cache[m-1][1] == -1)
    	{
    		return cache[m-1][1] = ackermann(m - 1, 1);
		}
		else if(cache[m-1][1] != -1)
		{
			return cache[m-1][1];
		}
	}
	
	if(m > 0 && n > 0)
	{
		if(cache[m][n-1] != -1)
		{
			if(cache[m-1][cache[m][n-1]] != -1)
			{
				return cache[m-1][cache[m][n-1]];
			}
			else if(cache[m-1][cache[m][n-1]] == -1)
			{
				return cache[m-1][cache[m][n-1]] = ackermann(m-1, cache[m][n-1]);
			}
		}
		else if(cache[m][n-1] == -1)
		{
			cache[m][n-1] = ackermann(m, n-1);
			
			if(cache[m-1][cache[m][n-1]] != -1)
			{
				return cache[m-1][cache[m][n-1]];
			}
			else if(cache[m-1][cache[m][n-1]] == -1)
			{
				return cache[m-1][cache[m][n-1]] = ackermann(m-1, cache[m][n-1]);
			}
		}
	}
	
    //return ackermann(m - 1, ackermann(m, n - 1));
}
