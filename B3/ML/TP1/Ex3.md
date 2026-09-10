- La fabrication est toujours la plus optimale quand le nombre d'heures ouvrées est maximum
- Le modèle va priotiser les produits dont le profit est le plus élevé
- maximize tonnage : sum {p in PROD} qte_produite [p] (...);
- param pourcentage_min := (...);
qte_produite {p in PROD} >= (sum {p in PROD} qte_produite [p]) * pourcentage_min;