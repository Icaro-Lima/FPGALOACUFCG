// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _VMain_H_
#define _VMain_H_

#include "verilated.h"
class VMain__Syms;

//----------

VL_MODULE(VMain) {
  public:
    // CELLS
    // Public to allow access to /*verilator_public*/ items;
    // otherwise the application code can consider these internals.
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(SWI[8],0,0);
    VL_OUT8(LED[8],0,0);
    VL_OUT8(SEG[8],0,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    //char	__VpadToAlign36[4];
    VMain__Syms*	__VlSymsp;		// Symbol table
    
    // PARAMETERS
    // Parameters marked /*verilator public*/ for use by application code
    
    // CONSTRUCTORS
  private:
    VMain& operator= (const VMain&);	///< Copying not allowed
    VMain(const VMain&);	///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible WRT DPI scope names.
    VMain(const char* name="TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~VMain();
    
    // USER METHODS
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval();
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(VMain__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(VMain__Syms* symsp, bool first);
  private:
    static IData	_change_request(VMain__Syms* __restrict vlSymsp);
  public:
    static void	_combo__TOP__1(VMain__Syms* __restrict vlSymsp);
    static void	_eval(VMain__Syms* __restrict vlSymsp);
    static void	_eval_initial(VMain__Syms* __restrict vlSymsp);
    static void	_eval_settle(VMain__Syms* __restrict vlSymsp);
} VL_ATTR_ALIGNED(128);

#endif  /*guard*/
