

#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

class IntStack
{
private:
	int* stackArray;
	int stackSize;
	int top;

public:

	IntStack(int size) {
		stackArray = new int[size];
		stackSize = size;
		top = -1;
	}

	IntStack(const IntStack& obj) {
		if (obj.stackSize > 0)
			stackArray = new int[obj.stackSize];
		else
			stackArray = nullptr;

		stackSize = obj.stackSize;

		for (int count = 0; count < stackSize; count++)
			stackArray[count] = obj.stackArray[count];

		top = obj.top;
	}

	~IntStack() {
		delete[] stackArray;
	}

	void push(int num)
	{
		if (isFull())
		{
			cout << "The stack is full.\n";
		}
		else
		{
			top++;
			stackArray[top] = num;
		}
	}
	void pop(int& num)
	{
		if (isEmpty())
		{
			cout << "The stack is empty.\n";

		}
		else {
			num = stackArray[top];
			top--;
		}
	}
	bool isFull() const {
		bool status;

		if (top == stackSize - 1)
			status = true;
		else
			status = false;

		return status;
	}
	bool isEmpty() const
	{
		bool status;

		if (top == -1)
			status = true;
		else
			status = false;

		return status;
	}
};

class MathStack : public IntStack
{
public:

	MathStack(int s) : IntStack(s) {}

	void add()
	{
		int num, sum;

		pop(sum);
		pop(num);

		sum += num;
		push(sum);
		
	}

	void sub()
	{
		int num, diff;

		pop(diff);
		pop(num);

		diff -= num;

		push(diff);
	}

	void mult()
	{
		int num, product;

		pop(product);
		pop(num);

		product = product * num;
		push(product);
	}

	void div()
	{
		int num, quotient;

		pop(quotient);
		pop(num);

		quotient = quotient / num;
		push(quotient);
	}

	void addAll()
	{
		int num, sum = 0;
		
		while (!isEmpty())
		{
			pop(num);
			sum += num;
		}
		

		push(sum);
	}

	void multAll()
	{
		int num, product;
		 
		product = isEmpty() ? 0 : 1;

		while (!isEmpty())
		{
			pop(num);
			product = product * num;
		}


		push(product);
	}
};

int main()
{
	int catchVar;

	MathStack stack(5);

	cout << "Pushing 3\n";
	stack.push(3);
	cout << "Pushing 6\n";
	stack.push(6);

	stack.add();

	cout << "The sum is ";
	stack.pop(catchVar);
	cout << catchVar << endl << endl;

	cout << "Pushing 7\n";
	stack.push(7);
	cout << "Pushing 10\n";
	stack.push(10);

	stack.sub();

	cout << "The difference is ";
	stack.pop(catchVar);
	cout << catchVar << endl;
	

	cout << "Pushing 8\n";
	stack.push(8);
	cout << "Pushing 9\n";
	stack.push(9);

	stack.mult();

	cout << "The product is ";
	stack.pop(catchVar);
	cout << catchVar << endl;

	cout << "Pushing 2\n";
	stack.push(2);
	cout << "Pushing 4\n";
	stack.push(4);

	stack.div();

	cout << "The quotient is ";
	stack.pop(catchVar);
	cout << catchVar << endl;

	cout << "Pushing 10\n";
	stack.push(10);
	cout << "Pushing 11\n";
	stack.push(11);
	cout << "Pushing 12\n";
	stack.push(12);
	

	stack.addAll();

	cout << "The sum of all values is ";

	stack.pop(catchVar);

	cout << catchVar << endl;

	cout << "Pushing 2\n";
	stack.push(2);
	cout << "Pushing 4\n";
	stack.push(4);
	cout << "Pushing 13\n";
	stack.push(13);
	

	
	stack.multAll();

	cout << "The product is of all values is ";

	stack.pop(catchVar);

	cout << catchVar << endl;

	
}