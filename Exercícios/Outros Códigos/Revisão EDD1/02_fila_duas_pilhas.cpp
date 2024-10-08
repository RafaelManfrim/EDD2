#include <iostream>
#define MAX_ITEMS 5

using namespace std;

struct Stack {
    int top;
    int items[MAX_ITEMS];
};

struct Queue {
    Stack stack1;
    Stack stack2;
};

bool stack_empty(Stack &stack) {
    return stack.top == -1;
}

bool stack_full(Stack &stack) {
    return stack.top == MAX_ITEMS - 1;
}

void stack_push(Stack &stack, int value) {
    if (stack_full(stack)) {
        cout << "Houve um erro na fila" << endl;
    } else {
        stack.items[++stack.top] = value;
    }
}

int stack_pop(Stack &stack) {
    if (stack_empty(stack)) {
        cout << "Houve um erro na fila" << endl;
        exit(1);
    } else {
        return stack.items[stack.top--];
    }
}

void initialize_queue(Queue &queue) {
    queue.stack1.top = -1;
    queue.stack2.top = -1;
}

void queue_push(Queue &queue, int value) {
    if(!stack_full(queue.stack1)) {
        stack_push(queue.stack1, value);
        return;
    }

    if(stack_empty(queue.stack2)) {
        for(int i = 0; i < MAX_ITEMS; i++) {
            int transited_value = stack_pop(queue.stack1);
            stack_push(queue.stack2, transited_value);
        }

        stack_push(queue.stack1, value);
        return;
    }

    cout << "A fila está cheia!" << endl << endl;
}

int queue_pop(Queue &queue) {
    if(!stack_empty(queue.stack2)) {
        return stack_pop(queue.stack2);
    }

    if(!stack_empty(queue.stack1)) {
        while(queue.stack1.top >= 0) {
            int transited_value = stack_pop(queue.stack1);
            stack_push(queue.stack2, transited_value);
        }

        return stack_pop(queue.stack2);
    }

    cout << "A fila está vazia!" << endl;
    exit(1);
}

void queue_print(Queue queue) {
    cout << "Fila: " << endl;
    int i = 0;

    cout << "Entrada: ";
    while(i <= queue.stack1.top) {
        cout << " <- " << queue.stack1.items[i];
        i++;
    }

    cout << endl << "Saída: ";
    i = 0;
    while(i <= queue.stack2.top) {
        cout << queue.stack2.items[i] << " -> ";
        i++;
    }

    cout << endl << endl;
}

int main() {
    Queue queue;
    initialize_queue(queue);

    queue_push(queue, 3);
    queue_push(queue, 7);
    queue_push(queue, 2);
    queue_print(queue);

    queue_push(queue, 5);
    queue_push(queue, 8);
    queue_print(queue);

    queue_push(queue, 0);
    queue_push(queue, 9);
    queue_push(queue, 4);
    queue_push(queue, 1);
    queue_push(queue, 6);
    queue_print(queue);

    cout << "Testando push na fila cheia: ";
    queue_push(queue, 10); // Testar se enche a fila

    int popped_value = queue_pop(queue);
    cout << "Removido valor: " << popped_value << endl << endl;

    queue_print(queue);

    popped_value = queue_pop(queue);
    cout << "Removido valor: " << popped_value << endl << endl;

    queue_print(queue);

    cout << "Testando push na pilha 1 cheia: ";
    queue_push(queue, -1);

    cout << "Removendo 3 valores: " << endl << endl;
    queue_pop(queue);
    queue_pop(queue);
    queue_pop(queue);
    queue_print(queue);

    cout << "Removendo mais um valor: " << endl << endl;
    queue_pop(queue);
    queue_print(queue);

    cout << "Removendo 4 valores: " << endl << endl;
    queue_pop(queue);
    queue_pop(queue);
    queue_pop(queue);
    queue_pop(queue);
    queue_print(queue);

    cout << "Testando remoção com a fila totalmente vazia: ";
    queue_pop(queue);

    return 0;
}
