//TODO
//1. Сам алгоритм бинарной кучи
//2. Оформить как контейнер с минимальным функционалом - конструктор, деструктор, конструктор копирования, перемещения, push/pop, размер, итераторы(какие вообще для такого контейнера доступны?)
//4. GTEST, ну и со стандартными алгоритмами бы проверить 
//5. создать cmake файл потом для сборки под linux
#include "bheap.hpp"

#include <iostream>
#include <set>

using namespace bheap_STL;

int main()
{
	bheap<int> heap;
	bheap<int> heap2;	

	for(auto i=0; i<20; ++i)
		heap.insert(i);
	
	for (auto i = 0; i < 40; ++i)
		heap2.insert(i);

	heap.swap(heap2);

	cout << heap << endl;

}
