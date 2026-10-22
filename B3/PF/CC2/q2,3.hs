data ArbreB a = Feuille a | Noeud a (ArbreB a) (ArbreB a) deriving Show
monArbreB :: ArbreB Int
monArbreB = Noeud 5 (Noeud 0 (Feuille 3) (Feuille 17)) (Feuille (-2))

ouvre :: Show a => a -> String
ouvre x = "<" ++ show x ++ ">\n"

ferme :: Show a => a -> String
ferme x = "</" ++ show x ++ ">\n"

indentation :: Int -> String
indentation n = replicate (4 * n) ' '

chaineAuxB :: (Show a) => Int -> ArbreB a -> String
chaineAuxB p (Feuille x) = indentation p ++ ouvre x
chaineAuxB p (Noeud x gauche droite) =
    indentation p ++ ouvre x 
    ++ chaineAuxB (p+1) gauche ++ chaineAuxB (p+1) droite
    ++ indentation p ++ ferme x

chaineB :: Show a => ArbreB a -> String
chaineB ar = chaineAuxB 0 ar

data Arbre a = F a | N a [Arbre a]

monArbre :: Arbre String
monArbre = N "Placard" [N "Tiroir" [F "Fourchettes", F "Cuilleres", F "Couteaux"],
    N "Tiroir" [],
    N "Tiroir" [N "Boîte" [F "Cumin", F "Timut", F "Kankankan"]]]

chaineAux :: (Show a) => Int -> Arbre a -> String
chaineAux p (F x) = indentation p ++ ouvre x
chaineAux p (N x l) = indentation p ++ ouvre x ++ concatMap (chaineAux (p + 1)) l ++ indentation p ++ ferme x

chaine :: Show a => Arbre a -> String
chaine ar = chaineAux 0 ar