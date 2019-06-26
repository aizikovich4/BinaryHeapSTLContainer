#include "bheap.h"


/*


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

*/