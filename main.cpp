#include <iostream>
#include <cstring>
#include <vector>

using namespace std;
const string digits = "123456789";
const string rows = "ABCDEFGHI";
const string cols = "123456789";

void cross(string A, string B, vector<string> &out)
{
	//"cross product of elements in A and elemenets in B"
	//in other words output a list the lenth of A times the length of B
	//in that list have every element in A added to every elemnt in B
	//forming n*m new objects, in this case strings
	
	string new_string;
	string a_char;

	for(int i = 0; i < A.length(); i++)
	{
		a_char = A[i];

		for(int j = 0; j < B.length(); j++)
		{
			new_string = a_char + B[j];
			out.push_back(new_string);
		}
	}
}

int main()
{
	vector<string> squares;
	cross(rows,cols,squares);
	for(int i = 0; i < squares.size(); i++)
	{
		cout << squares[i] << " ";
	}
	return 0;
}
