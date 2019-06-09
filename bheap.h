#pragma once
#include <iostream>
using namespace std;
namespace bheap_STL {
	template <typename T> class bheap
	{
		private:

		public:
			bheap();
			bheap(const bheap& _Right);
			~bheap();
			bool empty() { return true; }; //boris
			size_t size() { return 0; }; //boris
			void clear();
			void insert();
			void swap(T other); //boris

	};



	template <typename T> bheap<T>::bheap()
	{
		
		cout << "Constructor by-default" << endl;
	}

	template <typename T> bheap<T>::~bheap()
	{
		cout << "Destructor" << endl;
	}

	template <typename T> bheap<T>::bheap(const bheap& _Right)
	{
		cout << "Copy constructor" << endl;
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
