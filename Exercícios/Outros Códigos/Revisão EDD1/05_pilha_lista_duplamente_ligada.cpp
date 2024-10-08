#include <iostream>

using namespace std;

struct Node {
    int value;
    Node* next;
    Node* prev;
};

struct Stack {
    Node* head;
};

bool stack_is_empty(Stack* stack) {
    return stack->head == nullptr;
}

void push(Stack* stack, int new_value) {
    Node* new_node = new Node;
    new_node->value = new_value;
    new_node->next = stack->head;
    new_node->prev = nullptr;

    if (stack->head != nullptr) {
        stack->head->prev = new_node;
    }

    stack->head = new_node;
}

int pop(Stack* stack) {
    if (stack_is_empty(stack)) {
        cout << "A pilha está vazia, não há nada para remover." << endl;
        exit(1);
    }

    Node* node = stack->head;
    stack->head = stack->head->next;

    if (stack->head != nullptr) {
        stack->head->prev = nullptr;
    }

    int removed_value = node->value;
    delete node;
    return removed_value;
}

void print(Stack stack) {
    Node* node = stack.head;

    cout << "Pilha: ";

    while (node != nullptr) {
        cout << node->value << " -> ";
        node = node->next;
    }

    cout << "nullptr" << endl;
}

int main() {
    Stack stack;
    stack.head = nullptr;

    print(stack);

    push(&stack, 3);
    print(stack);

    push(&stack, 7);
    push(&stack, 8);
    print(stack);

    int popped_value = pop(&stack);
    cout << "Removido: " << popped_value << endl;
    print(stack);

    popped_value = pop(&stack);
    cout << "Removido: " << popped_value << endl;
    print(stack);

    popped_value = pop(&stack);
    cout << "Removido: " << popped_value << endl;
    print(stack);

     //pop(&stack); //Usar para testar a validação de erro

    return 0;
}