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

int main() {

	//std::vector<char> operators{ '+', '-', '/', '*', '(', ')' };
	std::map<char, int> operators;
	std::string expression;
	std::queue<int> outputQueue;
	std::stack<char> operatorStack;
	int i;

	std::cout << "Enter expression" << std::endl;
	std::getline(std::cin, expression);

	operators.insert(std::pair<char, int>('(', 1));
	operators.insert(std::pair<char, int>(')', 1));
	operators.insert(std::pair<char, int>('^', 2));
	operators.insert(std::pair<char, int>('*', 3));
	operators.insert(std::pair<char, int>('/', 3));
	operators.insert(std::pair<char, int>('+', 4));
	operators.insert(std::pair<char, int>('-', 4));

	for (i = 0; i < expression.length(); i++) {
		int index = i;
		char expressionToCheck = expression[i];
		if (isdigit(expression[i])) {
			std::string fullNumber;

			while (checkIfNumber(expression[index])) {
				fullNumber += expression[index];
				index++;
			}
			outputQueue.push(std::stoi(fullNumber));
		}
		else {
			std::map<char, int>::iterator mapIterator;
			for (mapIterator = operators.begin(); mapIterator != operators.end(); ++mapIterator) {
				if (mapIterator->first == expression[i]) {
					operatorStack.push(expression[i]);
				}
			}
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
		std::cout << outputQueue.front() << " ";
		outputQueue.pop();
	}
	std::cout << std::endl;
}

void clearQueue(std::queue<int> &outputQueue) {
	std::queue<int> emptyQueue;
	std::swap(outputQueue, emptyQueue);
}

void clearStack(std::stack<char> &operatorStack) {
	std::stack<char> emptyStack;
	std::swap(operatorStack, emptyStack);
}

bool checkIfNumber(char character) {
	return (isdigit(character) ? true :  false);
}