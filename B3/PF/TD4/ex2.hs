import Data.List (sortOn)

l :: [(String, [Float])]
l = [
    ("a", [10,0]),
    ("b", [20,10]),
    ("c", [5,15])
    ]

moyenneCoef :: Fractional a => [a] -> a -> [a] -> a
-- moyenneCoef [] t n = -1 
moyenneCoef _ _ [] = -1
moyenneCoef c t n = sum (zipWith (*) c n) / t

moyennesEtudiants :: Fractional a => [a] -> [(String, [a])] -> [(String, a)]
moyennesEtudiants c l = map (\ (nom, notes) -> (nom, moyenneCoef c t notes)) l
    where t = sum c

-- sortOn :: Ord b => (a -> b) -> [a] -> [a]

classementMoyenne :: Ord a => [(String, a)] -> [(String, a)]
classementMoyenne l = sortOn (\ (nom, moyenne) -> moyenne) l

classementNotes :: (Fractional a, Ord a) => [a] -> [(String, [a])] -> [(String, a)]
classementNotes c l = classementMoyenne (moyennesEtudiants c l)

groupeMoyennes :: Ord a => [(String, a)] -> a -> a -> [String]
groupeMoyennes [] _ _ = []
groupeMoyennes ((nom, moyenne):xs) n1 n2
    | (n1 <= moyenne && moyenne <= n2) || (n1 >= moyenne && moyenne >= n2) = nom : reste
    | otherwise = reste
    where reste = groupeMoyennes xs n1 n2

groupeNotes :: (Fractional a, Ord a) => [a] -> [(String, [a])] -> a -> a -> [String]
groupeNotes c l n1 n2 = groupeMoyennes (classementNotes c l) n1 n2
