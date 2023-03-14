#' jsonschema_validate
#'
#' Validate an input 'JSON' file against a specified schema.
#'
#' @param schema Path to a local file containing a valid JSON schema.
#' @param json Path to a local JSON file to be validated against the schema.
#' @param quiet If `FALSE` (default), print all error messages generating in
#' parsing the JSON file to screen, in which case function returns nothing. If
#' `TRUE`, function returns all errors as a character string.
#' @return Nothing if `quiet = FALSE`; otherwise all errors encountered  in
#' parsing the JSON file.
#'
#' @export
jsonschema_validate <- function (schema = NULL, json = NULL, quiet = FALSE) {

    if (quiet) {
        x <- utils::capture.output (rcpp_json_validate (schema, json))
    } else {
        x <- rcpp_json_validate (schema, json)
    }

    invisible (x)
}
