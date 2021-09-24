﻿#include<iostream>
using namespace std;

void main()
{
	setlocale(LC_ALL, "Russian");
	const int n = 5;
	int arr[n] = { 3,5,8,13,21 };
	cout << arr << endl;
	for (int i = 0; i < n; i++)
	{
		cout << *(arr + i) << "\t";
		cout << endl;
	}
}
/*
						ДИНАМИЧЕСКИЕ СТРУКТУРЫ ДАННЫХ
Простейшей структурой данных является массив.
Массив - это набор элементов одного типа в непрерывной области памяти.
Из непрерывной области памяти вытекают и преимущества и недостатки массивов. 
Преимущества массивов: Главным преимуществом массивов по сравнению с другими стр. данных 
является быстрый доступ к элементам, который осуществляется за константное время, поскольку сводится к операции сложения.
А операцию сложения процессор всегда выполняет за одно и то же время(затрачивает одно и то же кол-во тактов на выполнение)
Главным недостатком массивов является сложность добавления/удаления элементов, которая приводит к дополнительным затратам ресурсов памяти и процессорного времени
Недостатки массивов устраняют списки. Список (List) - это набор элементов в произвольных областях памяти, каждый из которых содержит адрес след. элемента. 
Последний элемент списка указывает на ноль.
Главным преимуществом списка по сравнению с массивом является быстрое добавление/удаление элементов, которе осуществляется за конст. время и не требует доп. затрат памяти.
Для того чтобы добавить в список элемент не нужно копировать весь список в другое место.
Главным недостатком списка является медленный доступ к элементам списка.
Время доступа к элементу списка зависит от размера списка. Чтобы прочитать последний элемент списка нужно пройти через все его элементы начиная с начального.
Списки бывают односвязные и двусвязные. Пока будем рассматривать только односвязный список.
						РЕАЛИЗАЦИЯ ОДНОСВЯЗНОГО СПИСКА
Односвязный список реализуется при помощи двух классов. Класс-элемент - описывает структуру элемента и класс-список.
Класс ForwardList объединяет элементы в список и отвечает за добавление элементов, удаление и прочии операции со списком. 
Статическая переменная является общей для всех объектов класса и ее можно проинициализировать только за классом

Initializer_list - это контейнер такой же, как и наш ForwardList. 
Контейнер - это объект, который организует хранение других объектов в памяти.
У любого контейнера есть методы:
//begin();  //Возвращает итератор на начало контейнера.
//end();	//Возвращает итератор на конец контейнера.

						ДВУСВЯЗНЫЙ СПИСОК 
Двусвязным называется список, каждый жлемент которого содержит указатель не только на след. но и на предыдущий элемент. 
Это дает возможность ходить по списку в обоих направлениях. Что уменьшает время поиска элемента в два раза. 
У двусвязного списка есть не только голова, но и хвост. Когда двусвязный список пуст его голова и хвост указывают на ноль.
Когда в списке появляется первый элемент он одновременно является и головой и хвостом списка. 
Также он одновременно является и первым  и последним элементом списка с какой стороны не посмотреть.





*/