f1 :: [Bool] -> Bool
f1 = foldl (||) False

{- f2 :: (a -> Bool) -> [a] -> [a]
f2 p l = foldl (\l' e -> if p e then l' else e:l') [] l -}
f2 :: (a -> Bool) -> [a] -> [a]
f2 p l = go [] l
    where
        go acc []     = acc
        go acc (x:xs) = go (if p x then acc else x : acc) xs

{- f3 :: (Num a) => [a] -> a
f3 = snd . foldl (\(i,v) x -> (i+1,v + x^i)) (1,0) -}
f3 :: (Num a) => [a] -> a
f3 l = go l 0 1
    where
        go [] v _ = v
        go (x:xs) v i = go xs (v+x^i) (i+1)

{- f4 :: (Num a) => (a -> Bool) -> [a] -> Maybe a
f4 p = foldl f Nothing
    where
        f (Just a) e
            | p e = Just (a*e)
            | otherwise = Just a
        f Nothing e
            | p e = Just e
            | otherwise = Nothing -}
