#include "json-validator.h"

// Modified from template at
// https://github.com/pboettch/json-schema-validator

#include <Rcpp.h>

// [[Rcpp::export]]
void rcpp_json_validate (const std::string schema_name, const std::string json_name, const bool with_instance) {

    std::ifstream f_s (schema_name);
    json schema = nlohmann::json::parse (f_s);

    json_validator validator; // create validator

    std::string out = "";

    try {
        validator.set_root_schema(schema); // insert root-schema
    } catch (const std::exception &e) {
        const std::string estr = std::to_string(*e.what());
        out += "ERROR: Validation of schema failed: " + estr + "\n";
        Rcpp::stop (out);
    }

    std::ifstream f_j (json_name);
    json json_data = nlohmann::json::parse (f_j);

    class error_handler_with_instance : public nlohmann::json_schema::basic_error_handler
    {
        void error(const nlohmann::json_pointer<std::basic_string<char, std::char_traits<char>, std::allocator<char>>> &pointer, const json &instance,
            const std::string &message) 
        {
            nlohmann::json_schema::basic_error_handler::error(pointer, instance, message);
            Rcpp::Rcout << "JSON Error: '" << pointer << "' - '" << instance << "': " << message << "\n";
        }
    };

    class error_handler_without_instance : public nlohmann::json_schema::basic_error_handler
    {
        void error(const nlohmann::json_pointer<std::basic_string<char, std::char_traits<char>, std::allocator<char>>> &pointer, const json &instance,
            const std::string &message) 
        {
            nlohmann::json_schema::basic_error_handler::error(pointer, instance, message);
            Rcpp::Rcout << "JSON Error: '" << pointer << "': " << message << std::endl;
        }
    };

    if (with_instance)
    {
        error_handler_with_instance err;
        validator.validate (json_data, err);
    } else {
        error_handler_without_instance err;
        validator.validate (json_data, err);
    }
}
