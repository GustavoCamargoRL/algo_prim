// Atividade assíncrona 4 
// Fundamentos de Algoritmos para Otimização
// Problema da Arvore geradora mínima

// Autor: Gustavo Lima
// prof: Raphael Kramer

// numeração das cidades:
// 0-sao luiz; 1-teresina; 2-fortaleza; 3-natal; 4-joao pessoa; 5-recife; 6-maceio; 7-aracaju; 8-salvador
// 9-belo horizonte; 10-sao paulo; 11-rio de janeiro; 12-vitoria; 13-cuiaba; 14-goiania; 15-campo grande
// 16-brasilia



#include <iostream>
#include <vector>
#include <algorithm> 

#define NCidades 17  //define o numero de cidades/vertices a ser analisado

int custoTotal = 0;
std::vector<std::string> nomes = { {"sao luiz"}, {"teresina"}, {"fortaleza"}, {"natal"},
{"joao pessoa"}, {"recife"}, {"maceio"}, {"aracaju"}, {"salvador"},
{"belo horizonte"}, {"sao paulo"}, {"rio de janeiro"}, {"vitoria"},
{"cuiaba"}, {"goiania"}, {"campo grande"}, {"brasilia"} };

int minVal(int key[], bool arvore[])
{
	// Inicialização do menor valor
	int min = INT_MAX;
	int min_index;

	for (int v = 0; v < NCidades; v++)
		if (arvore[v] == false && key[v] < min)
			min = key[v], min_index = v;
	return min_index;
}

void prim(std::vector<std::vector<int>> grafo)
{
	
	int origem[NCidades];  // Vetor de origem das cidades
	int key[NCidades];	   // Variavel auxiliar para escolher o menor valor entre as cidades
	bool visitado[NCidades]; // Vetor representando quais cidades já foram visitadas

	// Inicialização das chaves como infinito
	for (int i = 0; i < NCidades; i++)
	{
		key[i] = INT_MAX, visitado[i] = false;
	}
		
	key[0] = 0;  // Definindo valor da cidade inicial como 0
	origem[0] = -1; // A cidade de origem não possui predecessor

	// Inicializando loop de busca
	for (int count = 0; count < NCidades; count++)
	{
		int u = minVal(key, visitado);  // seleciona a cidade com menor valor de distancia que nao foi visitada

		visitado[u] = true; // Atualiza a cidade selecionada como visitada

		// Atualiza o menor valor associado a cidade destino e origem
		// Considerar apenas as cidades ainda não visitadas
		for (int v = 0; v < NCidades; v++)

			//Atualiza o valor da chave se grafo[u][v] é menor que key[v]
			if (grafo[u][v] && visitado[v] == false && grafo[u][v] < key[v]) 
			{
				origem[v] = u;
				key[v] = grafo[u][v];
			}
		if (count > 0) 
		{
			std::cout << "adiciona: ";
			for (int i = 0; i < nomes[origem[u]].size(); i++)
			{
				std::cout << nomes[origem[u]][i];
			}
			std::cout << '-';
			for (int i = 0; i < nomes[u].size(); i++)
			{
				std::cout << nomes[u][i];
			}
			std::cout << "  distancia:" << grafo[u][origem[u]] << std::endl;
			custoTotal += grafo[u][origem[u]];
		}
		
				
			
	}
}




int main(int argc, char *argv[])
{
	std::vector<std::vector<int>> matrix = {
	{{0},{43},{90},{142},{157},{171},{162},{155},{158},{251},{293},{293},{255},{268},{201},{287},{199}},
	{{43},{0},{62},{105},{120},{112},{119},{111},{115},{202},{265},{245},{212},{254},{188},{272},{168}} ,
	{{90},{62},{0},{52},{67},{77},{94},{110},{118},{232},{294},{258},{215},{302},{216},{300},{196}} ,
	{{142},{105},{52},{0},{17},{28},{54},{49},{109},{236},{292},{259},{213},{346},{260},{333},{240}} ,
	{{157},{120},{67},{17},{0},{11},{36},{61},{91},{219},{275},{227},{195},{329},{243},{316},{171}} ,
	{{171},{112},{77},{28},{11},{0},{25},{50},{80},{208},{263},{230},{184},{318},{232},{305},{212}} ,
	{{162},{119},{94},{54},{36},{25},{0},{27},{57},{185},{241},{208},{161},{295},{209},{282},{189}} ,
	{{155},{111},{110},{49},{61},{50},{27},{0},{31},{160},{215},{182},{136},{270},{184},{257},{164}} ,
	{{158},{115},{118},{109},{91},{80},{57},{31},{0},{140},{196},{163},{117},{250},{164},{237},{144}} ,
	{{251},{202},{232},{236},{219},{208},{185},{160},{140},{0},{58},{44},{51},{156},{88},{126},{72}} ,
	{{293},{265},{294},{292},{275},{263},{241},{215},{196},{58},{0},{43},{94},{152},{89},{98},{100}} ,
	{{293},{245},{258},{259},{227},{230},{208},{182},{163},{44},{43},{0},{52},{192},{130},{141},{116}} ,
	{{255},{212},{215},{213},{195},{184},{161},{136},{117},{51},{94},{52},{0},{208},{139},{191},{124}} ,
	{{268},{254},{302},{346},{329},{318},{295},{270},{250},{156},{152},{192},{208},{0},{89},{70},{105}} ,
	{{201},{188},{216},{260},{243},{232},{209},{184},{164},{88},{89},{130},{139},{89},{0},{84},{20}} ,
	{{287},{272},{300},{333},{316},{305},{282},{257},{237},{126},{98},{141},{191},{70},{84},{0},{104}} ,
	{{199},{168},{196},{240},{171},{212},{189},{164},{144},{72},{100},{116},{124},{105},{20},{104},{0}} };

	std::cout << "numeracao das cidades: 0-sao luiz; 1-teresina; 2-fortaleza; 3-natal; 4-joao pessoa; 5-recife; 6-maceio; 7-aracaju; 8-salvador";
	std::cout << " 9-belo horizonte; 10-sao paulo; 11-rio de janeiro; 12-vitoria; 13-cuiaba; 14-goiania; 15-campo grande 16-brasilia" << std::endl;
	std::cout << "Peso dos arcos = Distancia na ordem de 10km" << std::endl;
	std::cout << "Algoritmo de Prim:" << std::endl;
	prim(matrix);

	std::cout << "Custo total: " << custoTotal << std::endl;

	return 0;
}
