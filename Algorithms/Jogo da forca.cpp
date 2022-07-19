//Testes feitos em C++ para um amigo...
//Posteriormente atualizo isso aqui com o código inteiro

//Headers e defines

#include <bits/stdc++.h>
using namespace std;
typedef vector<char> vc;

//Functions

bool have(vc letras, char c){
    for(auto e : letras){
        if(e == c){
            return true;
        }
        else{
            return false;
        }
    }
};

//Main e variáveis

int main(){
    string array[5] = {"computador", "programar", "jogos", "software", "felicidade"};
    string acertos[10]; 
    vc letras;
    char c;
    
    memset(acertos, '-', sizeof(acertos));
    srand(time(NULL));
    int r = rand() % 5;
    int count = 0, i, t = 6, f = 0;

    cout << "Bem vindo ao jogo da forca!" << endl;
    cout << "A palavra ja foi selecionada! Tente advinhar..." << endl;
    cout << "Digite uma letra/palavra: ";
    
    while(true){
        int control = 0;
        cin >> c;
        if(have(letras, c) == true){
            cout << "Essa letra já foi usada..." << endl;
            cout << "Digite outra: ";
        }
        else{
            for(auto e : array[r]){
                if(e == c){
                    acertos[control] = c;
                    control++;
                    f++;
                }
            }
            letras.push_back(c);
            if(control == 0){
                t--;
                cout << "Infelizmente não existe essa letra/palavra na palavra a ser achada!" << endl;
                cout << "Tente novamente..." << endl;
                cout << "Digite uma letra/palavra: ";
                cout << "A palavra ficou assim: ";
                for(int j = 0; j < array[r].length(); j++){
                    cout << acertos[j] << " ";
                }
            }
            else{
                cout << "Boa, acertou! Continue assim!" << endl;
                cout << "Digite uma letra/palavra: ";
            }
        }
        if(f == array[r].length() + 1){
            cout << "Parabéns, venceu o jogo!" << endl;
            cout << "A palavra ficou assim: ";
            for(int j = 0; j < array[r].length(); j++){
                cout << acertos[j] << " ";
            }
            break;
        }
        else if(t <= 0){
            cout << endl << "Infelizmente não completou a palavra nas 5 tentativas..." << endl;
            cout << "Boa sorte na próxima :)" << endl;
            cout << "A palavra era: " << array[r] << endl;
            break;
        }
    }
    return 0;
}
