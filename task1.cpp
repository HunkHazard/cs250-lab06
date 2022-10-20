#include <cstdlib>
#include <iostream>
#include <time.h>
using namespace std;

int main(){
	int n;
	cout << "Enter Number of Dice throws: " ;
	cin >> n;
	
	srand(time(0));	
	for (int i=0;i<n;i++){
		cout << (rand()%6)+1 << " ";
	}
	
	cout << endl;
	
	return 0;
}




