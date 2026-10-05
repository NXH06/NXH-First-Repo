data ArbreBin = Noeud Int ArbreBin ArbreBin | ArbreVide deriving Show

a :: ArbreBin
a = Noeud 3 (Noeud 7 ArbreVide ArbreVide) (Noeud 1 ArbreVide ArbreVide)
b :: ArbreBin
b = Noeud 2 (Noeud 3 (Noeud (-1) ArbreVide ArbreVide) (Noeud 1 ArbreVide ArbreVide)) (Noeud (-2) ArbreVide (Noeud 4 ArbreVide ArbreVide))

existe :: ArbreBin -> Int -> Bool
existe ArbreVide _ = False
-- ag/ad: arbre gauche/droite
existe (Noeud v ag ad) v'
    | v == v' = True
    | otherwise = existe ag v' || existe ad v'

sommePos :: ArbreBin -> Int
sommePos ArbreVide = 0
sommePos (Noeud v ag ad)
    | v > 0 = v + sommeRecur
    | otherwise = sommeRecur
    where sommeRecur = sommePos ag + sommePos ad

ajouter :: Int -> ArbreBin -> ArbreBin
ajouter _ ArbreVide = ArbreVide
ajouter v' (Noeud v ag ad) = Noeud (v + v') (ajouter v' ag) (ajouter v' ad)