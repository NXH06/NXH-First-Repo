data ABR a =
    N a (ABR a) (ABR a)
    | V deriving (Show, Eq)

-- arbres prototypes
ap1 :: ABR Int
ap1 = N 5 (N 3 (N 1 V V) (N 4 V V)) (N 7 V V) -- ordonnée
ap2 :: ABR Int
ap2 = N 5 (N 3 (N 1 V V) (N 4 V V)) (N 0 V V) -- non-ordonnée

inserer :: Ord a => a -> ABR a -> ABR a
inserer a' V = N a' V V
inserer a' r@(N a g d) = case compare a' a of
    LT -> N a (inserer a' g) d
    GT -> N a g (inserer a' d)
    EQ -> r

abrToList :: ABR a -> [a]
abrToList V = []
abrToList (N a g d) = abrToList g ++ (a : abrToList d)

estOrdonnee :: Ord a => [a] -> Bool
estOrdonnee [] = True
estOrdonnee [x] = True
estOrdonnee (x1:xs@(x2:_)) = x1 <= x2 && estOrdonnee xs

estABR :: Ord a => ABR a -> Bool
estABR a = estOrdonnee (abrToList a)

type Dict a b = ABR (a, b)

ap3 :: ABR (Int, Int)
ap3 = N (5, 5) (N (3, 3) (N (1, 1) V V) (N (4, 4) V V)) (N (7, 7) V V)

insererDict :: (Ord a, Num b) => (a, b) -> Dict a b -> Dict a b -- ajoute les valeurs si le couple existe déjà dans l'arbre
insererDict cv V = N cv V V
insererDict a'@(c', v') (N a@(c, v) g d) = case compare c' c of
    LT -> N a (insererDict a' g) d
    GT -> N a g (insererDict a' d)
    EQ -> N (c, v + v') g d

assoc :: Ord a => a -> Dict a b -> Maybe b
assoc _ V = Nothing
assoc c' (N a@(c, v) g d) = case compare c' c of
    LT -> assoc c' g
    GT -> assoc c' d
    EQ -> Just v

newtype CV a b = CV (a, b) deriving Show

instance Eq a => Eq (CV a b) where
    (==) :: Eq a => CV a b -> CV a b -> Bool
    (==) (CV (a1, _)) (CV (a2, _)) = a1 == a2
instance Ord a => Ord (CV a b) where
    compare :: Ord a => CV a b -> CV a b -> Ordering
    compare (CV (a1, _)) (CV (a2, _)) = compare a1 a2

-- type Dict' a b = ABR (CV a b)

ap4 :: ABR Int
ap4 = N 2 (N 1 (N 0 V V) V) V

hauteurEtEquilibre :: ABR a -> (Bool, Int) -- l'équilibrage de l'arbre et son hauteur maximum
hauteurEtEquilibre V = (True, 0)
hauteurEtEquilibre (N _ g d) =
    let
        (eg, hg) = hauteurEtEquilibre g
        (ed, hd) = hauteurEtEquilibre d
    in
        (eg && ed && abs (hg - hd) <= 1, 1 + max hg hd)

data AbrE a b = 
    NE a b (AbrE a b) (AbrE a b)
    | VE
    deriving (Show, Eq)
data Balance = Gauche | Droite | Centre deriving (Show, Eq)
type AVL a = AbrE a Balance

ap5 :: AVL Int
ap5 = NE 1 Centre (NE 2 Gauche (NE 3 Centre VE VE) VE) (NE 4 Droite VE (NE 5 Centre VE VE))

