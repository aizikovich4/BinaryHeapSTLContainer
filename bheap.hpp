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
		

		class iterator
		{
		public:
			typedef iterator self_type;
			typedef T value_type;
			typedef T& reference;
			typedef T* pointer;
			typedef std::forward_iterator_tag iterator_category;
			typedef int difference_type;
			iterator(pointer ptr) : ptr_(ptr) { }
			self_type operator++() { ptr_++; return *this; } // PREFIX
			self_type operator++(int junk) { self_type i = *this; ptr_++; return i; } // POSTFIX
			value_type& operator*() { return *ptr_; }
			pointer operator->() { return ptr_; }
			bool operator==(const self_type& rhs) { return ptr_ == rhs.ptr_; }
			bool operator!=(const self_type& rhs) { return ptr_ != rhs.ptr_; }
		private:
			pointer ptr_;
		};

		class const_iterator
		{
		public:
			typedef const_iterator self_type;
			typedef T value_type;
			typedef T& reference;
			typedef T* pointer;
			typedef int difference_type;
			typedef std::forward_iterator_tag iterator_category;
			const_iterator(pointer ptr) : ptr_(ptr) { }
			self_type operator++() { self_type i = *this; ptr_++; return i; }
			self_type operator++(int junk) { ptr_++; return *this; }
			const value_type& const_iterator::operator*() { return *ptr_; }
			const pointer operator->() { return ptr_; }
			bool operator==(const self_type& rhs) { return ptr_ == rhs.ptr_; }
			bool operator!=(const self_type& rhs) { return ptr_ != rhs.ptr_; }
		private:
			pointer ptr_;
		};

		bheap() {};
		friend iterator;
		bheap(initializer_list<T> values) { std::copy(values.begin(), values.end(), _data.begin()); };
		bheap(const unsigned int n);
		bheap(const bheap& rhs);
		bool empty() const noexcept { return _data.empty(); };
		size_t size()const noexcept { return _data.size(); };
		size_t max_size()const noexcept { return _data.max_size(); };
		void swap(bheap<T>& other);

		void clear()const noexcept { _data.clear(); };
		void insert(T value);

		friend ostream& operator<< <T>(ostream& os, const bheap<T>& rhs);
		decltype(auto) begin() { return _data.begin(); };
		decltype(auto) end(){return _data.end(); };		
		const_iterator begin() const
		{
			return const_iterator(_data.begin);
		}

		const_iterator end() const
		{
			return const_iterator(_data.end());
		}

		bool operator==(const bheap<T>& rhs) { return (this->_data == rhs._data); };
		bool operator!=(const bheap<T>& rhs) { return !(*this == rhs); };
		T& operator[](size_t index){
			assert(index < _data.size());
			return _data[index];
		}


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
	
	
	
	template <typename T> bheap<T>::bheap(const bheap<T>& rhs)
	{
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
		_data.push_back(value);
		heapify();
		
	}

	template <typename T> void bheap<T>::heapify() noexcept
	{
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
		class heapIt : public std::iterator<std::output_iterator_tag, T>
	{
	private:
		heapIt(T* p);
	public:
		typedef T          value_type;
		/* T is template param */
		typedef T         *pointer;
		typedef const T   *const_pointer;
		typedef T         &reference;
		typedef const T   &const_reference;
		typedef size_t     size_type;
		typedef ptrdiff_t  difference_type;
		heapIt(const heapIt& it);

		bool operator!=(heapIt const& other) const;
		bool operator==(heapIt const& other) const; //need for BOOST_FOREACH
		//typename heapIt::reference operator*() const;
		heapIt& operator++();
		heapIt& operator--();
	private:
		T* p;
	};

	template<typename T>
	heapIt<T>::heapIt(T* p) :
		p(p)
	{

	}

	template<typename T>
	heapIt<T>::heapIt(const heapIt& it) :
		p(it.p)
	{

	}

	template<typename T>
	bool heapIt<T>::operator!=(heapIt const& other) const
	{
		return p != other.p;
	}

	template<typename T>
	bool heapIt<T>::operator==(heapIt const& other) const
	{
		return p == other.p;
	}

	/*
	template<typename T>
	typename heapIt<T>::reference heapIt<T>::operator*() const
	{
		return *p;
	}
	*/

	template<typename T>
	heapIt<T>& heapIt<T>::operator++()
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
