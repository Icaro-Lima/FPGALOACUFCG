// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VMain.h for the primary calling header

#include "VMain.h"             // For This
#include "VMain__Syms.h"

//--------------------
// STATIC VARIABLES


//--------------------

VL_CTOR_IMP(VMain) {
    VMain__Syms* __restrict vlSymsp = __VlSymsp = new VMain__Syms(this, name());
    VMain* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    { int __Vi0=0; for (; __Vi0<8; ++__Vi0) {
	    SWI[__Vi0] = VL_RAND_RESET_I(1);
    }}
    { int __Vi0=0; for (; __Vi0<8; ++__Vi0) {
	    LED[__Vi0] = VL_RAND_RESET_I(1);
    }}
    { int __Vi0=0; for (; __Vi0<8; ++__Vi0) {
	    SEG[__Vi0] = VL_RAND_RESET_I(1);
    }}
}

void VMain::__Vconfigure(VMain__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

VMain::~VMain() {
    delete __VlSymsp; __VlSymsp=NULL;
}

//--------------------


void VMain::eval() {
    VMain__Syms* __restrict vlSymsp = this->__VlSymsp; // Setup global symbol table
    VMain* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    VL_DEBUG_IF(VL_PRINTF("\n----TOP Evaluate VMain::eval\n"); );
    int __VclockLoop = 0;
    IData __Vchange=1;
    while (VL_LIKELY(__Vchange)) {
	VL_DEBUG_IF(VL_PRINTF(" Clock loop\n"););
	vlSymsp->__Vm_activity = true;
	_eval(vlSymsp);
	__Vchange = _change_request(vlSymsp);
	if (++__VclockLoop > 100) vl_fatal(__FILE__,__LINE__,__FILE__,"Verilated model didn't converge");
    }
}

void VMain::_eval_initial_loop(VMain__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    vlSymsp->__Vm_activity = true;
    int __VclockLoop = 0;
    IData __Vchange=1;
    while (VL_LIKELY(__Vchange)) {
	_eval_settle(vlSymsp);
	_eval(vlSymsp);
	__Vchange = _change_request(vlSymsp);
	if (++__VclockLoop > 100) vl_fatal(__FILE__,__LINE__,__FILE__,"Verilated model didn't DC converge");
    }
}

//--------------------
// Internal Methods

void VMain::_combo__TOP__1(VMain__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VMain::_combo__TOP__1\n"); );
    VMain* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at Main.sv:7
    vlTOPp->SEG[0] = (IData)(vlTOPp->SWI)[0];
}

void VMain::_eval(VMain__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VMain::_eval\n"); );
    VMain* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__1(vlSymsp);
}

void VMain::_eval_initial(VMain__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VMain::_eval_initial\n"); );
    VMain* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void VMain::final() {
    VL_DEBUG_IF(VL_PRINTF("    VMain::final\n"); );
    // Variables
    VMain__Syms* __restrict vlSymsp = this->__VlSymsp;
    VMain* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void VMain::_eval_settle(VMain__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VMain::_eval_settle\n"); );
    VMain* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__1(vlSymsp);
}

IData VMain::_change_request(VMain__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VMain::_change_request\n"); );
    VMain* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    IData __req = false;  // Logically a bool
    return __req;
}
