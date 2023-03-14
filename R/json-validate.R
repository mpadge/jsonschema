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

    with_instance <- FALSE

    if (quiet) {
        x <- utils::capture.output (rcpp_json_validate (schema, json, with_instance))
    } else {
        x <- rcpp_json_validate (schema, json, with_instance)
    }

    x <- post_process_validation (x)
    x <- add_default_types (x, schema)

    invisible (x)
}

post_process_validation <- function (x) {

    if (is.null (x)) {
        return (x)
    }

    x <- gsub ("^JSON\\s+Error\\:\\s+", "", x)

    ids <- regmatches (x, gregexpr ("\\'[^\\']*\\'", x))
    ids <- vapply (ids, function (i) {
        gsub ("\\'", "", i [1])
    }, character (1L))

    msgs <- gsub ("^.*\\:\\s+", "", x)

    data.frame (
        id = ids,
        msg = msgs
    )
}

add_default_types <- function (x, schema) {

    if (is.null (x)) {
        return (x)
    }

    ids <- gsub ("^\\/", "", x$id)
    index <- which (nzchar (ids))

    s <- jsonlite::read_json (schema)
    x$expected_type <- ""
    x$expected_type [index] <- vapply (index, function (i) {
        s$properties [[ids [i]]]$type
    }, character (1L))

    return (x)
}
