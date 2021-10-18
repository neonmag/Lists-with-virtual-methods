#include <iostream>

using namespace std;

struct Element
{
	// Данные
	int data;
	// Адрес следующего элемента списка
	Element* Next;
};

class Queue
{
	int count;
	int maxCount;
	Element* Head;
	Element* Tail;
public:
	Queue(int count);
	~Queue();
	void Delete();
	virtual void Add(int c);
	virtual void Extract();
	int GetCount();
	void Output();
};

template <class S>
class Stack
{
	int count;
	S* Top;
	S* Bot;
public:
	Stack();
	virtual void Push(char symb);
	bool IsEmpty();
	bool IsFull();
	int GetCount();
	void Output();
	virtual void Delete();
	virtual void DeleteAll();
	~Stack();
};

void main()
{
	Queue QU(10);
	for (int i = 0; i < 10; i++)
	{
		QU.Add(i);
	}
	QU.Output();

	system("pause");

	srand(time(0));
	Stack<Element> ST;
	char c;
	// пока стек не заполнится
	/*while (!ST.IsFull())
	{
		c = rand() % 4 + 2;
		ST.Push(c);
	}*/
	for (int i = 0; i < 15; i++)
	{
		c = rand() % 4 + 2;
		ST.Push(c);
	}
	ST.Output();
	ST.DeleteAll();
	cout << "\n\n";
	ST.Output();


	system("pause");
}

Queue::Queue(int count)
{
	maxCount = count;
	count = 0;
	Head = Tail = NULL;
}

Queue::~Queue()
{
	while (Head != 0)
	{
		Delete();
	}
}

void Queue::Delete()
{
	Element* element = Head;
	Head = Head->Next;
	delete element;
	count--;
}

void Queue::Add(int c)
{
	Element* element = new Element;
	element->data = c;
	element->Next = NULL;
	if (Head != NULL)
	{
		Tail->Next = element;
		Tail = element;
	}
	else
	{
		Head = Tail = element;
	}
	count++;
}

void Queue::Extract()
{
	Element* element = Head;
	Head = Head->Next;
	count--;
	delete element;

}

int Queue::GetCount()
{
	return count;
}

void Queue::Output()
{
	Element* element = Head;
	while (element != 0)
	{
		cout << element->data << " ";
		element = element->Next;
	}
}

template<class S>
Stack<S>::Stack()
{
	Top = Bot = NULL;
	count = 0;
}

template<class S>
void Stack<S>::Push(char symb)
{
	Element* element = new Element;
	element->data = symb;
	element->Next = NULL;
	if (Top != 0)
	{
		Bot->Next = element;
		Bot = element;
	}
	else
	{
		Top = Bot = element;
	}
	count++;
}

template<class S>
bool Stack<S>::IsEmpty()
{
	return Bot == 0;
}

template<class S>
bool Stack<S>::IsFull()
{
	return Bot == 0;
}

template<class S>
int Stack<S>::GetCount()
{
	return count;
}

template<class S>
void Stack<S>::Output()
{
	Element* element = Top;
	while (element != NULL)
	{
		cout << element->data << " ";
		element = element->Next;
	}
}

template<class S>
void Stack<S>::Delete()
{
	Element* element = Top;
	Top = Top->Next;
	delete element;
	count--;
}

template<class S>
void Stack<S>::DeleteAll()
{
	while (Top != 0)
	{
		Delete();
	}
	cout << "\nDeleted\n";
}

template<class S>
Stack<S>::~Stack()
{
	DeleteAll();
}
