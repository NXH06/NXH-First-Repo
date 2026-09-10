-- Chargement des donnees
import Text.Read (readMaybe)
import Text.Parsec.Token (GenTokenParser(identifier))

chargerWikipedia :: FilePath -> IO [(Int, String, String)]
chargerWikipedia chemin =
    do
        s <- readFile chemin
        let xs = splitOn '\n' s
        return $ map readArticle $ filter (not.null) xs
    where
        readArticle st = case splitOn '|' st of
            [s1,s2,s3] -> case readMaybe s1 of
                Just i -> (i, s2, s3)
                _ -> error "Le premier champ de chaque ligne doit être un entier."
            _ -> error "Chaque ligne doit contenir trois champs."
        splitOn _ [] = [[]]
        splitOn sep (x:xs) =
            let res@(r:rs) = splitOn sep xs
            in if x == sep then []:res else (x:r):rs

----
-- Debut du TP ci-dessous
----

-- Q1
titre :: (Int, String, String) -> String
titre (id, titre, corps) = titre

compterArticles :: [(Int, String, String)] -> Int
compterArticles [] = 0 -- fin de la liste
compterArticles (a:l) = compterArticles l + 1 -- comptage récursive

existeArticle :: Int -> [(Int, String, String)] -> Bool
existeArticle _ [] = False
existeArticle i ((ia,_,_):l)
    | i == ia = True
    | otherwise = existeArticle i l

{- Autre version:
existeArticle i ((ia,_,_):l) = i == ia || existeArticle i l
-}

prendre :: Int -> [(Int, String, String)] -> [(Int, String, String)]
prendre n l = prendreAux n l
    where
        prendreAux :: Int -> [(Int, String, String)] -> [(Int, String, String)]
        prendreAux _ [] = [] -- si la liste d'origine est vide
        prendreAux 0 _ = [] -- si on a obtenu la liste finale
        prendreAux n (a:ltail) = a:prendreAux (n - 1) ltail
        {- Ne prendre pas le contenu des articles afin de rendre le résultat plus lisible sur le terminal
        prendreAux n ((i,t,_):ltail) = (i,t,""):prendreAux (n - 1) ltail -}

-- Q2
longueurMoyenne :: [(Int, String, String)] -> Float
longueurMoyenne d = longueurMoyenneAuxTerm d 0 0
    where
        longueurMoyenneAuxTerm :: [(Int, String, String)] -> Int -> Int -> Float
        -- fromIntegral convertit Int -> Float, parce que la division n'accepte que des Floats
        longueurMoyenneAuxTerm [] n s = if n /= 0 then fromIntegral s / fromIntegral n else 0
        longueurMoyenneAuxTerm ((_,_,contenu):ltail) n s = longueurMoyenneAuxTerm ltail (n + 1) (s + length contenu)
