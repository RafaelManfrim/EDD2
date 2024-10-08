#include <iostream>

using namespace std;

struct Node {
    int value;
    Node* next;
    Node* prev;
};

struct Queue {
    Node* head;
    Node* tail;
};

bool queue_is_empty(Queue* queue) {
    return queue->head == nullptr;
}

void push(Queue* queue, int new_value) {
    Node* new_node = new Node;
    new_node->value = new_value;
    new_node->next = nullptr;
    new_node->prev = queue->tail;

    if (queue->tail != nullptr) {
        queue->tail->next = new_node;
    }

    queue->tail = new_node;

    if (queue->head == nullptr) {
        queue->head = new_node;
    }
}

int pop(Queue* queue) {
    if (queue_is_empty(queue)) {
        cout << "A fila está vazia, não há nada para remover." << endl;
        exit(1);
    }

    Node* node_to_remove = queue->head;
    int removed_value = node_to_remove->value;

    queue->head = node_to_remove->next;

    if (queue->head != nullptr) {
        queue->head->prev = nullptr;
    } else {
        queue->tail = nullptr;
    }

    delete node_to_remove;
    return removed_value;
}

void print(Queue queue) {
    Node* node = queue.head;

    cout << "Fila: ";

    while (node != nullptr) {
        cout << node->value << " -> ";
        node = node->next;
    }

    cout << "nullptr (saída)" << endl;
}

int main() {
    Queue queue;
    queue.head = nullptr;
    queue.tail = nullptr;

    print(queue);

    push(&queue, 2);
    print(queue);

    push(&queue, 5);
    push(&queue, 6);
    print(queue);

    push(&queue, 1);
    push(&queue, 4);
    print(queue);

    int popped_value = pop(&queue);
    cout << "Removido: " << popped_value << endl;
    print(queue);

    popped_value = pop(&queue);
    cout << "Removido: " << popped_value << endl;
    print(queue);

    popped_value = pop(&queue);
    cout << "Removido: " << popped_value << endl;
    print(queue);

    popped_value = pop(&queue);
    cout << "Removido: " << popped_value << endl;
    popped_value = pop(&queue);
    cout << "Removido: " << popped_value << endl;
    print(queue);

//     pop(&queue); // Usar para testar a validação de erro

    return 0;
}