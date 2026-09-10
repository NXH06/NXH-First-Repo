compterOcc :: Int -> [Int] -> Int
compterOcc _ [] = 0
compterOcc a (x:l)
    | a == x = 1 + acc
    | otherwise = acc
    where acc = compterOcc a l

eliminer :: Int -> [Int] -> [Int]
eliminer _ [] = []
eliminer a (x:ltail)
-- plutôt qu'eliminer les occurences de "a", garder les élements qui ne sont pas "a"
    | a == x = lnew
    | otherwise = x:lnew
    where lnew = eliminer a ltail

compter :: [Int] -> [(Int, Int)]
compter [] = []
compter (a:l) = (a,n):compter l'
    where
        -- ajouter la première occurence de chaque élément existant, compterOcc ne commence que compter à la deuxième
        n = compterOcc a l + 1
        l' = eliminer a l
