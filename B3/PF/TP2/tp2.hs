import Text.Read (readMaybe)

-- Type Album
data Album = Album
    { titre   :: String
    , artiste :: String
    , label   :: String
    , annee   :: Int
    , genre   :: String
    }
    deriving Show

-- Chargement des donnees
chargerDiscogs :: FilePath -> IO [Album]
chargerDiscogs chemin =
    do
        s <- readFile chemin
        let xs = splitOn '\n' s
        return $ map readAlbum $ filter (not.null) xs
    where
        readAlbum st = case splitOn '|' st of
                [s1,s2,s3,s4,s5] -> case readMaybe s4 of
                        Just i -> Album s1 s2 s3 i s5
                        _ -> error "Le quatrième champ de chaque ligne doit être un entier."
                _ -> error "Chaque ligne doit contenir cinq champs."
        splitOn _ [] = [[]]
        splitOn sep (x:xs) =
                let res@(r:rs) = splitOn sep xs
                in if x == sep then []:res else (x:r):rs

----
-- Debut du TP ci-dessous
----

-- Ex 1
prendre :: Int -> [Album] -> [Album]
prendre 0 _ = []
prendre n (x:xs) = x : prendre (n - 1) xs

formaterAlbum :: Album -> String
formaterAlbum alb = titre alb ++ ", par " ++ artiste alb

formaterAlbum' :: Album -> String
formaterAlbum' (Album {titre=t,artiste=a}) = t ++ ", par " ++ a

formaterListe :: [Album] -> [String]
formaterListe [] = []
formaterListe (x:xs) = formaterAlbum x : formaterListe xs

formaterCollection :: [Album] -> String
formaterCollection [] = []
formaterCollection l = go (formaterListe l)
    where
        go [] = []
        go (x:xs) = x ++ "\n" ++ go xs

-- Ex 2
titreExiste :: String -> [Album] -> Bool
titreExiste t [] = False
titreExiste t (x:xs)
    | t == titre x = True
    | otherwise = titreExiste t xs

data Resultat = Trouve Album | NonTrouve deriving Show
chercherTitre :: String -> [Album] -> Resultat
chercherTitre _ [] = NonTrouve
chercherTitre t (x:xs)
    | t == titre x = Trouve x
    | otherwise = chercherTitre t xs

chercherGenre :: String -> [Album] -> [Album]
chercherGenre _ [] = []
chercherGenre g (x:xs)
    | g == genre x = x : chercherGenre g xs
    | otherwise = chercherGenre g xs

-- Ex 3
data Couleur = Rouge | Noir
data ABR = Noeud Couleur Album ABR ABR | ArbreVide

comparerAlbums :: Album -> Album -> Ordering
comparerAlbums a b
    | ta < tb = LT
    | ta > tb = GT
    | otherwise = EQ
    where
        ta = titre a
        tb = titre b


----
-- Début de TP4
----

prendre4 :: Int -> [Album] -> [Album]
prendre4 n l = if n > length l then l else take n l 

formaterCollection4 :: [Album] -> String
formaterCollection4 l = concatMap (\ s -> s ++ "\n") (map formaterAlbum l)

titreExiste4 :: String -> [Album] -> Bool
titreExiste4 t = any (\ a -> titre a == t)

chercherTitre4 :: String -> [Album] -> Resultat
chercherTitre4 t l = if null res then NonTrouve else Trouve (res !! 0) where res = filter (\ a -> titre a == t) l

chercherGenre4 :: String -> [Album] -> [Album]
chercherGenre4 _ [] = []
chercherGenre4 g (x:xs)
    | g == genre x = x : chercherGenre4 g xs
    | otherwise = chercherGenre4 g xs