////////////////////////////////////////////////////////////////////////////////
// Copyright (C) 2017, MINRES Technologies GmbH
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// 1. Redistributions of source code must retain the above copyright notice,
//    this list of conditions and the following disclaimer.
//
// 2. Redistributions in binary form must reproduce the above copyright notice,
//    this list of conditions and the following disclaimer in the documentation
//    and/or other materials provided with the distribution.
//
// 3. Neither the name of the copyright holder nor the names of its contributors
//    may be used to endorse or promote products derived from this software
//    without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.
//
// Contributors:
//       eyck@minres.com - initial implementation
//
//
////////////////////////////////////////////////////////////////////////////////

#ifndef _AON_H_
#define _AON_H_

#include "scc/tlm_target.h"

namespace sysc {

class aon_regs;

class aon : public sc_core::sc_module, public scc::tlm_target<> {
public:
    SC_HAS_PROCESS(aon);
    sc_core::sc_in<sc_core::sc_time> clk_i;
    sc_core::sc_in<bool> erst_n_i;
    sc_core::sc_out<sc_core::sc_time> lfclkc_o;
    sc_core::sc_out<bool> rst_o;
    aon(sc_core::sc_module_name nm);
    virtual ~aon() override; // need to keep it in source file because of fwd declaration of aon_regs

protected:
    void start_of_simulation() override;
    void clock_cb();
    void reset_cb();
    void reset_internal_cb();
    sc_core::sc_time clk;
    std::unique_ptr<aon_regs> regs;
};

} /* namespace sysc */

#endif /* _GPIO_H_ */
