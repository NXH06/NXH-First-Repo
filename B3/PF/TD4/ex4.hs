a = [[1,2], [1,2]]
b = [[1,2,3],[1,2,3],[1,2,3]]

idMat :: Num a => Int -> [[a]]
idMat n = map ligne [1..n]
    where ligne i = replicate (i - 1) 0 ++ [1] ++ replicate (n - i) 0

(<.>) :: Num a => [a] -> [a] -> a
[] <.> [] = 0
u <.> v = sum (zipWith (*) u v)

transpose :: Num a => [[a]] -> [[a]]
transpose [] = repeat []
transpose (l:ls) = zipWith (:) l (transpose ls)
{-- "repeat []" autorise éventuellement "a:[]" quand on commence à transposer la dernière ligne de la matrice --}

(|*|) :: Num a => [[a]] -> [[a]] -> [[a]]
[] |*| _ = []
_ |*| [] = []
m |*| n = map (\ l -> map (l <.>) (transpose n)) m
{-- (l <.>): forme eta-réduite de (\ c -> l <.> c) --}