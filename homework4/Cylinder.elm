module Cylinder exposing (..)
import Basics

type alias Cylinder = {height : Float, radius : Float}

new : Cylinder
new = { radius = 1.0, height = 1.0 }

volume : Cylinder -> Float
volume c = pi * (c.radius ^ 2) * c.height

surfaceArea : Cylinder -> Float
surfaceArea c = (2 * (pi * (c.radius ^ 2))) + (2 * pi * c.radius * c.height)

widen : Int -> Cylinder -> Cylinder
widen factor c =
    let newRadius = c.radius + c.radius * (toFloat factor)
    in { height = c.height, radius = newRadius }

stretch : Int -> Cylinder -> Cylinder
stretch factor c =
    let newHeight = c.height + c.height * (toFloat factor)
    in { height = newHeight, radius = c.radius }
