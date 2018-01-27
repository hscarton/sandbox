#include <iostream>

using namespace std;

int tribbles (int n)
{
	if(n < 2)
	{
		return 1;
	}
	
	else if(n = 2)
	{
		return 2;
	}
	
	else if(n = 3)
	{
		return 4;
	}
	
	else 
	{
		return n * tribbles(n - 1);
	}
}
	
int main(void)
{
	
	cout << tribbles(8) << endl;
	
	return 0;
}
