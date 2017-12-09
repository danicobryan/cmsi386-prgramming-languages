module DateCalculatorApp exposing (..)
import Html exposing (Html, body, input, text, h1, p, button)
import Html.Attributes exposing (style, value)
import Html.Events exposing (onClick, onInput)
import Date exposing (..)
import Date.Extra as Date exposing (..)

type alias Model = { date1: String, date2: String }
type Msg = ChangeDate1 String | ChangeDate2 String

daysBetween firstString secondString =
  case Date.fromString firstString of
    Err msg -> Err "First input string is not a date."
    Ok _ ->
      case Date.fromString firstString of
        Err msg -> Err "Second input string is not a date."
        Ok _ ->
          Ok <|
            let
              firstDate = Date.fromString firstString |> Result.withDefault (Date.fromTime 0)
              secondDate = Date.fromString secondString |> Result.withDefault (Date.fromTime 0)
            in
              Date.diff Day (firstDate) (secondDate)

daysBetweenMessage date1String date2String =
    case (date1String, date2String) of
        (Ok d1, Ok d2) -> toString (daysBetween date1String date2String) ++ "days."
        (Err s, _) -> s
        (_, Err s) -> s

main =
    Html.beginnerProgram { model = model, view = view, update = update }

model : Model
model = { date1 = "00-00-0000", date2 = "00-00-0000"}

update : Msg -> Model -> Model
update msg model =
    case msg of
        ChangeDate1 d1 -> { model | date1 = d1 }
        ChangeDate2 d2 -> { model | date2 = d2 }

view : Model -> Html Msg
view model =
    body [style [("textAlign", "center")]]
        [ h1 [] [text "Date Calculator"]
        , p [] [text "From: ", input [value model.date1] []]
        , p [] [text "To: ", input [value model.date2] []]
        , button [] [text "calculate"]
        , p [] [text <| daysBetweenMessage model.date1 model.date2]
        ]
