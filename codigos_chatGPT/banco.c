#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Definição da estrutura do nó da lista
typedef struct no {
    float saldo;
    struct no *prox;
} No;

// Função para criar um novo nó com o saldo inicial
No* criarNo(float saldo) {
    No *novoNo = (No*) malloc(sizeof(No));
    novoNo->saldo = saldo;
    novoNo->prox = NULL;
    return novoNo;
}

// Função que insere um novo nó no início da lista
void depositar(No **cabeca, float valor) {
    No *novoNo = criarNo(valor);
    novoNo->prox = *cabeca;
    *cabeca = novoNo;
    printf("Deposito realizado com sucesso. Novo saldo: %.2f\n", valor + (*cabeca)->saldo);
}

// Função que saca um valor da lista, se houver saldo suficiente
void sacar(No **cabeca, float valor) {
    if (valor <= (*cabeca)->saldo) {
        (*cabeca)->saldo -= valor;
        printf("Saque realizado com sucesso. Novo saldo: %.2f\n", (*cabeca)->saldo);
    } else {
        printf("Saldo insuficiente para saque. Saldo atual: %.2f\n", (*cabeca)->saldo);
    }
}

// Função que imprime o saldo atual
void verSaldo(No **cabeca) {
    printf("Seu saldo é: %.2f\n", (*cabeca)->saldo);
}

// Função que solicita um novo empréstimo e adiciona o valor ao saldo
void fazerEmprestimo(No **cabeca, float valor) {
    (*cabeca)->saldo += valor;
    printf("Empréstimo de %.2f solicitado com sucesso. Novo saldo: %.2f\n", valor, (*cabeca)->saldo);
}

// Função que imprime a lista
void imprimirLista(No *cabeca) {
    No *aux = cabeca;
    while (aux != NULL) {
        printf("%.2f ", aux->saldo);
        aux = aux->prox;
    }
    printf("\n");
}

// Função principal
int main() {
    No *cabeca = NULL;
    // Depositar valores na conta
    depositar(&cabeca, 1000.00);
    depositar(&cabeca, 500.50);
    // Imprimir lista de saldos: 500.50 1000.00
    imprimirLista(cabeca);
    // Sacar um valor
    sacar(&cabeca, 300.00);
    // Imprimir o saldo atual: 700.50
    verSaldo(&cabeca);
    // Solicitar um novo empréstimo
    fazerEmprestimo(&cabeca, 1000.00);
    // Imprimir o saldo atual: 1700.50
    verSaldo(&cabeca);
    return 0;
}