#include <iostream>

using namespace std;

struct No {
    No* no_esq;
    No* no_dir;
    No* no_pai;
    int valor;
    int balanceamento = 0;
};

struct ArvoreAVL {
    No* raiz = nullptr;
};

void percurso_em_ordem(No* no) {
    if(no != nullptr){
        percurso_em_ordem(no->no_esq);
        cout << no->valor << " ";
        percurso_em_ordem(no->no_dir);
    }
}

No* BuscaNaArvore(No* no, int valor) {
    while(no != nullptr && valor != no->valor) {
        if(valor < no->valor) {
            no = no->no_esq;
        } else {
            no = no->no_dir;
        }
    }

    return no;
}

No* ArvoreMinimoRecursivo(No* no) {
    if(no->no_esq != nullptr) {
        return ArvoreMinimoRecursivo(no->no_esq);
    } else {
        return no;
    }
}

No* EncontraSucessor(No* no) {
    if(no->no_dir != nullptr) {
        return ArvoreMinimoRecursivo(no->no_dir);
    }

    No* no_pai = no->no_pai;
    while (no_pai != nullptr && no == no_pai->no_dir) {
        no = no_pai;
        no_pai = no_pai->no_pai;
    }
    return no_pai;
}

void rotacao_a_esquerda(ArvoreAVL* arvore, No* no) {
    if(no->no_dir == nullptr) {
        return;
    }

    No* no_dir = no->no_dir;
    no->no_dir = no_dir->no_esq;

    if (no_dir->no_esq != nullptr) {
        no_dir->no_esq->no_pai = no;
    }

    no_dir->no_pai = no->no_pai;

    if (no->no_pai == nullptr) {
        arvore->raiz = no_dir;
    } else if (no == no->no_pai->no_esq) {
        no->no_pai->no_esq = no_dir;
    } else {
        no->no_pai->no_dir = no_dir;
    }
    no_dir->no_esq = no;
    no->no_pai = no_dir;

    no->balanceamento = no->balanceamento - 1 - max(0, no_dir->balanceamento);
    no_dir->balanceamento = no_dir->balanceamento - 1 + min(0, no->balanceamento);
}

void rotacao_a_direita(ArvoreAVL* arvore, No* no) {
    if(no->no_esq == nullptr) {
        return;
    }

    No* no_esq = no->no_esq;
    no->no_esq = no_esq->no_dir;

    if (no_esq->no_dir != nullptr) {
        no_esq->no_dir->no_pai = no;
    }

    no_esq->no_pai = no->no_pai;

    if (no->no_pai == nullptr) {
        arvore->raiz = no_esq;
    } else if (no == no->no_pai->no_dir) {
        no->no_pai->no_dir = no_esq;
    } else {
        no->no_pai->no_esq = no_esq;
    }
    no_esq->no_dir = no;
    no->no_pai = no_esq;

    no->balanceamento = no->balanceamento + 1 - min(0, no_esq->balanceamento);
    no_esq->balanceamento = no_esq->balanceamento + 1 + max(0, no->balanceamento);
}

void rebalancear_subarvore(ArvoreAVL* arvore, No* no_pai) {
    if (no_pai->balanceamento == -2) { // Caso Esquerda-Esquerda ou Esquerda-Direita
        if (no_pai->no_esq->balanceamento <= 0) { // Esquerda-Esquerda
            rotacao_a_direita(arvore, no_pai);
        } else { // Esquerda-Direita
            rotacao_a_esquerda(arvore, no_pai->no_esq);
            rotacao_a_direita(arvore, no_pai);
        }
    } else if (no_pai->balanceamento == 2) { // Caso Direita-Direita ou Direita-Esquerda
        if (no_pai->no_dir->balanceamento >= 0) { // Direita-Direita
            rotacao_a_esquerda(arvore, no_pai);
        } else { // Direita-Esquerda
            rotacao_a_direita(arvore, no_pai->no_dir);
            rotacao_a_esquerda(arvore, no_pai);
        }
    }
}

