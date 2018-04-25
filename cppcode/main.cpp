#include <iostream>
#include <cstring>
#include <vector>
#include <map>

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
void build_unitlist(vector<vector<string>> &unitlist)
{
	string temp_str;
	vector<string> temp_vec;
	
	//this part builds the cols i.e. A1, B1, C1...
	for(int i = 0; i < 9; i++)
	{
		temp_str = cols[i];
		cross(rows,temp_str,temp_vec);	
		unitlist.push_back(temp_vec);
		temp_vec.clear();
	}

	//this part builds the rows i.e. A1, A2, A3...
	for(int i = 0; i < 9; i++)
	{
		temp_str = rows[i];
		cross(temp_str,cols,temp_vec);
		unitlist.push_back(temp_vec);
		temp_vec.clear();
	}

	//this part builds the houses i.e. A1,A2,A3,B1,B2...
	string letters[3] = {"ABC","DEF","GHI"};	
	string numbers[3] = {"123","456","789"};
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			cross(letters[i],numbers[j],temp_vec);
			unitlist.push_back(temp_vec);
			temp_vec.clear();
		}
	}
}

void out_put_unitlist(vector<vector<string>> &unitlist)
{
	//basic function to output unit list to the user
	for(int i = 0; i < unitlist.size(); i++)
	{
		for(int j = 0; j < unitlist[i].size(); j++)
		{
			cout << unitlist[i][j] << " ";
		}
		cout << endl;
	}
}

int main()
{
	//these are all our tile coordinates
	vector<string> squares;
	cross(rows,cols,squares);

	//these are our rows,cols, and houses
	vector<vector<string>> unitlist;
	build_unitlist(unitlist);

	
	return 0;
}
