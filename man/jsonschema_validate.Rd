% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/json-validate.R
\name{jsonschema_validate}
\alias{jsonschema_validate}
\title{jsonschema_validate}
\usage{
jsonschema_validate(schema = NULL, json = NULL, quiet = FALSE)
}
\arguments{
\item{schema}{Path to a local file containing a valid JSON schema.}

\item{json}{Path to a local JSON file to be validated against the schema.}

\item{quiet}{If \code{FALSE} (default), print all error messages generating in
parsing the JSON file to screen.}
}
\value{
(Invisibly) A \code{data.frame} detailing all errors encountered  in
parsing the JSON file.
}
\description{
Validate an input 'JSON' file against a specified schema.
}
