double :: Int -> Int
double x = x * 2

poly :: Float -> Float -> Float -> Float -> Float
poly a b c x = a * x * x + b * x + c

f1 :: Int -> Int -> Int
f1 a b = (2 * a + 5 * b) * b

f2 :: Bool -> Char -> Char -> Char
f2 a b c = if a then b else c

f3 :: Int -> Int -> Int
f3 a b = if a == 0 then b else f3 (a-1) (b+1)

main = do
    print(f3 2 3)