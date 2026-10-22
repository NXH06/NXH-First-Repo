zipWith' :: (a -> b -> c) -> [a] -> [b] -> [c]
zipWith' _ [] _ = []
zipWith' _ _ [] = []
zipWith' f l1 l2 = map (\ (x,y) -> f x y) (zip l1 l2)