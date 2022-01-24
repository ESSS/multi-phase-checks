#include "udf.h"


// /* type definition section */
// typedef enum
// {
//   MP_OFF = 0,       /* same as FALSE */
//   MP_VOF,           /* corresponds to boolean mp_vof    */
//   MP_HOMOGENEOUS,   /*                        mp_hom    */
//   MP_DRIFT_FLUX,    /*                        mp_drift  */
//   MP_MULTI_FLUID,   /*                        mp_mfluid */
//   MP_MODEL_MAX
// } MP_Model;

// extern FLUENT_EXPORT MP_Model sg_mphase;
// extern FLUENT_EXPORT cxboolean mp_vof;
// extern FLUENT_EXPORT cxboolean mp_mixture;
// extern FLUENT_EXPORT cxboolean mp_hom;
// extern FLUENT_EXPORT cxboolean mp_drift;
// extern FLUENT_EXPORT cxboolean mp_mfluid;
// extern FLUENT_EXPORT int mp_n;


DEFINE_ON_DEMAND(print_multi_phase_variables)
{
    // Model selected and stored in the `sg_mphase` variable.
    Message0("\n...multi-phase option via the `sg_mphase` variable:\n");
    switch(sg_mphase)
    {
        case MP_OFF:
            Message0("\t...single-phase setup.\n");
            break;
        case MP_VOF:
            Message0("\t...VOF multi-phase setup.\n");
            break;
        case MP_HOMOGENEOUS:
            Message0("\t...Mixture homogeneous multi-phase setup.\n");
            break;
        case MP_DRIFT_FLUX:
            Message0("\t...Mixture drift-flux multi-phase setup.\n");
            break;
        case MP_MULTI_FLUID:
            Message0("\t...Eulerian multi-fluid multi-phase setup.\n");
            break;
        default:
            Error("\t...Unknown multi-phase setup!\n");
            break;
    }

    // Some `cxboolean` variables related to multi-phase setups.
    Message0("\n...multi-phase Boolean variables:\n");
    Message0("\t...`mp_vof` variable = %d\n", mp_vof);
    Message0("\t...`mp_mixture` variable = %d\n", mp_mixture);
    Message0("\t...`mp_hom` variable = %d\n", mp_hom);
    Message0("\t...`mp_drift` variable = %d\n", mp_drift);
    Message0("\t...`mp_mfluid` variable = %d\n", mp_mfluid);
    Message0("\t...`mp_n` variable = %d\n", mp_n);
}