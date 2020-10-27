#include<iostream>
using namespace std;

void makeSieve(int n,bool isPrime[]) 
{
    for (int i = 0; i <= n; i++)   
		isPrime[i] = true;
    
	isPrime[0] = false;
    isPrime[1] = false;

    for (int i = 2; i * i <= n; i++) 
	{
        if (isPrime[i] == true) 
		{
            for (int j = i * i; j <= n; j += i) 
			{
                isPrime[j] = false;
            }
        }
    }
}
int main() 
{
    int n;
    cout<<"Ente the value of n\n";
    cin >> n;
    bool isPrime[n + 1] = {false};
  
    makeSieve(n,isPrime);
    cout << "Prime numbers upto n are:\n";
    for(int i = 1; i <= n; i++)
	{
    	if (isPrime[i]) 
			cout << i << "\n";
		
	}
    return 0;
}
