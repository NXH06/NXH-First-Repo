compterOcc :: Int -> [Int] -> Int
compterOcc _ [] = 0
compterOcc a (x:l)
    | a == x = 1 + acc
    | otherwise = acc
    where acc = compterOcc a l

eliminer :: Int -> [Int] -> [Int]
eliminer _ [] = []
eliminer a (x:xs)
-- plutôt qu'eliminer les occurences de "a", garder les élements qui ne sont pas "a"
    | a == x = lnew
    | otherwise = x:lnew
    where lnew = eliminer a xs

compter1 :: [Int] -> [(Int, Int)]
compter1 [] = []
compter1 (a:l) = (a,n):compter1 l'
    where
    -- ajouter la première occurence de chaque élément existant, compterOcc ne commence que compter à la deuxième
    n = compterOcc a l + 1
    l' = eliminer a l

comptElim :: Int -> [Int] -> (Int, [Int])
comptElim _ [] = (0, [])
comptElim a l = go 0 [] l
    where
    go :: Int -> [Int] -> [Int] -> (Int, [Int])
    go n acc [] = (n, acc)
    go n acc (x:xs)
        | a == x = go (n + 1) acc xs
        | otherwise = go n (acc ++ [x]) xs

{- Cool trick:
comptElim a [] = (0, [])
comptElim a (x:xs)
    | a == x = (1 + count, filtered)
    | otherwise = (count, x:filtered)
    where (count, filtered) = comptElim a xs
-}

compter2 :: [Int] -> [(Int, Int)]
compter2 [] = []
compter2 l = (n, a) : compter2 l'
    where
    a = head l
    (n, l') = comptElim a l

{- Complexité:
compter1: 2n(n-1)/2
compter2: n(n-1)/2
-}