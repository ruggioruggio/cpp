//scritto il 15 ottobre 2026, ho iniziato cpp a scuola circa 3 settimane fa

#include <iostream>
#include <random>
#include <ctime>
#include <cstdlib>
#include <string>

using namespace std;

int main () {
	srand(time(NULL));
	
	int sceltaClasseEroe;
	int puntiAttaccoEroe;
	int sceltaAttaccoEroe;
	int puntiDifesaEroe;
	int hpMostro;
	int dannoEroe;
	int hpGiocatore;
	int puntiAttaccoMostro;
	int puntiDifesaMostro;
	int mossaMostro;
	int dannoMostro;
	int numeroTurno;
	int sceltaAzione;
	string elementoArmaEroe;
	bool isCritico;
	bool scudoMostro;
	
	hpMostro = 200;
	puntiAttaccoMostro = 35;
	hpGiocatore = 100;
	puntiDifesaMostro = 16;
	sceltaAzione = 1;
	numeroTurno = 0;
	
	cout << "scegli la tua classe: digita 1 per mago, digita 2 per elfo o digita 3 per Ninfea" << endl;
	cin >> sceltaClasseEroe;
	
	while (sceltaClasseEroe != 1 && sceltaClasseEroe != 2 && sceltaClasseEroe != 3) {
		cout << "scegli la tua classe: digita 1 per mago, digita 2 per elfo o digita 3 per Ninfea" << endl;
		cin >> sceltaClasseEroe;
	}
	
	if (sceltaClasseEroe == 1) {
		puntiAttaccoEroe = 50;
		puntiDifesaEroe = 10;
		elementoArmaEroe = "Fuoco";
	} else if (sceltaClasseEroe == 2) {
		puntiAttaccoEroe = 40;
		puntiDifesaEroe = 15;
		elementoArmaEroe = "Elettro";
	} else {
		puntiAttaccoEroe = 30;
		puntiDifesaEroe = 25;
		elementoArmaEroe = "Acqua";
	}
	
	while (sceltaAzione == 1 || sceltaAzione == 2) {
		while (hpGiocatore > 0 && hpMostro > 0) {
			numeroTurno = numeroTurno + 1;
			cout << "Scegli la modalità d'attacco: digita 1 per attacco alto, digita 2 per attacco frontale o digita 3 per attacco basso" << endl;
			cin >> sceltaAttaccoEroe;
			
			while (sceltaAttaccoEroe != 1 && sceltaAttaccoEroe != 2 && sceltaAttaccoEroe != 3) {
				cout << "Scegli la modalità d'attacco: digita 1 per attacco alto, digita 2 per attacco frontale o digita 3 per attacco basso" << endl;
				cin >> sceltaAttaccoEroe;
			}
			
			if (sceltaAttaccoEroe == 1) {
				if (rand() % 100 < 20) {
					dannoEroe = 0;
					cout << "COLPO MISSATO" << endl;
				} else {
					dannoEroe = puntiAttaccoEroe - 15 + 10;
				}
			} 
			else if (sceltaAttaccoEroe == 2) {
				dannoEroe = puntiAttaccoEroe - 15;
			} 
			else {
				dannoEroe = puntiAttaccoEroe - 5;
			}

			if (rand() % 100 < 20) {
				isCritico = true; 
				dannoEroe = dannoEroe * 2;
				cout << "COLPO CRITICO" << endl;
			}
			
			hpMostro = hpMostro - dannoEroe;
			cout << "Danno inflitto al Mostro: " << dannoEroe << endl;
			cout << "HP del Mostro rimanenti: " << hpMostro << endl;                                 
			
			if (hpMostro > 0) {
				mossaMostro = rand() % 3;
				if (mossaMostro == 0) {
					dannoMostro = puntiAttaccoMostro - puntiDifesaEroe + rand() % 5;
					cout << "il mostro ha attaccato causandoti " << dannoMostro << " di danno!" << endl;
				} else if (mossaMostro == 1) {
					if (rand() % 100 < 30) {
						dannoMostro = 0;
						cout << "il mostro ha missato l'attacco!" << endl;
					} else {
						dannoMostro = (puntiAttaccoMostro * 1.3) - puntiDifesaEroe;
						cout << "il mostro ha attaccato causandoti " << dannoMostro << " di danno!" << endl;
					} 
				} else {
					dannoMostro = 0;
					scudoMostro = true;
					hpMostro = hpMostro + 15;
					cout << "Il mostro non ha attaccato, ma ha attivato lo scudo e rigenerato 15 di HP" << endl;
				}
			}
			
			hpGiocatore = hpGiocatore - dannoMostro;
			
			if (hpGiocatore <= 0) {
				if (hpMostro <= 0) {
					cout << "sembra che entrambi siate morti!";
					return 1;
				} else {
					cout << "sei morto... il mostro è sopravvissuto con " << hpMostro << " di salute" << endl;
					return 1;
				}
			} else {
				if (hpMostro <= 0) {
					cout << "HAI BATTUTO IL MOSTRO sopravvivendo con " << hpGiocatore << " di salute" << endl;
					return 1;
				} else {
					cout << "la tua salute è: " << hpGiocatore << endl;
				}
			}
			
			cout << "numero di turni: " << numeroTurno << endl;
			cout << "digita 1 per attaccare o digita 2 per usare la pozione di cura, saltando il turno" << endl;
			cin >> sceltaAzione;
			
			while (sceltaAzione != 1 && sceltaAzione != 2) {
				cout << "digita 1 per attaccare o digita 2 per usare la pozione di cura, saltando il turno" << endl;
				cin >> sceltaAzione;
			}
			
			if (sceltaAzione == 1) {
			} else {
				hpGiocatore = hpGiocatore + 30;
				if (hpGiocatore > 100) {
					hpGiocatore = 100;
				}
				if (hpMostro > 0) {
					mossaMostro = rand() % 3;
					if (mossaMostro == 0) {
						dannoMostro = puntiAttaccoMostro - puntiDifesaEroe + rand() % 5;
						cout << "il mostro ha attaccato causandoti " << dannoMostro << " di danno!" << endl;
					} else if (mossaMostro == 1) {
						if (rand() % 100 < 30) {
							dannoMostro = 0;
							cout << "il mostro ha missato l'attacco!" << endl;
						} else {
							dannoMostro = (puntiAttaccoMostro * 1.3) - puntiDifesaEroe;
							cout << "il mostro ha attaccato causandoti " << dannoMostro << " di danno!" << endl;
						}
					} else {
						dannoMostro = 0;
						scudoMostro = true;
						hpMostro = hpMostro + 15;
						cout << "Il mostro non ha attaccato, ma ha attivato lo scudo e rigenerato 15 di HP" << endl;
					}
				} 
				hpGiocatore = hpGiocatore - dannoMostro;
				cout << "la tua salute è: " << hpGiocatore << endl;
			}
		}
	}
	return 0;
}
