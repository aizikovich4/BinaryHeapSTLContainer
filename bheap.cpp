#include "bheap.h"


/*
struct Heap* heap_create(int maxsize)
{
	struct Heap* heap_ptr = NULL;
	
	heap_ptr =(Heap*) malloc(sizeof(struct Heap));
	if (heap_ptr)
	{
		heap_ptr->maxsize = maxsize;
		heap_ptr->count_items = 0;
		heap_ptr->items = (Heap_item*)malloc(sizeof(struct Heap_item) * maxsize);
		if (!heap_ptr->items)
		{
			exit(1);
		}

		return heap_ptr;
	}
	else
		exit(1);

}

void heap_free(struct Heap* h)
{
	free(h->items);
	free(h);
}

static void heap_swap(struct Heap_item* first, struct Heap_item* second)
{
	struct Heap_item tmp = *first;
	*first = *second;
	*second = tmp;
}

struct Heap_item heap_max(const struct Heap* heap)
{
	int res = 0;
	struct Heap_item ret_item = { -1,0, NULL };

	if (heap->count_items > 0)
	{
		ret_item = heap->items[1];
	}
	else
		printf("Heap is empty\n");

	return ret_item;

}

void heap_display(struct Heap* heap) {
	int i;

	printf("Queue: ");
	for (i = 0; i <= heap->count_items; ++i) {
		printf("%d ", heap->items[i].priority);
	}
	printf("\n");

}


int heap_insert(struct Heap* heap, int priority, char* value, const unsigned long data)
{
	int i = 0;
	struct Heap_item* tmp = NULL;


	++heap->count_items;
	heap->items[heap->count_items].priority = priority;
	heap->items[heap->count_items].value = value;
	heap->items[heap->count_items].data = data;

	// heapify, push to up
	for (i = heap->count_items; i > 1 && heap->items[i].priority > heap->items[i / 2].priority; i = i / 2)
	{
		heap_swap(&heap->items[i], &heap->items[i / 2]);
	}

	return 0;
}

int heap_removemax(struct Heap* heap, struct Heap_item* value)
{
	int largest_index, leftChild;
	int end_heap;

	if (!heap->count_items)
	{
		return 0;
	}
	end_heap = heap->count_items - 1;
	heap_swap(&heap->items[1], &heap->items[heap->count_items]);  //swap with head with last
	for (largest_index = 1; 2 * largest_index <= end_heap; largest_index = leftChild)  //try to rebuild heap
	{
		leftChild = 2 * largest_index;                       //index for point out to leaves
		if (leftChild < end_heap && heap->items[leftChild].priority < heap->items[leftChild + 1].priority)
		{
			leftChild++;
		}
		if (heap->items[largest_index].priority >= heap->items[leftChild].priority)
		{
			break;
		}
		heap_swap(&heap->items[largest_index], &heap->items[leftChild]);
	}
	*value = heap->items[heap->count_items--];


	return 1;
}

unsigned int heap_size(struct Heap* heap)
{
	int count = 0;
	count = heap->count_items;
	return count;
}

*/