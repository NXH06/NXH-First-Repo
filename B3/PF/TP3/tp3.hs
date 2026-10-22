{-# LANGUAGE MultiParamTypeClasses,FlexibleInstances,FunctionalDependencies #-}

-- data
data Album = Album
    { albumTitre :: String
    , albumArtiste :: String
    , albumLabel :: String
    , albumAnnee :: Int
    , albumGenre :: String
    }
    deriving Show

data Article = Article
    { articleId :: Int
    , articleTitre :: String
    , articleContenu :: String
    }
    deriving Show

-- Chargement des donnees
splitOn :: Eq a => a -> [a] -> [[a]]
splitOn _ [] = [[]]
splitOn sep (x:xs) =
    let res@(r:rs) = splitOn sep xs
    in if x == sep then []:res else (x:r):rs

chargerDiscogs :: FilePath -> IO [Album]
chargerDiscogs chemin =
    do
        s <- readFile chemin
        let xs = splitOn '\n' s
        return $ map readAlbum $ filter (not.null) xs
    where
        readAlbum st =
                let [s1,s2,s3,s4,s5] = splitOn '|' st
                in Album s1 s2 s3 (read s4 :: Int) s5

chargerWikipedia :: FilePath -> IO [Article]
chargerWikipedia chemin =
    do
        s <- readFile chemin
        let xs = splitOn '\n' s
        return $ map readArticle $ filter (not.null) xs
    where
        readArticle st =
                let [s1,s2,s3] = splitOn '|' st
                in Article (read s1 :: Int) s2 s3
        splitOn _ [] = [[]]
        splitOn sep (x:xs) =
                let res@(r:rs) = splitOn sep xs
                in if x == sep then []:res else (x:r):rs

----
-- Debut du TP ci-dessous
----

{-
dw <- chargerWikipedia "../TP1/wikipedia.dat"
dd <- chargerDiscogs "../TP2/discogs.dat"
-}

prendre :: Int -> [a] -> [a]
prendre _ [] = []
prendre 0 _ = []
prendre n (x:xs) = x : prendre (n - 1) xs

existe :: Eq a => a -> [a] -> Bool
existe _ [] = False
existe e (x:xs) = e == x || existe e xs

rechercher :: Eq a => a -> [a] -> Maybe a
rechercher e l = if existe e l then Just e else Nothing

instance Eq Album where
    (==) :: Album -> Album -> Bool
    a1 == a2 = albumTitre a1 == albumTitre a2
    (/=) :: Album -> Album -> Bool
    a1 /= a2 = albumTitre a1 /= albumTitre a2
instance Eq Article where
    (==) :: Article -> Article -> Bool
    a1 == a2 = articleId a1 == articleId a2
    (/=) :: Article -> Article -> Bool
    a1 /= a2 = articleId a1 /= articleId a2

data Couleur = Rouge | Noir
data ABR a = F a Couleur | N a Couleur (ABR a) (ABR a)

a = N 3 Rouge (F 1 Noir) (F 5 Noir)
