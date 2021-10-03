#include<iostream>
using namespace std;

class Element
{
	static int count;
	int Data;			//Значение элемента
	Element* pNext;		//Адрес следующего элемента
public:
	Element(int Data, Element* pNext = nullptr) :Data(Data), pNext(pNext)
	{
		count++;
		cout << "EConstructor\t" << this << endl;
	}
	~Element()
	{
		count--;
		cout << "EDestructor\t" << this << endl;
	}
	friend class ForwardList;
	friend class Iterator;
};

int Element::count = 0;


class ForwardList
{
	Element* Head;		//Голова списка - указывает на начальный (нулевой) эл. списка
	size_t size;
public:
	class Iterator
	{
		Element* Temp;
	public:
		Iterator(Element* Temp = nullptr) :Temp(Temp)
		{
			cout << "ItConstructor:\t" << this << endl;
		}
		~Iterator()
		{
			cout << "ItDestructor:\t" << this << endl;
		}
		Iterator& operator++()
		{
			Temp = Temp->pNext;
			return *this;
		}
		bool operator==(const Iterator& other)const
		{
			return this->Temp == other.Temp;
		}
		bool operator!=(const Iterator& other)const
		{
			return this->Temp != other.Temp;
		}

		int& operator*()
		{
			return Temp->Data;
		}
	};
	Iterator begin()
	{
		return this->Head;
	}
	Iterator end()
	{
		return nullptr;
	}
public:
	ForwardList()
	{
		//Конструктор по умолчанию создает пустой список. 
		Head = nullptr;
		size = 0;
		//Если голова указывает на 0, то список пуст, т.е. не содержит элементов.
		//И голове больше не на что указывать.
		cout << "LConstructor\t" << this << endl;
	}
	~ForwardList()
	{
		while (Head)pop_front();
		cout << "LDestructor\t" << this << endl;
	}
	ForwardList(const initializer_list<int>& il) :ForwardList()
	{
		cout << typeid(il.begin()).name() << endl;
		for (int const* it = il.begin(); it != il.end(); it++)
		{
			this->push_back(*it);
		}
	}
	ForwardList(const ForwardList& other):ForwardList()
	{
		for (Element* Temp = other.Head; Temp; Temp = Temp->pNext) push_back(Temp->Data);
		//Конструктор копирования выпоняет Deep Copy
	}

	//					Operators:
	ForwardList& operator=(const ForwardList& other)
	{
		//1) Удаляем старое значение объекта 
		while (Head)pop_front();
		//2) Выполняем побитовое копирование 
		for (Element* Temp = other.Head; Temp; Temp = Temp->pNext) 
			push_back(Temp->Data);
		return *this;
	}

	//					Adding Elements 
	void push_front(int Data)
	{
		//1)Создаем новый элемент 
		Element* New = new Element(Data);
		//2)Прикрепляем елемент к списку 
		New->pNext = Head;
		//3)Говорим что новый элемент теперь начальный элемент списка 
		Head = New;
		
		size++;
	}
	void push_back(int Data)
	{
		if (Head == nullptr) return push_front(Data);
		Element* Temp = Head;
		while (Temp->pNext)
		{
			Temp = Temp->pNext;
		}
		//Element* New = new Element(Data);
		//Temp->pNext = New;
		Temp->pNext = new Element(Data);
		size++;
	}
	void insert(int index, int Data)
	{
		if (index == 0)return push_front(Data);
		if (index >= size)return push_back(Data);
		Element* Temp = Head;
		for (int i = 0; i < index-1; i++)Temp = Temp->pNext;
		Element* New = new Element(Data);
		New->pNext = Temp->pNext;
		Temp->pNext = New;
		size++;
	}

	//					Removing Elements
	void pop_front()
	{
		//1) Запоминаем адрес удаляемого элемента
		Element* erased = Head;
		//2) Исключаем элемент из списка
		Head = Head->pNext;
		//3) Удаляем элемент из памяти.
		delete erased;
		size--;
	}
	void pop_back()
	{
		//1) Доходим до конца списка
		Element* Temp = Head;
		while (Temp->pNext->pNext)Temp = Temp->pNext;
		//2	Удаляем элемент из памяти
		delete Temp->pNext;
		//3)Забываем об удаленном элементе.
		Temp->pNext = nullptr;
		size--;
	}

		//				Methods:
	void print()const
	{
		Element* Temp = Head;  //Temp - это итератор
		//Итератор - это указатель, при помощи которого можно получить доступ к элементам стр. данных
		//while (Temp!=nullptr)
		//{
		//	cout << Temp << "\t" << Temp->Data << "\t" << Temp->pNext << endl;
		//	Temp = Temp->pNext; //Переход на след. элемент.
		//}
		for(Element* Temp=Head; Temp; Temp=Temp->pNext)
			cout << Temp << "\t" << Temp->Data << "\t" << Temp->pNext << endl;

		cout << "Общее кол-во элементов" << Element::count << endl;
		cout << "Кол-во элементов списка" << size << endl;
	}
	
};
#define delimiter "\n-----------------------------------------------------------\n"
//#define BASE_CHECK

void main()
{
	setlocale(LC_ALL, "Russian");
#ifdef BASE_CHECK
	int n;
	cout << "Введите размер списка: ";
	cin >> n;
	ForwardList list;
	for (int i = 0; i < n; i++)
	{
		//list.push_front(rand() % 100);
		list.push_back(rand() % 100);
	}
	list.print();
	int index;
	int value;
	/*cout << "Введите индекс: "; cin >> index;
	cout << "Введите значение: "; cin >> value;
	list.insert(index, value);
	list.print();   */
#endif // BASE_CHECK

	ForwardList list = { 3,5,8,13,21 };
	list.print();
	cout << delimiter << endl;
	for (int i : list)
	{
		cout << i << "\t";
	}
	cout << endl;
	cout << delimiter << endl;
	/*for (ForwardList::Iterator it = list.begin(); it != list.end(); ++it)
	{
		cout << *it << endl;
	}
	cout << endl;*/
	cout << delimiter << endl;

	//ForwardList list2;
	//list2 = list;
	//list2.print();
}