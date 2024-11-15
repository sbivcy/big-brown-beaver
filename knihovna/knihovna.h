// DATOVÉ STRUKTURY
// Zásobník
typedef struct {
    int max_size;
    int top;
    int* array;
} Stack;

// inicializace zásobníku
extern void initializeStack(Stack *stack, int max_size);

// je zásobník prázdný?
extern int isEmptyStack(Stack *stack);

// je zásobník plný?
extern int isFullStack(Stack *stack);

// přidání na zásobník
extern void push(Stack *stack, int value);

// odebrání ze zásobníku
extern int pop(Stack *stack);

// vrchní prvek zásobníku
extern int peekStack(Stack *stack);

// uvolnění paměti používané zásobníkem
extern void freeStack(Stack *stack);


// Fronta
typedef struct {
    int max_size;
    int front;
    int back;
    int size;
    int *array;
} Queue;

// inicializce fronty
extern void initializeQueue(Queue *q, int max_size);

// je fronta prázdná?
extern int isEmptyQueue(Queue *q);

// je fronta plná?
extern int isFullQueue(Queue *q);

// přidání prvku do fronty
extern void enqueue(Queue *q, int value);

// odebrání prvku z frotny
extern int dequeue(Queue *q);

// první prvek ve frontě
extern int peekQueue(Queue *q);

// uvolnění paměti používané frontou
extern void freeQueue(Queue *q);


// Oboustranná fronta
typedef struct {
    int max_size;
    int front;
    int back;
    int size;
    int *array;
} Deque;

// inicializace oboustranné fronty
extern void initializeDeque(Deque *q, int max_size); 

// je oboustranná fronta plná?
extern int isFullDeque(Deque *q); 

// je ooustranná fronta prázdná?
extern int isEmptyDeque(Deque *q);

// přidání prvku na začátek fronty
extern void pushFront(Deque *q, int value);

// přidání prvku na konec fronty
extern void pushBack(Deque *q, int value);

// odebrání prvního prvku fronty
extern int popFront(Deque *q);

// odebrání posledního prvku fronty
extern int popBack(Deque *q);

// první prvek fronty
extern int peekFront(Deque *q);

// poslední prvek fronty
extern int peekBack(Deque *q);

// uvolnění paměti používané oboustrannou frontou
extern void freeDeque(Deque *q);


// Binární halda
typedef struct {
   int max_size;
   int size;
   int *array;
} Heap;

// inicializace haldy
extern void initializeHeap(Heap *heap, int max_size);

// vytvoření haldy z pole
extern void buildHeap(Heap *heap, int array[], int array_size);

// bublání nahoru
extern void bubbleUp(Heap *heap, int index);

// bublání dolu
extern void bubbleDown(Heap *heap, int index);

// vložení prvku do haldy
extern void insert(Heap *heap, int value);

// nejvyšší prvek v haldě (bez odstranění)
extern int max(Heap *heap);

// vrátí a odstraní z haldy nejvyšší prvek
extern int extractMax(Heap *heap);

// uvolnění paměti používané haldou
extern void freeHeap(Heap *heap);


// SORTY
extern void bubbleSort(int array[], int array_size);

extern void heapSort(int array[], int array_size);

extern void quickSort(int array[], int array_size);













