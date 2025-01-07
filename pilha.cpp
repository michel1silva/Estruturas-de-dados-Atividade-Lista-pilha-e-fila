#include <iostream>
#define MAX 100 

struct REGISTRO {
    int chave;
};

struct PILHA {
    REGISTRO A[MAX];
    int topo;
};

void inicializarPilha(PILHA *p) {
    p->topo = -1;
}

bool pilhaVazia(PILHA *p) {
    return p->topo == -1;
}

bool pilhaCheia(PILHA *p) {
    return p->topo == MAX - 1;
}

bool push(PILHA *p, REGISTRO reg) {
    if (pilhaCheia(p)) return false;
    p->A[++(p->topo)] = reg;
    return true;
}

bool pop(PILHA *p, REGISTRO *reg) {
    if (pilhaVazia(p)) return false;
    *reg = p->A[(p->topo)--];
    return true;
}

void exibirPilha(PILHA *p) {
    std::cout << "Pilha (do topo para a base): ";
    for (int i = p->topo; i >= 0; i--) {
        std::cout << p->A[i].chave << " ";
    }
    std::cout << "\n";
}

void exibirPilhaInvertida(PILHA *p) {
    std::cout << "Pilha (da base para o topo): ";
    for (int i = 0; i <= p->topo; i++) {
        std::cout << p->A[i].chave << " ";
    }
    std::cout << "\n";
}

int main() {
    PILHA pilha;
    inicializarPilha(&pilha);

    REGISTRO r1 = {10};
    REGISTRO r2 = {20};
    REGISTRO r3 = {30};

    push(&pilha, r1);
    push(&pilha, r2);
    push(&pilha, r3);

    exibirPilha(&pilha);

    exibirPilhaInvertida(&pilha);

    REGISTRO removido;
    while (pop(&pilha, &removido)) {
        std::cout << "Elemento removido: " << removido.chave << "\n";
    }

    exibirPilha(&pilha);

    return 0;
}

