
#include <iostream>

using namespace std;

int main() {
    // Aqui já estão os resultados da relação calabresa x cebola
    int pizza[] = {-3, 4, -5, 0, 2, -1, 6, -4, 3, 8, -10, 2, -3, 1, 6, 9};
    int tamanho_pizza = 16;
    int rodada_pizza = 1;
    int pedaco = 0;

    int inicio = 0;
    int fim = 0;

    int pontuacao = 0;
    int negativos_acumulados = 0;
    int positivos_acumulados = 0;
    int positivos_aplicar = 0;

    cout << "Começando a Pizza" << endl;
    while(true) {
        if(rodada_pizza == 2 && pedaco == inicio) {
            pontuacao += positivos_aplicar;
            break;
        }

        cout << "Pedaço " << pedaco + 1 << " => " << pizza[pedaco] << endl;
//        cout << " <<< Pontuação: " << pontuacao << " - Negativos acumulados: " << negativos_acumulados << " - Positivos acumulados: " << positivos_acumulados << endl;

        if(pizza[pedaco] < 0) {
            if(pontuacao >= 0) {
                negativos_acumulados += pizza[pedaco];
            }

            if(pontuacao + negativos_acumulados < 0) {
                inicio = 0;
                pontuacao = 0;
                negativos_acumulados = 0;
                positivos_acumulados = 0;
            }
        } else {
            if(inicio == 0) {
                inicio = pedaco;
                positivos_acumulados = 0;
                positivos_aplicar = 0;
            }

            if(pizza[pedaco] + negativos_acumulados >= 0) {
                positivos_aplicar += positivos_acumulados;
                pontuacao += pizza[pedaco] + negativos_acumulados;
                negativos_acumulados = 0;
                positivos_acumulados = 0;
                fim = pedaco;
            } else {
                positivos_acumulados += pizza[pedaco];
            }
        }

        pedaco++;

        if(pedaco == tamanho_pizza) {
            if(rodada_pizza == 2) {
                break;
            }

            cout << "Começando a Pizza Novamente" << endl;
            rodada_pizza++;
            pedaco = 0;
        }
    }

    cout << "Início: " << inicio + 1 << endl;
    cout << "Fim: " << fim + 1 << endl;
    cout << "Pontuacao: " << pontuacao;

    return 0;
}