data Operateur = Et | Ou | Implique | Equivalent deriving (Eq, Show)
data Formule =
    Top
    | Bottom
    | Non Formule
    | Binaire Operateur Formule Formule
    | Variable String
    deriving (Eq, Show)

-- Arbre initiale
f :: Formule
f = Binaire Equivalent (Variable "a") (Binaire Ou (Non (Variable "b")) (Variable "c"))

supprimeEquivalence :: Formule -> Formule
supprimeEquivalence (Variable v) = Variable v
supprimeEquivalence (Non f) = Non (supprimeEquivalence f)
supprimeEquivalence (Binaire Equivalent f1 f2) =
    let
        fc1 = supprimeEquivalence f1
        fc2 = supprimeEquivalence f2
    in
        Binaire Et (Binaire Implique fc1 fc2) (Binaire Implique fc2 fc1)
supprimeEquivalence (Binaire op f1 f2) = Binaire op (supprimeEquivalence f1) (supprimeEquivalence f2)

supprimeImplique :: Formule -> Formule
supprimeImplique (Variable v) = Variable v
supprimeImplique (Non f) = Non (supprimeImplique f)
supprimeImplique (Binaire Implique f1 f2) = Binaire Ou (Non (supprimeImplique f1)) (supprimeImplique f2)
supprimeImplique (Binaire op f1 f2) = Binaire op (supprimeImplique f1) (supprimeImplique f2)

propageNegation :: Formule -> Formule
-- le cas de base
propageNegation (Variable v) = Variable v
-- la règle de double négation
propageNegation (Non (Non f)) = propageNegation f
-- les lois de De Morgan
propageNegation (Non (Binaire Ou f1 f2)) = propageNegation (Binaire Et (Non f1) (Non f2))
propageNegation (Non (Binaire Et f1 f2)) = propageNegation (Binaire Ou (Non f1) (Non f2))
-- le cas récursif
propageNegation (Binaire op f1 f2) = Binaire op (propageNegation f1) (propageNegation f2)
-- l’application de la négation aux littéraux
propageNegation (Non f) = Non (propageNegation f)

distribue :: Formule -> Formule
-- les cas de base
distribue (Variable v) = Variable v
distribue (Non f) = Non (distribue f)
-- distributivité de "Et" par rapport à "Ou"
distribue (Binaire Et f1 f2) = conj (distribue f1) (distribue f2)
    where
        -- en cas d'une chaîne de "Et" suivi par un "Ou", faire le "Ou" flotter au-dessus la chaîne
        conj :: Formule -> Formule -> Formule
        conj (Binaire Ou g1 g2) h = Binaire Ou (conj g1 h) (conj g2 h)
        conj h (Binaire Ou g1 g2) = Binaire Ou (conj h g1) (conj h g2)
        conj g h = Binaire Et g h
-- le cas récursif
distribue (Binaire op f1 f2) = Binaire op (distribue f1) (distribue f2)

fnd :: Formule -> Formule
fnd = distribue . propageNegation . supprimeImplique . supprimeEquivalence