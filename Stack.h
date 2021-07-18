#pragma once
template <typename T>
class Stack
{
public:
	Stack();
	~Stack();
	void push(T data);
	void pop();
	void clear();
	bool isEmpty();
	int top();
	int GetSize();
	T parse(T data); //findValue P.S If not found - return -1.

	typedef Node* iterator;
	iterator GetBegin() { return head; }
	iterator GetNext(iterator it) { if (it) return it->pNext; }
	T GetValue(iterator it)
	{
		if (it) return it->data;
	}
private:
	template<typename T>
	class Node
	{
		Node* pNext;
		T data;
		Node(T data = T(), Node* pNext = nullptr)
		{
			this->data = data;
			this->pNext = pNext;
		}
	};
	int size;
	Node<T>* head;
};

template<typename T>
inline Stack<T>::Stack()
{
	size = 0;
	head = nullptr;
}

template<typename T>
inline Stack<T>::~Stack() { clear(); }

template<typename T>
inline void Stack<T>::push(T data)
{
	Node<T>* current = new Node<T>(data, this->head);
	head = current;
	++size;
}

template<typename T>
inline void Stack<T>::pop()
{
	Node<T>* temp = head;
	head = head->pNext;
	delete temp;
	--size;
}

template<typename T>
inline bool Stack<T>::isEmpty()
{
	if (head == nullptr) return true;
	else return false;
}

template<typename T>
inline int Stack<T>::top() { return head->data; }

template<typename T>
inline int Stack<T>::GetSize() { return size; }

template<typename T>
inline T Stack<T>::parse(T data) //findValue
{
	int counter = 0;
	Node* current = head;
	while (current != nullptr)
	{
		if (current->data == data) return counter;
		current = current->pNext;
		++counter;
	}
	return -1;
}

template<typename T>
inline void Stack<T>::clear() { while (size) pop(); }
