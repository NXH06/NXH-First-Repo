set PROD;
param budget >= 0;
param temps_prod_dispo >= 0;
param audience_touchee {PROD} >= 0;
param coute {PROD} >= 0;
param duree_minimum {PROD} >= 0; # mésurée en minutes en cas de "tv" et "radio", pages en cas de "magazine"
param temps_prod {PROD} >= 0; # mésurée en jours

var duree {p in PROD} >= duree_minimum[p];

maximize somme_audience_touchee: sum {p in PROD} duree[p] * audience_touchee[p];

subject to limite_budget: sum {p in PROD} duree[p] * coute[p] <= budget;
subject to limite_temps_prod: sum {p in PROD} duree[p] * temps_prod[p] <= temps_prod_dispo;

data;
param budget := 1000000;
param temps_prod_dispo := 700;
param: PROD: audience_touchee coute duree_minimum temps_prod :=
    tv 1800000 20000 10 7
    magazine 1000000 10000 2 21
    radio 250000 2000 120 1;
