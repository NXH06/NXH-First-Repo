data Expr a = 
    BOp BinOp (Expr a) (Expr a)
    | Neg (Expr a)
    | Lit a
    | Var String
    | Let String (Expr a) (Expr a)
data BinOp = Add | Sou | Mul | Div

evalBinOp :: Fractional a => BinOp -> a -> a -> a
evalBinOp Add = (+)
evalBinOp Sou = (-)
evalBinOp Mul = (*)
evalBinOp Div = (/)

type Environnement a = [(String, a)]

eval :: (Eq a, Fractional a) => Expr a -> Environnement a -> Maybe a
eval (Var n) env = lookup n env
eval (Let n en e) env = case eval en env of
    Just vn -> eval e $ (n,vn):env
    _ -> Nothing
eval (Lit v) _ = Just v
eval (Neg e) env = case eval e env of
    Just v -> Just $ negate v
    _ -> Nothing
eval (BOp op e1 e2) env = case (op, eval e1 env, eval e2 env) of
    (Div, _, Just 0) -> Nothing
    (op', Just v1, Just v2) -> Just $ evalBinOp op' v1 v2
    _ -> Nothing

ex1 :: Maybe Double
ex1 = eval (BOp Add (BOp Mul (Lit 2) (Var "a")) (BOp Mul (Lit 3) (Var "b"))) [("a",1), ("b",3)]