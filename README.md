# LegoCar
Adaptive Cruise Control Lego Car
LegoCar - Andrei Vlad-Cristian 

DOCUMENTATIA NU ESTE IN FAZA FINALA - REZULTATUL FINAL POATE FI DIFERIT FATA DE DOCUMENTATIA ACTUALA

LegoCar este o masina din lego de dimensiune medie si greutate considerabila datorata constructiei solide si a motorului stepper 28-BYJ48. Masina este formata din 4 compartimente. 
	1. In spate, jos, este situat motorul stepper legat fix cu 2 soricei de sasiul masinii si conectat cu un ax care transmite puterea motorului sub capota. 
	2. In compartimentul de sub capota se afla un ax ce leaga cele doua roti motoare si preia puterea de la axul stepper-ului printr-un sistem de roti dintate, invartind rotile pentru a misca masina. Capota se poate deschide pentru a vizualiza sistemul de transmisie.
	3. In spate, deasupra motorului stepper, se afla placa Arduino fixata cu soricei de sasiul masinii si driverul ULN2003 folosit pentru a comanda motorul stepper. Atat placa Arduino cat si driverul ULN2003 sunt alimentate independent la cate o baterie de 9V. In acest compartiment exista gauri prin care firele pot iesi organizat pentru a ajunge la componentele cu care trebuie sa comunice.
	4. Deasupra compartimentului 3 se afla o capota cu 2 balamale pentru a putea accesa placa si driverul. Pe aceasta placa se afla un ecran LCD si un senzor ultra sonic pentru masurarea distantei. In timpul folosirii capota trebuie sa fie inchisa, altfel masina cel mai probabil nu se va misca.
	
Modul de functionare
LegoCar foloseste tehnologia utilizata de producatorii de masini pentru mentinerea unei distante sigure fata de vehiculele din fata numita Adapative Cruise Control (ACC). Cu ajutorul senzorului ultra sonic, LegoCar masoara periodic distanta in fata, iar atunci cand se apropie periculos de un obiect incetineste sau chiar opreste daca situatia impune. De asemenea LCD-ul afiseaza constant informatii despre distanta fata de obstacolele din fata si anunta atunci cand masina detecteaza un pericol.
	
