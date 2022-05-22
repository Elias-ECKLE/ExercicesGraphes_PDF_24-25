
#include "CReseau.h"


void gotoxy(short x, short y)           //Introduction of gotoxy function//                                               
{
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}


reseau::reseau() {
	this->n_nbNoeuds = 0;
	this->n_nbConnexions = 0;
	this->n_nbNoeuds = 0;

	this->p_tabNoeuds = nullptr;
	this->p_matriceConnex = nullptr;
	//this->p_tabNoeuds = new node[this->n_nbNoeuds];
	//this->p_matriceConnex = new char* [this->n_nbNoeuds];

	
}

reseau::~reseau() {
	delete p_tabNoeuds;
}


void reseau::InitMatrice() {
	//on alloue la place qu'il faut selon le nb de noeuds 
	this->p_matriceConnex = new char* [this->n_nbNoeuds];
	for (int i = 0; i < this->n_nbNoeuds; i++) {
		p_matriceConnex[i] = new char[this->n_nbNoeuds];

		for (int j = 0; j < this->n_nbNoeuds; j++) {
			p_matriceConnex[i][j] = 'n';
		}
	}
	

}

//agrandir la taille de la map 
void reseau::MaxMatrice() {

	char** p_matriceConnexTemp = this->p_matriceConnex;
	this->p_matriceConnex = new char* [this->n_nbNoeuds];

	for (int i = 0; i < this->n_nbNoeuds - 1; i++) {
		p_matriceConnex[i] = new char[this->n_nbNoeuds];

		for (int j = 0; j < this->n_nbNoeuds - 1; j++) {
			p_matriceConnex[i][j] = p_matriceConnexTemp[i][j];
		}
	}
	p_matriceConnex[this->n_nbNoeuds - 1] = new char[this->n_nbNoeuds];
	for (int j = 0; j < this->n_nbNoeuds; j++) {
		p_matriceConnex[this->n_nbNoeuds - 1][j] = 'n'; 
	}

	//on libère la matrice temporaire 
	
	if (p_matriceConnexTemp!=nullptr) {
		for (int i = 0; i < this->n_nbNoeuds -1 ; i++) {
			delete p_matriceConnexTemp[i];
		}

		delete p_matriceConnexTemp;
		
	}
}

void reseau::AfficherMatrice() {

	cout <<"---------------Affichage Matrice----------------" << endl;
	this->decalageY++;



	//graduation x
	for (int i = 0; i < this->n_nbNoeuds; i++) {
		//graduation y
		for (int j = 0; j < this->n_nbNoeuds; j++) {
			gotoxy(i, j+this->decalageY);
			cout << this->p_matriceConnex[i][j] << endl;
		}


	}
	this->decalageY += this->n_nbNoeuds;


}



//ajouter un noeud dans le graphe 
void reseau::AjouterNoeud(node noeud) {

	this->n_nbNoeuds++;

	//on ajoute le noeud dans le tableau de pointeurs p_tabNoeuds
		//par défaut il s'agit du premier noeud, le tableau étant à null on alloue alors la place nécessaire à un noeud
	if (p_tabNoeuds==nullptr) {
		this->p_tabNoeuds = new node[this->n_nbNoeuds];
		this->p_tabNoeuds[0] = noeud;

		//on initialise la matrice dans le même temps 
		InitMatrice();
		return;
	}

	//sinon si le tableau a déjà des noeuds alors on réalloue l'emplctm qu'il faut pour y ajouter un nouveau noeud
	//on stock les valeurs dans un tab temporaire et on les intilialise par de nouveau en suite
	node* p_tabNoeudsTemp = this->p_tabNoeuds;
	this->p_tabNoeuds = new node[this->n_nbNoeuds];

	for (int i = 0; i < this->n_nbNoeuds - 1; i++) {
		this->p_tabNoeuds[i] = p_tabNoeudsTemp[i];
	}
	this->p_tabNoeuds[this->n_nbNoeuds - 1] = noeud;



	//et on agrandit la matrice pour que sa taille colle toujours au nombre de noeuds ajoutés:
	//MaxMatrice();


	
	//si p_temp n'est pas null alors on supprime l'espace alloué à cet effet
	if (p_tabNoeudsTemp != nullptr) {
		delete p_tabNoeudsTemp;
	}


}

bool reseau::CheckNoeud(node noeud) {

	for (int i = 0; i<this->n_nbNoeuds; i++) {
		if (this->p_tabNoeuds[i].n_id == noeud.n_id) {
			return true;
		}
	}
	return false;
}
void reseau::AjouterConnexion(node noeud1, node noeud2 ) {

	if (this->p_tabNoeuds!=nullptr) {

		//on vérifie dans un premier temps si les deux noeuds existent bien ou pas
		if (CheckNoeud(noeud1) && CheckNoeud(noeud2)){
		
				

			
		}
	}





}




void reseau::AfficherNoeuds() {

	cout << "---------------Liste de noeuds----------------" << endl;
	this->decalageY++;
	 
	for (int i = 0; i<this->n_nbNoeuds ;i++) {
		cout <<this->p_tabNoeuds[i].n_id<<" : "<<this->p_tabNoeuds[i].f_posCoord<< endl;
		this->decalageY++;
	}
}