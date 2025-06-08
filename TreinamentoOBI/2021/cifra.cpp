#include <iostream>
#include <vector>
#include <string>
using namespace std;
bool isVowel(int l){
    return l == 0 || l == 4 || l == 8 || l == 14 || l == 20;
}
int main(){
    vector<int> alfabeto;
    for(char letras = 'a'; letras <= 'z'; letras++){
        if(letras == 'w' || letras == 'y') continue;
        alfabeto.push_back(letras - 'a');
    }
    string palavra;
    vector<char> out;
    cin >> palavra;
    for(int i = 0; i < palavra.size(); i++){
        if(isVowel(palavra[i] - 'a')){
            out.push_back(palavra[i]);
            continue;
        }
        out.push_back(palavra[i]);
        int posicao = 0;
        for(int j = 0; j < alfabeto.size(); j++){
            if(alfabeto[j] == palavra[i] - 'a'){
                posicao = j;
                break;
            }
        }
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
        if(idEsquerda < 0) {
            out.push_back(alfabeto[idDireita] + 'a');
        } else if(idDireita >= alfabeto.size()) {
            out.push_back(alfabeto[idEsquerda] + 'a');
        } else if(posicao - idEsquerda <= idDireita - posicao) {
            out.push_back(alfabeto[idEsquerda] + 'a');
        } else {
            out.push_back(alfabeto[idDireita] + 'a');
        }
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
    }
    for(char l : out){
        cout << l;
    }
    cout << endl;
    return 0;
}
