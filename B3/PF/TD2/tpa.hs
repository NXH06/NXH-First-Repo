data Client = Client {
    nom :: String,
    prenom :: String,
    email :: String,
    adresse :: String
} deriving Show

data Liste = M Int Liste | Vide deriving Show