decoupe :: [Int] -> ([Int], [Int])
decoupe l = go ([], []) l
    where
    go :: ([Int], [Int]) -> [Int] -> ([Int], [Int])
    go ll [] = ll
    go (l1, l2) [x] = (l1 ++ [x], l2)
    go (l1, l2) (x1:x2:xs) = go (l1 ++ [x1], l2 ++ [x2]) xs

fusion :: [Int] -> [Int] -> [Int]
fusion a b = go a b []
    where
    go :: [Int] -> [Int] -> [Int] -> [Int]
    go [] [] acc = acc
    go l [] acc = acc ++ l
    go [] l acc = acc ++ l
    go (x1:l1) (x2:l2) acc
        | x1 < x2 = go l1 (x2:l2) (acc ++ [x1])
        | otherwise = go (x1:l1) l2 (acc ++ [x2])

triFusion :: [Int] -> [Int]
triFusion [] = []
triFusion [x] = [x]
triFusion l = 
    let (l1, l2) = decoupe l in fusion (triFusion l1) (triFusion l2)

compteTri :: [Int] -> [(Int, Int)]
compteTri [] = []
compteTri l = go l 0 (head l) []
    where
    go :: [Int] -> Int -> Int -> [(Int, Int)] -> [(Int, Int)]
    go [] count prev acc = acc ++ [(prev, count)]
    go (x:xs) count prev acc
        | x == prev = go xs (count + 1) prev acc
        | otherwise = go xs 1 x (acc ++ [(prev, count)])

compter3 :: [Int] -> [(Int, Int)]
compter3 [] = []
compter3 l = compteTri (triFusion l)