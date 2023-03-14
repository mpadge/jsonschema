#include <Rcpp.h>

//' src_fn
//'
//' A test C++ function
//' @noRd
// [[Rcpp::export]]
int test () {
    return 1L; }
