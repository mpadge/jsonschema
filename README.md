# jsonschema

<!-- badges: start -->

[![R build
status](https://github.com/mpadge/jsonschema/workflows/R-CMD-check/badge.svg)](https://github.com/mpadge/jsonschema/actions?query=workflow%3AR-CMD-check)
[![codecov](https://codecov.io/gh/mpadge/jsonschema/branch/main/graph/badge.svg)](https://codecov.io/gh/mpadge/jsonschema)
[![Project Status:
Concept](https://www.repostatus.org/badges/latest/wip.svg)](https://www.repostatus.org/#wip)
<!-- badges: end -->

The `jsonschema` R package validates ‘JSON’ (JavaScript Object Notation)
files against a specified [JSON schema](https://json-schema.org/). Most
functionality comes directly from [Patrick Boettcher’s
‘json-schema-validator’ C++
library](https://github.com/pboettch/json-schema-validator/), along with
[Neils Lohmann’s ‘Modern JSON for C++’
library](https://github.com/nlohmann/json). Both of these libraries are
included here.

The ‘json-schema-validator’ library, and hence this package, validates
against [JSON Schema Draft
7](https://json-schema.org/specification-links.html#draft-7).

## Example

This example is modified from [the `pboettch/json-schema-validator/`
README](https://github.com/pboettch/json-schema-validator/). The schema
illustrates the general structure of JSON schemas:

``` r
schema <- '{
    "$schema": "http://json-schema.org/draft-07/schema#",
    "title": "A person",
    "properties": {
        "id": {
            "description": "Unique identifier",
            "type": "integer"
        },
        "date": {
            "type": "string",
            "format": "date"
        },
        "name": {
            "description": "Name",
            "type": "string"
        },
        "age": {
            "description": "Age of the person",
            "type": "number",
            "minimum": 2,
            "maximum": 200
        }
    },
    "required": [
                 "id",
                 "date",
                 "name",
                 "age"
                 ],
    "type": "object"
}'
```

That repository then provides the following examples of JSON input to
validate against that schema:

``` r
person_bad <- '{
    "id": "nope",
    "date": "2022-02",
    "age": 42
}'
person_good <- '{
    "id": 1,
    "date": "2022-02-02",
    "name": "Albert",
    "age": 42
}'
```

This package works exclusively with locally-stored files. The following
lines save those three items to local files.

``` r
writeLines (schema, "schema.json")
writeLines (person_bad, "person_bad.json")
writeLines (person_good, "person_good.json")
```

The JSON files can then be validated by loading the package and running
its single function:

``` r
library (jsonschema)
jsonschema_validate ("schema.json", "person_good.json") # no output
jsonschema_validate ("schema.json", "person_bad.json")
```

    ## JSON Error: '': required property 'name' not found in object
    ## JSON Error: '/date': format-checking failed: 2022-02 is not a date string according to RFC 3339.
    ## JSON Error: '/id': unexpected instance type

The results can be captured in a `data.frame` object like this:

``` r
x <- jsonschema_validate ("schema.json", "person_bad.json", quiet = TRUE)
print (x)
```

    ##      id                                                 msg expected_type
    ## 1              required property 'name' not found in object
    ## 2 /date 2022-02 is not a date string according to RFC 3339.        string
    ## 3   /id                            unexpected instance type       integer

## Prior Art

The [‘jsonvalidate’ package](https://docs.ropensci.org/jsonvalidate/)
also validates JSON files against schemas, through wrapping two
JavaScript libraries.

## Code of Conduct

Please note that this package is released with a [Contributor Code of
Conduct](https://ropensci.org/code-of-conduct/). By contributing to this
project, you agree to abide by its terms.
