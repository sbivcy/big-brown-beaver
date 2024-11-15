#include <stdlib.h>
#include <stdio.h>
#include "knihovna.h"


// Zásobník
void initializeStack(Stack *stack, int max_size) {
    stack->max_size = max_size;
    stack->top = -1;
    stack->array = (int*)calloc(max_size, sizeof(int));
}

int isEmptyStack(Stack *stack) {
    return stack->top == -1;
}

int isFullStack(Stack *stack) {
    return stack->top == stack->max_size - 1;
}

void push(Stack *stack, int value) {
    if (isFullStack(stack)) {
        puts("Stack overflow");
        return;
    }
    stack->top++;
    stack->array[stack->top] = value;
}

int pop(Stack *stack) {
    if (isEmptyStack(stack)) {
        puts("Stack underflow");
        return 0;
    }
    int value = stack->array[stack->top];
    stack->top--;
    return value;
}

int peekStack(Stack *stack) {
    if (isEmptyStack(stack)) {
        puts("Stack is empty");
        return 0;
    }
    return stack->array[stack->top];
}

void freeStack(Stack *stack) {
    free(stack->array);
}


// Fronta
void initializeQueue(Queue *q, int max_size) {
    q->max_size = max_size;
    q->front = max_size - 1;
    q->back = 0;
    q->size = 0;
    q->array = (int*)calloc(max_size, sizeof(int));
}

int isEmptyQueue(Queue *q) {
    return q->size == 0;
}

int isFullQueue(Queue *q) {
    return q->size == q->max_size;
}

void enqueue(Queue *q, int value) {
    if (isFullQueue(q)) {
        puts("Queue overflow");
        return;
    }
    q->front = (q->front + 1) % q->max_size;
    q->array[q->front] = value;
    q->size++;
}

int dequeue(Queue *q) {
    if (isEmptyQueue(q)) {
        puts("Queue underflow");
        return 0;
    }
    int value = q->array[q->back];
    q->back = (q->back + 1) % q->max_size;
    q->size--;
    return value;
}

int peekQueue(Queue *q) {
    if (isEmptyQueue(q)) {
        puts("Queue underflow");
        return 0;
    }
    return q->array[q->back];
}

void freeQueue(Queue *q) {
    free(q->array);
}


// Oboustranná fronta
void initializeDeque(Deque *q, int max_size) {
    q->max_size = max_size;
    q->front = max_size - 1; 
    q->size = 0;
    q->array = (int*)calloc(max_size, sizeof(int));
}

int isFullDeque(Deque *q) {
    return q->size == q->max_size;
}

int isEmptyDeque(Deque *q) {
    return q->size == 0;
}

void pushFront(Deque *q, int value) {
    if (isFullDeque(q)) {
        puts("Deque overflow");
	return;
    }
    q->front = (q->front + 1) % q->max_size;
    q->size++;
    q->array[q->front] = value;
}

void pushBack(Deque *q, int value) {
    if (isFullDeque(q)) {
        puts("Deque overflow");
	return;
    }
    q->back--;
    if (q->back < 0) {
        q->back = q->back + q->max_size;
    }
    q->size++;
    q->array[q->back] = value;
}

int popFront(Deque *q) {
    if (isEmptyDeque(q)) {
        puts("Deque underflow");
	return 0;
    }
    int value = q->array[q->front];
    q->front--;
    if (q->front < 0) {
        q->front = q->front + q->max_size;
    }
    q->size--;
    return value;
}

int popBack(Deque *q) {
    if (isEmptyDeque(q)) {
        puts("Deque underflow");
	return 0;
    }
    int value = q->array[q->back];
    q->back = (q->back + 1) % q->max_size;
    q->size--;
    return value;
}

int peekFront(Deque *q) {
    if (isEmptyDeque(q)) {
        puts("Deque underflow");
	return 0;
    }
    return q->array[q->front];
}

int peekBack(Deque *q) {
    if (isEmptyDeque(q)) {
        puts("Deque underflow");
	return 0;
    }
    return q->array[q->back];
}

void freeDeque(Deque *q) {
    free(q->array);
}


// Binární halda
void initializeHeap(Heap *heap, int max_size) {
    heap->max_size = max_size;
    heap->size = 0;
    heap->array = (int*)calloc(max_size, sizeof(int));
}

void buildHeap(Heap *heap, int array[], int array_size) {
    heap->max_size = array_size;
    heap->size = array_size;
    heap->array = array;
    for (int i = array_size / 2; i >= 0; i--) {
        bubbleDown(heap, i);
    }
}

void bubbleUp(Heap *heap, int index) {
    if (index == 0) {
        return;
    }
    if (heap->array[(index - 1) / 2] < heap->array[index]) {
        int value = heap->array[(index - 1) / 2];
        heap->array[(index - 1) / 2] = heap->array[index];
	heap->array[index] = value;
	bubbleUp(heap, (index - 1) / 2);
    }
}

void bubbleDown(Heap *heap, int index) {
    if (index * 2 + 2 > heap->size) {
        return;
    }
    int child_index;
    if (index * 2 + 2 == heap->size) {
        child_index = index * 2 + 1;
    } else {
        if (heap->array[index * 2 + 1] < heap->array[index * 2 + 2]) {
            child_index = index * 2 + 2;
	} else {
            child_index = index * 2 + 1;
	}
    }
    if (heap->array[index] < heap->array[child_index]) {
        int value = heap->array[index];
	heap->array[index] = heap->array[child_index];
	heap->array[child_index] = value;
        bubbleDown(heap, child_index);
    }
}

void insert(Heap *heap, int value) {
    if (heap->size == heap->max_size) {
        printf("Heap is full");
        return;
    }
    heap->array[heap->size] = value;
    heap->size++;
    bubbleUp(heap, heap->size - 1);
}

int max(Heap *heap) {
    if (heap->size == 0) {
        puts("Heap is empty");
        return 0;
    }
    return heap->array[0];
}

int extractMax(Heap *heap) {
    if (heap->size == 0) {
        puts("Heap is empty");
        return 0;
    }
    int value = heap->array[0];
    heap->size--;
    heap->array[0] = heap->array[heap->size];
    heap->array[heap->size] = value;
    bubbleDown(heap, 0);
    return value;
}

void freeHeap(Heap *heap) {
    free(heap->array);
}


// SORTY
void bubbleSort(int array[], int array_size) {
    for (int i = 1; i < array_size; i++) {
        while (i > 0) {
            if (array[i] < array[i - 1]) {
                int temp = array[i];
		array[i] = array[i - 1];
		array[i - 1] = temp;
		i--;
	    } else {
                break;
	    }
	}
    }
}

void heapSort(int array[], int array_size) {
    Heap heap;
    buildHeap(&heap, array, array_size);
    for (int i = 0; i < array_size; i++) {
        extractMax(&heap);
    }
}

void quickSort(int array[], int array_size) {
    void qSort(int array[], int left, int right) {
        if (left >= right) {
            return;
	}
        int pivot = array[left];
        int i = left, j = right;
        while (i <= j) {
            while (array[i] < pivot) {
                i++;
	    }
            while (array[j] > pivot) {
                j--;
	    }
	    if (i < j) {
                int temp = array[i];
		array[i] = array[j];
		array[j] = temp;
	    }
	    if (i <= j) {
                i++;
		j--;
	    }
	}
    qSort(array, left, j);
    qSort(array, i, right);
    }
    qSort(array, 0, array_size - 1);
}










