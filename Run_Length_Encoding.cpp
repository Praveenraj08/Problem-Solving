//============================================================================
// Name        : Run_Length_Encoding.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
using namespace std;

int main() {
	string str="aaabbbccc"; //input
	//output ==> a2b3c3;
	int o_index=0; //outputIndex

	int i,j;
	i=0;
	ostringstream convert;

	while (i<str.length())
	{
		int count=1;
		j=i+1;
		while(j<str.length()&& str[i]==str[j])
			{
			count++;
			i++;
			j++;
			}
		str[o_index]=str[i];
		convert << count;

		str[++o_index]=std::str(count);

	}
}
