fa1 :: (a -> Bool) -> a -> Maybe a
fa1 p a
    | p a = Just a
    | otherwise = Nothing

fa2 :: (a -> c) -> (b -> d) -> (a,b) -> (c,d)
fa2 f g (a,b) = (f a, g b)

fa3 :: (a -> a) -> Int -> a -> a
fa3 _ 0 x = x
fa3 f n x = f (fa3 f (n - 1) x)

fflip :: (a -> b -> c) -> (b -> a -> c)
fflip f = \ x y -> f y x

ap1 :: Num a => a -> a -> a -> a
ap1 a b c = a + b * c

ap3 :: (a -> b) -> a -> c -> (b,c)
ap3 f a b = (f a, b)