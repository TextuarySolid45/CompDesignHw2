//Group names: Lopez,Gabe and Noel
// Assignment: No.1
//   Due Date: September 9th
//	Purpose: This program reads an expression in postfix form, 
//			 evaluates the expression and displays its value

//using list and iosteam libraries 
#include<iostream>
#include<string>
#include<list>
using namespace std;

//functions that return if a string is a operator, operant or variable 
bool isOperation(string c);
bool isDigit(string s);
bool isVariable(string s);

int main() {

	//initiate list
	list<int> s;
	list<string>  l;
	

	//while statement connected to continue question at the end
	bool contin = true;
	while (contin) {
		
		//int values that will be used to store
		//data that is gonna be computed 
		int a, b;

		//input character and prompt user to enter info
		string in;
	
		std::cout << "Enter a postfix expression with $ at the end: ";
		while(in != "$"){
			l.push_front(in);
			std::cin >> in;

		}
		
	
		//while loop that will break when the exit character is entered
		string input = l.front();
		while (input !) {

			//if the input is a digit
			if (isDigit(input)) {
				s.push_front(stoi(input));

			//if the input is a operation 
			}else if (isOperation(input)) {
				//switch case for input = operation 
				switch (input[0]) {

				case '+':
					//get front value
					a = s.front();
					//pop front value
					s.pop_front();
					//get seccond front value
					b = s.front();
					//pop second front value
					s.pop_front();
					//push to the front the result of the operation
					s.push_front(a + b);
					//break case
					break;

				case '-':
					a = s.front();
					s.pop_front();
					b = s.front();
					s.pop_front();
					s.push_front(b-a);
					break;

				case '*':
					a = s.front();
					s.pop_front();
					b = s.front();
					s.pop_front();
					s.push_front(a * b);
					break;

				case '/':
					a = s.front();
					s.pop_front();
					b = s.front();
					s.pop_front();
					s.push_front(b/a);
					break;

				default:
					std::cout << "Default" << endl;
				}
			}
			//if the input is a undefined variable 
			else {
				std::cout << "Enter the value for " << input << ": ";
				int val; std::cin >> val;
				s.push_front(val);
			}
		
			l.pop_front();
		}

		//When escape key is entered, the calculated value will be displayed
		//and the stack poped off the last element
		std::cout << "\tValue: "<<s.front()<<endl;
		s.pop_front();

		//The user is prompted is they want to continue
		std::cout << "CONTINUE(y/n) ";
		char ans;
		std::cin >> ans;
		if ('n' == tolower(ans)) {
			break;
		}
	}
	system("pause");
	return 0;
}

//true if the spring is a operation and false if otherwise
bool isOperation(string s) {
	if (s == "+" || s == "-" || s == "*" || s == "/") { return true; }
	else { return false; }
}

//true if all characters in the string are a digit and are not a space
bool isDigit(string s) {
	for (int i = 0; i < s.length(); i++){
		if (!isdigit(s[i]) && !isspace(s[i])) {
			return false;
		}
	}
	return true;
}

//true if it finds a alphanumeric character that is not a digit 
//and false otherwise
bool isVariable(string s) {
	for (int i = 0; i < s.length(); i++) {
		if (isalpha(s[i]) && !isdigit(s[i])) {
			return true;
		}
	}
	return false;
}