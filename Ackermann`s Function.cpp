// Author: Ali Faisal
// A(4, 1) is limit

#include <iostream>
#define y 100000

using namespace std;

int ackermann(int m, int n);
int cache[5][y] = {0};

string seq;

int main()
{
    int m, n;
	
	cout<<"Enter The Ackermann Arguments: ";
	cin>>m>>n;
	
	cout<<endl<<"A("<<m<<", "<<n<<")"<<endl;
	
	cout<<"\n"<<ackermann(m, n)<<"\n";
	
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
    	if(cache[m][n] != 0)
    	{
    		return cache[m][n];
		}
		else
		{
			if(cache[m-1][1] != 0)
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
		if(cache[m][n] != 0)
		{
			return cache[m][n];
		}
		else
		{
			return cache[m][n] = ackermann(m - 1, ackermann(m, n - 1));
		}
	}
}
