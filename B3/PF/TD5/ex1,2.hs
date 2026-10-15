import Data.List

-- Q1
data ExprB =
    Lit Bool
    | BinOp OpLog ExprB ExprB
    | Non ExprB
    | Var String
    deriving Show

data OpLog = Et | Ou deriving Show

evalBinOp :: OpLog -> Bool -> Bool -> Bool
evalBinOp Et = (&&)
evalBinOp Ou = (||)

type Environnement = [(String, Bool)]

a :: ExprB
a = (Non (BinOp Et (BinOp Ou (Lit False) (Var "y")) (Var "x")))

eval :: ExprB -> Environnement -> Maybe Bool
eval (Lit b) _ = Just b
eval (BinOp op e1 e2) env = case (eval e1 env, eval e2 env) of
    (Just b1, Just b2) -> Just $ evalBinOp op b1 b2
    _ -> Nothing
eval (Non e) env = case eval e env of
    Just b -> Just $ not b
    _ -> Nothing
eval (Var v) env = lookup v env

-- Q2
listerVariables :: ExprB -> [String]
listerVariables = eliminerDoublons . sort . collecterVariables
    where
        eliminerDoublons [] = []
        eliminerDoublons [x] = [x]
        eliminerDoublons (x1:x2:xs) = case x1 == x2 of
            True -> eliminerDoublons (x2:xs)
            False -> x1 : eliminerDoublons (x2:xs) 
        collecterVariables n = case n of
            Lit _ -> []
            Var x -> [x]
            BinOp _ e1 e2 -> collecterVariables e1 ++ collecterVariables e2
            Non e -> collecterVariables e

valuations :: [String] -> [Environnement]
valuations [] = [[]]
valuations l = go l [[]]
    where
        go :: [String] -> [Environnement] -> [Environnement]
        go [] acc = acc
        {-- Applique récursivement le produit Cartésien de chaque nouvelle variable et la liste accumulative des environnements,
        en utilisant la compréhension des listes.
        À cause de l'implémentation au-dessous, les environnements auront l'ordre des variables à l'envers,
        mais le résultat ne change ultimement pas. --}
        go (x:xs) acc = go xs [b:a | a <- acc, b <- [(x, True), (x, False)]]

verif :: ExprB -> [Environnement]
verif a = filter (\ env -> eval a env == Just True) $ (valuations . listerVariables) a

reduire :: ExprB -> ExprB
reduire (Lit b) = Lit b
reduire (Var v) = Var v
reduire (Non e) = case reduire e of
    Lit b -> Lit (not b)
    e' -> Non e'
reduire (BinOp op e1 e2) = case (reduire e1, reduire e2) of
    (Lit b1, Lit b2) -> Lit $ evalBinOp op b1 b2
    (r1, r2) -> BinOp op r1 r2

