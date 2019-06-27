#pragma once
#include <iostream>
#include <iterator>
#include <algorithm>
using namespace std;
namespace bheap_STL {
	template <typename T>  //forward declare to make function declaration possible
	class bheap;
	
	template <typename T>  // declaration
	ostream& operator<<(ostream& os, const bheap<T>& );

	template <typename T> 
	class bheap
	{
		private:
			const size_t _DEFAULT_LIMIT = 20;
			size_t _size;	//current size of queue
			size_t _limit;	//current limit of queue
			T *_queue;
			void heapify() noexcept;
		public:
			bheap();
			bheap(const unsigned int n);
			bheap(const bheap& _Right);
			~bheap();
			bool empty() noexcept { return _size == 0; };
			size_t size() noexcept { return _size; }; 
			void clear()noexcept {
				delete[] _queue;
				_size = 0;
				_limit = _DEFAULT_LIMIT;
			};
			void insert(T value);

			friend ostream& operator<< <T>(ostream& os, const bheap<T>& rhs) ;

	};

	template <typename T> ostream& operator<<(ostream& os, const bheap<T>& rhs) {
		if (rhs._size)
			copy(rhs._queue + 1, rhs._queue + rhs._size + 1, ostream_iterator<T>(os, "  "));
		return os;
	}
	template <typename T> bheap<T>::bheap()
	{
		cout << "Constructor by-default" << endl;
		_limit = _DEFAULT_LIMIT;
		_size = 0;
		_queue = new T[_limit];
		
	}

	template <typename T> bheap<T>::~bheap()
	{
		cout << "Destructor" << endl;
		if (_queue)
			delete[] _queue;
	}

	template <typename T> bheap<T>::bheap(const bheap& _Right)
	{
		cout << "Copy constructor" << endl;
	}


	template <typename T> void bheap<T>::insert(T value)
	{
		cout << "insert" << endl;
		if ( (_limit - _size) < (_size / 2) ) { //if container fill on half, get new memory and copy queue to new place
			cout << "increase the queue" << endl;
			_limit *= 2;
			try {
				T* tmp = new T[_limit];

			}
			catch (...){
				cout << "something bad" << endl;
			}
			//TODO boris - make copy 
		}
		
		++this->_size;
		_queue[this->_size] = value;
		
		heapify();
		
	}

	template <typename T> void bheap<T>::heapify() noexcept
	{
		cout << "heapify" << endl;
		// heapify, push to up
		for (size_t i = this->_size; i > 1 && _queue[i] > _queue[i / 2]; i = i / 2)
		{
			swap(_queue[i], _queue[i / 2]);
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
struct Heap_item heap_max(const struct Heap* heap);
void            heap_display(struct Heap* heap);
int             heap_insert(struct Heap* heap, int priority, char* value, const unsigned long data);
int             heap_removemax(struct Heap* heap, struct Heap_item* value);
unsigned int    heap_size(struct Heap* heap);

*/
