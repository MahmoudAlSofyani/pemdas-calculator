#include <iostream>
#include <stdio.h>
#include <string>
#include <queue>
#include <stack>
#include <map>

const int LEFT_ASSOC = 0;
const int RIGHT_ASSOC = 1;

void showStack(std::stack<char>);
void showQueue(std::queue<int>);
void clearQueue(std::queue<int>& outputQueue);
void clearStack(std::stack<char>& operatorStack);
bool checkIfNumber(char character);
int getPrecedence(char character);
int getAssociativity(char character);

int main() {

	std::string expression;
	std::queue<int> outputQueue;
	std::stack<char> operatorStack;
	int i;

	std::cout << "Enter expression" << std::endl;
	std::getline(std::cin, expression);
	expression.erase(remove(expression.begin(), expression.end(), ' '), expression.end());


	int expressionLength = expression.length();
	int counter = 0;

	while (expressionLength > 0) {
		char token = expression[counter];
	
		if (isdigit(token)) {
			outputQueue.push(token);
		}
		else if (token == '+' || token == '-' || token == '*' || token == '/' || token == '^') {
			while (!operatorStack.empty() && (operatorStack.top() == '+' || operatorStack.top() == '-' || operatorStack.top() == '*' || operatorStack.top() == '/' || operatorStack.top() == '^') && ((getPrecedence(operatorStack.top()) > getPrecedence(token) || (getPrecedence(operatorStack.top()) == getPrecedence(token)) && getAssociativity(token) == 0)) && (operatorStack.top() != '(')) {

				outputQueue.push(operatorStack.top());
				operatorStack.pop();
			}
			operatorStack.push(token);
		}
		else if (token == '(') {
			operatorStack.push(token);
		}
		else if (token == ')') {
			while (operatorStack.top() != '(') {
				outputQueue.push(operatorStack.top());
				operatorStack.pop();
			}
			if (operatorStack.top() == '(') {
				operatorStack.pop();
			}
		}
		expressionLength--;
		counter++;
	}

	while (!operatorStack.empty()) {
		outputQueue.push(operatorStack.top());
		operatorStack.pop();
	}

	

	std::cout << "Operator Stack: " << std::endl;
	showStack(operatorStack);
	std::cout << std::endl;
	std::cout << "Output Queue:" << std::endl;
	showQueue(outputQueue);

	clearQueue(outputQueue);
	clearStack(operatorStack);

	return 0;

}


void showStack(std::stack<char> operatorStack) {
	while (!operatorStack.empty()) {
		std::cout << operatorStack.top() << " ";
		operatorStack.pop();
	}
	std::cout << std::endl;
}

void showQueue(std::queue<int> outputQueue) {
	while (!outputQueue.empty()) {
		std::cout << static_cast<char>(outputQueue.front()) << " ";
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
		return 2;
	}
	case '/':
	case '*': {
		return 3;
	}
	case '^': {
		return 4;
	}
	}
}

int getAssociativity(char character) {

	// 0 - left
	// 1 - right

	switch (character) {
	case '+':
	case '-':
	case '/':
	case '*': {
		return LEFT_ASSOC;
	}
	case '^': {
		return RIGHT_ASSOC;
	}
	}
}