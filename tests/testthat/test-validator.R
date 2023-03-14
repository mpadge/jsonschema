schema <- '{
    "$schema": "http://json-schema.org/draft-07/schema#",
    "title": "A person",
    "properties": {
        "id": {
            "description": "Unique identifier",
            "type": "integer"
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
                 "name",
                 "age"
                 ],
    "type": "object"
}'
f_schema <- fs::path (fs::path_temp (), "schema.json")
if (!fs::file_exists (f_schema)) {
    writeLines (x, f_schema)
}

bad <- '{
    "id": "nope",
    "age": 42
}'
f_bad <- fs::path (fs::path_temp (), "schema.json")
if (!fs::file_exists (f_bad)) {
    writeLines (bad, f_bad)
}

good <- '{
    "id": 1,
    "name": "Albert",
    "age": 42
}'
f_good <- fs::path (fs::path_temp (), "schema.json")
if (!fs::file_exists (f_good)) {
    writeLines (good, f_good)
}

test_that ("validate", {
    expect_output (
        x <- jsonschema_validate (f_schema, f_bad, quiet = FALSE)
    )
    expect_null (x)

    expect_silent (
        x <- jsonschema_validate (f_schema, f_bad, quiet = TRUE)
    )
    expect_s3_class (x, "data.frame")
    expect_equal (nrow (x), 3L)
    expect_equal (ncol (x), 2L)
})
