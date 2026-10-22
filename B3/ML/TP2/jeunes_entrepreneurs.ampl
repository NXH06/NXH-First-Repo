set MARCHANDISE;
param somme_poids_max >= 0;
param somme_volume_max >= 0; # mésurée en centimètres cubes
param valeur {MARCHANDISE} >= 0;
param poids {MARCHANDISE} >= 0;
param volume {MARCHANDISE} >= 0;
param dispo {MARCHANDISE} >= 0;

var nombre {p in MARCHANDISE} integer <= dispo[p], >= 0;

maximize somme_valeur: sum {p in MARCHANDISE} nombre[p] * valeur[p];

subject to limite_poids: sum {p in MARCHANDISE} nombre[p] * poids[p] <= somme_poids_max;
subject to limite_volume: sum {p in MARCHANDISE} nombre[p] * volume[p] <= somme_volume_max;

data;
param somme_poids_max := 30;
param somme_volume_max := 200000; # soit 0.2 * 10^6
param: MARCHANDISE: valeur poids volume dispo :=
    telephone 20 0.2 125 20
    lecteur_dvd 35 1 15000 15
    montre 10 0.3 50 50;

option solver gurobi; # pour que le solver n'ignore pas l'intégralité de la variable "nombre"
