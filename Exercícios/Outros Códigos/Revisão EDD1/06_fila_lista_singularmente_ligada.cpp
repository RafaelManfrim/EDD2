#include <iostream>

using namespace std;

struct Node {
    int value;
    Node* next;
};

struct Queue {
    Node* head;
};

bool queue_is_empty(Queue* queue) {
    return queue->head == nullptr;
}

void push(Queue* queue, int new_value) {
    Node* new_node = new Node;
    new_node->value = new_value;
    new_node->next = queue->head;
    queue->head = new_node;
}

int pop(Queue* queue) {
    if (queue_is_empty(queue)) {
        cout << "A fila está vazia, não há nada para remover." << endl;
        exit(1);
    }

    Node* selected_node = queue->head;

    if (selected_node->next == nullptr) {
        int removed_value = selected_node->value;
        delete selected_node;
        queue->head = nullptr;
        return removed_value;
    }

    while(selected_node->next->next != nullptr) {
        selected_node = selected_node->next;
    }

    int removed_value = selected_node->next->value;
    delete selected_node->next;
    selected_node->next = nullptr;
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