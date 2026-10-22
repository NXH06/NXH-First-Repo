data Chanson = C {
    titre :: String,
    annee :: Int
} deriving Show

c1 = C {titre="melodrama", annee=2025}
c2 = C {titre="Sabry Aalil", annee=2003}
c3 = C {titre="Lágrimas Negras", annee=1931}

recent :: [Chanson] -> [Chanson]
recent = filter (\x -> annee x > 2010)

zipChanson :: [String] -> [Int] -> [Chanson]
zipChanson = zipWith (\t a -> C {titre=t, annee=a})
