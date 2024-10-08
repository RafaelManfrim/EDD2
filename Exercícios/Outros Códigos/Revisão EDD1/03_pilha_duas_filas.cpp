#include <iostream>
#define MAX_ITEMS 5

using namespace std;

struct Queue {
    int front;
    int back;
    int items[MAX_ITEMS];
};

struct Stack {
    Queue queue1;
    Queue queue2;
    Queue* main_queue;
};

void initialize_queue(Queue &queue) {
    queue.front = 0;
    queue.back = -1;
}

void initialize_stack(Stack &stack) {
    initialize_queue(stack.queue1);
    initialize_queue(stack.queue2);
    stack.main_queue = &stack.queue1;
}

bool queue_empty(Queue &queue) {
    return queue.front > queue.back;
}

bool queue_full(Queue &queue) {
    return queue.back == MAX_ITEMS - 1;
}

void queue_push(Queue &queue, int value) {
    if (queue_full(queue)) {
        cout << "Pilha cheia!" << endl;
        return;
    }

    queue.items[++queue.back] = value;
}

int queue_pop(Queue &queue) {
    if (queue_empty(queue)) {
        cout << "Pilha vazia!" << endl;
        exit(1);
    }

    int removed = queue.items[queue.front];

    for (int i = queue.front; i < queue.back; i++) {
        queue.items[i] = queue.items[i + 1];
    }

    queue.back--;

    return removed;
}

void stack_push(Stack &stack, int value) {
    queue_push(*stack.main_queue, value);
}

int stack_pop(Stack &stack) {
    Queue* aux_queue;

    if(stack.main_queue == &stack.queue1) {
        aux_queue = &stack.queue2;
    } else {
        aux_queue = &stack.queue1;
    }

    while(stack.main_queue->back >= 1) {
        int popped_value = queue_pop(*stack.main_queue);
        queue_push(*aux_queue, popped_value);
    }

    int stack_popped_value = queue_pop(*stack.main_queue);

    stack.main_queue = aux_queue;

    return stack_popped_value;
}

void stack_print(Stack stack) {
    cout << "Pilha: ";
    for(int i = 0; i <= stack.main_queue->back; i++) {
        cout << stack.main_queue->items[i] << " -> ";
    }

    cout << "Saída" << endl << endl;
}

int main() {
    Stack stack;
    initialize_stack(stack);

    stack_print(stack);

    stack_push(stack, 3);
    stack_push(stack, 7);
    stack_print(stack);

    stack_push(stack, 5);
    stack_push(stack, 4);
    stack_print(stack);

    stack_push(stack, 1);
    stack_print(stack);

//    stack_push(stack, 1); // Testando limite de items

    int popped = stack_pop(stack);
    cout << "Removido: " << popped << endl;
    stack_print(stack);

    popped = stack_pop(stack);
    cout << "Removido: " << popped << endl;
    stack_print(stack);

    stack_push(stack, 9);
    stack_push(stack, 8);
    stack_print(stack);

    popped = stack_pop(stack);
    cout << "Removido: " << popped << endl;
    stack_print(stack);

    return 0;
}
