insererQuand :: (a -> Bool) -> a -> [a] -> [a]
insererQuand _ a [] = [a]
insererQuand p a (x:xs)
    | p x = a:x:xs
    | otherwise = x : insererQuand p a xs

triInsertion :: Ord a => [a] -> [a]
triInsertion [] = []
triInsertion l = go l []
    where
        go [] acc = acc
        go (a:as) acc = go as (insererQuand (\ x -> a < x) a acc)