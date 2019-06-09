//TODO
//1. Сам алгоритм бинарной кучи
//2. Оформить как контейнер с минимальным функционалом - конструктор, деструктор, конструктор копирования, перемещения, push/pop, размер, итераторы(какие вообще для такого контейнера доступны?)
//4. GTEST, ну и со стандартными алгоритмами бы проверить 
//5. создать cmake файл потом для сборки под linux




#define COUNT_WRITERS       2
#define COUNT_READERS       2

#define MAX_ADDS_THREADS     100

static void events_queue_handler(int flag);
static void* thread_writers(void* par);
static void* thread_reader(void* par);
static void* user_console_thread(void* par);
static void run_threads();


static pthread_t tid_writer[COUNT_WRITERS];
static pthread_t tid_reader[COUNT_READERS];
static pthread_t user_console;
static pthread_mutex_t mutex_thread = PTHREAD_MUTEX_INITIALIZER;
static pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
struct Heap* heap;
static unsigned long time_read = 250000;
static unsigned long time_write = 250000;
static int err = 0;
static char* mas[] = { "Task 0", "Task 1", "Task 2", "Task 3", "Task 4", "Task 5", "Task 6", "Task 7", "Task 8", "Task 9", "Task 10" };

void* thread_writers(void* par)
{
	time_t t;

	printf("start writer thread \n");
	srand(time(&t));

	while (1)
	{
		unsigned int r = rand() % 11; //write random count of items to queue
		if (!heap_insert(heap, r, mas[r], pthread_self()))
		{
			printf("Writer insert item: %d - %s,  %lu \n", r, mas[r], pthread_self());
		}
		usleep(time_write); //sleep at this moment, for exclude queue overflow
	}

}

void* thread_reader(void* par)
{
	struct Heap_item item;

	printf("start reader thread \n");
	while (1)
	{
		if (heap_size(heap))
			heap_display(heap);
		if (heap_removemax(heap, &item))   //get size ant removemax at once, else - race condition
		{
			printf("\t Reader(%lu) get item: prior(%d), %s, %lu \n", pthread_self(), item.priority, item.value, item.thread_id);
			usleep(time_read); //emulate hard work of processor with new element from queue
		}
	}
}


void events_queue_handler(int flag)         //it custom handler events from queue. All necessary and additional action we may do in this place.
{
	switch (flag) {
	case LOW_WATER_MARK:
		printf("LOW_WATER_MARK received \n");
		break;
	case HIGH_WATER_MARK:
		printf("HIGH_WATER_MARK received \n");
		break;
	default:
		break;
	}
}




#include <iostream>

int main()
{
    std::cout << "Hello World!\n";
	heap = heap_create(150, events_queue_handler);
	while (1)
	{

	}

}
