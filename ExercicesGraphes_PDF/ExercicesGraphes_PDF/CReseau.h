#pragma once

#include <iostream>
#include "SNoeud.h"
#include<windows.h>

using namespace std;






class reseau {

	int n_nbNoeuds;
	int n_nbConnexions;
	int decalageY;
	node* p_tabNoeuds;
	char** p_matriceConnex;



public :

	reseau();
	~reseau();

	//initiliasation de la matrice à 'n' : 'n' pour false et 'o' pour true
	void InitMatrice();
	void MaxMatrice();
	void AfficherMatrice();


	bool CheckNoeud(node);
	void AjouterNoeud(node);
	void AfficherNoeuds();

	bool CheckConnexion(node, node);
	void AjouterConnexion(node, node);











};