void atualizar_balanceamentos(ArvoreAVL* arvore, No* no_inserido) {
    No* no_pai = no_inserido->no_pai;

    while (no_pai != nullptr) { // Atualiza os fatores de balanceamento ao subir na árvore
        if (no_inserido == no_pai->no_esq) {
            no_pai->balanceamento--; // Filho esquerdo reduz o fator
        } else {
            no_pai->balanceamento++; // Filho direito aumenta o fator
        }

        if (no_pai->balanceamento == 0) { // Se o fator de balanceamento for 0, a subárvore está equilibrada
            return;
        }

        if (no_pai->balanceamento == 2 || no_pai->balanceamento == -2) { // Se o fator de balanceamento for ±2, precisamos rebalancear
            rebalancear_subarvore(arvore, no_pai);
            return;
        }

        no_inserido = no_pai;
        no_pai = no_pai->no_pai;
    }
}

void inserir(ArvoreAVL* arvore, int valor) {
    No* novo_no = new No{nullptr, nullptr, nullptr, valor, 0};

    if (arvore->raiz == nullptr) {
        arvore->raiz = novo_no;
        return;
    }

    No* atual = arvore->raiz;
    No* pai = nullptr;

    while (atual != nullptr) {
        pai = atual;
        if (valor < atual->valor) {
            atual = atual->no_esq;
        } else {
            atual = atual->no_dir;
        }
    }

    novo_no->no_pai = pai;

    if (valor < pai->valor) {
        pai->no_esq = novo_no;
    } else {
        pai->no_dir = novo_no;
    }

    atualizar_balanceamentos(arvore, novo_no);
}

No* delecao(ArvoreAVL* arvore, No* no, int valor) {
    if (no == nullptr) return nullptr;

    if (valor < no->valor) {
        no->no_esq = delecao(arvore, no->no_esq, valor);
    } else if (valor > no->valor) {
        no->no_dir = delecao(arvore, no->no_dir, valor);
    } else {
        if (no->no_esq == nullptr && no->no_dir == nullptr) { // Nó folha
            delete no;
            return nullptr;
        }
        if (no->no_esq == nullptr || no->no_dir == nullptr) { // Caso 2: Um único filho
            No* filho = (no->no_esq != nullptr) ? no->no_esq : no->no_dir;
            filho->no_pai = no->no_pai;
            delete no;
            return filho;
        }
        // Dois filhos
        No* sucessor = EncontraSucessor(no);
        no->valor = sucessor->valor;
        no->no_dir = delecao(arvore, no->no_dir, sucessor->valor);
    }

    int bal_esq = no->no_esq ? no->no_esq->balanceamento : -1;
    int bal_dir = no->no_dir ? no->no_dir->balanceamento : -1;
    no->balanceamento = bal_dir - bal_esq;

    if (no->balanceamento > 1) { // Caso direita desbalanceada
        if (no->no_dir->balanceamento < 0) {
            rotacao_a_direita(arvore, no->no_dir);
        }
        rotacao_a_esquerda(arvore, no);
    } else if (no->balanceamento < -1) { // Caso esquerda desbalanceada
        if (no->no_esq->balanceamento > 0) {
            rotacao_a_esquerda(arvore, no->no_esq);
        }
        rotacao_a_direita(arvore, no);
    }

    return no;
}

void imprimir_arvore(No* raiz, int nivel = 0) {
    if (raiz != nullptr) {
        imprimir_arvore(raiz->no_dir, nivel + 1);
        cout << string(nivel * 4, ' ') << raiz->valor << " (" << raiz->balanceamento << ")\n";
        imprimir_arvore(raiz->no_esq, nivel + 1);
    }
}

int main() {
    ArvoreAVL arvore;

    inserir(&arvore, 4);
    inserir(&arvore, 7);
    inserir(&arvore, 5);
    inserir(&arvore, 46);
    inserir(&arvore, 25);
    inserir(&arvore, 11);
    inserir(&arvore, 18);
    inserir(&arvore, 33);
    inserir(&arvore, 38);
    inserir(&arvore, 2);
    inserir(&arvore, 51);

    cout << "Raiz: " << arvore.raiz->valor << endl;

    cout << "Percurso em Ordem: ";
    percurso_em_ordem(arvore.raiz);
    cout << endl << endl;

    cout << "Árvore: " << endl;
    imprimir_arvore(arvore.raiz);

    delecao(&arvore, arvore.raiz, 33);

    cout << "Árvore: " << endl;
    imprimir_arvore(arvore.raiz);

    return 0;
}