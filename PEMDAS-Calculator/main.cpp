#include <iostream>
#include <stdio.h>
#include <string>
#include <queue>
#include <stack>
#include <map>

void showStack(std::stack<char>);
void showQueue(std::queue<int>);
void clearQueue(std::queue<int>& outputQueue);
void clearStack(std::stack<char>& operatorStack);
bool checkIfNumber(char character);
int getPrecedence(char character);
int getAssociativity(char character);

int main() {

<<<<<<< HEAD
	struct Operators {
		char op;
		int precendence;
		//0 -> Right
		//1 -> Left
		int associativity;
	};

	Operators operations[5];

	operations[0] = { '+', 0, 1 };
	operations[1] = { '-', 0, 1 };
	operations[2] = { '/', 1, 1 };
	operations[3] = { '*', 1, 1 };
	operations[4] = { '^', 2, 0 };

=======
	std::map<char, int> operators;
>>>>>>> 81892d58ff4c0dac2c7efda6c09df13e2326a772
	std::string expression;
	std::queue<int> outputQueue;
	std::stack<char> operatorStack;
	int i;

	std::cout << "Enter expression" << std::endl;
	std::getline(std::cin, expression);
	expression.erase(remove(expression.begin(), expression.end(), ' '), expression.end());

	int opIndex;

	for (int i = 0; i < expression.length(); i++) {

		int index = i;
<<<<<<< HEAD
		if (isdigit(expression[index])) {
=======
		if (isdigit(expression[i])) {
>>>>>>> 81892d58ff4c0dac2c7efda6c09df13e2326a772
			std::string fullNumber;
			while (isdigit(expression[index])) {
				fullNumber += expression[index];
				index++;
			}
			outputQueue.push(std::stoi(fullNumber));
		}

		if (expression[index] == '+' || expression[index] == '-' || expression[index] == '/' || expression[index] == '*' || expression[index] == '^') {
			for (int j = 0; j < 5; j++) {
				if (expression[index] == operations[j].op) {
					opIndex = j;
				}
			}

			while (!operatorStack.empty() && (operatorStack.top() == '+' || operatorStack.top() == '-' || operatorStack.top() == '/' || operatorStack.top() == '*' || operatorStack.top() == '^')) {
				if ((getAssociativity(expression[index]) == 1 && (getPrecedence(expression[index]) <= getPrecedence(operatorStack.top()))) || (getAssociativity(expression[index]) == 0 && (getPrecedence(expression[index]) < getPrecedence(operatorStack.top())))) {
					outputQueue.push(operatorStack.top());
					operatorStack.pop();
				}
			}
			operatorStack.push(expression[index]);
		}

		if (expression[index] == '(') {
			operatorStack.push(expression[index]);
		}
		if (expression[index] == ')') {
			while (!operatorStack.empty() && operatorStack.top() != '(') {
				outputQueue.push(operatorStack.top());
				operatorStack.pop();
			}
			operatorStack.pop();
		}
		i = index;
	}

	std::cout << "Operator Stack: " << std::endl;
	showStack(operatorStack);
	std::cout << std::endl;
	std::cout << "Output Queue:" << std::endl;
	showQueue(outputQueue);

	clearQueue(outputQueue);
	clearStack(operatorStack);
	operators.clear();

	return 0;

}


void showStack(std::stack<char> operatorStack) {
	while (!operatorStack.empty()) {
		std::cout << static_cast<char>(operatorStack.top()) << " ";
		operatorStack.pop();
	}
	std::cout << std::endl;
}

void showQueue(std::queue<int> outputQueue) {
	while (!outputQueue.empty()) {
		std::cout << outputQueue.front() << " ";
		outputQueue.pop();
	}
	std::cout << std::endl;
}

void clearQueue(std::queue<int>& outputQueue) {
	std::queue<int> emptyQueue;
	std::swap(outputQueue, emptyQueue);
}

void clearStack(std::stack<char>& operatorStack) {
	std::stack<char> emptyStack;
	std::swap(operatorStack, emptyStack);
}

bool checkIfNumber(char character) {
	return (isdigit(character) ? true : false);
}

int getPrecedence(char character) {
	switch (character) {
	case '+':
	case '-': {
		return 0;
	}
	case '/':
	case '*': {
		return 1;
	}
	case '^': {
		return 2;
	}
	}
}

int getAssociativity(char character) {
	switch (character) {
	case '+':
	case '-':
	case '/':
	case '*': {
		return 1;
	}
	case '^': {
		return 0;
	}
	}
}