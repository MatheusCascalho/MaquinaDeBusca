// Copyright 2010 Universidade Federal de Minas Gerais (UFMG)
//
// Lista de exercícios sobre Tipos Abstratos de Dados.
// Aplicação: Números Complexos - Coordenadas Euclidianas.
//
// QUESTÃO 1:
// Implemente em complexo.cpp as funções descritas em complexo.h.
//
// QUESTÃO 2:
// Escreva um programa que simula uma calculadora de números complexos.
// Ele deve apresentar um menu com as operações de soma, subtração,
// multiplicação, divisão, módulo e conjugado. Após o usuário escolher uma das
// funções, o programa deve ler o valor dos parâmetros e em seguida exibir o
// resultado da função.
//
// QUESTÃO 3:
// Escreva uma função "void CalcularRaizes(float a, float b, float c,
// Complexo* r1, Complexo* r2)" que recebe os coeficientes
// de uma equação de segundo grau "a.x^2 + b.x + c = 0" e retorna por r1 e r2
// as raízes (possivelmente complexas) desta equação.
//
// QUESTÃO 4:
// Escreva um programa que lê do teclado os coeficientes reais de uma equação de
// segundo grau e imprime na tela as raízes (possivelmente complexas) desta
// equação.

#include <cmath>
#include <iostream>
#include <sstream>
#include <windows.h>
#include "complexo.h"

using namespace std;

double CalcularDelta(double a, double b, double c){
  double delta = (b * b - 4*a*c);
  return(delta);
}

void CalcularRaizes(double a, double b, double c, Complexo& r1, Complexo& r2){
  double delta = (CalcularDelta(a, b, c));
 
  if (delta >= 0){
    r1 = Complexo((-b + sqrt(delta))/2*a, 0);
    r2 = Complexo((-b - sqrt(delta))/2*a, 0);
  } else {
    r1 = Complexo((-b/2*a),(sqrt(-delta)/2*a));
    r2 = Complexo((-b/2*a),(- sqrt(-delta)/2*a));
  }
}

void imprimeComplexo(Complexo x){
  if (x.real() != 0 && x.imag() != 0){
    cout << x.real() << " + " << x.imag() << "i \n";
  } else if (x.imag() == 0){
    cout << x.real() << endl;
  } else if (x.real() == 0){
    cout << x.imag() << "i \n";
  }
}


