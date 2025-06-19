#include <iostream>
#include <vector>
#include <string>
using namespace std;
bool isVowel(int l){
    return l == 0 || l == 4 || l == 8 || l == 14 || l == 20;
}
// Verifica se a letra é uma vogal de acordo com o índice
int main(){
    vector<int> alfabeto;
    for(char letras = 'a'; letras <= 'z'; letras++){
        if(letras == 'w' || letras == 'y') continue;
        alfabeto.push_back(letras - 'a');
    }
    // Inicializa o vetor de alfabeto com os índices das letras
    string palavra;
    vector<char> out;
    cin >> palavra;
    // Recebe a entrada e declara a saída
    for(int i = 0; i < palavra.size(); i++){
        if(isVowel(palavra[i] - 'a')){
            out.push_back(palavra[i]);
            continue;
        }
        // Se for uma vogal, adiciona na saída e segue para a próxima letra 
        out.push_back(palavra[i]);
        // Adiciona a consoante na saída
        int posicao = 0;
        for(int j = 0; j < alfabeto.size(); j++){
            if(alfabeto[j] == palavra[i] - 'a'){
                posicao = j;
                break;
            }
        }
        // Encontra o índice da consoante
        int idEsquerda = -1, idDireita = alfabeto.size();
        for (int j = posicao; j >= 0; j--) {
            if(isVowel(alfabeto[j])){
                idEsquerda = j;
                break;
            }
        }
        for(int k = posicao; k < alfabeto.size(); k++){
            if(isVowel(alfabeto[k])){
                idDireita = k;
                break;
            }
        }
        // Acha os índices das vogais mais próximas
        if(idEsquerda < 0) {
            out.push_back(alfabeto[idDireita] + 'a');
        } 
        // Se não houver nenhuma vogal à esquerda, adiciona a vogal da direita
        else if(idDireita >= alfabeto.size()) {
            out.push_back(alfabeto[idEsquerda] + 'a');
        } 
        // Se não houver nenhuma à direita, adiciona a da esquerda
        else if(posicao - idEsquerda <= idDireita - posicao) {
            out.push_back(alfabeto[idEsquerda] + 'a');
        } 
        // Se a vogal esquerda estiver mais próxima ou a distância for igual, adiciona a da esquerda
        else {
            out.push_back(alfabeto[idDireita] + 'a');
        }
        // Senão, adiciona a da direita 
        if(posicao == alfabeto.size() - 1)
            out.push_back(palavra[i]);
        else{
            for(int j = posicao + 1; j < alfabeto.size(); j++){
                if(!isVowel(alfabeto[j])){
                    out.push_back('a' + alfabeto[j]);
                    break;
                }
            }
        }
        // Adiciona a próxima consonte
    }
    for(char l : out){
        cout << l;
    }
    cout << endl;
    return 0;
}
