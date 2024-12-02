#include <iostream>

using namespace std;

struct No {
    No* no_esq;
    No* no_dir;
    No* no_pai;
    int valor;
};

struct ArvoreBinariaBusca {
    No* raiz;
};

void PercursoEmOrdem(No* raiz) {
    if(raiz != nullptr){
        PercursoEmOrdem(raiz->no_esq);
        cout << raiz->valor << " ";
        PercursoEmOrdem(raiz->no_dir);
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

No* BuscaRecursivaNaArvore(No* no, int valor) {
    if(valor < no->valor) {
        return BuscaRecursivaNaArvore(no->no_esq, valor);
    } else if (valor > no->valor) {
        return BuscaRecursivaNaArvore(no->no_dir, valor);
    } else {
        return no;
    }
}

No* ArvoreMinimo(No* no) {
    while(no->no_esq != nullptr) {
        no = no->no_esq;
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

No* ArvoreMaximo(No* no) {
    while(no->no_dir != nullptr) {
        no = no->no_dir;
    }

    return no;
}

No* ArvoreMaximoRecursiva(No* no) {
    if(no->no_dir != nullptr) {
        return ArvoreMaximoRecursiva(no->no_dir);
    } else {
        return no;
    }
}

No* EncontraSucessor(No* no) {
    if(no->no_dir != nullptr) {
        return ArvoreMinimo(no->no_dir);
    }

    No* no_pai = no->no_pai;
    while (no_pai != nullptr && no == no_pai->no_dir) {
        no = no_pai;
        no_pai = no_pai->no_pai;
    }
    return no_pai;
}

No* EncontraPredecessor(No* no) {
    if(no->no_esq != nullptr) {
        return ArvoreMaximo(no->no_esq);
    }

    No* no_pai = no->no_pai;
    while (no_pai != nullptr && no == no_pai->no_esq) {
        no = no_pai;
        no_pai = no_pai->no_pai;
    }
    return no_pai;
}

void InserirNaArvore(ArvoreBinariaBusca* arvore, No* no) {
    No* no_atual = arvore->raiz;

    if (no_atual == nullptr) {
        arvore->raiz = no;
    } else {
        No* no_pai = nullptr;

        while(no_atual != nullptr) {
            no_pai = no_atual;

            if(no->valor < no_atual->valor) {
                no_atual = no_atual->no_esq;
            } else {
                no_atual = no_atual->no_dir;
            }
        }

        if(no->valor < no_pai->valor) {
            no_pai->no_esq = no;
        } else {
            no_pai->no_dir = no;
        }

        no->no_pai = no_pai;
    }
}

No* InserirNaArvoreRecursiva(No* subarvore, No* no_pai, No* no) {
    if(subarvore == nullptr) {
        no->no_pai = no_pai;
        return no;
    }

    if(no->valor < subarvore->valor) {
        subarvore->no_esq = InserirNaArvoreRecursiva(subarvore->no_esq, subarvore, no);
    } else if(no->valor > subarvore->valor) {
        subarvore->no_dir = InserirNaArvoreRecursiva(subarvore->no_dir, subarvore, no);
    }

    return subarvore;
}

void SubstituiSubarvore(ArvoreBinariaBusca* arvore, No* no_substituido, No* no_substituir) {
    if(no_substituido->no_pai == nullptr) {
        arvore->raiz = no_substituir;
    } else {
        if(no_substituido == no_substituido->no_pai->no_esq) {
            no_substituido->no_pai->no_esq = no_substituir;
        } else {
            no_substituido->no_pai->no_dir = no_substituir;
        }
    }

    if(no_substituir != nullptr) {
        no_substituir->no_pai = no_substituido->no_pai;
    }
}

void DelecaoArvore(ArvoreBinariaBusca* arvore, No* no_deletar) {
    if(no_deletar->no_esq == nullptr) {
        SubstituiSubarvore(arvore, no_deletar, no_deletar->no_dir);
    } else if(no_deletar->no_dir == nullptr) {
        SubstituiSubarvore(arvore, no_deletar, no_deletar->no_esq);
    } else {
        No* sucessor = ArvoreMinimo(no_deletar->no_dir);

        if(sucessor != no_deletar->no_dir) {
            SubstituiSubarvore(arvore, sucessor, sucessor->no_dir);
            sucessor->no_dir = no_deletar->no_dir;
            sucessor->no_dir->no_pai = sucessor;
        }

        SubstituiSubarvore(arvore, no_deletar, sucessor);
        sucessor->no_esq = no_deletar->no_esq;
        sucessor->no_esq->no_pai = sucessor;
    }
}

void CriaNo(No* no, int valor) {
    no->no_dir = nullptr;
    no->no_esq = nullptr;
    no->no_pai = nullptr;
    no->valor = valor;
}


int main() {
    ArvoreBinariaBusca* arvore = new ArvoreBinariaBusca();
    arvore->raiz = nullptr;

    No* no = new No();
    CriaNo(no, 5);
    InserirNaArvore(arvore, no);

    no = new No();
    CriaNo(no, 2);
    InserirNaArvore(arvore, no);

    no = new No();
    CriaNo(no, 10);
    InserirNaArvore(arvore, no);

    no = new No();
    CriaNo(no, 8);
    InserirNaArvore(arvore, no);

    no = new No();
    CriaNo(no, 7);
    InserirNaArvore(arvore, no);

    cout << "Percurso em Ordem: ";
    PercursoEmOrdem(arvore->raiz);

    cout << endl;

    No* no_menor = ArvoreMinimo(arvore->raiz);
    cout << "Posição na memória do menor nó: " << no_menor << ", valor: " << no_menor->valor << endl;

    No* no_maior = ArvoreMaximo(arvore->raiz);
    cout << "Posição na memória do maior nó: " << no_maior << ", valor: " << no_maior->valor << endl;

    No* no_buscado = BuscaNaArvore(arvore->raiz, 7);
    cout << "Posição na memória do nó buscado: " << no_buscado << ", valor: " << no_buscado->valor << endl;
    cout << "Excluindo o nó que buscamos!" << endl;
    DelecaoArvore(arvore, no_buscado);

    cout << "Percurso em Ordem sem o nó excluído: ";
    PercursoEmOrdem(arvore->raiz);

    cout << endl;

    No* no_buscado_recursivamente = BuscaRecursivaNaArvore(arvore->raiz, 8);
    cout << "Posição na memória do nó buscado recursivamente: " << no_buscado_recursivamente << ", valor: " << no_buscado_recursivamente->valor << endl;

    No* predecessor = EncontraPredecessor(no_buscado_recursivamente);
    cout << "Posição na memória do predecessor do nó buscado recursivamente: " << predecessor << ", valor: " << predecessor->valor << endl;

    No* sucessor = EncontraSucessor(no_buscado_recursivamente);
    cout << "Posição na memória do sucessor do nó buscado recursivamente: " << sucessor << ", valor: " << sucessor->valor << endl;

    no_menor = ArvoreMinimoRecursivo(arvore->raiz);
    cout << "Posição na memória do menor nó: " << no_menor << ", valor: " << no_menor->valor << endl;

    no_maior = ArvoreMaximoRecursiva(arvore->raiz);
    cout << "Posição na memória do maior nó: " << no_maior << ", valor: " << no_maior->valor << endl;

    no = new No();
    CriaNo(no, 19);
    InserirNaArvoreRecursiva(arvore->raiz, nullptr, no);

    no = new No();
    CriaNo(no, 2);
    InserirNaArvoreRecursiva(arvore->raiz, nullptr, no);

    no = new No();
    CriaNo(no, 6);
    InserirNaArvoreRecursiva(arvore->raiz, nullptr, no);

    cout << "Percurso em Ordem depois de inserir recursivamente: ";
    PercursoEmOrdem(arvore->raiz);

    delete arvore;

    return 0;
}