int main() {
  double real, imaginaria, a, b, c;
  Complexo numero, X, Y;

  int caso = 1;
  while(caso > 0){

    cout << "\tBem vindo(a) a calculadora de numeros complexos!\n" << endl
         << "Por favor, digite um numero correspondente a uma operacao a ser realizada.\n" << endl;

    cout << "1 - Soma de dois numeros complexos." << endl
         << "2 - Subtracao de dois numeros complexos." << endl
         << "3 - Multiplicacao de dois numeros complexos." << endl
         << "4 - Divisao de um numero complexo por outro." << endl
         << "5 - Encontrar o Modulo de um numero complexo." << endl
         << "6 - Encontrar o Conjugado de um numero complexo." << endl
         << "7 - Encontrar o Inverso de um numero complexo." << endl
         << "8 - Achar as Raizes de uma Funcao do 2o Grau." << endl
         << "0 - Fechar o programa.\n" << endl
         << "Entrada: ";
        
      
    cin >> caso;

    switch (caso){

      case 0:
        cout << "Fechando o Programa..." << endl;
        break;

      case 1:
        cout << "Operacao selecionada: Soma." << endl;
             
        cout << "Por favor digite a parte real e imaginaria de um numero complexo X: " << endl;
        cin >> real >> imaginaria;
        X = Complexo(real,imaginaria);

        cout << "Por favor digite a parte real e imaginaria de um numero complexo Y: " << endl;
        cin >> real >> imaginaria;
        Y = Complexo(real,imaginaria);

        cout << "Numero X: ";
        imprimeComplexo(X);
        cout << "Numero Y: ";
        imprimeComplexo(Y);
        cout << "Soma X + Y: ";
        imprimeComplexo(X + Y);
        cout << "\n\n\n";
        system("pause");
        system("cls");
        break;

      case 2:
        cout << "Operacao selecionada: Subtracao." << endl;
             
        cout << "Por favor digite a parte real e imaginaria de um numero complexo X: " << endl;
        cin >> real >> imaginaria;
        X = Complexo(real,imaginaria);

        cout << "Por favor digite a parte real e imaginaria de um numero complexo Y: " << endl;
        cin >> real >> imaginaria;
        Y = Complexo(real,imaginaria);

        cout << "Numero X: ";
        imprimeComplexo(X);
        cout << "Numero Y: ";
        imprimeComplexo(Y);
        cout << "Subtracao X - Y: ";
        imprimeComplexo(X - Y);
        cout << "\n\n\n";
        system("pause");
        system("cls");
        break;

      case 3:
        cout << "Operacao selecionada: Multiplicacao." << endl;
             
        cout << "Por favor digite a parte real e imaginaria de um numero complexo X: " << endl;
        cin >> real >> imaginaria;
        X = Complexo(real,imaginaria);

        cout << "Por favor digite a parte real e imaginaria de um numero complexo Y: " << endl;
        cin >> real >> imaginaria;
        Y = Complexo(real,imaginaria);

        cout << "Numero X: ";
        imprimeComplexo(X);
        cout << "Numero Y: ";
        imprimeComplexo(Y);
        cout << "Multiplicacao X * Y: ";
        imprimeComplexo(X * Y);
        cout << "\n\n\n";
        system("pause");
        system("cls");
        break;

      case 4:
        cout << "Operacao selecionada: Divisao." << endl;
             
        cout << "Por favor digite a parte real e imaginaria de um numero complexo X: " << endl;
        cin >> real >> imaginaria;
        X = Complexo(real,imaginaria);

        cout << "Por favor digite a parte real e imaginaria de um numero complexo Y: " << endl;
        cin >> real >> imaginaria;
        Y = Complexo(real,imaginaria);

        cout << "Numero X: ";
        imprimeComplexo(X);
        cout << "Numero Y: ";
        imprimeComplexo(Y);
        cout << "Divisao X / Y: ";
        imprimeComplexo(X / Y);
        cout << "\n\n\n";
        system("pause");
        system("cls");
        break;

      case 5:
        cout << "Operacao selecionada: Modulo." << endl;
             
        cout << "Por favor digite a parte real e imaginaria de um numero complexo X: " << endl;
        cin >> real >> imaginaria;
        X = Complexo(real,imaginaria);

        cout << "Numero X: ";
        imprimeComplexo(X);
        cout << "Modulo de X: " << X.modulo();
        cout << "\n\n\n";
        system("pause");
        system("cls");
        break;
      
      case 6:
        cout << "Operacao selecionada: Conjugado." << endl;
             
        cout << "Por favor digite a parte real e imaginaria de um numero complexo X: " << endl;
        cin >> real >> imaginaria;
        X = Complexo(real,imaginaria);

        cout << "Numero X: ";
        imprimeComplexo(X);
        cout << "Conjugado de X: ";
        imprimeComplexo(X.conjugado());
        cout << "\n\n\n";
        system("pause");
        system("cls");
        break;

      case 7:
        cout << "Operacao selecionada: Inverso." << endl;
             
        cout << "Por favor digite a parte real e imaginaria de um numero complexo X: " << endl;
        cin >> real >> imaginaria;
        X = Complexo(real,imaginaria);

        cout << "Numero X: ";
        imprimeComplexo(X);
        cout << "Inverso de X: ";
        imprimeComplexo(X.inverso());
        cout << "\n\n\n";
        system("pause");
        system("cls");
        break;
      
      case 8:
        cout << "Operacao selecionada: Raizes de uma Funcao do 2o Grau." << endl
             << "Funcao: aX2 + bX + c" << endl;

        cout << "Digite a: ";
        cin >> a;
        cout << "Digite b: ";
        cin >> b;
        cout << "Digite c: ";
        cin >> c;

        cout << "Funcao montada: " << a << "x`2 + " << b << "x + "<< c << endl;

        CalcularRaizes(a, b, c, X, Y);
        cout << "Raiz 1: ";
        imprimeComplexo(X);       
        cout << "Raiz 2: ";
        imprimeComplexo(Y);
        
        system("pause");
        system("cls");
        break;
      
      default:
        cout << "Numero de entrada invalido, reiniciando...\n" << endl;
        system("pause");
        system("cls");
        break;
    }
  }

    system("pause");
    return 0;
}
