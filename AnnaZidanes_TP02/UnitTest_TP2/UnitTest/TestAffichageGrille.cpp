#include "pch.h"
#include "CppUnitTest.h"
#include "../../AnnaZidanes_TP02/AnnaZidanes_TP02.cpp"
#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;


/*
Voici le document pour les tests unitaires de votre TP2
Vous devez avoir l'ensemble des tests au vert pour votre projet
exemple, si vous n'avez pas de parametre sur votre fonction Grille()
tous les tests GrilleSansParam doivent etre au vert

Pour les tests de victoires, ceux-ci sont effectué avec des lettres minuscules
si voux avez utilisé une autre type de données, vous pouvez la modifier.


Pour les tests, l'important est qu'ils soit au vert. Si vous avez besoin d'aide pour les
ajuster a votre solution, contacter moi et nous les écrirons ensemble.
*/



namespace UnitTest
{
	TEST_CLASS(TestAffichageGrille)
	{
	public:

		TEST_METHOD(TestGrilleAvecParam)
		{
			//Mettre ici le resultat de votre grille sous format texte
			// l'exemple ici donne une grille de format
			/*  -----------
				1 | 2 | 3 |
				-----------
				4 | 5 | 6 |
				-----------
				7 | 8 | 9 |
				-----------
			*/

			//Si vous voulez avoir un affichage different, vous devez changer la chaine de charactere ici pour etre la meme que le votre
			string grilleTEST = "\n-----------\n1 | 2 | 3 | \n-----------\n4 | 5 | 6 | \n-----------\n7 | 8 | 9 | \n-----------\n";

			//La grille utilise pour le test, changer si differente de la votre
			char grille[10] = "123456789";

			ostringstream oss;
			streambuf* p_cout_streambuf = std::cout.rdbuf();
			cout.rdbuf(oss.rdbuf());


			//Fonction qui imprime la grille
			AfficherGrille(grille);

			cout.rdbuf(p_cout_streambuf);
			string sortie = oss.str();
			Assert::AreEqual(grilleTEST, sortie);
			cout << oss.str();
		}
		TEST_METHOD(TestGrilleAvecParamMAJ)
		{
			//Mettre ici le resultat de votre grille sous format texte
			// l'exemple ici donne une grille de format
			/*  -----------
				1 | 2 | 3 |
				-----------
				4 | 5 | 6 |
				-----------
				7 | 8 | 9 |
				-----------
			*/

			//Si vous voulez avoir un affichage different, vous devez changer la chaine de charactere ici pour etre la meme que le votre
			string grilleTEST = "\n-----------\n1 | 2 | X | \n-----------\n4 | O | 6 | \n-----------\n7 | 8 | 9 | \n-----------\n";

			//La grille utilise pour le test, changer si differente de la votre
			char grille[10] = "12X4O6789";

			ostringstream oss;
			streambuf* p_cout_streambuf = std::cout.rdbuf();
			cout.rdbuf(oss.rdbuf());


			//Fonction qui imprime la grille
			AfficherGrille(grille);

			cout.rdbuf(p_cout_streambuf);
			string sortie = oss.str();
			Assert::AreEqual(grilleTEST, sortie);
			cout << oss.str();
		}

		
		TEST_METHOD(TestVictoirePasDeVictoire) {
			char grilleTEST[10] = "123456789";
			bool vic = Victoire(grilleTEST);
			Assert::AreEqual(false, vic);
		}

		TEST_METHOD(TestVictoireNULL) {
			char grilleTEST[10] = "XOXOXOOXO";
			bool vic = Victoire(grilleTEST);
			Assert::AreEqual(false, vic);
		}

		TEST_METHOD(TestVictoireLigne1) {
			char grilleTEST[10] = "XXX456789";
			bool vic = Victoire(grilleTEST);
			Assert::AreEqual(true, vic);
		}
		TEST_METHOD(TestVictoireLigne2) {
			char grilleTEST[10] = "123OOO789";
			bool vic = Victoire(grilleTEST);
			Assert::AreEqual(true, vic);
		}
		TEST_METHOD(TestVictoireLigne3) {
			char grilleTEST[10] = "123456XXX";
			bool vic = Victoire(grilleTEST);
			Assert::AreEqual(true, vic);
		}

		TEST_METHOD(TestVictoireDiagonal1) {
			char grilleTEST[10] = "X234X678X";
			bool vic = Victoire(grilleTEST);
			Assert::AreEqual(true, vic);
		}
		TEST_METHOD(TestVictoireDiagonal2) {
			char grilleTEST[10] = "12O4O6O89";
			bool vic = Victoire(grilleTEST);
			Assert::AreEqual(true, vic);
		}

		TEST_METHOD(TestVictoireColonne1) {
			char grilleTEST[10] = "X2OXX6X89";
			bool vic = Victoire(grilleTEST);
			Assert::AreEqual(true, vic);
		}

		TEST_METHOD(TestVictoireColonne2) {
			char grilleTEST[10] = "X2OX56X89";
			bool vic = Victoire(grilleTEST);
			Assert::AreEqual(true, vic);
		}

		TEST_METHOD(TestVictoireColonne3) {
			char grilleTEST[10] = "12X45X78X";
			bool vic = Victoire(grilleTEST);
			Assert::AreEqual(true, vic);
		}
	};
}
