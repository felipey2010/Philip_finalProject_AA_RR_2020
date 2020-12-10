/**
**IMPLEMENTACAO DE ALGORITMO DE CAIXERO VIAJANTE
**REF: https://www.geeksforgeeks.org/traveling-salesman-problem-tsp-implementation/
**/
#include <bits/stdc++.h>
#include <memory>
#include <iostream>
#include <chrono>

using namespace std;
//Numero de vertices
#define V 4

//utilizando como benchmark para avaliar o desempenho
class Timer{
public:
    Timer(){
        m_StartTimepoint = std::chrono::high_resolution_clock::now();
    }
    ~Timer(){
        Stop();
    }

    void Stop(){
        auto endTimepoint = std::chrono::high_resolution_clock::now();

        auto start = std::chrono::time_point_cast<std::chrono::microseconds>(m_StartTimepoint).time_since_epoch().count();
        auto end = std::chrono::time_point_cast<std::chrono::microseconds>(endTimepoint).time_since_epoch().count();
        auto duration = end - start;
        double ms = duration * 0.001;

        std::cout << duration << "us (" << ms << "ms)\n";
    }
private:
    std::chrono::time_point <std::chrono::high_resolution_clock> m_StartTimepoint;
};

//Algoritmo de caixeiro viajante
int TSP(int grafo[][V], int s){
    // armazenar todos os vertices alem do vertice de origem
    vector<int> vertice;
    for (int i = 0; i < V; i++)
        if (i != s)
            vertice.push_back(i);

    // armazenar peso minimo Ciclo Hamiltoniano.
    int caminho_minimo = INT_MAX;
    do {

        // armazenar peso do caminho atual (custo)
        int peso_caminho_atual = 0;

        // calcular o peso do caminho atual
        int k = s;
        for (int i = 0; i < vertice.size(); i++) {
            peso_caminho_atual += grafo[k][vertice[i]];
            k = vertice[i];
        }
        peso_caminho_atual += grafo[k][s];

        // atualizar caminho minimo
        caminho_minimo = min(caminho_minimo, peso_caminho_atual);

    } while (
        next_permutation(vertice.begin(), vertice.end()));

    return caminho_minimo;
}

int main(){
    // matriz representacao do grafo
    int grafo[][V] = { { 0, 10, 15, 20 },
                       { 10, 0, 35, 25 },
                       { 15, 35, 0, 30 },
                       { 20, 25, 30, 0 } };
    int s = 0;
    {
        Timer timer;
        cout << "Custo minimo = " << TSP(grafo, s) << endl;

    }
        return 0;
}
