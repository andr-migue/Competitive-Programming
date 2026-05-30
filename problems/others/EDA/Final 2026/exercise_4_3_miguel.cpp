#include <bits/stdc++.h>
#include "../../../../algorithms/kosaraju.cpp"

using namespace std;
using namespace structures;

// x_i (positivo) → nodo 2*i
// ¬x_i (negativo) → nodo 2*i + 1
int lit_to_node(int lit)
{
    if (lit > 0)
    {
        return 2 * (lit - 1);
    } 
    else         
    {
        return 2 * (-lit - 1) + 1;
    }
}

// Retorna asignación satisfacible, o vacío si es insatisfacible.
// Literales 1-indexados: positivo = x_{i-1}, negativo = ¬x_{|i|-1}.
// Cláusula unitaria (a): pasar a == b.
// nodo ^ 1 niega cualquier literal (intercambia par <=> impar)
vector<bool> solve(int n, vector<pair<int,int>> &clauses)
{
    directed_list_graph graph(2 * n);

    for (auto [a, b] : clauses)
    {
        int u = lit_to_node(a);
        int v = lit_to_node(b);

        int not_u = lit_to_node(-a);
        int not_v = lit_to_node(-b);

        graph.connect(not_u, v);
        graph.connect(not_v, u);
    }

    vector<int> components = kosaraju(graph);

    for (int i = 0; i < n; i++)
    {
        if (components[2 * i] == components[2 * i + 1])
        {
            return {};
        }
    }

    vector<bool> assignment(n);
    
    for (int i = 0; i < n; i++)
    {
        assignment[i] = components[2 * i] > components[2 * i + 1];
    }

    return assignment;
}