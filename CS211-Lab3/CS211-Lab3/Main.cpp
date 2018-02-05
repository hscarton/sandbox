#include <iostream>
#include <stack>
#include "StringSplitter.h"
#include <string>
#include <fstream>
#include <ctype>
#include <string>

using namespace std;

double evaluatePostfixExpression(string postfix_string)
{
	double result = -1;
	stack<double> postfix_stack{};
	vector<string> pieces = StringSplitter::split(postfix_string, " ");

	//TODO: evalute pieces as a postfix expression

	for (auto i : pieces)
	{

		if (isdigit(stoi(i)))
		{
			postfix_stack.push(stoi(i));
		}
		else
		{
			
		}
	}

	return result;
}
int main(void)
{
	//prompt user for file to open
	string file_to_open;
	cout << "Enter file name: ";
	getline(cin, file_to_open);

	//open file
	ifstream input_file{ file_to_open };

	//safety checking
	if (input_file.is_open())
	{
		//read from the file as long as more content is available
		while (input_file.good())
		{
			string current_line;
			getline(input_file, current_line);
			//static method/functions do not belong to ANY class of that type
			//declare funcitons static if they do not operate on any instance
			double result = evaluatePostfixExpression(current_line);
			cout << current_line << " = " << result << endl;
			
		}
	}

	return 0;

}