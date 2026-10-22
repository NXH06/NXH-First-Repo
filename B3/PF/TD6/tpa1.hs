f2 :: [a] -> [a]
f2 [] = []
f2 (a:as) = a:a:f2 as

f3 :: [a] -> [a] -> [a]
f3 l [] = l
f3 l (a:as) = f3 (a:a:l) as

f4 :: (Ord a) => [a] -> Maybe a
f4 [] = Nothing
f4 (a:as) = h a (f4 as)
    where
        h a mb@(Just b)= if a < b then Just a else mb
        h a Nothing = Just a

f5 :: [a] -> [[a]]
f5 [] = [[]]
f5 (a:as) = [] : map (a:) (f5 as)

f6 :: [a] -> [[a]]
f6 = go [[]]
    where
        go l [] = l
        go l (a:as) = go ([] : map (a:) l) as