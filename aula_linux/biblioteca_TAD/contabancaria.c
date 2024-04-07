#include <stdio.h>
#include "contabancaria.h"

void Inicializa(ContaBancaria* pconta, int numero, double saldo){
	pconta->numero = numero;
	pconta->saldo = saldo;
}

void Deposito(ContaBancaria* pconta, double valor){
	pconta->saldo += valor;
}

void Saque(ContaBancaria* pconta, double valor){
	pconta->saldo-=valor;
}

void Imprime(ContaBancaria conta){
	printf("\nNumero: %d", conta.numero);
	printf("\nSaldo: %f", conta.saldo);
}

