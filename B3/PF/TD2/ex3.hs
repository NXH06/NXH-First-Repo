data Section = Section String [Section] deriving Show

lyah :: [Section]
lyah = 
    [
    Section "Introduction" 
        [
        Section "About this tutorial" [],
        Section "So what's Haskell?" [],
        Section "What you need to dive in" []
        ],
    Section "Starting Out" 
        [
        Section "Ready, set, go!" 
            [
            Section "asdf" [],
            Section "ghj" [],
            Section "kl" []
            ],
        Section "Baby's first functions"
            [
            Section "zxcv" [],
            Section "bnm" []
            ],
        Section "An intro to lists" [],
        Section "Texas ranges" [],
        Section "I'm a list comprehension" [],
        Section "Tuples" []
        ]
    ]
test1 :: Section
test1 = lyah !! 0
test2 :: Section
test2 = lyah !! 1

-- Q1
sectionToStrings :: Section -> [String]
sectionToStrings (Section titre []) = [titre]
sectionToStrings (Section titre subs) = titre : concatMap sectionToStrings subs

sommaireToString :: [Section] -> String
sommaireToString [] = []
sommaireToString subs = concatMap (++ "\n") (concatMap sectionToStrings subs)

-- Q2
numSommaire :: String -> [Section] -> [Section]
numSommaire s [] = []
numSommaire s l = go 1 l
    where
        go :: Int -> [Section] -> [Section]
        go k [] = []
        go k (x:xs) = numSection s k x : go (k + 1) xs

numSection :: String -> Int -> Section -> Section
numSection s k (Section titre subs) = Section (s ++ show k ++ marquerNombre ++ titre) (numSommaire (indent ++ s ++ show k ++ ".") subs)
    where
        indent :: String
        indent = ".."
        marquerNombre :: String
        marquerNombre = " "

-- Q3
showSommaire :: [Section] -> String
showSommaire som = sommaireToString (numSommaire "" som)
