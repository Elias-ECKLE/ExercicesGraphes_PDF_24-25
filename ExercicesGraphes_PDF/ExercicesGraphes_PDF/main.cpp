

#include "CReseau.h"


//exercice 24.1 
//prérequis :
//nb de noeuds : 6 / nb de connexion 

int main() {



	node noeud1;
	noeud1.n_id = 0;
	noeud1.f_posCoord = 0.f;

	node noeud2;
	noeud2.n_id = 1;
	noeud2.f_posCoord = 2.f;


	node noeud3;
	noeud3.n_id = 2;
	noeud3.f_posCoord = 6.f;


	node noeud4;
	noeud4.n_id = 4;
	noeud4.f_posCoord = 1.f;


	node noeud5;
	noeud5.n_id = 5;
	noeud5.f_posCoord = 14.f;

	node noeud6;
	noeud6.n_id = 6;
	noeud6.f_posCoord = 19.f;

	reseau net;
	net.AjouterNoeud(noeud1);
	net.AjouterNoeud(noeud2);
	net.AjouterNoeud(noeud3);
	net.AjouterNoeud(noeud4);	
	net.AjouterNoeud(noeud5);	
	net.AjouterNoeud(noeud6);

	net.AfficherNoeuds();

	net.InitMatrice();



	return 0;
}