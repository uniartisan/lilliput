/*
 * Copyright (c) 2021 SAP SE. All rights reserved.
 * Copyright (c) 2021, Red Hat Inc. All rights reserved.
 * Copyright (c) 2021, Oracle and/or its affiliates. All rights reserved.
 *
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 *
 * This code is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 2 only, as
 * published by the Free Software Foundation.
 *
 * This code is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * version 2 for more details (a copy is included in the LICENSE file that
 * accompanied this code).
 *
 * You should have received a copy of the GNU General Public License version
 * 2 along with this work; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 * Please contact Oracle, 500 Oracle Parkway, Redwood Shores, CA 94065 USA
 * or visit www.oracle.com if you need additional information or have any
 * questions.
 *
 */

#include "precompiled.hpp"

#include "macroAssembler_riscv.hpp"
#include "oops/compressedKlass.hpp"
#include "utilities/ostream.hpp"
#include "runtime/globals.hpp"

// Given an address p, return true if p can be used as an encoding base.
//  (Some platforms have restrictions of what constitutes a valid base address).
bool CompressedKlassPointers::is_valid_base(address p) {
  return true;
  //return MacroAssembler::klass_decode_mode_for_base(p) != MacroAssembler::KlassDecodeNone;
}

void CompressedKlassPointers::print_mode(outputStream* st) {
  st->print_cr("Narrow klass base: " PTR_FORMAT ", Narrow klass shift: %d, "
               "Narrow klass range: " UINT64_FORMAT, p2i(base()), shift(),
               KlassEncodingMetaspaceMax);
}
// TODO 68fbdb32af3907
// https://github.com/uniartisan/lilliput/commit/68fbdb32af390762a01380b277a3ae30f864fdb4#diff-1aa79d2d356a1cec3cf5744e14ae25b8c34cf094926c77e82b8884e08d12b634
// void CompressedKlassPointers::print_mode(outputStream* st) {
//   st->print_cr("Narrow klass base: " PTR_FORMAT ", Narrow klass shift: %d, "
//                "Narrow klass range: " UINT64_FORMAT_X
//                ", Encoding mode %s",
//                p2i(base()), shift(), KlassEncodingMetaspaceMax,
//                MacroAssembler::describe_klass_decode_mode(MacroAssembler::klass_decode_mode()));
// }

