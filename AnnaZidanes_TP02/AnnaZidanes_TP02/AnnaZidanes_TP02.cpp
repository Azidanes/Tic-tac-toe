
#include <iostream>
#include <cstdlib>
using namespace std;



// La fonction « grille » qui gère l’affichage de la grille en fonction de la case choisie par le joueur
void AfficherGrille(char Grille[]) {

	system("cls");

	for (int i = 0; i < 9; ++i) {
		if (i % 3 == 0) {
			cout << endl << "-----------" << endl;
		}
		cout << Grille[i] << " | ";

	}
	cout << endl << "-----------" << endl;
}

// La fonction « Verifierchoix » qui vérifie si la case choisie est vide et si c'est le cas, met le symbole dans cette case
/**/void Verifierchoix(int case_, char symbole, char Grille[]) {

	while (Grille[case_ - 1] == 'X' || Grille[case_ - 1] == 'O') {
		cout << endl << endl << "Veiullez faire une choix de une case vide" << endl;
		cin >> case_;
	}

	Grille[case_ - 1] = symbole;



}


// La fonction « victoire » qui vérifie si 3 cases consécutives contiennent le même symbole

bool Victoire(char Grille[]) {

	bool victoire = false;

	//Victoireligne1
	if ((Grille[0] == 'X' && Grille[1] == 'X' && Grille[2] == 'X') || (Grille[0] == 'O' && Grille[1] == 'O' && Grille[2] == 'O'))
		victoire = true;
	// Victoireligne2:
	else if ((Grille[3] == 'X' && Grille[4] == 'X' && Grille[5] == 'X') || (Grille[3] == 'O' && Grille[4] == 'O' && Grille[5] == 'O'))
		victoire = true;
	// Victoireligne3:
	else if ((Grille[6] == 'X' && Grille[7] == 'X' && Grille[8] == 'X') || (Grille[6] == 'O' && Grille[7] == 'O' && Grille[8] == 'O'))
		victoire = true;
	//Victoirecolumne1:
	else if ((Grille[0] == 'X' && Grille[3] == 'X' && Grille[6] == 'X') || (Grille[0] == 'O' && Grille[3] == 'O' && Grille[6] == 'O'))
		victoire = true;
	//Victoirecolumne2:
	else if ((Grille[1] == 'X' && Grille[4] == 'X' && Grille[7] == 'X') || (Grille[1] == 'O' && Grille[4] == 'O' && Grille[7] == 'O'))
		victoire = true;
	//Victoirecolumne3:
	else if ((Grille[2] == 'X' && Grille[5] == 'X' && Grille[8] == 'X') || (Grille[2] == 'O' && Grille[5] == 'O' && Grille[8] == 'O'))
		victoire = true;
	//VictoireDiagonal1:
	else if ((Grille[0] == 'X' && Grille[4] == 'X' && Grille[8] == 'X') || (Grille[0] == 'O' && Grille[4] == 'O' && Grille[8] == 'O'))
		victoire = true;
	//VictoireDiagonal2:
	else if ((Grille[2] == 'X' && Grille[4] == 'X' && Grille[6] == 'X') || (Grille[2] == 'O' && Grille[4] == 'O' && Grille[6] == 'O'))
		victoire = true;

	return victoire;
}







int main() {
	//La fonction « main » dans laquelle il sera demandé au joueur de choisir une case.

	cout << "-----------------TIC TAC TOE------------------------" << endl;




	char Grille[9] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };
	AfficherGrille(Grille);
	int choix = 0;
	int coups = 0;

	int jouerEnCours = 1;
	while (!Victoire(Grille) && coups < 9) {

		if (jouerEnCours == 1) {
			cout << endl;
			cout << endl << "Jouer 1 (X), veiullez faire une choix de case" << endl;
			cin >> choix;
			Verifierchoix(choix,'X', Grille);

			jouerEnCours++;
		}

		else if (jouerEnCours == 2) {
			cout << endl;
			cout << endl << "Jouer 2 (O), veiullez faire une choix de case" << endl;
			cin >> choix;
			Verifierchoix(choix,'O', Grille);
			jouerEnCours--;
		}
		AfficherGrille(Grille);
		coups++;
	}

	if (Victoire(Grille) && (jouerEnCours == 2)) {

		AfficherGrille(Grille);
		cout << "Jouer 1 a gagne!" << endl;
	
	}
	else if (Victoire(Grille) && (jouerEnCours == 1)) {

		AfficherGrille(Grille);
		cout << "Jouer 2 a gagne!" << endl;
	
	}

	if (!Victoire(Grille) && coups == 9) {
		AfficherGrille(Grille);
		cout << "La partie est null" << endl;
	}

}





