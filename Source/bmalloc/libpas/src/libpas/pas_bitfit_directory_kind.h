/*
 * Copyright (c) 2020 Apple Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE INC. ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL APPLE INC. OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
 * OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. 
 */

#ifndef PAS_BITFIT_DIRECTORY_KIND_H
#define PAS_BITFIT_DIRECTORY_KIND_H

#include "pas_utils.h"

PAS_BEGIN_EXTERN_C;

/* Bitfit directories form a type hierarchy like so:
   
       - directory
           - global directory
           - biasing directory
   
   Only the types at the leaves are instantiable. The pas_bitfit_directory_kind enum is for
   describing the instantiable leaves. */

enum pas_bitfit_directory_kind {
    pas_bitfit_global_directory_kind,
    pas_bitfit_biasing_directory_kind
};

typedef enum pas_bitfit_directory_kind pas_bitfit_directory_kind;

static inline const char* pas_bitfit_directory_kind_get_string(pas_bitfit_directory_kind kind)
{
    switch (kind) {
    case pas_bitfit_global_directory_kind:
        return "bitfit_global_directory";
    case pas_bitfit_biasing_directory_kind:
        return "bitfit_biasing_directory";
    }
    PAS_ASSERT(!"Should not be reached");
    return NULL;
}

PAS_END_EXTERN_C;

#endif /* PAS_BITFIT_DIRECTORY_KIND_H */
