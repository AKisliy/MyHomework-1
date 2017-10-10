#include <iostream>


using namespace std;


int main() 
{
    int n;
    cout << "Enter number of floors: ";
    cin >> n;
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < i+1; j++)
        {
            cout << "*";
        }
        cout << "\n";
    }
    
    cout << "\n";
    
    for(int i = n; i > 0; i--)
    {
        for(int j = 0; j <= i-1; j++)
        {
            cout << "*";
        }
        cout << "\n";
    }
    
    cout << "\n";
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - i; j++)
	{
            cout << ' ';
	}	
 
	for (int j = 1; j <= i * 2 - 1; j++)
	{
            cout << '*';
	}			
	cout << "\n";
    }
    for(int i = 1; i <= n; i++)
    {
        if(i != n)
            cout << ' ';
    }
    cout << '*';
    
    return 0;
}
