monMinimum :: Ord a => [a] -> Maybe a
monMinimum [] = Nothing
monMinimum l = go (tail l) (head l) where
    go [] m = Just m
    go (x:xs) m = if x < m then go xs x else go xs m