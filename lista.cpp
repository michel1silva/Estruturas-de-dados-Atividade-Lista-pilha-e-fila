#include <iostream>
using namespace std;

typedef int TIPOCHAVE;

struct REGISTRO {
    TIPOCHAVE chave;
    // Outros campos...
};

struct ELEMENTO {
    REGISTRO reg;
    ELEMENTO *ant;
    ELEMENTO *prox; 
};

typedef ELEMENTO* PONT;

struct LISTA {
    PONT inicio;
};

void inicializarLista(LISTA *l) {
    l->inicio = NULL;
}

bool inserirElemListaOrd(LISTA *l, REGISTRO reg) {
    PONT novo = new ELEMENTO(); 
    novo->reg = reg;
    novo->ant = NULL;
    novo->prox = NULL;

    PONT atual = l->inicio;
    PONT anterior = NULL;

    while (atual != NULL && atual->reg.chave < reg.chave) {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual != NULL && atual->reg.chave == reg.chave) {
        delete novo; 
        return false; 
    }

    novo->prox = atual;
    if (atual != NULL) {
        atual->ant = novo;
    }

    if (anterior == NULL) {
        l->inicio = novo; 
    } else {
        anterior->prox = novo;
        novo->ant = anterior;
    }

    return true;
}

bool excluirElemLista(LISTA *l, TIPOCHAVE chave) {
    PONT atual = l->inicio;

    while (atual != NULL && atual->reg.chave != chave) {
        atual = atual->prox;
    }

    if (atual == NULL) {
        return false; 
    }

    if (atual->ant != NULL) {
        atual->ant->prox = atual->prox;
    } else {
        l->inicio = atual->prox;
    }

    if (atual->prox != NULL) {
        atual->prox->ant = atual->ant;
    }

    delete atual;
    return true;
}

void exibirLista(LISTA *l) {
    PONT atual = l->inicio;
    while (atual != NULL) {
        std::cout << atual->reg.chave << " ";
        atual = atual->prox;
    }
    std::cout << std::endl;
}

int main() {
    LISTA lista;
    inicializarLista(&lista);

    REGISTRO r1 = {10};
    REGISTRO r2 = {20};
    REGISTRO r3 = {15};

    inserirElemListaOrd(&lista, r1);
    inserirElemListaOrd(&lista, r2);
    inserirElemListaOrd(&lista, r3);

    std::cout << "Lista após inserções: ";
    exibirLista(&lista);

    excluirElemLista(&lista, 15);
    std::cout << "Lista após excluir 15: ";
    exibirLista(&lista);

    excluirElemLista(&lista, 10);
    std::cout << "Lista após excluir 10: ";
    exibirLista(&lista);

    excluirElemLista(&lista, 20);
    std::cout << "Lista após excluir 20: ";
    exibirLista(&lista);

    return 0;
}
