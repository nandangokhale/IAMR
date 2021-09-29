#include <TurbulentForcing_params.H>
#include <AMReX_BaseFab.H>
#include <AMReX_ParmParse.H>
#include <AMReX_Arena.H>


// factor by which to reduce sampling for faster performance
AMREX_GPU_MANAGED int TurbulentForcing::ff_factor;
// make the forcing divergence free?
AMREX_GPU_MANAGED bool TurbulentForcing::div_free_force;
// how many modes to use
AMREX_GPU_MANAGED int TurbulentForcing::nmodes;
// don't use any modes below mode_start. We probably don't need this
AMREX_GPU_MANAGED int TurbulentForcing::mode_start;

// BaseFabs will be sized as (0,0,0)(array_size-1,array_size-1,array_size-1)
amrex::BaseFab<amrex::Real> TurbulentForcing::FTX_fab;
amrex::BaseFab<amrex::Real> TurbulentForcing::TAT_fab;
amrex::BaseFab<amrex::Real> TurbulentForcing::FAX_fab;
amrex::BaseFab<amrex::Real> TurbulentForcing::FAY_fab;
amrex::BaseFab<amrex::Real> TurbulentForcing::FAZ_fab;
amrex::BaseFab<amrex::Real> TurbulentForcing::FPX_fab;
amrex::BaseFab<amrex::Real> TurbulentForcing::FPY_fab;
amrex::BaseFab<amrex::Real> TurbulentForcing::FPZ_fab;
amrex::BaseFab<amrex::Real> TurbulentForcing::FPXX_fab;
amrex::BaseFab<amrex::Real> TurbulentForcing::FPXY_fab;
amrex::BaseFab<amrex::Real> TurbulentForcing::FPXZ_fab;
amrex::BaseFab<amrex::Real> TurbulentForcing::FPYX_fab;
amrex::BaseFab<amrex::Real> TurbulentForcing::FPYY_fab;
amrex::BaseFab<amrex::Real> TurbulentForcing::FPYZ_fab;
amrex::BaseFab<amrex::Real> TurbulentForcing::FPZX_fab;
amrex::BaseFab<amrex::Real> TurbulentForcing::FPZY_fab;
amrex::BaseFab<amrex::Real> TurbulentForcing::FPZZ_fab;


void
TurbulentForcing::read_turbulent_forcing_params ()
{
    using namespace amrex;

    // read in parameters for turbulent forcing
    ParmParse pp("turb");

    // Make user set nmodes. This must match up with nmodes used in making MagicFile
    nmodes = -1;
    pp.get("nmodes", nmodes);

    div_free_force = true;
    pp.query("div_free_force", div_free_force);

    ff_factor = 4;
    pp.query("ff_factor", ff_factor);

    mode_start = 0;
    pp.query("mode_start", mode_start);

    // Create Array4 object for temp storage of magic numbers on CPU
    //Real*** data[array_size][array_size][array_size] = {{0.}};
    //.... or maybe I want amrex::Array3D??? - C order

    // Now read in values from the MagicFile to CPU storage.
// For now, fake it

    // Box bx(IntVect::TheZeroVector(), IntVect(AMREX_D_DECL(array_size, array_size, array_size)));
    // TurbulentForcing::FTX.resize(bx, 1, The_Device_Arena());
    // TurbulentForcing::TAT.resize(bx, 1, The_Device_Arena());
    // TurbulentForcing::FAX.resize(bx, 1, The_Device_Arena());
    // TurbulentForcing::FAY.resize(bx, 1, The_Device_Arena());
    // TurbulentForcing::FAZ.resize(bx, 1, The_Device_Arena());
    // TurbulentForcing::FPX.resize(bx, 1, The_Device_Arena());
    // TurbulentForcing::FPY.resize(bx, 1, The_Device_Arena());
    // TurbulentForcing::FPZ.resize(bx, 1, The_Device_Arena());
    // TurbulentForcing::FPXX.resize(bx, 1, The_Device_Arena());
    // TurbulentForcing::FPXY.resize(bx, 1, The_Device_Arena());
    // TurbulentForcing::FPXZ.resize(bx, 1, The_Device_Arena());
    // TurbulentForcing::FPYX.resize(bx, 1, The_Device_Arena());
    // TurbulentForcing::FPYY.resize(bx, 1, The_Device_Arena());
    // TurbulentForcing::FPYZ.resize(bx, 1, The_Device_Arena());
    // TurbulentForcing::FPZX.resize(bx, 1, The_Device_Arena());
    // TurbulentForcing::FPZY.resize(bx, 1, The_Device_Arena());
    // TurbulentForcing::FPZZ.resize(bx, 1, The_Device_Arena());

    init_force_fab(FTX_fab);
    init_force_fab(TAT_fab);
    init_force_fab(FAX_fab);
    init_force_fab(FAY_fab);
    init_force_fab(FAZ_fab);
    init_force_fab(FPX_fab);
    init_force_fab(FPY_fab);
    init_force_fab(FPZ_fab);
    init_force_fab(FPXX_fab);
    init_force_fab(FPXY_fab);
    init_force_fab(FPXZ_fab);
    init_force_fab(FPYX_fab);
    init_force_fab(FPYY_fab);
    init_force_fab(FPYZ_fab);
    init_force_fab(FPZX_fab);
    init_force_fab(FPZY_fab);
    init_force_fab(FPZZ_fab);

}

void
TurbulentForcing::init_force_fab (amrex::BaseFab<amrex::Real>& farray)
{
    using namespace amrex;

// Allocate space on the device. Defaults to CPU if !AMREX_USE_GPU
    Box bx(IntVect::TheZeroVector(), IntVect(AMREX_D_DECL(array_size, array_size, array_size)));
    int ncomp = 1;
    farray.resize(bx, ncomp, The_Device_Arena());

// For now, initialize to bogus number for debugging
    farray.setVal<RunOn::Device>(1.2345e40);
    //farray.setVal<RunOn::Device>(0.);

    // Copy in forcing data
}
