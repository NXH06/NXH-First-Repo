f3 :: (Fractional a) => [a] -> a -> a -> a
f3 [] m s = m / s
f3 (x:xs) m s = f3 xs (m + 1) (s + x)

f4 :: (Num a, Num b) => (a -> b -> b -> b) -> [b] -> (a, b)
f4 f = foldr (\e (k, v) -> (k + 1, f k e v)) (0,0)

f4' :: (Num a, Num b) => (a -> b -> b -> b) -> [b] -> (a, b)
f4' _ [] = (0, 0)
f4' f (x:xs) = (k + 1, f k x v)
    where (k, v) = f4' f xs