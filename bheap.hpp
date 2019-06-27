#pragma once
#include <iostream>
#include <iterator>
#include <algorithm>
#include <memory>
#include <vector>

using namespace std;
namespace bheap_STL {
	template <typename T> 
		class bheap; //forward declare to make function declaration possible
	
	template <typename T>  
		ostream& operator<<(ostream& os, const bheap<T>& ); // declaration

	template <typename T> 
		class bheap
	{
		private:
			vector<T> _data;
			void heapify() noexcept;
		public:
			bheap();
			bheap(initializer_list<T> values);
			bheap(const unsigned int n);
			bheap(const bheap& rhs);
			bool empty() const noexcept { return _data.empty(); };
			size_t size()const noexcept { return _data.size(); };
			size_t max_size()const noexcept { return _data.max_size(); };
			void swap(bheap<T>& other);

			void clear()const noexcept { _data.clear(); };
			void insert(T value);
			friend ostream& operator<< <T>(ostream& os, const bheap<T>& rhs) ;
			bool operator==(const bheap<T>& rhs) { return (this->_data == rhs._data); };
			bool operator!=(const bheap<T>& rhs) { return !(*this == rhs); };
			bheap<T>& operator=(const bheap<T>& rhs) { 
				this->_data = rhs._data;
				heapify(); 
				return *this; 
			};
			bheap<T>& operator=(const std::initializer_list<T> rhs) {
				copy(rhs._data(), rhs._data(), _data.begin());
				heapify(); 
				return *this;
			};

	};
	
	template <typename T> bheap<T>::bheap()
	{
				
	}
	
	template <typename T> bheap<T>::bheap(initializer_list<T> values) 
	{
		std::copy(values.begin(), values.end(), _data.begin());
	}

	
	template <typename T> bheap<T>::bheap(const bheap<T>& rhs)
	{
		cout << "Copy constructor" << endl;
		if (*this != rhs)
			_data = rhs._data;
	}

	template <typename T> void bheap<T>::swap(bheap<T>& other)
	{
			bheap<T> temp(other);
			other = *this;
			*this = temp;
	}	

	template <typename T> void bheap<T>::insert(T value)
	{
		cout << "insert" << endl;
		_data.push_back(value);
		heapify();
		
	}

	template <typename T> void bheap<T>::heapify() noexcept
	{
		cout << "heapify" << endl;
		size_t i = 0;
		// heapify, push to up
		if ((i=_data.size()-1) > 1)
		{	
			for (;i > 1 &&  _data[i] > _data[i / 2]; i = i / 2)
			{
				std::swap(_data[i], _data[i / 2]);
			}
		}
	}

	template <typename T> ostream& operator<<(ostream& os, const bheap<T>& rhs) {
		if (rhs._data.size())
			copy(rhs._data.begin()+1, rhs._data.end(), ostream_iterator<T>(os, "  "));
		return os;
	}

	
	///-----------------iterator realization---------------------

	template<typename T> 
		class BHeapIterator : public std::iterator<std::input_iterator_tag, T>
	{
		friend bheap;
	private:
		BHeapIterator(T* p);
	public:
		BHeapIterator(const BHeapIterator& it);

		bool operator!=(BHeapIterator const& other) const;
		bool operator==(BHeapIterator const& other) const; //need for BOOST_FOREACH
		typename BHeapIterator::reference operator*() const;
		BHeapIterator& operator++();
	private:
		T* p;
	};

	template<typename T>
	BHeapIterator<T>::BHeapIterator(T* p) :
		p(p)
	{

	}

	template<typename T>
	BHeapIterator<T>::BHeapIterator(const BHeapIterator& it) :
		p(it.p)
	{

	}

	template<typename T>
	bool BHeapIterator<T>::operator!=(BHeapIterator const& other) const
	{
		return p != other.p;
	}

	template<typename T>
	bool BHeapIterator<T>::operator==(BHeapIterator const& other) const
	{
		return p == other.p;
	}

	template<typename T>
	typename BHeapIterator<T>::reference BHeapIterator<T>::operator*() const
	{
		return *p;
	}

	template<typename T>
	BHeapIterator<T>& BHeapIterator<T>::operator++()
	{
		++p;
		return *this;
	}
}
/*

struct Heap_item heap_max(const struct Heap* heap);
void            heap_display(struct Heap* heap);
int             heap_insert(struct Heap* heap, int priority, char* value, const unsigned long data);
int             heap_removemax(struct Heap* heap, struct Heap_item* value);
unsigned int    heap_size(struct Heap* heap);

*/
