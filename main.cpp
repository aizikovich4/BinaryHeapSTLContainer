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
	bheap<int> heapasd;
	bheap<float> a;
	cout << a.empty() << endl;
	heapasd.insert(2);
	heapasd.insert(4);
	cout << heapasd << endl;
	cout << a << endl;

}
