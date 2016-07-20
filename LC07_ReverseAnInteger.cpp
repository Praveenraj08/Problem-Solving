//============================================================================
// Name        : LC07_ReverseAnInteger.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	int x=-120; //input
	int sum=0;

	while(x!=0)
	{

		if(sum>INT_MAX/10 ||sum<INT_MIN/10)
		{
			return 0;
		}

		sum=sum*10+x%10;
		x=x/10;


	}
	cout<<sum;
	return 1;

}
