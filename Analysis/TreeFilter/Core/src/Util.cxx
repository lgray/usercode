#include "Core/Util.h"
#include <math.h>

float calc_mt( const TLorentzVector & obj, const TLorentzVector & nu ) {

    return sqrt( 2*obj.Pt()*nu.Pt() * ( 1 - cos( obj.DeltaPhi(nu) ) ) );

}

