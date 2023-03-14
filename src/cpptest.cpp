#include <Rcpp.h>

//' src_fn
//'
//' A test C++ function
//' @srrstats {G2.3} in src directory
//' @noRd
// [[Rcpp::export]]
int test () {
    return 1L; }
