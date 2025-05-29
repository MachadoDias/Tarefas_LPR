#include <iostream>
#include <locale> 
using namespace std;

void MediaNumerosPares(){
    int quantidade;
    cout << "Digite a quantidade de números a serem inseridos: ";
    cin >> quantidade;

    int soma = 0;
    int contador = 0;

    while (quantidade > 0) {
        int numero;
        cout << "Digite um número: ";
        cin >> numero;

        if (numero % 2 == 0) {
            soma += numero;
            contador++;
        }

        quantidade--;
    }

    if (contador > 0) {
        double media = static_cast<double>(soma) / contador;
        cout << "A média dos números pares é: " << media << endl;
    } else {
        cout << "Nenhum número par foi digitado." << endl;
    }
}

void SomaMultiplos3De50a500(){
    int soma = 0;
    for (int i = 50; i <= 500; i++) {
        if (i % 2 != 0 && i % 3 == 0) {
            soma += i;
        }
    }

    cout << "A soma dos números ímpares múltiplos de 3 de 50 a 500 é: " << soma << endl;

}

void SumDigits(){
    int n;
    cout<<"Digite o número: ";
    cin>>n;
    n*=n;
    int sum = 0;
    while(n > 0){
        sum += n%10;
        n /= 10;
    }
    cout<<sum<<endl;
}

int main(){
    setlocale(LC_ALL, "pt_BR.utf8");
    short escolha;
    cout<<"Escolha um algoritmo:\n1 - Média de números pares\n2 - Soma dos números múltiplos de 3 entre 50 e 500\n3 - Soma dos dígitos do quadrado de um número\n";
    cin>>escolha;
    switch (escolha)
    {
    case 1:
        MediaNumerosPares();
        break;
    
    case 2:
        SomaMultiplos3De50a500();
        break;

    case 3:
        SumDigits();
        break;
    
    default:
        cout<<"Opção inválida";
        break;
    }
}