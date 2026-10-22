data BinOp = Add | Sous | Mult | Div deriving Show
data Expression a = BOp BinOp (Expression a) (Expression a) | Val a deriving Show

e1 :: Fractional a => Expression a
e1 = BOp Add (BOp Div (Val 3) (Val 2)) (BOp Mult (Val 4) (Val 5))

binOpToFun :: Fractional a => BinOp -> a -> a -> a
binOpToFun Add = (+)
binOpToFun Sous = (-)
binOpToFun Mult = (*)
binOpToFun Div = (/)

foldExpr :: (BinOp -> b -> b -> b) -> (a -> b) -> Expression a -> b
foldExpr _ val (Val a) = val a
foldExpr bop val (BOp op e1 e2) = bop op (ev e1) (ev e2)
    where ev = foldExpr bop val

evalExp :: Fractional a => Expression a -> a
evalExp = foldExpr binOpToFun id -- ne change pas les feuilles

{- nbOp :: Num b => Expression a -> b
nbOp (Val _) = 0
nbOp (BOp _ e1 e2) = 1 + nbOp e1 + nbOp e2 -}
nbOp :: Num b => Expression a -> b
nbOp = foldExpr (\_ g d -> 1 + g + d) (const 0)
