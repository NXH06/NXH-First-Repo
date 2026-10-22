tv :: Bool -> a -> Maybe a
tv True v = Just v
tv False v = Nothing

inc :: Int -> Int
inc n = n + 1

incl :: Num a => [a] -> [a]
incl [] = []
incl (x:xs) = (x+1) : incl xs

divl :: (Eq a, Fractional a) => a -> [a] -> [Maybe a]
divl _ [] = []
divl d (x:xs)
    | x /= 0 = Just (d/x) : xs'
    | otherwise = Nothing : xs'
    where
        xs' = divl d xs