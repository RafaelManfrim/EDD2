#include <iostream>

using namespace std;

struct No {
    int valor;
    No* prox;
};

void inserir_inicio(No** cabeca, int novo_valor) {
    No* novo_no = new No;
    novo_no->valor = novo_valor;
    novo_no->prox = *cabeca;
    *cabeca = novo_no;
}

void inserir_fim(No** cabeca, int novo_valor) {
    No* novo_no = new No;
    novo_no->valor = novo_valor;
    novo_no->prox = nullptr;

    if (*cabeca == nullptr) {
        *cabeca = novo_no;
        return;
    }

    No* no_selecionado = *cabeca;
    while(no_selecionado->prox != nullptr) {
        no_selecionado = no_selecionado->prox;
    }

    no_selecionado->prox = novo_no;
}

void inserir_posicao(No** cabeca, int novo_valor, int posicao) {
    // Assume-se que as posições começarão à partir de 1
    if (posicao <= 0) {
        return;
    }

    if (posicao == 1) {
        inserir_inicio(cabeca, novo_valor);
        return;
    }

    No* no_selecionado = *cabeca;
    int i = 1;
    while (i < posicao - 1) {
        if(no_selecionado->prox == nullptr) {
            cout << "Posição inválida!" << endl;
            return;
        }

        no_selecionado = no_selecionado->prox;
        i++;
    }

    No* novo_no = new No;
    novo_no->valor = novo_valor;
    novo_no->prox = no_selecionado->prox;
    no_selecionado->prox = novo_no;
}

int remover_inicio(No** cabeca) {
    if (*cabeca == nullptr) {
        cout << "A lista está vazia, não há nada para remover." << endl;
        exit(1);
    }

    No* no_a_remover = *cabeca;
    *cabeca = (*cabeca)->prox;
    int valor_removido = no_a_remover->valor;
    delete no_a_remover;
    return valor_removido;
}

int remover_fim(No** cabeca) {
    if (*cabeca == nullptr) {
        cout << "A lista está vazia, não há nada para remover." << endl;
        exit(1);
    }

    No* no_selecionado = *cabeca;

    if (no_selecionado->prox == nullptr) {
        int valor_removido = no_selecionado->valor;
        delete no_selecionado;
        *cabeca = nullptr;
        return valor_removido;
    }

    while(no_selecionado->prox->prox != nullptr) {
        no_selecionado = no_selecionado->prox;
    }

    int valor_removido = no_selecionado->prox->valor;
    delete no_selecionado->prox;
    no_selecionado->prox = nullptr;
    return valor_removido;
}

int remover_posicao(No** cabeca, int posicao) {
    // Assume-se que as posições começarão à partir de 1
    if (posicao <= 0) {
        cout << "Posição Inválida!";
        exit(1);
    }

    if (posicao == 1) {
        return remover_inicio(cabeca);
    }

    No* no_selecionado = *cabeca;
    int i = 1;
    while (i < posicao - 1) {
        if(no_selecionado->prox == nullptr) {
            cout << "Posição inválida!" << endl;
            exit(1);
        }

        no_selecionado = no_selecionado->prox;
        i++;
    }

    No* no_a_remover = no_selecionado->prox;
    no_selecionado->prox = no_a_remover->prox;
    int valor_removido = no_a_remover->valor;
    delete no_a_remover;
    return valor_removido;
}

void imprime_lista(No* no) {
    cout << "Lista: ";

    while (no != nullptr) {
        cout << no->valor << " -> ";
        no = no->prox;
    }

    cout << "nullptr" << endl;
}

void excluir_lista(No** cabeca) {
    No* no_selecionado = *cabeca;
    No* prox = nullptr;

    while (no_selecionado != nullptr) {
        prox = no_selecionado->prox;
        delete no_selecionado;
        no_selecionado = prox;
    }

    *cabeca = nullptr;
}

int main() {
    No* cabeca = nullptr;

    cout << "Inserções no início: " << endl;

    inserir_inicio(&cabeca, 1);
    imprime_lista(cabeca);

    inserir_inicio(&cabeca, 3);
    inserir_inicio(&cabeca, 5);
    imprime_lista(cabeca);

    inserir_inicio(&cabeca, 4);
    imprime_lista(cabeca);

    cout << "Inserções no fim: " << endl;

    inserir_fim(&cabeca, 9);
    imprime_lista(cabeca);

    inserir_fim(&cabeca, 7);
    imprime_lista(cabeca);

    cout << "Inserções no meio: " << endl;

    inserir_posicao(&cabeca, 8, 2);
    imprime_lista(cabeca);

    inserir_posicao(&cabeca, 2, 7);
    imprime_lista(cabeca);

    inserir_posicao(&cabeca, 0, 1);
    imprime_lista(cabeca);

    cout << "Tentando inserir em uma posição não existente: " << endl;

    inserir_posicao(&cabeca, 15, 18);

    cout << "Excluindo do começo: " << endl;

    remover_inicio(&cabeca);
    imprime_lista(cabeca);

    remover_inicio(&cabeca);
    imprime_lista(cabeca);

    cout << "Excluindo do fim: " << endl;

    remover_fim(&cabeca);
    imprime_lista(cabeca);

    remover_fim(&cabeca);
    imprime_lista(cabeca);

    cout << "Excluindo no meio: " << endl;

    remover_posicao(&cabeca, 4);
    imprime_lista(cabeca);

    remover_posicao(&cabeca, 1);
    imprime_lista(cabeca);

    cout << "Tentando remover uma posição não existente: " << endl;

    remover_posicao(&cabeca, 10);

    excluir_lista(&cabeca);
    return 0;
}