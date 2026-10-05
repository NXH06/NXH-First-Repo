data Dictionnaire = N (Int, Int) Dictionnaire Dictionnaire | V deriving Show

a :: Dictionnaire
a = N (5, 5) (N (3, 3) (N (1, 1) V V) (N (4, 4) V V)) (N (7, 7) V V)

-- Implementation avec les valeurs pré-definies
comparer :: Int -> Int -> Ordering
comparer n m
    | n < m = LT
    | n > m = GT
    | otherwise = EQ
decompte :: Dictionnaire -> Int -> Int
decompte V _ = 0
decompte (N (c, v) ag ad) n =
    case comparer n c of
        LT -> decompte ag n
        GT -> decompte ad n
        EQ -> v

{- Version normal
decompte V _ = 0
decompte (N (c, v) ag ad) n
    | n > c = decompte ad n
    | n < c = decompte ag n
    | otherwise = v -- n == c
-}

incrementer :: Dictionnaire -> Int -> Dictionnaire
incrementer V n = N (n, 1) V V
incrementer (N (c, v) ag ad) n
    | n < c = N (c, v) (incrementer ag n) ad
    | n > c = N (c, v) ag (incrementer ad n)
    | otherwise = N (c, v + 1) ag ad

compte :: [Int] -> [(Int, Int)]
compte [] = []
compte l = decompteTout (incrementerRecur V l)
    where
    incrementerRecur acc [] = acc
    incrementerRecur acc (x:xs) = incrementerRecur (incrementer acc x) xs
    decompteTout V = []
    decompteTout (N n ag ad) = decompteTout ag ++ (n : decompteTout ad)

{- Complexité de la fonction compte: (meilleur | pire cas)
incrementerRecur: n | sqrt(n)
decompteTout: 1 | n
--> compte: n | n^(3/2) -}
