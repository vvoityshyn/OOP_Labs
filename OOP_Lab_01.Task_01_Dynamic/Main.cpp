#include <iostream>

using namespace std;

class Stack
{
private:
	//static const int MAX_ITEMS_NUMBER = 100;
	int maxItemsNumber;
	int *items;
	int itemsNumber;
public:
	Stack(int capacity);
	~Stack();

	void push(int item);
	int pop();
	int peak();
	int size();
	int capacity();
};

int main()
{
	Stack *stack = new Stack(10);

	stack->push(1);
	stack->push(2);
	stack->push(3);
	stack->push(4);
	stack->push(5);

	cout << "Capacity: " << stack->capacity() << endl;
	cout << "Stack size: " << stack->size() << endl;

	int item;
	item = stack->pop();
	cout << "Item: " << item << " (size: " << stack->size() << ")" << endl;
	item = stack->pop();
	cout << "Item: " << item << " (size: " << stack->size() << ")" << endl;
	item = stack->pop();
	cout << "Item: " << item << " (size: " << stack->size() << ")" << endl;
	item = stack->pop();
	cout << "Item: " << item << " (size: " << stack->size() << ")" << endl;
	item = stack->pop();
	cout << "Item: " << item << " (size: " << stack->size() << ")" << endl;

	// error
	//item = stack.pop();

	delete stack;
	
	system("pause");
	return 0;
}

Stack::Stack(int capacity)
{
	cout << "Stack(int capacity)" << endl;
	this->items = new int[capacity];
	this->maxItemsNumber = capacity;
	this->itemsNumber = 0;
}
Stack::~Stack()
{
	delete [] this->items;
	cout << "~Stack()" << endl;
}
void Stack::push(int item)
{
	if (this->itemsNumber >= this->capacity())
	{
		throw "The stack is full";
	}
	this->items[this->itemsNumber] = item;
	this->itemsNumber += 1;
}
int Stack::pop()
{
	if (this->itemsNumber <= 0)
	{
		throw "The stack is empty";
	}
	int item = this->items[this->itemsNumber - 1];
	this->items[this->itemsNumber - 1] = 0;
	this->itemsNumber -= 1;
	return item;
}
int Stack::peak()
{
	if (this->itemsNumber <= 0)
	{
		throw "The stack is empty";
	}
	return this->items[this->itemsNumber - 1];
}
int Stack::size()
{
	return this->itemsNumber;
}
int Stack::capacity()
{
	return this->maxItemsNumber;
}