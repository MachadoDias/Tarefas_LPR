#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
struct Livro{
    string Titulo;
    string Autor;
    unsigned int AnoPublicacao;
    unsigned int NumeroPaginas;
    float Preco;
};
int main(){
    vector<Livro> livros(3);
    cout << "Digite os dados dos livros em sequencia: " << endl;
    for(Livro &livro : livros){
        cout << "Digite o titulo do livro: "; cin >> livro.Titulo;
        cout << "Digite o nome do autor: "; cin >> livro.Autor;
        cout << "Digite o ano de publicacao do livro: "; cin >> livro.AnoPublicacao;
        cout << "Digite o numero de paginas: "; cin >> livro.NumeroPaginas;
        cout << "Digite o preco do livro: "; cin >> livro.Preco;
    }
    float valorTotal = 0;
    float media = 0;
    for(Livro livro : livros){
        valorTotal += livro.Preco;
        media += livro.NumeroPaginas;
    }
    media /= livros.size();
    cout << "Valor total dos livros: " << fixed << setprecision(2) << valorTotal << endl << "Media de paginas: " << fixed << setprecision(2) << media;
}