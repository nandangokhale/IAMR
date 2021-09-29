#ifndef _TurbulentForcing_params_H_
#define _TurbulentForcing_params_H_

namespace TurbulentForcing {

    // function to read in the parameters
    void read_turbulent_forcing_params ();
    void init_force_fab (amrex::BaseFab<amrex::Real>& farray);

    // factor by which to reduce sampling for faster performance
    extern AMREX_GPU_MANAGED int ff_factor;
    // make the forcing divergence free?
    extern AMREX_GPU_MANAGED bool div_free_force;
    // how many modes to use
    extern AMREX_GPU_MANAGED int nmodes;
    // don't use any modes below mode_start. We probably don't need this
    extern AMREX_GPU_MANAGED int mode_start;

    constexpr int array_size = 33;
    // BaseFabs will be sized as (0,0,0)(array_size-1,array_size-1,array_size-1)
    extern amrex::BaseFab<amrex::Real> FTX_fab;
    extern amrex::BaseFab<amrex::Real> TAT_fab;
    extern amrex::BaseFab<amrex::Real> FAX_fab;
    extern amrex::BaseFab<amrex::Real> FAY_fab;
    extern amrex::BaseFab<amrex::Real> FAZ_fab;
    extern amrex::BaseFab<amrex::Real> FPX_fab;
    extern amrex::BaseFab<amrex::Real> FPY_fab;
    extern amrex::BaseFab<amrex::Real> FPZ_fab;
    extern amrex::BaseFab<amrex::Real> FPXX_fab;
    extern amrex::BaseFab<amrex::Real> FPXY_fab;
    extern amrex::BaseFab<amrex::Real> FPXZ_fab;
    extern amrex::BaseFab<amrex::Real> FPYX_fab;
    extern amrex::BaseFab<amrex::Real> FPYY_fab;
    extern amrex::BaseFab<amrex::Real> FPYZ_fab;
    extern amrex::BaseFab<amrex::Real> FPZX_fab;
    extern amrex::BaseFab<amrex::Real> FPZY_fab;
    extern amrex::BaseFab<amrex::Real> FPZZ_fab;
}
#endif
