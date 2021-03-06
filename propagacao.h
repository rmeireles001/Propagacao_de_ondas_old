#ifndef prop_onda
#define prop_onda

#define ponderacao 1.0
#define ro 2700
#define pontos 1001

#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include "arv.h"

using namespace std;

struct ord{
	double area;
	double ggexp;
};

class propagacao{
public:
	double *Gexp, *G, *A, *Z, *R, *F, *P, *posicao;
	int *config;
	double **A1, **B1, **Y;
	double E, c;
	propagacao();
	~propagacao();
	double **alocar_mat(int size);
	void liberar_mat(double **mat, int size);
	void inserir(string s);
	void prob_direto(int n, double *G);
	void prob_inverso();
	void prob_inverso(int n);
	double erroG(int i);
	void atribuirA(int n, double v);
	void dados_experimentais(string s, int n, int ini);
	void estimativa_inicial(double n);
	void config_area(double n);
	void attr_config(int k, double var);
	void atualizar_area(int k);
	void zerar(int n);
	double luus_jaakola(int pos);
	void run_lj(string arq_areas, string saida, int inicio, int fim);
	//void run_aco(string arq_areas, string saida, int inicio, int fim);
	void escrever_txt(string saida, string metodo, double tempo, int inicio, int fim);
	double cgrasp(double llimit, double ulimit, double incr, int section);
	void run_cgrasp(string arq_areas, string saida, int inicio, int fim);
	void edit_areas();
	void print_erro(int secao, double delta, string arq_ent, string arq_saida);
	double binary_search(arvore *arv, double llimit, double ulimit, double delta, double secao);
	void imprime_area(arvore *arv, int b, double delta, int secao, double llimit);
	void imprime_eco(arvore *arv, int b, double delta, int secao, double llimit);
	void imprimir(double valor, int b, double delta);
	double busca_ordenada(ord *vet, int secao, double delta, double llimit, double ulimit);
	int part(ord *vetor, int ini, int fim);
	void quickSort(ord *vetor, int ini, int fim);
};

double prand(double low, double high);
double function(double x);

#endif
