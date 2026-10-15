import Data.List (find)
import Data.List (sortOn)

type Cellule = String
type Ligne = [Cellule]
type CSV = [Ligne]

csv1 :: CSV
csv1 = [["a","b","c"], ["b","a","c"], ["a","a","b"]]
csv2 :: CSV
csv2 = [["a","d"], ["a","b"]]
csv3 :: CSV
csv3 = [["a","b","c"], ["b","a","c"], ["a","a","b"], ["c","a","b"]]

decoupe :: Eq a => a -> [a] -> [[a]]
decoupe _ [] = [[]]
-- Quand un séparateur est rencontré, ajoute une liste vide en tête de la liste primaire, puis ajoute les éléments devant le sep à cette nouvelle liste
decoupe sep (x:xs)
    | x == sep  = [] : decoupe sep xs
    | otherwise = case decoupe sep xs of
        (g:gs) -> (x:g):gs

csv :: String -> CSV
csv "" = [[]]
csv s = map (decoupe ',') (decoupe '\n' s)
{-- Il faut utiliser '' au lieu de "" pour entrer ',' et '\n' comme type Char et pas String --}

(!?) :: [a] -> Int -> Maybe a
l !? n = case find (\ (_,i) -> i == n) (zip l [0..]) of
    Just (a,_) -> Just a
    Nothing -> Nothing

{-- Solution utilisant (!!):
l !? n
    | n >= 0 && n < length l = Just (l !! n)
    | otherwise = Nothing
--}

jointureLigne :: Int -> Int -> Ligne -> CSV -> CSV
jointureLigne c1 c2 l csv2 = map (l ++) (filter (\ l2 -> l !? c1 == l2 !? c2) csv2)

jointure :: Int -> Int -> CSV -> CSV -> CSV
jointure c1 c2 csv1 csv2 = concatMap (\ l1 -> jointureLigne c1 c2 l1 csv2) csv1

trierCSV :: Int -> CSV -> CSV
trierCSV n csv = sortOn (!? n) csv

avance :: Int -> Int -> Ligne -> CSV -> (CSV, CSV)
avance _ _ _ [] = ([],[])
avance c1 c2 l csvt2 = (takeWhile (\ l2 -> l2 !? c2 == l !? c1) csvt2', csvt2')
    where csvt2' = dropWhile (\ l2 -> l2 !? c2 < l !? c1) csvt2

jointureT :: Int -> Int -> CSV -> CSV -> CSV
jointureT c1 c2 csv1 csv2 = go (trierCSV c1 csv1) (trierCSV c2 csv2)
    where
        go :: CSV -> CSV -> CSV
        go [] _ = []
        go (l1:ls1) csvt2 =
            let (csvt2l, csvt2') = avance c1 c2 l1 csvt2
            in map (l1 ++) csvt2l ++ go ls1 csvt2'
