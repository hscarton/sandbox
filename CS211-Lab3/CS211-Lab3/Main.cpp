#include <iostream>
#include <stack>
#include "StringSplitter.h"
#include <string>
#include <fstream>
#include <string>

using namespace std;

double evaluatePostfixExpression(string postfix_string)
{
	double result = 0;
	stack<double> postfix_stack{};
	vector<string> pieces = StringSplitter::split(postfix_string, " ");
        double temp = 0;

	//TODO: evaluate pieces as a postfix expression

	for (auto i : pieces)
	{
                //cast i as an int and check whether it is a digit
            
		if (isdigit(stoi(i)))
		{
                    //then push to the stack
                    
                    postfix_stack.push(stod(i));
		}
		
                //if the string is not a digit, it must be an operator
                //determine which operator it is, and do the operation
                //on the first two elements in the stack
                
                else
		{
		    if(i == "+")
                    {
                        temp = postfix_stack.top();
                        postfix_stack.pop();
                        temp += postfix_stack.top();
                    }
                    else if(i == "-")
                    {
                        temp = postfix_stack.top();
                        postfix_stack.pop();
                        temp -= postfix_stack.top();
                    }
                    else if(i == "*")
                    {
                        temp = postfix_stack.top();
                        postfix_stack.pop();
                        temp = temp * postfix_stack.top();
                    }
                    else if(i == "/")
                    {
                        temp = postfix_stack.top();
                        postfix_stack.pop();
                        temp = temp / postfix_stack.top();
                    }
		}
                /*
                while(postfix_stack.empty() == false)
                {
                    //in STL, we use top() to get the top item, pop()
                    //returns nothing
                    cout << postfix_stack.top();
                    
                    //pop is only used to remove the top-most item from 
                    //the stack
                    //postfix_stack.pop();
                }
                 
	}
        
        postfix_stack.pop();
 */
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
			//declare functions static if they do not operate on any instance
			double result = evaluatePostfixExpression(current_line);
			cout << current_line << " = " << result << endl;
			
		}
	}

	return 0;

}