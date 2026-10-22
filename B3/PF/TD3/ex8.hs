import Data.List (sort, insert)

data Freq a = F a Float deriving Show

voyellesF :: [Freq Char]
voyellesF = [F 'a' 17.5, F 'e' 42.2, F 'i' 14.3, F 'o' 10.4, F 'u' 14.7, F 'y' 0.8]

data ArbreH a =
    Noeud (ArbreH a) (ArbreH a)
    | Feuille a
    deriving Show

instance Eq (Freq a) where
    (==) :: Freq a -> Freq a -> Bool
    (F _ f1) == (F _ f2) = f1 == f2
instance Ord (Freq a) where
    compare :: Freq a -> Freq a -> Ordering
    compare (F _ f1) (F _ f2) = compare f1 f2

sortF :: [Freq a] -> [Freq a]
sortF = sort 
insertF :: Freq a -> [Freq a] -> [Freq a]
insertF = insert

initH :: [Freq a] -> [Freq (ArbreH a)]
initH = map (\ (F a freq) -> (F (Feuille a) freq))

etapeH :: Freq (ArbreH a) -> Freq (ArbreH a) -> [Freq (ArbreH a)] -> [Freq (ArbreH a)]
etapeH (F t1 f1) (F t2 f2) l = insert (F (Noeud t1 t2) (f1 + f2)) l

arbreH :: [Freq a] -> Maybe (ArbreH a)
arbreH [] = Nothing
arbreH l = Just (go (initH (sortF l)))
    where
        go :: [Freq (ArbreH a)] -> ArbreH a
        go [(F t _)] = t
        go (x1:x2:xs) = go (etapeH x1 x2 xs)
