data ArbreH
    = F Char -- Feuille
    | N ArbreH ArbreH -- Noeud
    deriving Show
data Direction = G | D deriving Show
data Chemin = Valide [Direction] | Invalide deriving Show

voyellesH :: ArbreH
voyellesH =
    N (F 'e')
    (N (N (N (F 'y') (F 'o'))
    (F 'i'))
    (N (F 'u') (F 'a')))

existe :: ArbreH -> Char -> Bool
existe (F v) v' = v == v'
existe (N ag ad) v' = existe ag v' || existe ad v'

chemin :: ArbreH -> Char -> Chemin
chemin a v' = if not (null res) then Valide res else Invalide
    where
        res = go a []
        go :: ArbreH -> [Direction] -> [Direction]
        go (F v) acc = if v == v' then acc else []
        go (N ag ad) acc
            | not (null goleft) = goleft
            | not (null goright) = goright
            | otherwise = []
            where
                goleft = go ag (acc ++ [G])
                goright = go ad (acc ++ [D])

(+++) :: Chemin -> Chemin -> Chemin
Valide a +++ Valide b = Valide (a ++ b)
_ +++ Invalide = Invalide
Invalide +++ _ = Invalide

encoder :: ArbreH -> String -> Chemin
encoder _ "" = Valide []
encoder a (x:xs) = case code of
    Invalide -> Invalide
    Valide _ -> code +++ encoder a xs
    where code = chemin a x

data ResChar = Present Char | Absent deriving Show

decoder :: ArbreH -> [Direction] -> ResChar
-- Si la liste de direction est vide alors qu'on n'est encore arrivé à une feuille, le chemin est invalide
decoder (N _ _) [] = Absent
decoder (F c) l
    | null l = Present c
    | otherwise = Absent
decoder (N ag ad) (x:xs) = case x of
    G -> decoder ag xs
    D -> decoder ad xs

decoderUn :: ArbreH -> [Direction] -> (ResChar, [Direction])
decoderUn (N _ _) [] = (Absent, [])
decoderUn (F c) l = (Present c, l)
decoderUn (N ag ad) (x:xs) = case x of
    G -> decoderUn ag xs
    D -> decoderUn ad xs

decoderTous :: ArbreH -> [Direction] -> String
decoderTous _ [] = ""
decoderTous a l = case decoderUn a l of
    (Present c, l') -> c : decoderTous a l'
    _ -> "" -- comme "otherwise", mais pour *case...of* plutôt que des gardes