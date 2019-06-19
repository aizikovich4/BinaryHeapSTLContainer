#pragma once
#include <iostream>
using namespace std;
namespace bheap_STL {
	template <typename T> class bheap
	{
		private:
			size_t _size;
			size_t _limit;
			T *head;
		public:
			bheap();
			bheap(const unsigned int n);
			bheap(const bheap& _Right);
			~bheap();
			bool empty() noexcept { return _size; };
			size_t size() noexcept { return _size; }; 
			void clear();
			void insert(T value);
			void swap(T other); //boris

	};



	template <typename T> bheap<T>::bheap()
	{
		cout << "Constructor by-default" << endl;
		_size = 20;
		head = new T[_size];
		
	}

	template <typename T> bheap<T>::~bheap()
	{
		cout << "Destructor" << endl;
		if (head)
			delete[] head;
	}

	template <typename T> bheap<T>::bheap(const bheap& _Right)
	{
		cout << "Copy constructor" << endl;
	}


	template <typename T> void bheap<T>::insert(T value)
	{
		cout << "insert" << endl;
		if ( (limit - size) < (size / 2) ) { //if container fill on half, get new memory and copy all elements to new memory
			limit *= 2;
			T* tmp = new T[limit];


		}
		
	}


}
/*
struct Heap_item {
	int priority;               // priority of elemen
	unsigned long data;
	char* value;                // data
};

struct Heap {
	int maxsize;                 // max heap size
	int count_items;             // count of elements ih heap
	struct Heap_item* items;     //heap elements, we will stories them from first position, not from zero position
};

struct Heap* heap_create(int maxsize);
void            heap_free(struct Heap* h);
static void     heap_swap(struct Heap_item* first, struct Heap_item* second);
struct Heap_item heap_max(const struct Heap* heap);
void            heap_display(struct Heap* heap);
int             heap_insert(struct Heap* heap, int priority, char* value, const unsigned long data);
int             heap_removemax(struct Heap* heap, struct Heap_item* value);
unsigned int    heap_size(struct Heap* heap);

*/
