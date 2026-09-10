monExp1 :: Int -> Int -> Int
monExp1 a 0 = 1
monExp1 a n = a * monExp1 a (n - 1)
{- Forme équivalente utilisant "case":
monExp1 a n = case n of
    0 -> 1
    n -> a * monExp1 a (n - 1) -}

monExp2 :: Int -> Int -> Int
monExp2 a n = expAux n 1 where
    -- "a" ne change jamais, donc pas besoin de le mettre dans la fonction auxiliare
    expAux :: Int -> Int -> Int
    expAux n acc
        | n == 0 = acc
        | otherwise = expAux (n - 1) (a * acc)

monExp3 :: Int -> Int -> Int
monExp3 _ 0 = 1
monExp3 a n
    | r == 0 = e * e
    | otherwise = a * e * e
    where
        (q,r) = quotRem n 2
        e = monExp3 a q
{- Forme utilisant "quot" à la place de "quotRem":
monExp3 _ 0 = 1
monExp3 a n
    | even n = monExp3 a (n `quot` 2) ^ 2
    | odd n = a * monExp3 a (n `quot` 2) ^ 2 -}

monExp4 :: Int -> Int -> Int
monExp4 a n
    | n == 0 = 1
    | otherwise = multiplierListe (creerListe a n)
    where
        creerListe :: Int -> Int -> [Int]
        creerListe _ 0 = []
        creerListe a n = a:creerListe a (n - 1)

        multiplierListe :: [Int] -> Int
        multiplierListe [] = 1
        -- pas besoin de (x:ltail), [] dans le ligne précédent corresponde déjà au liste vide
        multiplierListe l = multListeAux l 1
            where
                multListeAux [] acc = acc
                multListeAux (x:ltail) acc = multListeAux ltail (x * acc)

