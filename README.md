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
library](https://github.com/pboettch/json-schema-validator). Both of
these libraries are included here.

The ‘json-schema-validator’ library, and hence this package, validates
against [JSON Schema Draft
7](https://json-schema.org/specification-links.html#draft-7).

## Example

This example is taken directly from [the
`pboettch/json-schema-validator/`
README](https://github.com/pboettch/json-schema-validator/). The schema
provided there illustrates the general structure of JSON schemas:

``` r
schema <- '{
    "$schema": "http://json-schema.org/draft-07/schema#",
    "title": "A person",
    "properties": {
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
    "age": 42
}'
person_good <- '{
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
jsonschema_validate ("schema.json", "person_good.json")
jsonschema_validate ("schema.json", "person_bad.json")
```

    ## JSON Error: '' - '{"age":42}': required property 'name' not found in object

## Code of Conduct

Please note that this package is released with a [Contributor Code of
Conduct](https://ropensci.org/code-of-conduct/). By contributing to this
project, you agree to abide by its terms.
