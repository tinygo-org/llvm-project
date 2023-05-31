//===--- Xtensa.cpp - Implement Xtensa target feature support -------------===//
//
//                     The LLVM Compiler Infrastructure
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This file implements Xtensa TargetInfo objects.
//
//===----------------------------------------------------------------------===//

#include "Xtensa.h"
#include "clang/Basic/Builtins.h"
#include "clang/Basic/MacroBuilder.h"
#include "clang/Basic/TargetBuiltins.h"

using namespace clang;
using namespace clang::targets;

void XtensaTargetInfo::getTargetDefines(const LangOptions &Opts,
                                        MacroBuilder &Builder) const {
  Builder.defineMacro("__xtensa__");
  Builder.defineMacro("__XTENSA__");
  if (BigEndian)
    Builder.defineMacro("__XTENSA_EB__");
  else
    Builder.defineMacro("__XTENSA_EL__");
  if (HasWindowed)
    Builder.defineMacro("__XTENSA_WINDOWED_ABI__");
  else
    Builder.defineMacro("__XTENSA_CALL0_ABI__");
  if (!HasFP)
    Builder.defineMacro("__XTENSA_SOFT_FLOAT__");
  Builder.defineMacro("__XCHAL_HAVE_BE", BigEndian ? "1" : "0");
  Builder.defineMacro("__XCHAL_HAVE_DENSITY", HasDensity ? "1" : "0");
  Builder.defineMacro("__XCHAL_HAVE_MAC16", HasMAC16 ? "1" : "0");
  Builder.defineMacro("__XCHAL_HAVE_MUL16", HasMul16 ? "1" : "0");
  Builder.defineMacro("__XCHAL_HAVE_MUL32", HasMul32 ? "1" : "0");
  Builder.defineMacro("__XCHAL_HAVE_MUL32_HIGH", HasMul32High ? "1" : "0");
  Builder.defineMacro("__XCHAL_HAVE_DIV32", HasDiv32 ? "1" : "0");
  Builder.defineMacro("__XCHAL_HAVE_NSA", HasNSA ? "1" : "0");
  Builder.defineMacro("__XCHAL_HAVE_MINMAX", HasMINMAX ? "1" : "0");
  Builder.defineMacro("__XCHAL_HAVE_SEXT", HasSEXT ? "1" : "0");
  Builder.defineMacro("__XCHAL_HAVE_LOOPS", HasLoop ? "1" : "0");
  Builder.defineMacro("__XCHAL_HAVE_THREADPTR", HasTHREADPTR ? "1" : "0");
  Builder.defineMacro("__XCHAL_HAVE_S32C1I", HasS32C1I ? "1" : "0");
  Builder.defineMacro("__XCHAL_HAVE_BOOLEANS", HasBoolean ? "1" : "0");
  Builder.defineMacro("__XCHAL_HAVE_FP", HasFP ? "1" : "0");
  Builder.defineMacro("__XCHAL_HAVE_FP_DIV", HasFP ? "1" : "0");
  Builder.defineMacro("__XCHAL_HAVE_FP_RECIP", HasFP ? "1" : "0");
  Builder.defineMacro("__XCHAL_HAVE_FP_SQRT", HasFP ? "1" : "0");
  Builder.defineMacro("__XCHAL_HAVE_FP_RSQRT", HasFP ? "1" : "0");
  Builder.defineMacro("__XCHAL_HAVE_FP_POSTINC", HasFP ? "1" : "0");
  Builder.defineMacro("__XCHAL_HAVE_WINDOWED", HasWindowed ? "1" : "0");
  Builder.defineMacro("__XCHAL_HAVE_DEBUG", HasDebug ? "1" : "0");
  Builder.defineMacro("__XCHAL_HAVE_ABS");  // core arch
  Builder.defineMacro("__XCHAL_HAVE_ADDX"); // core arch
  Builder.defineMacro("__XCHAL_HAVE_L32R"); // core arch
}
