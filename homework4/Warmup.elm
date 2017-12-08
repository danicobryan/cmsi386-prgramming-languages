module Warmup exposing (..)
import Html exposing (Html, text)
import List exposing (map, foldr, filter)
import Regex
import Date

{-- A function that accepts a number of U.S. cents and returns a tuple containing, respectively,
    the smallest number of U.S. quarters, dimes, nickels, and pennies that equal the given amount. --}

{-- A function that accepts a string and returns a new string equivalent to the argument
    but with all apostrophes and double quotes removed. --}
stripQuotes: String -> String
stripQuotes str =
    str
      |> Regex.replace Regex.All (Regex.regex "[\'\"]")(\_ -> "")

-- A function that returns a list of successive powers of a base starting at 1 and going up to some limit.


-- A function that returns the sum of the cubes of all of the odd integers in a list. Use map, filter, and foldr.

isOdd: Int -> Bool
isOdd number =
    if number % 2 == 0 then False else True

sumOfCubesOfOdds: List Int -> Int
sumOfCubesOfOdds numbers =
    List.foldr (+) 0 (List.map (\b -> b * b * b) (List.filter (isOdd) (numbers)))

{-- A function that returns the number of days between two dates,
    where the dates are given as strings in the format "YYYY-MM-DD". --}
