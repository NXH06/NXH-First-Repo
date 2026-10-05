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
        Section "Ready, set, go!" [],
        Section "Baby's first functions" [],
        Section "An intro to lists" [],
        Section "Texas ranges" [],
        Section "I'm a list comprehension" [],
        Section "Tuples" []
        ]
    ]

sectionToStrings :: Section -> [String]
sectionToStrings (Section titre []) = [titre]
sectionToStrings (Section titre subs) = titre : concat (map sectionToStrings subs)

sommaireToString :: [Section] -> [String]
sommaireToString [] = []
sommaireToString subs = concat (map sectionToStrings subs)

numSommaire :: String -> [Section] -> [Section]
numSommaire s [] = []
numSommaire "" som = som
numSommaire s som = map (\ (Section titre subs) -> (Section (s ++ titre) (numSommaire s subs))) som 

-- numSection :: String -> Int -> Section -> Section
-- numSection s k (Section titre subs) = Section (s ++ (show k) ++ titre) (map (numSection ".." k' ))